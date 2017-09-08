#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logic.h"
#include "QString"
#include "QMessageBox"
#include "QGridLayout"
#include <QPushButton>
#include <uidish.h>
#include <uitable.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

void MainWindow::fresh(){
     ui->Userlabel->setText(QString::fromStdString(CurrentUser->showName()));
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

int flag=0;
void MainWindow::tablefresh(){
    for(int i=0;i<30;i++){
        if(utable[i]->tp->showStatus() == Chosed) {
            utable[i]->setStyleSheet("background-color:grey;");
            utable[i]->disable();
        }
    }
    flag =1;
}


void MainWindow::on_sTableBtn_clicked()
{
    if(flag==0){
        QGridLayout *layout = ui->gridLayout_2;
        for(int i=0;i<30;i++){
            utable[i]= new Uitable(this);
            utable[i]->settable(&t[i]);
            utable[i]->settext(t[i].showNumber());
            connect(utable[i],SIGNAL(select()),this,SLOT(tablefresh()));

         }
         int i =0;
            for(int p=0;p<10;p++){
                for(int k=0;k<3;k++){
                    layout->addWidget(utable[i],p,k,1,1);
                    i++;
                }
            }
            flag=1;
    }
    if(flag==2){
        int i=0;
        tablefresh();
        for(int p=0;p<10;p++){
            for(int k=0;k<3;k++){
                utable[i]->show();
                i++;
            }
        }
        flag=1;
    }
   else tablefresh();
}


void MainWindow::on_sDishBtn_clicked()
{
    int i=0;
    for(int p=0;p<10;p++){
        for(int k=0;k<3;k++){
            utable[i]->hide();
            i++;
        }
    }
    flag =2;
}
