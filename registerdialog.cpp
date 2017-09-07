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
    User p(ui->userlineEdit->text().toStdString(),ui->phonelineEdit->text().toStdString(),ui->pwdlineEdit->text().toStdString());
    ww.u.insert(p);
    CurrentUser = p;
    accept();
}
