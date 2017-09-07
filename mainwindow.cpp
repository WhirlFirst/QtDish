#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logic.h"
#include "QString"
#include "QMessageBox"
#include "QGridLayout"
#include <QPushButton>
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

void MainWindow::on_sTableBtn_clicked()
{
   ui->label->deleteLater();
   QGridLayout *layout = new QGridLayout;
   QPushButton *table[50];
   for(int i=0;i<50;i++){
       table[i]= new QPushButton(this);
       table[i]->setText(QString::fromStdString(t[i].showNumber()));
    }
   layout->addWidget(table[0],0,0,1,1);
   layout->addWidget(table[1],0,1,1,1);
   ui->centralWidget->setLayout(layout);
}
