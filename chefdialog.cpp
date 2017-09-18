#include "chefdialog.h"
#include "ui_chefdialog.h"
#include <QTableWidget>
#include <QStringList>
#include <QTableWidgetItem>
#include <QString>
#include <QDebug>
#include "QGridLayout"
#include "logic.h"
#include "QMessageBox"
#include <QSqlQuery>
chefDialog::chefDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chefDialog)
{
    ui->setupUi(this);

    //qDebug()<<QString::number(CurrentChef->showdishnumber());
    //ui->numberlabel->setText(QString::number(CurrentChef->shownumber()));
    //CurrentChef->showdishnumber();
}

chefDialog::~chefDialog()
{
    if(chefdialogflag==1){
        QSqlQuery query;
        for(int r =0;r<30;r++){
            query.exec(QString("delete from dish%1").arg(r));
            t[r].reset();
            for(int i=0;i<t[r].size();i++){
                Dish* o = t[r].showSingle();
                query.prepare(QString("insert into dish%1 (name,price,status,score)""values(?,?,?,?)").arg(r));
                query.addBindValue(o->showName());
                query.addBindValue(QString::number(o->showPrice()));
                query.addBindValue(o->showStatus());
                query.addBindValue(QString::number(o->showScore()));
                query.exec();
            }
        }
        QMap<int,string>::iterator iit;
        if(CurrentWaiter !=0){

            for(iit = CurrentWaiter->dm.begin();iit!= CurrentWaiter->dm.end();iit++){
                query.prepare("select * from message? order by number desc limit 1");
                query.addBindValue(QString::number(iit.key()).toInt());
                query.exec();
                while(query.next()){
                    messageflag = query.value(0).toInt();
                }
                qDebug()<<QString::fromStdString(iit.value());
                query.prepare("insert into message? (number,thing) values(?,?)");
                query.addBindValue(QString::number(iit.key()).toInt());
                query.addBindValue(QString::number(messageflag));
                query.addBindValue(QString::fromStdString(iit.value()));
                query.exec();
                messageflag++;
            }
        }
    }
    delete ui;
}

void chefDialog::on_startbtn_clicked()
{
    QTableWidget* s = ui->tableWidget;
    int row1 =-1;
    row1 = s->currentRow();
    if(row1>=0){
       int r =s->item(row1,1)->text().toInt();
       CurrentChef->settablenumber(r);
       t[r].reset();
       s->item(row1,1)->setBackgroundColor(QColor(0,60,10));
       QString nam = s->item(row1,0)->text();
       for(int e = 0;e<t[r].size();e++){
           Dish* g =t[r].showSingle();
          if( g->showName()== nam&&g->showStatus()=="Onqueue"){
            CurrentChef->startworking(g);
          }

       }
    }
}

void chefDialog::on_finishbtn_clicked()
{
    QTableWidget* s = ui->tableWidget;
    int row1 =-1;
    row1 = s->currentRow();
    if(row1>=0){
       emit CurrentChef->finishworking();
        int q=s->item(row1,1)->text().toInt();
       CurrentWaiter = t[q].surveice;
       qDebug()<<QString::number(q)<<QString::fromStdString(CurrentWaiter->showName());
       CurrentWaiter->dm.insert(q,CurrentChef->cookingDish->showName().toStdString());
    }
       QMessageBox::information(this,tr("厉害"),tr("平均用时：").append(QString::number(CurrentChef->showtime()).append(tr("s"))),QMessageBox::Yes);
       ui->numberlabel->setText(QString::number(CurrentChef->showdishnumber()));
       int u=0;
       int y=0;
       s->clearContents();
       for(int i =0;i<30;i++){
           y+= t[i].size();
       }
       s->setRowCount(y);
       for(int i=0;i<30;i++){
           t[i].reset();
           for(int x=0;x<t[i].size();x++){
               Dish* o = t[i].showSingle();
               if(o->showStatus()=="Onqueue"){
                   s->setItem(u,0,new QTableWidgetItem(o->showName()));
                   s->setItem(u,1,new QTableWidgetItem(QString::number(i)));
                   u++;
               }
           }
       }
}

void chefDialog::fresh(){
    ui->numberlabel->setText(QString::number(CurrentChef->showdishnumber()));
    ui->namelabel->setText(CurrentChef->showname());
}

void chefDialog::reloaddata(){
    QSqlQuery query;
    for(int i=0;i<30;i++){
        query.exec(QString("select * from dish%1").arg(i));
        while (query.next()) {
            QString value0 = query.value(0).toString();
            QString value1 = query.value(1).toString();
            QString sta = query.value(2).toString();
            Status e;
            if(sta =="Onqueue") e = Onqueue;
            else if(sta =="Cooking") e = Cooking;
            else if(sta =="Finshed") e = Finshed;
            float sco = query.value(3).toFloat();
            t[i].initdish(Dish(value1.toInt(),value0,sco,e));
        }
    }
    for(int j =0;j<30;j++){
        query.exec(QString("select * from ttable where number = %1").arg(j));
        QString wawa;
         while (query.next()) {
            wawa = query.value(3).toString();
         }
        WaiterMap::iterator m =  ww.waitermap.find(wawa);
        if(wawa!=0){
            qDebug()<<wawa;
            if(QString::fromStdString(m.value().showName())==wawa)
                CurrentWaiter = &m.value();
        }
        t[j].surveice = CurrentWaiter;
    }
    QStringList headers;
    QTableWidget* s = ui->tableWidget;
    s->setColumnCount(2);
    int y =0;
    for(int i =0;i<30;i++){
        y+= t[i].size();
    }
    s->setRowCount(y);
    headers << "菜名" << "桌号";
    s->setHorizontalHeaderLabels(headers);
    s->setEditTriggers(QAbstractItemView::NoEditTriggers);
    s->setSelectionBehavior(QAbstractItemView::SelectRows);
    s->setShowGrid(true);
    s->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    s->resizeRowsToContents();
    int u=0;
    for(int i=0;i<30;i++){
        t[i].reset();
        for(int x=0;x<t[i].size();x++){
            Dish* o = t[i].showSingle();
            if(o->showStatus()=="Onqueue"){
                s->setItem(u,0,new QTableWidgetItem(o->showName()));
                s->setItem(u,1,new QTableWidgetItem(QString::number(i)));
                u++;
            }
        }
    }
    s->show();
}

void chefDialog::savedata(){


}
