#include "adduserdialog.h"
#include "ui_adduserdialog.h"
#include "logic.h"
addUserDialog::addUserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addUserDialog)
{
    ui->setupUi(this);
}

addUserDialog::~addUserDialog()
{
    delete ui;
}

void addUserDialog::on_pushButton_clicked()
{
    string number = ui->phonelineEdit->text().toStdString();
    string uname = ui->userlineEdit->text().toStdString();
    string pw = ui->pwdlineEdit->text().toStdString();
    ww.u.insert(User(uname,number,pw));
    close();
}
