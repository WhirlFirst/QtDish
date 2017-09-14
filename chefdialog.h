#ifndef CHEFDIALOG_H
#define CHEFDIALOG_H

#include <QDialog>

namespace Ui {
class chefDialog;
}

class chefDialog : public QDialog
{
    Q_OBJECT

public:
    explicit chefDialog(QWidget *parent = 0);
    ~chefDialog();
    void fresh();
private slots:
    void on_startbtn_clicked();

    void on_finishbtn_clicked();

private:
    Ui::chefDialog *ui;
};

#endif // CHEFDIALOG_H
