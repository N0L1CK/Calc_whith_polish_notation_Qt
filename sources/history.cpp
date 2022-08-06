#include "history.h"
#include "ui_history.h"

history::history(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::history)
{
    ui->setupUi(this);
}

history::~history()
{
    delete ui;
}

void history::slot(QString str)
{
    ui->lable->append(str);

}
