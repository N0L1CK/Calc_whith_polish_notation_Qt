#include "calc.h"
#include "ui_calc.h"

Calc::Calc(QWidget *parent) : QWidget(parent),
                              ui(new Ui::Calc) {
    setlocale(LC_ALL,"en_US");
    ui->setupUi(this);
    SetSignals();
    g_m = new graphic_modeling();
    his = new history();
    connect(this, &Calc::signal_wright_history, his, &history::slot);

}

Calc::~Calc() {
    
    delete ui;
}
void Calc::SetSignals() {
    connect(ui->pushButton_open_arch, SIGNAL(clicked()), this, SLOT(pressParenthes()));
    connect(ui->pushButton_close_arch, SIGNAL(clicked()), this, SLOT(pressParenthes()));
    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(pressOperation()));
    connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(pressOperation()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(pressOperation()));

    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(pressFunction()));
    connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(pressFunction()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(pressDigit()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(pressDigit()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(pressDigit()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(pressOperation()));

    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(pressFunction()));
    connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(pressFunction()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(pressDigit()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(pressDigit()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(pressDigit()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(pressOperation()));

    connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(pressFunction()));
    connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(pressFunction()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(pressDigit()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(pressDigit()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(pressDigit()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(pressOperation()));

    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(pressFunction()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(pressFunction()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(pressFunction()));
    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(pressDigit()));
    connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(pressDot()));
    connect(ui->pushButton_X, SIGNAL(clicked()), this, SLOT(buttonX()));
    connect(ui->pushButton_CE, SIGNAL(clicked()), this, SLOT(pressCE()));
    connect(ui->pushButton_backspace, SIGNAL(clicked()), this, SLOT(pressBackspace()));
    connect(ui->push_button_res, SIGNAL(clicked()), this, SLOT(pressRes()));
    connect(ui->g_m, SIGNAL(clicked()), this, SLOT(pressGM()));
    connect(ui->history, SIGNAL(clicked()), this, SLOT(pressHistory()));
}



void Calc::pressDigit() {
    QPushButton *button = (QPushButton *)sender();
    static QRegularExpression regex("([+\\-*\\/^(.]|\\d)$");
    static QRegularExpression regex1("mod$");
    if (!ui->text->toPlainText().size() || ui->text->toPlainText().contains(regex) || ui->text->toPlainText().contains(regex1)) {
        ui->text->setText(ui->text->toPlainText() + button->text());
    }
}
void Calc::buttonX() {
    static QRegularExpression regex("([+\\-*\\/^\\(])$");
    if (!ui->text->toPlainText().size() || ui->text->toPlainText().contains(regex)) {
        ui->text->setText(ui->text->toPlainText() + "x");
        this->existX = 1;
    }
}
void Calc::pressOperation() {
    QPushButton *button = (QPushButton *)sender();
    static QRegularExpression regex("([*\\/^])$");
    static QRegularExpression regex1("([\\)x]|\\d)$");
    static QRegularExpression regex2("(([+\\-*\\/^\\(\\)%])[+\\-])$");
    if (button->text().contains(regex)) {
        if (ui->text->toPlainText().contains(regex1)) {
            ui->text->setText(ui->text->toPlainText() + button->text());
        }
    } else {
        if (!ui->text->toPlainText().contains(regex2) && ui->text->toPlainText().size() != 1) {
            ui->text->setText(ui->text->toPlainText() + button->text());
        } else if (ui->text->toPlainText().contains(regex1)) {
            ui->text->setText(ui->text->toPlainText() + button->text());
        }
    }
}

void Calc::pressFunction() {
    QPushButton *button = (QPushButton *)sender();
    static QRegularExpression regex("([+\\-*\\/^(])$");
    if (!ui->text->toPlainText().size() || ui->text->toPlainText().contains(regex)) {
        ui->text->setText(ui->text->toPlainText() + button->text() + '(');
        this->parenthesis++;
    }
}
void Calc::pressParenthes() {
    QPushButton *button = (QPushButton *)sender();
    if (button->objectName() == "pushButton_open_arch") {
        static QRegularExpression regex("([+\\-*\\/^(])$");
        if (!ui->text->toPlainText().size() || ui->text->toPlainText().contains(regex)) {
            ui->text->setText(ui->text->toPlainText() + button->text());
            this->parenthesis++;
        }
    } else if (this->parenthesis) {
        static QRegularExpression regex("(\\d|[)x])$");
        if (ui->text->toPlainText().contains(regex)) {
            ui->text->setText(ui->text->toPlainText() + button->text());
            this->parenthesis--;
        }
    }
}
void Calc::pressDot() {
    static QRegularExpression regex1("\\d+[.]\\d+$");
    static QRegularExpression regex2("\\d+$");
    if (!ui->text->toPlainText().contains(regex1) &&
        ui->text->toPlainText().contains(regex2)) {
        ui->text->setText(ui->text->toPlainText() + '.');
    }
}


void Calc::pressCE() {
    QPushButton *button = (QPushButton *)sender();
    if (button->objectName() == "pushButton_CE") {
        ui->text->clear();
    }
}


void Calc::pressBackspace() {
    QPushButton *button = (QPushButton *)sender();
    if (button->objectName() == "pushButton_backspace") {
       QString str = ui->text->toPlainText();
       if( str.length() ) {
            str.remove( str.length()-1, 1);
            ui->text->setText(str);
       }
    }
}


void Calc::pressRes() {
    static QRegularExpression regex("(\\d|[\\)x])$");
    if (ui->text->toPlainText().contains(regex) && !this->parenthesis) {
        char str[256] = "";
        strncpy(str, ui->text->toPlainText().toLatin1().data(), ui->text->toPlainText().length());
        emit signal_wright_history(str);
        replace_all(str);
        to_postfix(str);
        emit signal_wright_history(str);
        if (!ui->lineEdit->text().contains("X value")) {
            double x = ui->lineEdit->text().toDouble();
            ui->text->setText(QString::number(calc(str, x), 'g', 7));
        } else {
            ui->text->setText(QString::number(calc(str, 0), 'g', 7));
        }
    }
}

void Calc::pressGM()
{
    g_m->show();
}


void Calc::pressHistory()
{
    his->show();
}

