#include "mainwindow.h"
#include <QApplication>
#include "logindialog.h"
#include "registerdialog.h"
#include "logic.h"
#include "QDebug"
int main(int argc, char *argv[])
{
    Dish d(0,"french");

    QApplication a(argc, argv);
    User p("rr","18811125508","123");
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
