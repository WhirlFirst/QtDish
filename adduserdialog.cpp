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
    QString number = ui->phonelineEdit->text();
    QString uname = ui->userlineEdit->text();
    QString pw = ui->pwdlineEdit->text();
    ww.u.insert(User(uname,number,pw));
    close();
}
