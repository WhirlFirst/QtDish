#include "superuserdialog.h"
#include "ui_superuserdialog.h"
#include "logic.h"
#include <QTableWidget>
#include <QStringList>
#include <QTableWidgetItem>
#include <QString>
#include <QDebug>
#include "QGridLayout"
#include "adddishdialog.h"
#include <QMessageBox>
#include "adduserdialog.h"
SuperUserDialog::SuperUserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SuperUserDialog)
{
    ui->setupUi(this);
    connect(ui->menuButton,SIGNAL(clicked(bool)),this,SLOT(menushow()));
    st = 0;
}

SuperUserDialog::~SuperUserDialog()
{
    delete ui;
}


void SuperUserDialog::menushow(){
    QStringList headers;
    QTableWidget* s = ui->tableWidget;
    s->clear();
    s->setColumnCount(3);
    s->setRowCount(ww.menu.size());
    headers << "菜名" << "价格"<<"评分";
    s->setHorizontalHeaderLabels(headers);
    s->setEditTriggers(QAbstractItemView::NoEditTriggers);
    s->setSelectionBehavior(QAbstractItemView::SelectRows);
    s->setShowGrid(true);
    s->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    s->resizeRowsToContents();
    ww.menu.reset();
    for(int i=0;i<ww.menu.size();i++){
        Dish* p =ww.menu.showSingle();
        s->setItem(i,0,new QTableWidgetItem(QString::fromStdString(p->showName())));
        s->setItem(i,1,new QTableWidgetItem(QString::number(p->showPrice())));
        s->setItem(i,2,new QTableWidgetItem(QString::number(p->showScore())));
    }
    s->show();
    st=1;
}

void SuperUserDialog::fresh(){
    QTableWidget* s = ui->tableWidget;
    s->setRowCount(ww.menu.size());
    ww.menu.reset();
    for(int i=0;i<ww.menu.size();i++){
        Dish* p =ww.menu.showSingle();
        s->setItem(i,0,new QTableWidgetItem(QString::fromStdString(p->showName())));
        s->setItem(i,1,new QTableWidgetItem(QString::number(p->showPrice())));
        s->setItem(i,2,new QTableWidgetItem(QString::number(p->showScore())));
    }
    s->show();
}


void SuperUserDialog::on_addBtn_clicked()
{
    if(st==1){
        addDishDialog a;
        a.exec();
        fresh();
    }
    else if(st==2){
       addUserDialog b;
       b.exec();
       QTableWidget* s = ui->tableWidget;
       s->setRowCount(ww.u.size());
       ww.u.reset();
       for(int i=0;i<ww.u.size();i++){
           User* p =ww.u.showSingle();
           s->setItem(i,0,new QTableWidgetItem(QString::fromStdString(p->checknumber())));
           s->setItem(i,1,new QTableWidgetItem(QString::fromStdString(p->showName())));
           s->setItem(i,2,new QTableWidgetItem(QString::fromStdString(p->checkpwd())));
       }
       s->show();
    }

}

void SuperUserDialog::on_deletebtn_clicked()
{
    QTableWidget* s = ui->tableWidget;
    int row1 =-1;
    row1 = s->currentRow();
    if(st==1&&row1>=0){
        ww.menu.reset(row1);
        ww.menu.deletecurrent();
        s->removeRow(row1);
    }
    if(st==2&&row1>=0){
        ww.u.reset(row1);
        ww.u.deletecurrent();
        s->removeRow(row1);
    }

}

void SuperUserDialog::on_pushButton_clicked()
{
    QTableWidget* s = ui->tableWidget;
    string e = ui->Searchline->text().toStdString();
    int w=0;
    int y=0;
    if(st ==1){
        ww.menu.reset();
        for(int i=0;i<ww.menu.size();i++){
            Dish* p =ww.menu.showSingle();
            if(p->showName() == e) {
                w=ww.menu.currentposition()-1;
                y=1;
                break;
            }
        }
    }
    else if(st ==2){
        ww.u.reset();
        for(int i=0;i<ww.u.size();i++){
            User* p =ww.u.showSingle();
            if(p->checknumber() == e) {
                w=ww.u.currentposition()-1;
                y=1;
                break;
            }
        }
    }
    if(y==1) {
        ui->Searchline->clear();
        s->selectRow(w);
    }
    else {
        QMessageBox::warning(this, tr("抱歉"),tr("没有搜索到，请重新输入"),QMessageBox::Yes);
        ui->Searchline->clear();
        ui->Searchline->setFocus();
    }
}

void SuperUserDialog::on_userbtn_clicked()
{
    ui->Searchline->setPlaceholderText(tr("请输入手机号"));
    QStringList headers;
    QTableWidget* s = ui->tableWidget;
    s->clear();
    s->setColumnCount(3);
    s->setRowCount(ww.u.size());
    headers << "手机号" << "用户名"<<"密码";
    s->setHorizontalHeaderLabels(headers);
    s->setEditTriggers(QAbstractItemView::NoEditTriggers);
    s->setSelectionBehavior(QAbstractItemView::SelectRows);
    s->setShowGrid(true);
    s->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    s->resizeRowsToContents();
    ww.u.reset();
    for(int i=0;i<ww.u.size();i++){
        User* p =ww.u.showSingle();
        s->setItem(i,0,new QTableWidgetItem(QString::fromStdString(p->checknumber())));
        s->setItem(i,1,new QTableWidgetItem(QString::fromStdString(p->showName())));
        s->setItem(i,2,new QTableWidgetItem(QString::fromStdString(p->checkpwd())));
    }
    s->show();
    st=2;
}