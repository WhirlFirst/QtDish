#include "uitable.h"
#include "ui_uitable.h"
#include "logic.h"
#include "QString"
#include "QMessageBox"
#include "mainwindow.h"
Uitable::Uitable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Uitable)
{
    ui->setupUi(this);
}

Uitable::~Uitable()
{
    delete ui;
}
void Uitable::settable(Table* temp){
    tp = temp;
}

void Uitable::settext(string ss){
    ui->pushButton->setText(QString::fromStdString(ss));
}

void Uitable::disable(){
    ui->pushButton->setStyleSheet("background-color:grey");
    ui->pushButton->setEnabled(false);
}

void Uitable::on_pushButton_clicked()
{
    tp->StartWorking(CurrentUser);
    QMessageBox::information(this, tr("选桌成功！"),tr("点击选菜继续！"),QMessageBox::Yes);
    emit select();
    CurrentTable = tp;
}

