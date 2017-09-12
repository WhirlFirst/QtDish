#ifndef WAITDIALOG_H
#define WAITDIALOG_H

#include <QDialog>

namespace Ui {
class WaitDialog;
}

class WaitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WaitDialog(QWidget *parent = 0);
    ~WaitDialog();

private slots:
    void on_exitbtn_clicked();

private:
    Ui::WaitDialog *ui;
};

#endif // WAITDIALOG_H
