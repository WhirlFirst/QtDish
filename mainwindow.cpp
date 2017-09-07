#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logic.h"
#include "QString"
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

void MainWindow::fresh(){
     ui->Userlabel->setText(QString::fromStdString(CurrentUser.showName()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSign_out_triggered()
{
    QMessageBox::warning(this, tr("thanks"),tr("感谢使用"),QMessageBox::Yes);
    this->close();
}
