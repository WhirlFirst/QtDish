#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logic.h"
#include "QString"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

void MainWindow::fresh(){
    if(!ww.u.isEmpty()) ui->label->setText(QString::fromStdString(ww.u.showSingle().showName()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
