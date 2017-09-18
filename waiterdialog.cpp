#include "waiterdialog.h"
#include "ui_waiterdialog.h"
#include "logic.h"
#include "QString"
#include "QMessageBox"
#include "QGridLayout"
#include <QPushButton>
#include <uidish.h>
#include <uitable.h>
#include <QSqlDatabase>
#include <QSqlQuery>
waiterDialog::waiterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::waiterDialog)
{
    ui->setupUi(this);

}

waiterDialog::~waiterDialog()
{
    if(databaseflag ==1){
        QSqlQuery query;
       for(int i=0;i<30;i++){
           if(utable[i]->tp->surveice != 0){
             query.prepare("update ttable set waiter = ? where number = ?");
             query.addBindValue(QString::fromStdString(utable[i]->tp->surveice->showName()));
             query.addBindValue(QString::number(i));
             query.exec();
           }
       }
       query.prepare("update waiter set acount = ? where name = ?");
       query.addBindValue(QString::number(CurrentWaiter->acount));
       query.addBindValue(QString::fromStdString(CurrentWaiter->showName()));
       query.exec();
    }
    delete ui;
}

void waiterDialog::showui(){
    QSqlQuery query;
    for(int i=0;i<30;i++){
        query.exec(QString("select * from ttable where number = %1").arg(i));
        User* y=0;
        while(query.next())
        {
            QString username = query.value(1).toString();
            ww.u.reset();
            for(int d =0;d<ww.u.size();d++){
                y = ww.u.showSingle();
                if(y->showName() == username)
                    break;
            }
            if(y!=0) t[i].StartWorking(y);
             QString sta = query.value(2).toString();
             TableStatus q;
             if(sta == "Empty") q=Empty;
             if(sta == "Full")  q =Full;
            QString waitername = query.value(3).toString();
            qDebug()<<waitername;
            if(waitername == 0){
            }
            else{
                WaiterMap::iterator it;
                it = ww.waitermap.find(waitername);
                t[i].setwaiter(&(it.value()));
            }
        }
    }
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
    for(int i=0;i<30;i++){
        if(t[i].surveice!=0) {
            query.exec(QString("select * from message%1").arg(i));
            while (query.next()) {
                string msg = query.value(1).toString().toStdString();
                t[i].surveice->dm.insert(i,msg);
            }
            query.exec(QString("delete from message%1").arg(i));
        }
    }
    QGridLayout *layout = ui->gridLayout;
    for(int i=0;i<30;i++){
        utable[i]= new Uitable(this);
        utable[i]->settable(&t[i]);
        utable[i]->settext(t[i].showNumber());
        connect(utable[i],SIGNAL(select()),this,SLOT(tablefresh()));
     }
     int i =0;
     tablefresh();
        for(int p=0;p<10;p++){
            for(int k=0;k<3;k++){
                layout->addWidget(utable[i],p,k,1,1);
                i++;
            }
        }
}

void waiterDialog::tablefresh(){
    for(int i=0;i<30;i++){
        if(utable[i]->tp->surveice != 0) {
                utable[i]->setStyleSheet("background-color:grey;");
                utable[i]->disable();
        }
        if(utable[i]->tp->surveice == 0 &&utable[i]->tp->showStatus() == "Empty"){
            utable[i]->setStyleSheet("background-color:grey;");
            utable[i]->disable();
        }
    }
    QMap<string,string>::iterator iit;
    for(iit = CurrentWaiter->cm.begin();iit!= CurrentWaiter->cm.end();iit++){
        QMessageBox::information(this, tr("提示"),QString::fromStdString(iit.key()).append(tr("号桌:")).append(QString::fromStdString(iit.value())),QMessageBox::Yes);
        CurrentWaiter->cm.remove(iit.key());
    }
    QMap<int,string>::iterator it;
    for(it = CurrentWaiter->dm.begin();it!= CurrentWaiter->dm.end();it++){
        QMessageBox::information(this, tr("提示"),QString::number(it.key()).append(tr("号桌:")).append(QString::fromStdString(it.value())),QMessageBox::Yes);
        CurrentWaiter->dm.remove(it.key());
    }
    ui->tablenumber->setText(QString::number(CurrentWaiter->acount).append(tr("桌")));
}

void waiterDialog::exit(){

}
