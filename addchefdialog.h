#ifndef ADDCHEFDIALOG_H
#define ADDCHEFDIALOG_H

#include <QDialog>

namespace Ui {
class addchefDialog;
}

class addchefDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addchefDialog(QWidget *parent = 0);
    ~addchefDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addchefDialog *ui;
};

#endif // ADDCHEFDIALOG_H
