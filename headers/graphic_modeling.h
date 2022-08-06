#ifndef SRC_HEADERS_GRAPHIC_MODELING_H_
#define SRC_HEADERS_GRAPHIC_MODELING_H_

#include <QWidget>
#include <QVector>
#include "qcustomplot.h"
extern "C" {
#include "parse.h"
#include "polish_notation.h"
}

namespace Ui {
    class graphic_modeling;
}
class graphic_modeling : public QWidget
{
    Q_OBJECT

public:
    explicit graphic_modeling(QWidget *parent = nullptr);
    ~graphic_modeling();

signals:
    void secondWindow();
private slots:
    void Configure(double *xBegin, double *xEnd, double *yBegin, double *yEnd);
    void on_pushButton_clicked();

private:
    Ui::graphic_modeling *ui;
    double x_begin, x_end, y_begin, y_end, h, X;
    int N;
    QVector<double> x, y;
};

#endif // SRC_HEADERS_GRAPHIC_MODELING_H_
