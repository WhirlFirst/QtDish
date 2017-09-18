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
    string uname = ui->userlineEdit->text().toStdString();
    QString pw = ui->pwdlineEdit->text();
    ww.waitermap.insert(QString::fromStdString(uname),Waiter(uname,pw));
    close();
}
