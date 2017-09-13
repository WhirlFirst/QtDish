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

private slots:

    void on_menubtn_clicked();

    void on_menuButton_clicked();

private:
    Ui::SuperUserDialog *ui;
};

#endif // SUPERUSERDIALOG_H
