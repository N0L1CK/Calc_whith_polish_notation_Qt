#ifndef SRC_HEADERS_CALC_H_
#define SRC_HEADERS_CALC_H_
#include <QWidget>
#include "graphic_modeling.h"
#include "history.h"
extern "C" {
#include "parse.h"
#include "polish_notation.h"
}

namespace Ui {
    class Calc;
}

class Calc : public QWidget {
    Q_OBJECT

public:
    explicit Calc(QWidget *parent = nullptr);
    ~Calc();

signals:
    void firstWindow();
    void signal_wright_history(QString);
private slots:

    void SetSignals();

    void buttonX();

    void pressDigit();

    void pressOperation();

    void pressFunction();

    void pressParenthes();

    void pressCE();

    void pressRes();

    void pressGM();

    void pressBackspace();

    void pressHistory();

    void pressDot();

private:
    Ui::Calc *ui;
    bool existX;
    bool existY;
    int parenthesis = 0;
    graphic_modeling *g_m;
    history *his;
};



#endif // SRC_HEADERS_CALC_H_
