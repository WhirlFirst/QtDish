#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <signal.h>
namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
signals:
        void judge(int x);
private slots:
    void on_commandLinkBtn_clicked();

    void on_loginBtn_clicked();


private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
