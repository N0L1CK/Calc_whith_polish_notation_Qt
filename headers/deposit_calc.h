#ifndef SRC_HEADERS_DEPOSIT_CALC_H_
#define SRC_HEADERS_DEPOSIT_CALC_H_

#include <QWidget>

namespace Ui {
class Deposit_calc;
}

class Deposit_calc : public QWidget
{
    Q_OBJECT

public:
    explicit Deposit_calc(QWidget *parent = nullptr);
    ~Deposit_calc();

private slots:


    void on_result_clicked();
    int check_date();

private:
    Ui::Deposit_calc *ui;
};

#endif // SRC_HEADERS_DEPOSIT_CALC_H_
