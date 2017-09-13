#include "mainwindow.h"
#include <QApplication>
#include "logindialog.h"
#include "registerdialog.h"
#include "logic.h"
#include "QDebug"
#include "superuserdialog.h"
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
    User p("lulu","18811125508","123");
    ww.u.insert(p);
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
    qDebug()<<"last";
    return a.exec();
}
