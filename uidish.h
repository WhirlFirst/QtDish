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
    void setlabel(QString n);
    void setprice(int pri);
    void setDish(Dish* dp);
    void setBtnabled(bool p= false);
    void btninit();
    Dish* d;
signals:
    void newdish();
private slots:
    void on_pushButton_clicked();

    void on_cancelButton_clicked();
    void fresh();
private:
    Ui::UiDish *ui;

    double number;
};

#endif // UIDISH_H
