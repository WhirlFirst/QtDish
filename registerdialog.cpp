#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "logic.h"
#include "QMessageBox"

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_RegisterBtn_clicked()
{
   User* t =  new User(ui->userlineEdit->text(),ui->phonelineEdit->text(),ui->pwdlineEdit->text());
    CurrentUser = t;
    ww.u.reset();
    int y=0;
    for(int i=0;i<ww.u.size();i++){
        User * p = ww.u.showSingle();
        if(p->checknumber()==CurrentUser->checknumber()) y++;
    }
    if(y>0) {
        QMessageBox::warning(this, tr("错误！"),tr("您已经注册过！"),QMessageBox::Yes);
        exit(0);
    }
    else{
        ww.u.insert(*CurrentUser);
        accept();
    }
}
