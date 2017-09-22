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
                query.prepare(QString("insert into dish%1 (number,name,price,status,score)""values(?,?,?,?,?)").arg(r));
                query.addBindValue(QString::number(i));
                query.addBindValue(o->showName());
                query.addBindValue(QString::number(o->showPrice()));
                query.addBindValue(o->showStatus());
                query.addBindValue(QString::number(o->showScore()));
                query.exec();
            }
        }
        QMap<string,int>::iterator iit;
        for(int r=0;r<30;r++){
            int x=0;
            if(t[r].surveice!=0){
                qDebug()<<"in";
                for(iit = t[r].surveice->dm.begin();iit!= t[r].surveice->dm.end();iit++){
                    query.prepare("insert into chefmessage? (number,name) values(?,?)");
                    query.addBindValue(QString::number(iit.value()).toInt());
                    query.addBindValue(QString::number(x));
                    query.addBindValue(QString::fromStdString(iit.key()));
                    query.exec();
                    x++;
                    }
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
       QString nam = s->item(row1,0)->text();
       if(t[r].surveice!=0)
       {

           CurrentWaiter = t[r].surveice;
            qDebug()<<"got survice";
       }
       for(int e = 0;e<t[r].size();e++){
           Dish* g =t[r].showSingle();
          if( g->showName()== nam&&g->showStatus()=="Onqueue"){
            CurrentChef->startworking(g);
            break;
          }

       }
       s->clearContents();
       s->setRowCount(1);
       s->setItem(0,0,new QTableWidgetItem(nam));
       s->setItem(0,1,new QTableWidgetItem(QString::number(r)));
    }
}

void chefDialog::on_finishbtn_clicked()
{
        QTableWidget* s = ui->tableWidget;
       emit CurrentChef->finishworking();
        int q=s->item(0,1)->text().toInt();
       CurrentWaiter = t[q].surveice;
       if(CurrentWaiter!=0)
            t[q].surveice->dm.insert(CurrentChef->cookingDish->showName().toStdString(),q);
       QMessageBox::information(this,tr("厉害"),tr("平均用时：").append(QString::number(CurrentChef->showtime()).append(tr("s"))),QMessageBox::Yes);
       ui->numberlabel->setText(QString::number(CurrentChef->showdishnumber()));
       int u=0;
       int y=0;
       s->clearContents();
       for(int i =0;i<30;i++){
           t[i].reset();
           for(int x=0;x<t[i].size();x++){
               Dish* temp = t[i].showSingle();
               if(temp->showStatus() == "Onqueue")
                   y++;
           }
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
            QString value0 = query.value(1).toString();
            QString value1 = query.value(2).toString();
            QString sta = query.value(3).toString();
            Status e;
            if(sta =="Onqueue") e = Onqueue;
            else if(sta =="Cooking") e = Cooking;
            else if(sta =="Finshed") e = Finshed;
            float sco = query.value(4).toFloat();
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
                t[j].surveice = &m.value();
        }
    }
    QStringList headers;
    QTableWidget* s = ui->tableWidget;
    s->setColumnCount(2);
    int y =0;
    for(int i =0;i<30;i++){
        t[i].reset();
        for(int x=0;x<t[i].size();x++){
            Dish* temp = t[i].showSingle();
            if(temp->showStatus() == "Onqueue")
                y++;
        }
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
