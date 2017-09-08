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

void MainWindow::moneyfresh(){
    QString p("总计：");
    p.append(QString::number(CurrentUser->showCost()));
    p.append("元");
    ui->moneylabel->setText(p);
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
         tablefresh();
            for(int p=0;p<10;p++){
                for(int k=0;k<3;k++){
                    layout->addWidget(utable[i],p,k,1,1);
                    i++;
                }
            }
            flag=1;
    }
   else tablefresh();
}


void MainWindow::on_sDishBtn_clicked()
{
    QGridLayout *layout = ui->gridLayout_2;
    for(int i=0;i<30;i++){
        layout->removeWidget(utable[i]);
    utable[i]->deleteLater();
    }
    flag =0;
    ww.menu.reset();
    for(int i=0;i<9;i++){
        udish[i]= new UiDish(this);
        udish[i]->btninit();
     }
    for(int p=0;p<ww.menu.size();p++){
        Dish* temp =ww.menu.showSingle();
        udish[p]->setDish(temp);
        udish[p]->setlabel(temp->showName());
        udish[p]->setprice(temp->showPrice());
        udish[p]->setBtnabled(true);
        connect(udish[p],SIGNAL(addnewdish()),this,SLOT(moneyfresh()));
    }
    int x =0;
       for(int p=0;p<3;p++){
           for(int k=0;k<3;k++){
               layout->addWidget(udish[x],p,k,1,1);
               x++;
           }
       }
}
