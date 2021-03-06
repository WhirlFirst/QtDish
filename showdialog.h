#ifndef SHOWDIALOG_H
#define SHOWDIALOG_H

#include <QDialog>

namespace Ui {
class ShowDialog;
}

class ShowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowDialog(QWidget *parent = 0);
    ~ShowDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ShowDialog *ui;
};


#endif // SHOWDIALOG_H
