#ifndef SRC_HEADERS_CREDIT_CALC_H_
#define SRC_HEADERS_CREDIT_CALC_H_

#include <QWidget>
#include <math.h>
namespace Ui {
class Credit_calc;
}

class Credit_calc : public QWidget
{
    Q_OBJECT

public:
    explicit Credit_calc(QWidget *parent = nullptr);
    ~Credit_calc();

private slots:
    void on_push_button_clicked();

private:
    Ui::Credit_calc *ui;
};

#endif // CREDIT_CALC_H
