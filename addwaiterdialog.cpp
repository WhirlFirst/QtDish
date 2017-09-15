#include "addwaiterdialog.h"
#include "ui_addwaiterdialog.h"
#include "logic.h"
addwaiterDialog::addwaiterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addwaiterDialog)
{
    ui->setupUi(this);
}

addwaiterDialog::~addwaiterDialog()
{
    delete ui;
}

void addwaiterDialog::on_pushButton_clicked()
{
    QString uname = ui->userlineEdit->text();
    QString pw = ui->pwdlineEdit->text();
    ww.waitermap.insert(uname,Waiter(uname.toStdString(),pw.toStdString()));
    close();
}
