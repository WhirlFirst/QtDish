#ifndef SUPERUSERDIALOG_H
#define SUPERUSERDIALOG_H

#include <QDialog>

namespace Ui {
class SuperUserDialog;
}

class SuperUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SuperUserDialog(QWidget *parent = 0);
    ~SuperUserDialog();
    void fresh();
    ;
private slots:
    void menushow();

    void on_addBtn_clicked();

    void on_deletebtn_clicked();

    void on_pushButton_clicked();

    void on_userbtn_clicked();

    void on_chiefbtn_clicked();

    void on_waiterbtn_clicked();

    void on_deletebtn_2_clicked();

private:
    Ui::SuperUserDialog *ui;
    int st;
};

#endif // SUPERUSERDIALOG_H
