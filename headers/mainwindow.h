#ifndef SRC_HEADERS_MAINWINDOW_H_
#define SRC_HEADERS_MAINWINDOW_H_

#include <QMainWindow>
#include "calc.h"
#include "credit_calc.h"
#include "deposit_calc.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_push_button_calculator_clicked();

    void on_push_button_credit_clicked();

    void on_push_button_deposit_clicked();

private:
    Ui::MainWindow *ui;
    Calc *Window;
    Credit_calc *Window1;
    Deposit_calc *Window2;
};
#endif // SRC_HEADERS_MAINWINDOW_H_
