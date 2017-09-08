#include "mainwindow.h"
#include <QApplication>
#include "logindialog.h"
#include "registerdialog.h"
#include "logic.h"
#include "QDebug"
int main(int argc, char *argv[])
{
    Dish d(1010,"abalone");
    Dish fp(10,"chips");
    Dish f(150,"chicken");
    Dish m(6,"ice cream");
    Dish h(20,"humberger");
    ww.menu.insert(d);
    ww.menu.insert(fp);
    ww.menu.insert(f);
    ww.menu.insert(m);
    ww.menu.insert(h);
    for(int i=0;i<30;i++){
        t[i].init(i);
    }
    QApplication a(argc, argv);
    User p("lulu","18811125508","123");
    ww.u.insert(p);
    LoginDialog ldl;
    MainWindow w;
    if(ldl.exec()== QDialog::Accepted)
    {
           w.fresh();
           w.show();
    }
    return a.exec();
}
