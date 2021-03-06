#ifndef WAITDIALOG_H
#define WAITDIALOG_H

#include <QDialog>
#include <uratingdish.h>
namespace Ui {
class WaitDialog;
}

class WaitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WaitDialog(QWidget *parent = 0);
    ~WaitDialog();
    void fresh();
private slots:
    void on_exitbtn_clicked();
    void on_Dishviewbtn_clicked();

    void on_servicebtn_clicked();

    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_btn3_clicked();

    void on_btn4_clicked();

    void on_btn5_clicked();

private:
    Ui::WaitDialog *ui;
    URatingDish* urdish[8];
};

#endif // WAITDIALOG_H
