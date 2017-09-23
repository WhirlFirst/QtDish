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
#include "addchefdialog.h"
#include "addwaiterdialog.h"
#include <QSqlQuery>
#include "connection.h"
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
    QSqlQuery query;
    ww.u.reset();
    query.exec("DELETE FROM user");
    for(int i=0;i<ww.u.size();i++){
        User* s = ww.u.showSingle();
        query.prepare("insert into user (name,number,password)""values(?,?,?)");
        query.addBindValue(s->showName());
        query.addBindValue(s->checknumber());
        query.addBindValue(s->checkpwd());
        query.exec();
    }
    ww.menu.reset();
    query.exec("delete from dish");
    for(int i=0;i<ww.menu.size();i++){
        Dish* o = ww.menu.showSingle();
        query.prepare("insert into dish (name,price,status,number,score)""values(?,?,?,?,?)");
        query.addBindValue(o->showName());
        query.addBindValue(QString::number(o->showPrice()));
        query.addBindValue(o->showStatus());
        query.addBindValue(QString::number(-1));
        query.addBindValue(QString::number(o->showScore()));
        query.exec();
    }
    query.exec("delete from chef");
    ChefMap::iterator it;
    for(it = ww.chefmap.begin();it!= ww.chefmap.end();it++){
        query.prepare("insert into chef (name,pwd,averagetime,averagescore,dishnumber)""values(?,?,?,?,?)");
        query.addBindValue(it.value().showname());
        query.addBindValue(it.value().showpwd());
        query.addBindValue(QString::number(it.value().showtime()));
        query.addBindValue(QString::number(it.value().showscore()));
        query.addBindValue(QString::number(it.value().showdishnumber()));
        query.exec();
    }
    WaiterMap::iterator ie;
    query.exec("delete from waiter");
    for(ie = ww.waitermap.begin();ie!= ww.waitermap.end();ie++){
        query.prepare("insert into waiter(name,pwd,score,acount)""values(?,?,?,?)");
        query.addBindValue(QString::fromStdString(ie.value().showName()));
        query.addBindValue(ie.value().showPwd());
        query.addBindValue(QString::number(ie.value().showscore()));
        query.addBindValue(QString::number(ie.value().acount));
        query.exec();
    }
    delete ui;
}


void SuperUserDialog::menushow(){
     ui->deletebtn_2->show();
    ui->Searchline->setPlaceholderText(tr("请输入菜名"));
    QStringList headers;
    QTableWidget* s = ui->tableWidget;
    s->clear();
    s->setColumnCount(3);
    s->setRowCount(ww.menu.size());
    headers << "菜名" << "价格"<<"评分";
    s->setHorizontalHeaderLabels(headers);
    //s->setEditTriggers(QAbstractItemView::NoEditTriggers);
    s->setSelectionBehavior(QAbstractItemView::SelectRows);
    s->setShowGrid(true);
    s->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    s->resizeRowsToContents();
    ww.menu.reset();
    for(int i=0;i<ww.menu.size();i++){
        Dish* p =ww.menu.showSingle();
        s->setItem(i,0,new QTableWidgetItem(p->showName()));
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
        s->setItem(i,0,new QTableWidgetItem(p->showName()));
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
           s->setItem(i,0,new QTableWidgetItem(p->checknumber()));
           s->setItem(i,1,new QTableWidgetItem(p->showName()));
           s->setItem(i,2,new QTableWidgetItem(p->checkpwd()));
       }
       s->show();
    }
    else if(st==3){
        addchefDialog as;
        as.exec();
        QTableWidget* s = ui->tableWidget;
        s->setRowCount(ww.chefmap.size());
        ChefMap::iterator it;
        int i=0;
        for(it = ww.chefmap.begin();it!= ww.chefmap.end();it++){
            s->setItem(i,0,new QTableWidgetItem(it.value().showname()));
            s->setItem(i,1,new QTableWidgetItem(it.value().showpwd()));
            i++;
        }
        s->show();
    }
    else if(st==4){
        addwaiterDialog as;
        as.exec();
        QTableWidget* s = ui->tableWidget;
        s->setRowCount(ww.waitermap.size());
        WaiterMap::iterator it;
        int i=0;
        for(it = ww.waitermap.begin();it!= ww.waitermap.end();it++){
            s->setItem(i,0,new QTableWidgetItem(QString::fromStdString(it.value().showName())));
            s->setItem(i,1,new QTableWidgetItem(it.value().showPwd()));
            i++;
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
    else if(st==2&&row1>=0){
        ww.u.reset(row1);
        ww.u.deletecurrent();
        s->removeRow(row1);
    }
    else if(st==3&&row1>=0){
        QString sd = s->item(row1,0)->text();
        ww.chefmap.remove(sd);
        s->removeRow(row1);
    }
    else if(st==4&&row1>=0){
        QString sd = s->item(row1,0)->text();
        ww.waitermap.remove(sd);
        s->removeRow(row1);
    }

}

void SuperUserDialog::on_pushButton_clicked()
{
    QTableWidget* s = ui->tableWidget;
    string e = ui->Searchline->text().toStdString();
    int w=0;
    int y=0;

    for(int i=0;i<s->rowCount();i++){
        if(s->item(i,0)->text()==ui->Searchline->text()){
            w=i;
            y=1;
            break;
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
    ui->deletebtn_2->show();
    ui->Searchline->setPlaceholderText(tr("请输入手机号"));
    QStringList headers;
    QTableWidget* s = ui->tableWidget;
    s->clear();
    s->setColumnCount(3);
    s->setRowCount(ww.u.size());
    headers << "手机号" << "用户名"<<"密码";
    s->setHorizontalHeaderLabels(headers);
    //s->setEditTriggers(QAbstractItemView::NoEditTriggers);
    s->setSelectionBehavior(QAbstractItemView::SelectRows);
    s->setShowGrid(true);
    s->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    s->resizeRowsToContents();
    ww.u.reset();
    for(int i=0;i<ww.u.size();i++){
        User* p =ww.u.showSingle();
        s->setItem(i,0,new QTableWidgetItem(p->checknumber()));
        s->setItem(i,1,new QTableWidgetItem(p->showName()));
        s->setItem(i,2,new QTableWidgetItem(p->checkpwd()));
    }
    s->show();
    st=2;
}

void SuperUserDialog::on_chiefbtn_clicked()
{
    ui->deletebtn_2->hide();
    ui->Searchline->setPlaceholderText(tr("请输入厨师姓名"));
    QStringList headers;
    QTableWidget* s = ui->tableWidget;
    s->clear();
    s->setColumnCount(2);
    s->setRowCount(ww.chefmap.size());
    headers <<"厨师姓名"<<"密码";
    s->setHorizontalHeaderLabels(headers);
    s->setEditTriggers(QAbstractItemView::NoEditTriggers);
    s->setSelectionBehavior(QAbstractItemView::SelectRows);
    s->setShowGrid(true);
    s->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    s->resizeRowsToContents();
    ChefMap::iterator it;
    int i=0;
    for(it = ww.chefmap.begin();it!= ww.chefmap.end();it++){
        s->setItem(i,0,new QTableWidgetItem(it.value().showname()));
        s->setItem(i,1,new QTableWidgetItem(it.value().showpwd()));
        i++;
    }
    s->show();
    st=3;
}

void SuperUserDialog::on_waiterbtn_clicked()
{
    ui->deletebtn_2->hide();
    ui->Searchline->setPlaceholderText(tr("请输入服务员姓名"));
    QStringList headers;
    QTableWidget* s = ui->tableWidget;
    s->clear();
    s->setColumnCount(2);
    s->setRowCount(ww.waitermap.size());
    headers <<"服务员姓名"<<"密码";
    s->setHorizontalHeaderLabels(headers);
    s->setEditTriggers(QAbstractItemView::NoEditTriggers);
    s->setSelectionBehavior(QAbstractItemView::SelectRows);
    s->setShowGrid(true);
    s->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    s->resizeRowsToContents();
    WaiterMap::iterator it;
    int i=0;
    for(it = ww.waitermap.begin();it!= ww.waitermap.end();it++){
        s->setItem(i,0,new QTableWidgetItem(QString::fromStdString(it.value().showName())));
        s->setItem(i,1,new QTableWidgetItem(it.value().showPwd()));
        i++;
    }
    s->show();
    st=4;
}

void SuperUserDialog::on_deletebtn_2_clicked()
{

    QTableWidget* s = ui->tableWidget;
    int u = s->rowCount();
    if(st==1){
        ww.menu.clear();
        for(int i=0;i<u;i++){
           QString name= s->item(i,0)->text();
            QString price = s->item(i,1)->text();
           QString score = s->item(i,2)->text();
           ww.menu.insert(Dish(price.toInt(),name,score.toFloat()));
        }
    }
    else if(st==2){
        ww.u.clear();
        int us = s->rowCount();
        for(int i=0;i<us;i++){
           QString number= s->item(i,0)->text();
            QString name = s->item(i,1)->text();
           QString pw = s->item(i,2)->text();
           ww.u.insert(User(name,number,pw));
        }
    }

}
