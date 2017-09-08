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
}

UiDish::~UiDish()
{
    delete ui;
}

void UiDish::setDish(Dish *dp){
    d=dp;
}

void UiDish::on_pushButton_clicked()
{
    qDebug()<<QString::fromStdString(CurrentTable->showNumber())<<endl;
    CurrentTable->addDish(*d);
    emit addnewdish();
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
}
