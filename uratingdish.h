#ifndef URATINGDISH_H
#define URATINGDISH_H

#include <QWidget>
#include "logic.h"
namespace Ui {
class URatingDish;
}

class URatingDish : public QWidget
{
    Q_OBJECT

public:
    explicit URatingDish(QWidget *parent = 0);
    ~URatingDish();
    void setDish(Dish *dp);
    Dish* s;
private slots:
    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_btn3_clicked();

    void on_btn4_clicked();

    void on_btn5_clicked();

    void on_determinBtn_clicked();


private:
    Ui::URatingDish *ui;
    int finnumber;
};

#endif // URATINGDISH_H
