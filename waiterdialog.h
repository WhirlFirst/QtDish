#ifndef WAITERDIALOG_H
#define WAITERDIALOG_H

#include <QDialog>
#include <uitable.h>
namespace Ui {
class waiterDialog;
}

class waiterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit waiterDialog(QWidget *parent = 0);
    ~waiterDialog();
    void showui();
public slots:
    void tablefresh();
private:
    Ui::waiterDialog *ui;
    Uitable *utable[30];
};

#endif // WAITERDIALOG_H
