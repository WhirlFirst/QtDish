#include "mainwindow.h"
#include <QApplication>
#include "logindialog.h"
#include "registerdialog.h"
#include "logic.h"

int main(int argc, char *argv[])
{
    Dish d(0,"french");

    QApplication a(argc, argv);

    LoginDialog ldl;
    MainWindow w;
    if(ldl.exec()== QDialog::Accepted)
    {
       if(!ww.u.isEmpty()) {
           w.update();
           w.fresh();
           w.show();
        }
    }
    return a.exec();
}
