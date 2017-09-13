#include "mainwindow.h"
#include <QApplication>
#include "logindialog.h"
#include "registerdialog.h"
#include "logic.h"
#include "QDebug"
#include "superuserdialog.h"
#include <QSqlQuery>
int main(int argc, char *argv[])
{

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
    ww.u.insert(p);
    qDebug() <<"finish";
    LoginDialog ldl;
    MainWindow w;
    SuperUserDialog l;
    int t =ldl.exec();
    if(t == 1){
        w.fresh();
        w.show();
    }
    else if(t ==2){
       l.show();
    }
    else if(t==3){

    }
    return a.exec();
}
