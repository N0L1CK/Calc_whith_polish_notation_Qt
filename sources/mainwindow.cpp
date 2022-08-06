#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Window = new Calc();
    Window1 = new Credit_calc();
    Window2 = new Deposit_calc();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_push_button_calculator_clicked()
{
    if (Window) {
        delete Window;
        Window = new Calc();
    }
    Window->show();

}


void MainWindow::on_push_button_credit_clicked()
{
    if (Window1) {
        delete Window1;
        Window1 = new Credit_calc();
    }
    Window1->show();

}


void MainWindow::on_push_button_deposit_clicked()
{
    if (Window2) {
        delete Window2;
        Window2 = new Deposit_calc();
    }
    Window2->show();

}




