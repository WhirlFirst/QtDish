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

private:
    Ui::chefDialog *ui;
};

#endif // CHEFDIALOG_H
