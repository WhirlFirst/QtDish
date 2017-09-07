#include "logindialog.h"
#include "ui_logindialog.h"
#include "registerdialog.h"
#include "showdialog.h"
#include "mainwindow.h"
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
    accept();
}
