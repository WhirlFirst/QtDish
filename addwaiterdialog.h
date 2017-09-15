#ifndef ADDWAITERDIALOG_H
#define ADDWAITERDIALOG_H

#include <QDialog>

namespace Ui {
class addwaiterDialog;
}

class addwaiterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addwaiterDialog(QWidget *parent = 0);
    ~addwaiterDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::addwaiterDialog *ui;
};

#endif // ADDWAITERDIALOG_H
