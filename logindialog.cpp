#include "logindialog.h"
#include "ui_logindialog.h"
#include "registerdialog.h"
#include "showdialog.h"
#include "logic.h"
#include "QMessageBox"
using namespace std;
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this); 
}

LoginDialog::~LoginDialog()
{
    delete ui;

}

void LoginDialog::on_commandLinkBtn_clicked()
{
    RegisterDialog r;
    hide();
    if(r.exec()==QDialog::Accepted){
        ShowDialog s;
        if(s.exec()==QDialog::Accepted){
            accept();
        }
    }
}


void LoginDialog::on_loginBtn_clicked()
{
    string name = ui->usrLineEdit->text().toStdString();
    string pwd = ui->pwdLineEdit->text().toStdString();
    ww.u.reset();
    int k=0;
    for(int i =0;i<ww.u.size();i++){
        User* tem = ww.u.showSingle();
        if(tem->showName() == name&&tem->checkpwd() == pwd){
            CurrentUser = tem;
           k++;
        }
    }

    if(k>0) {
       accept();
    }
    else{
        QMessageBox::warning(this, tr("警告！"),tr("用户名或密码错误！"),QMessageBox::Yes);
        ui->usrLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->usrLineEdit->setFocus();
    }

}
