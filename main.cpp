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
int main(int argc, char *argv[])
{
    Waiter wa;
    wa.cm.insertRear(CustomerMessage("5","加水"));
    wa.dm.insertRear(DishMessage(5,"土豆丝"));
    for(int i=0;i<30;i++){
        t[i].init(i);
        t[i].setwaiter(&wa);
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
    ww.menu.insert(d);
    ww.menu.insert(fp);
    ww.menu.insert(f);
    ww.menu.insert(m);
    ww.menu.insert(h);
    ww.menu.insert(q);
    ww.menu.insert(du);
    ww.menu.insert(ac);
    ww.menu.insert(b);
    ww.menu.insert(c);
    //ww.chef.insertRear(x);
    QApplication a(argc, argv);
//    if (!createConnection())  qDebug() <<"error";
//    QSqlQuery query;
//    ww.menu.reset();
//    for(int i=0;i<ww.menu.size();i++){
//        Dish* d = ww.menu.showSingle();
//        query.prepare("insert into dish (name, price) ""values (?, ?)");
//        query.addBindValue(d->showName().c_str());
//        query.addBindValue(d->showPrice());
//        query.exec();
//    }
//    query.exec("select * from dish");
//    qDebug()<<query.size();
//    while(query.next())
//        {
//            qDebug() << query.value(0).toString()
//                           << query.value(1).toInt();
//        }
    User p("lulu","18811125508","123");
    t[5].StartWorking(&p);
    t[6].StartWorking(&p);
    t[5].addDish(h);
    t[5].reset();
    t[5].showSingle()->changeStatus(Onqueue);
    t[6].addDish(c);
    t[6].reset();
    t[6].showSingle()->changeStatus(Onqueue);
    ww.u.insert(p);
    qDebug() <<"finish";
    CurrentManager = new Manager;
    CurrentManager->cheflist.insertRear(Chef("chef1","2",30,4.7,7.3));
    LoginDialog ldl;
    MainWindow w;
    SuperUserDialog l;
    chefDialog che;
    waiterDialog wati;
    chiefDialog management;
    int xxx =ldl.exec();
    if(xxx == 1){
        w.fresh();
        w.show();
    }
    else if(xxx ==2){
       l.show();
    }
    else if(xxx==3){
        che.show();
        che.fresh();
    }
    else if(xxx==4){
        CurrentWaiter = &wa;
        wati.showui();
        wati.show();
    }
    else if(xxx==5){
        management.freshdata();
        management.show();
    }
    return a.exec();
}
