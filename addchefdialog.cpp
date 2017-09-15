#include "addchefdialog.h"
#include "ui_addchefdialog.h"
#include "logic.h"
addchefDialog::addchefDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addchefDialog)
{
    ui->setupUi(this);
}

addchefDialog::~addchefDialog()
{
    delete ui;
}

void addchefDialog::on_pushButton_clicked()
{
    QString uname = ui->userlineEdit->text();
    QString pw = ui->pwdlineEdit->text();
    ww.chefmap.insert(uname,Chef(uname.toStdString(),pw.toStdString()));
    close();
}
