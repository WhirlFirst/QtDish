#ifndef UIDISH_H
#define UIDISH_H

#include <QWidget>
#include <logic.h>
#include <signal.h>
using namespace std;
namespace Ui {
class UiDish;
}

class UiDish : public QWidget
{
    Q_OBJECT

public:
    explicit UiDish(QWidget *parent = 0);
    ~UiDish();
    void setlabel(string n);
    void setprice(int pri);
    void setDish(Dish* dp);
    void setBtnabled(bool p= false);
    void btninit();
signals:
    void newdish();
private slots:
    void on_pushButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::UiDish *ui;
    Dish* d;
    int number;
};

#endif // UIDISH_H
