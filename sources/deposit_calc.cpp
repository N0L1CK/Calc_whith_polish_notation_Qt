#include "deposit_calc.h"
#include "ui_deposit_calc.h"

Deposit_calc::Deposit_calc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Deposit_calc)
{
    ui->setupUi(this);
    ui->combo_box_add->addItem(QString("единоразово"), 1);
    ui->combo_box_add->addItem(QString("ежемесячно"), 2);
    ui->combo_box_add->addItem(QString("ежеквартально"), 3);
    ui->combo_box_add->addItem(QString("ежегодно"), 4);
    ui->combo_box_out->addItem(QString("единоразово"), 1);
    ui->combo_box_out->addItem(QString("ежемесячно"), 2);
    ui->combo_box_out->addItem(QString("ежеквартально"), 3);
    ui->combo_box_out->addItem(QString("ежегодно"), 4);
}

Deposit_calc::~Deposit_calc()
{
    delete ui;
}




void Deposit_calc::on_result_clicked() {
    double sum = ui->sum->text().toDouble();
    double count = ui->count->text().toDouble();
    double add = ui->add->text().toDouble();
    double out = ui->out->text().toDouble();
    double prcent_dep = ui->procent_dep->text().toDouble()/ 100.0 / 12;
    double prcent_tax = ui->tax_procent->text().toDouble()/ 100.0 / 12;
    int add_count = ui->combo_box_add->currentIndex();
    int out_count = ui->combo_box_out->currentIndex();
    double res = sum;
    double res_tax = 0.0;
    double res_prcent = 0.0;
    if (check_date()) {
        for (int i = 0; i < count; ++i) {
            switch(add_count) {
                case 0: if (i == 1) res += add; break;
                case 1: res += add; break;
                case 2: if (i % 4 == 0) res += add; break;
                case 3: if (i % 12 == 0) res += add; break;
                default: break;
            }
            switch(out_count) {
                case 0: if (i == 1) res -= out; break;
                case 1: if (res-out > 0) res -= out; break;
                case 2: if (i % 4 == 0) res -= out; break;
                case 3: if (i % 12 == 0) res -= out; break;
                default: break;
            }
            res_prcent += res * prcent_dep;
            res_tax += res * prcent_dep * prcent_tax;
            res += res * prcent_dep - res_prcent * prcent_tax;
        }
        ui->res->setText("Сумма процентов: " + QString::number(res_prcent, 'f', 2) + '\n');
        ui->res->setText(ui->res->text() + "Общая сумма: " + QString::number(res, 'f', 2) + '\n');
        ui->res->setText(ui->res->text() + "Cумма налога: " + QString::number(res_tax, 'f', 2));
    }
}

int Deposit_calc::check_date() {
    int res = 0;
    if (ui->sum->text().toDouble() >= 0 && ui->count->text().toDouble() >= 0
            && ui->add->text().toDouble() >= 0 && ui->out->text().toDouble() >= 0
            && ui->procent_dep->text().toDouble() >= 0 && ui->tax_procent->text().toDouble() >= 0)
        res = 1;
    return res;
}
