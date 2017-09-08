#ifndef UIDISH_H
#define UIDISH_H

#include <QWidget>
#include <logic.h>
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
private slots:
    void on_pushButton_clicked();

private:
    Ui::UiDish *ui;
    Dish* d;
};

#endif // UIDISH_H
