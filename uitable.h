#ifndef UITABLE_H
#define UITABLE_H

#include <QWidget>
#include "logic.h"
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

private slots:
    void on_pushButton_clicked();
private:
    Ui::Uitable *ui;
    Table* tp;
};

#endif // UITABLE_H
