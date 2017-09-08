#ifndef UITABLE_H
#define UITABLE_H

#include <QWidget>
#include "logic.h"
#include "signal.h"
namespace Ui {
class Uitable;
}

class Uitable : public QWidget
{
    Q_OBJECT

public:
    explicit Uitable(QWidget *parent = 0);
    ~Uitable();
    void settable(Table* temp);
    void settext(string ss);
    void disable();
    Table* tp;
signals:
    void select();
private slots:
    void on_pushButton_clicked();
private:
    Ui::Uitable *ui;
};

#endif // UITABLE_H
