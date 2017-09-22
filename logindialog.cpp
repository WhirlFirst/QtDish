#include "logindialog.h"
#include "ui_logindialog.h"
#include "registerdialog.h"
#include "showdialog.h"
#include "logic.h"
#include "QMessageBox"
#include "superuserdialog.h"
#include "mainwindow.h"
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
            done(1);
        }
    }
}


void LoginDialog::on_loginBtn_clicked()
{
    QString name = ui->usrLineEdit->text();
    QString pwd = ui->pwdLineEdit->text();
    ww.u.reset();
    int k=0;
    if(name == "whirl"&&pwd == "1"){
        done(2);
    }
    else if(name == "manager"&&pwd =="1"){
        done(5);
    }
    else{
        for(int i =0;i<ww.u.size();i++){
            User* tem = ww.u.showSingle();
            if(tem->showName() == name&&tem->checkpwd() == pwd){
                CurrentUser = tem;
               k++;
               done(1);
            }
        }
        ChefMap::iterator it;
        for(it = ww.chefmap.begin();it!= ww.chefmap.end();it++){
            if(it.value().showname() == name&&it.value().showpwd() == pwd){
                CurrentChef = &(it.value());
                k++;
                done(3);
            }
        }
        WaiterMap::iterator ie;
        for(ie = ww.waitermap.begin();ie!= ww.waitermap.end();ie++){
            if(QString::fromStdString(ie.value().showName()) == name&&ie.value().showPwd() == pwd){
                CurrentWaiter = &(ie.value());
                k++;
                done(4);
            }
        }
        if(k<=0){
            QMessageBox::warning(this, tr("警告！"),tr("用户名或密码错误！"),QMessageBox::Yes);
            ui->usrLineEdit->clear();
            ui->pwdLineEdit->clear();
            ui->usrLineEdit->setFocus();
        }
    }
}

void LoginDialog::on_exitBtn_clicked()
{
   exit(0);
}
