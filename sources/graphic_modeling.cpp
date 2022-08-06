#include "graphic_modeling.h"
#include "ui_graphic_modeling.h"

graphic_modeling::graphic_modeling(QWidget *parent)
                                : QWidget(parent),
                                ui(new Ui::graphic_modeling) {
    ui->setupUi(this);


    h = 0.01;
    x_begin = -1000000;
    y_begin = -1000000;
    x_end = 1000000;
    y_end = 1000000;

}
void graphic_modeling::Configure(double *x_begin, double *x_end, double *y_begin, double *y_end) {
    if (ui->Xmin->text() != ui->Xmin->objectName())
        *x_begin = ui->Xmin->text().toDouble();
    if (ui->Xmax->text() != ui->Xmax->objectName())
        *x_end = ui->Xmax->text().toDouble();
    if (ui->Ymin->text() != ui->Ymin->objectName())
        *y_begin = ui->Ymin->text().toDouble();
    if (ui->Ymax->text() != ui->Ymax->objectName())
        *y_end = ui->Ymax->text().toDouble();
}

graphic_modeling::~graphic_modeling() {
    delete ui;
}



void graphic_modeling::on_pushButton_clicked() {
    double res = 0.0;
    char str[256] = "";
    strncpy(str, ui->textEdit->toPlainText().toLatin1().data(), ui->textEdit->toPlainText().length());
    Configure(&x_begin, &x_end, &y_begin, &y_end);
    replace_all(str);
    to_postfix(str);
    ui->widget->xAxis->setRange(x_begin, x_end);
    ui->widget->yAxis->setRange(y_begin, y_end);
    for (X = x_begin; X <= x_end; X += h) {
        if (isfinite(res = calc(str, X))) {
            x.push_back(X);
            y.push_back(res);
        }
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);
    ui->widget->replot();
    ui->widget->setInteraction(QCP::iRangeZoom, true);
    ui->widget->setInteraction(QCP::iRangeDrag, true);
    x.clear();
    y.clear();
    x.squeeze();
    y.squeeze();
}




