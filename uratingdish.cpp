#include "uratingdish.h"
#include "ui_uratingdish.h"
#include "QString"

URatingDish::URatingDish(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::URatingDish)
{
    ui->setupUi(this);
    finnumber = 0;
    s=0;
    ui->determinBtn->setEnabled(false);
}

URatingDish::~URatingDish()
{
    delete ui;
}

void URatingDish::setDish(Dish* dp){
    s = dp;
    ui->Dishlabel->setText(QString::fromStdString(dp->showName()));
}

void URatingDish::on_btn1_clicked()
{
    finnumber = 1;
    ui->determinBtn->setEnabled(true);
}

void URatingDish::on_btn2_clicked()
{
    finnumber =2;
    ui->determinBtn->setEnabled(true);
}

void URatingDish::on_btn3_clicked()
{
    finnumber =3;
    ui->determinBtn->setEnabled(true);
}

void URatingDish::on_btn4_clicked()
{
    finnumber =4;
    ui->determinBtn->setEnabled(true);
}

void URatingDish::on_btn5_clicked()
{
    finnumber =5;
    ui->determinBtn->setEnabled(true);
}

void URatingDish::on_determinBtn_clicked()
{
    int p =0;
    p=s->Evaluation(finnumber);
    ui->btn1->deleteLater();
    ui->btn2->deleteLater();
    ui->btn3->deleteLater();
    ui->btn4->deleteLater();
    ui->btn5->deleteLater();
    ui->determinBtn->setText(tr("当前平均得分：").append(QString::number(p)));
    ui->determinBtn->setEnabled(false);
}
