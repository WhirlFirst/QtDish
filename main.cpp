#include "mainwindow.h"
#include <QApplication>
#include "logindialog.h"
#include "registerdialog.h"
#include "logic.h"
#include "QDebug"
#include "superuserdialog.h"
#include <QSqlQuery>
#include "chefdialog.h"
#include "waiterdialog.h"
#include "chiefdialog.h"
#include "connection.h"
#include "waitdialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if (!createConnection())
                return 1;
    Waiter wa;
    for(int i=0;i<30;i++){
        t[i].init(i);
    }
    Dish d(1010,"abalone");
    Dish fp(10,"chips");
    Dish f(150,"chicken");
    Dish m(6,"ice cream");
    Dish h(20,"humberger");
    Dish q(168,"Roast Duck");
    Dish du(30,"Dumplings");
    Dish ac(10,"Rouga bun");
    Dish b(86,"Soy shrimp");
    Dish c(28,"potato floss");
    //Chef x("chef","1");

    QSqlQuery query;
    query.exec("select * from user");
    while(query.next())
    {
        QString value0 = query.value(0).toString();
        QString value1 = query.value(1).toString();
        QString value2 = query.value(2).toString();
        qDebug() << value0 << value1<<value2 ;
        ww.u.insert(User(value0,value1,value2));
    }
    query.exec("select * from dish where number = -1");
    while(query.next())
    {
        QString value0 = query.value(0).toString();
        QString value1 = query.value(1).toString();
        float sco = query.value(4).toFloat();
        qDebug() << value0 << value1 ;
        ww.menu.insert(Dish(value1.toInt(),value0,sco));
    }
    query.exec("select * from chef");
    while(query.next())
    {
        QString value0 = query.value(0).toString();
        QString value1 = query.value(1).toString();
        float atime = query.value(2).toFloat();
        float ascore = query.value(3).toFloat();
        float number = query.value(4).toFloat();
        ww.chefmap.insert(value0,Chef(value0,value1,number,ascore,atime));
    }
    query.exec("select * from waiter");
    while(query.next())
    {
        QString value0 = query.value(0).toString();
        QString value1 = query.value(1).toString();
        float sco = query.value(2).toFloat();
        int acount = query.value(3).toInt();
        qDebug()<<value0<<value1;
        ww.waitermap.insert(value0,Waiter(value0.toStdString(),value1,sco,acount));
    }

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
            if(waitername == 0){
            }
            else{
                WaiterMap::iterator it;
                it = ww.waitermap.find(waitername);
                t[i].setwaiter(&(it.value()));
            }
        }
    }
    CurrentManager = new Manager;
    LoginDialog ldl;
    MainWindow w;
    SuperUserDialog l;
    chefDialog che;
    waiterDialog wati;
    chiefDialog management;
    WaitDialog we;
    int xxx =ldl.exec();
    if(xxx == 1){
        query.prepare("select * from ttable where name = ?");
        query.addBindValue(CurrentUser->showName());
        query.exec();
        int i=0;
        QString wawa;
         while (query.next()) {
            i = query.value(0).toInt();
            wawa = query.value(3).toString();
         }
        qDebug()<<QString::number(i)<<CurrentUser->showName();
        qDebug()<<wawa;
        WaiterMap::iterator m =  ww.waitermap.find(wawa);
        query.exec(QString("select * from dish%1").arg(i));
        while (query.next()) {
            QString name = query.value(1).toString();
            int pri = query.value(2).toInt();
            QString sta = query.value(3).toString();
            float scor = query.value(4).toFloat();
            Status e;
            if(sta =="Onqueue") e = Onqueue;
            else if(sta =="Cooking") e = Cooking;
            else if(sta =="Finshed") e = Finshed;
            t[i].initdish(Dish(pri,name,scor,e));
        }
        if(t[i].size()>0){
            if(wawa!=0){
                if(QString::fromStdString(m.value().showName())==wawa)
                    CurrentWaiter = &m.value();
                qDebug()<<QString::fromStdString(CurrentWaiter->showName());
            }
            t[i].surveice = CurrentWaiter;
            CurrentTable = &(t[i]);
            waiterdialogflag=1;
            we.fresh();
            we.show();
        }
        else{
            w.fresh();
            w.show();
        }
    }
    else if(xxx ==2){
       l.show();
    }
    else if(xxx==3){

        che.reloaddata();
        chefdialogflag= 1;
        che.fresh();
        che.show();
        che.savedata();
    }
    else if(xxx==4){
        wati.showui();
        databaseflag=1;
        wati.show();
        wati.exit();
    }
    else if(xxx==5){
        management.freshdata();
        management.show();
    }
    else {
        w.close();
        QSqlDatabase::removeDatabase("QMYSQL");
    }
    qDebug() <<"finish";
    return a.exec();
}
