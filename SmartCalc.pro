QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

INCLUDEPATH += $$PWD/headers

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    sources/main.cpp \
    sources/calc.cpp \
    sources/credit_calc.cpp \
    sources/deposit_calc.cpp \
    sources/graphic_modeling.cpp \
    sources/history.cpp \
    sources/mainwindow.cpp \
    sources/parse.c \
    sources/polish_notation.c \
    sources/qcustomplot.cpp \
    sources/stack.c

HEADERS += \
    headers/calc.h \
    headers/credit_calc.h \
    headers/deposit_calc.h \
    headers/graphic_modeling.h \
    headers/history.h \
    headers/mainwindow.h \
    headers/parse.h \
    headers/polish_notation.h \
    headers/qcustomplot.h \
    headers/stack.h

FORMS += \
    ui/credit_calc.ui \
    ui/deposit_calc.ui \
    ui/graphic_modeling.ui \
    ui/history.ui \
    ui/mainwindow.ui \
    ui/calc.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
