OS=$(shell uname)
CC=gcc -std=c11 -D_GNU_SOURCE
INSTALL_DIR=SmartCalc
DIR=

TEST_FLAGS = -fprofile-arcs -ftest-coverage

ifeq ($(OS), Linux)
	TFLAGS = -lcheck -lm -lpthread -lrt -lsubunit -D_GNU_SOURCE 
	QMAKE=qmake 
	OPT=-spec linux-g++ CONFIG+=qtquickbuilder
	BUILD_DIR=SmartCalc-Desktop_x86_64bit-Release
	DIR=
	LIBS=-lcheck -lpthread -lrt -lm -lsubunit
else
	TFLAGS = -lcheck -lm -lpthread 
	QMAKE=qmake
	OPT= CONFIG+=qtquickbuilder
	BUILD_DIR=SmartCalc-Desktop_x86_64bit-Release/
	DIR=SmartCalc.app/Contents/MacOS
	LIBS=-lcheck -lm
endif

all: build

build:
	$(QMAKE) -o $(BUILD_DIR)/Makefile SmartCalc.pro $(OPT)
	make -C $(BUILD_DIR)/ first
	

rebuild: clean all

install:
	@mkdir -p $(INSTALL_DIR)
	@cp -r $(BUILD_DIR)$(DIR)/SmartCalc $(INSTALL_DIR)/SmartCalc
	

unistall:
	@rm -rf $(INSTALL_DIR)

dist: clean
	tar -czf "SmartCalc.tgz" headers sources ui *.pro Makefile 

dvi:
	@cp man.pdf $(INSTALL_DIR)/man.pdf
	open $(INSTALL_DIR)/man.pdf

test: 
	$(CC) -c $(TEST_FLAGS) -I headers sources/stack.c
	$(CC) -c $(TEST_FLAGS) -I headers sources/parse.c
	$(CC) -c $(TEST_FLAGS) -I headers sources/polish_notation.c
	$(CC) -I headers tests.c stack.o parse.o polish_notation.o $(TFLAGS) $(TEST_FLAGS)
	./a.out


gcov_report:
	lcov --directory . -c -o tests.info
	genhtml tests.info -o report
	open report/index.html

check:
	cp ../materials/linters/CPPLINT.cfg .
	cppcheck --enable=all headers/parse.h headers/polish_notation.h headers/stack.h sources/parse.c sources/polish_notation.c sources/stack.c tests.c
	python3 ../materials/linters/cpplint.py headers/parse.h headers/polish_notation.h headers/stack.h sources/parse.c sources/polish_notation.c sources/stack.c tests.c

clean:
	rm -rf a.out *.tgz *.o *.a *.gcda *.gcno *.info *.info report *Release *.cfg SmartCalc
