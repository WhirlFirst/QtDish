#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "logic.h"


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
    ww.u.insert(*CurrentUser);
    accept();
}
