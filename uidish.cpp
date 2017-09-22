#include "uidish.h"
#include "ui_uidish.h"
#include "QString"
#include "logic.h"
using namespace std;
UiDish::UiDish(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UiDish)
{
    ui->setupUi(this);
    ui->pushButton->setText(tr("想吃🤤"));
    ui->cancelButton->setEnabled(false);
    d = 0;
    connect(this,SIGNAL(newdish()),this,SLOT(fresh()));
}

UiDish::~UiDish()
{
    delete ui;
}

void UiDish::fresh(){
    ui->numberlabel->setText(tr("0"));
    ui->numberlabel->setText(QString::number(number));
}

void UiDish::setDish(Dish *dp){
    d=dp;
    number = 0;
    ui->numberlabel->setText(QString::number(number));
    ui->ratinglabel->setText(QString::number(dp->showScore(),'f',1).append("分"));
    if(number!=0) ui->cancelButton->setEnabled(true);
}

void UiDish::on_pushButton_clicked()
{
    CurrentTable->addDish(*d);
    number++;
    emit newdish();
    ui->cancelButton->setEnabled(true);
}

void UiDish::setlabel(QString n){
    ui->label->setText(n);
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
    d = 0;
}

void UiDish::on_cancelButton_clicked()
{
    CurrentTable->deleteDish(*d);
    number--;
    if(number == 0) ui->cancelButton->setEnabled(false);
    emit newdish();
}
