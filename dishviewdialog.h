#ifndef DISHVIEWDIALOG_H
#define DISHVIEWDIALOG_H

#include <QDialog>

namespace Ui {
class DishviewDialog;
}

class DishviewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DishviewDialog(QWidget *parent = 0);
    ~DishviewDialog();

private slots:
    void on_freshbtn_clicked();

    void on_exitbtn_clicked();

private:
    Ui::DishviewDialog *ui;
};

#endif // DISHVIEWDIALOG_H
