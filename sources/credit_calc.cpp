#include "credit_calc.h"
#include "ui_credit_calc.h"
#include <stdlib.h>

Credit_calc::Credit_calc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Credit_calc) {
    ui->setupUi(this);
}

Credit_calc::~Credit_calc() {
    delete ui;
}

void Credit_calc::on_push_button_clicked() {
    double sum = ui->credit_val->text().toDouble();
    double procent = ui->credit_procent->text().toDouble()/ 100.0 / 12;
    double count = ui->credit_count->text().toDouble();
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
    if (ui->radio_an->isChecked()) {
        x = sum * (procent + (procent / (pow(1.0 + procent, count) - 1.0)));
        y = x * count;
        z = y - sum;
        ui->label->setText("Ежемесячный платеж: " + QString::number(x, 'f', 2)+'\n');
        ui->label->setText(ui->label->text()+ "Переплата по кредиту: " + QString::number(z, 'f', 2)+'\n');
        ui->label->setText(ui->label->text()+ "Общая сумма выплат: " + QString::number(y, 'f', 2));

    } else if (ui->radio_dif->isChecked()) {
        x = sum / count;
        for (int i = 0; i < count; ++i) {
            y += x + (sum - x * i) * procent;
        }
        ui->label->setText("Ежемесячный платеж: " + QString::number(y/count, 'f', 2)+'\n');
        ui->label->setText(ui->label->text()+ "Переплата по кредиту: " + QString::number(y - sum, 'f', 2)+'\n');
        ui->label->setText(ui->label->text()+ "Общая сумма выплат: " + QString::number(y, 'f', 2));
    }
}

