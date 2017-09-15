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
chefDialog::chefDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chefDialog)
{
    ui->setupUi(this);
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
                s->setItem(u,0,new QTableWidgetItem(QString::fromStdString(o->showName())));
                s->setItem(u,1,new QTableWidgetItem(QString::number(i)));
                u++;
            }
        }
    }
    s->show();
    //qDebug()<<QString::number(CurrentChef->showdishnumber());
    //ui->numberlabel->setText(QString::number(CurrentChef->shownumber()));
    //CurrentChef->showdishnumber();
}

chefDialog::~chefDialog()
{
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
       string nam = s->item(row1,0)->text().toStdString();
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
        int q=CurrentChef->showdishnumber();
       CurrentWaiter = t[q].surveice;
       CurrentWaiter->dm.insertRear(DishMessage(q,CurrentChef->cookingDish->showName()));
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
                   s->setItem(u,0,new QTableWidgetItem(QString::fromStdString(o->showName())));
                   s->setItem(u,1,new QTableWidgetItem(QString::number(i)));
                   u++;
               }
           }
       }
}

void chefDialog::fresh(){
    ui->numberlabel->setText(QString::number(CurrentChef->showdishnumber()));
    ui->namelabel->setText(QString::fromStdString(CurrentChef->showname()));
}
