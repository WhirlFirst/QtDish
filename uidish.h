#ifndef UIDISH_H
#define UIDISH_H

#include <QWidget>
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
    void setBtntext(string s);
private slots:
    void on_pushButton_clicked();

private:
    Ui::UiDish *ui;
};

#endif // UIDISH_H
