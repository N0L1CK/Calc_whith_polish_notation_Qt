#ifndef SRC_HEADERS_HISTORY_H_
#define SRC_HEADERS_HISTORY_H_

#include <QWidget>

namespace Ui {
class history;
}

class history : public QWidget
{
    Q_OBJECT

public:
    explicit history(QWidget *parent = nullptr);
    ~history();

private:
    Ui::history *ui;

public slots:
    void slot(QString str);
};

#endif // SRC_HEADERS_HISTORY_H_
