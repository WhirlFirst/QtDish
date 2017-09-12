#include "uidish.h"
#include "ui_uidish.h"
#include "QString"
#include "logic.h"
#include "QDebug"
using namespace std;
UiDish::UiDish(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UiDish)
{
    ui->setupUi(this);
    ui->pushButton->setText(tr("想吃🤤"));
    ui->cancelButton->setEnabled(false);
}

UiDish::~UiDish()
{
    delete ui;
}

void UiDish::setDish(Dish *dp){
    d=dp;
    number = CurrentTable->searchDish(dp->showName());
    ui->numberlabel->setText(QString::number(number).append("份"));
    if(number!=0) ui->cancelButton->setEnabled(true);
}

void UiDish::on_pushButton_clicked()
{
    CurrentTable->addDish(*d);
    number++;
    ui->numberlabel->setText(QString::number(number).append("份"));
    emit newdish();
    ui->cancelButton->setEnabled(true);
}

void UiDish::setlabel(string n){
    ui->label->setText(QString::fromStdString(n));
}

void UiDish::setprice(int pri){
    ui->costlabel->setText(QString::number(pri).append("元"));
}

void UiDish::setBtnabled(bool p){
    ui->pushButton->setEnabled(p);
}

void UiDish::btninit(){
    ui->pushButton->setEnabled(false);
    ui->costlabel->setText(tr("0元"));
    ui->label->setText("暂无图片");
    ui->cancelButton->setEnabled(false);
}

void UiDish::on_cancelButton_clicked()
{
    CurrentTable->deleteDish(*d);
    number--;
    ui->numberlabel->setText(QString::number(number).append("份"));
    if(number == 0) ui->cancelButton->setEnabled(false);
    emit newdish();
}
