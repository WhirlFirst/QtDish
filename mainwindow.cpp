#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logic.h"
#include "QString"
#include "QMessageBox"
#include "QGridLayout"
#include <QPushButton>
#include <uidish.h>
#include <uitable.h>
#include <QDebug>
#include <paydialog.h>
#include <waitdialog.h>
int fl=0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::createnextbtn(){
    next = new QPushButton(this);
    next->setGeometry(440,650,93,28);
    next->setText(tr("下一页"));
    connect(next,SIGNAL(clicked()),this,SLOT(nextpagedish()));
    next->show();
}

void MainWindow::createfrontbtn(){
    front = new QPushButton(tr("上一页"),this);
    front->setGeometry(340,650,93,28);
    connect(front,SIGNAL(clicked(bool)),this,SLOT(frontpagedish()));
    front->setEnabled(false);
    front->show();
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
    flag =2;
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
            flag=2;
    }
    else if(flag==1||flag==4){
        QGridLayout *layout = ui->gridLayout_2;
        front->deleteLater();
        next->deleteLater();
        for(int i=0;i<9;i++){
            udish[i]->hide();
            layout->removeWidget(udish[i]);
            udish[i]->deleteLater();
         }
        for(int i=0;i<30;i++){
            utable[i]= new Uitable(this);
            utable[i]->settable(&t[i]);
            utable[i]->settext(t[i].showNumber());
            connect(utable[i],SIGNAL(select()),this,SLOT(tablefresh()));

         }
        tablefresh();
        int y=0;
        for(int p=0;p<10;p++){
            for(int k=0;k<3;k++){
                layout->addWidget(utable[y],p,k,1,1);
                y++;
            }
        }
        flag =3;
    }
   else tablefresh();
}


void MainWindow::nextpagedish(){
    fl++;
    QGridLayout *layout = ui->gridLayout_2;
    if(ww.menu.size()<(fl+1)*9) next->setEnabled(false);
    for(int d = 0;d<9;d++){
        udish[d]->btninit();
    }
    ww.menu.reset(fl*9);
    int s=0;
    for(int p=0+fl*9;p<ww.menu.size()&&p<(9+fl*9);p++){
        Dish* temp =ww.menu.showSingle();
        udish[s]->setDish(temp);
        udish[s]->setlabel(temp->showName());
        udish[s]->setprice(temp->showPrice());
        udish[s]->setBtnabled(true);
        connect(udish[s],SIGNAL(newdish()),this,SLOT(moneyfresh()));
        s++;
    }
    int x =0;
       for(int p=0;p<3;p++){
           for(int k=0;k<3;k++){
               if(udish[x]->d != 0) layout->addWidget(udish[x],p,k,1,1);
               else udish[x]->hide();
               x++;
           }
       }
    front->setEnabled(true);
}

void MainWindow::frontpagedish(){
    fl--;
    QGridLayout *layout = ui->gridLayout_2;
    if(fl==0) front->setEnabled(false);
    for(int d = 0;d<9;d++){
        udish[d]->btninit();
    }
    ww.menu.reset(fl*9);
    int s=0;
    for(int p=0+fl*9;p<ww.menu.size()&&p<(9+fl*9);p++){
        Dish* temp =ww.menu.showSingle();
        udish[s]->setDish(temp);
        udish[s]->setlabel(temp->showName());
        udish[s]->setprice(temp->showPrice());
        udish[s]->setBtnabled(true);
        connect(udish[s],SIGNAL(newdish()),this,SLOT(moneyfresh()));
        s++;
    }
    int x =0;
       for(int p=0;p<3;p++){
           for(int k=0;k<3;k++){
               if(udish[x]->d != 0) udish[x]->show();
               else udish[x]->hide();
               x++;
           }
       }
    next->setEnabled(true);
}

void MainWindow::on_sDishBtn_clicked()
{
    if(CurrentTable== 0) QMessageBox::warning(this, tr("哎呀"),tr("请先选桌"),QMessageBox::Yes);
    if(flag==4) ;
    else{
        QGridLayout *layout = ui->gridLayout_2;
        for(int i=0;i<30;i++){
            layout->removeWidget(utable[i]);
        utable[i]->deleteLater();
        }
        flag =1;
        ww.menu.reset();
        for(int i=0;i<9;i++){
            udish[i]= new UiDish(this);
            udish[i]->btninit();
         }
        for(int p=0;p<ww.menu.size()&&p<9;p++){
            Dish* temp =ww.menu.showSingle();
            udish[p]->setDish(temp);
            udish[p]->setlabel(temp->showName());
            udish[p]->setprice(temp->showPrice());
            udish[p]->setBtnabled(true);
            connect(udish[p],SIGNAL(newdish()),this,SLOT(moneyfresh()));
        }
        int x =0;
           for(int p=0;p<3;p++){
               for(int k=0;k<3;k++){
                   if(udish[x]->d != 0) layout->addWidget(udish[x],p,k,1,1);
                   else udish[x]->hide();
                   x++;
               }
           }
        createnextbtn();
        createfrontbtn();
        flag=4;
    }
}


void MainWindow::on_PayBtn_clicked()
{
    PayDialog pa;
    if(pa.exec() ==QDialog::Accepted){
        this->hide();
        WaitDialog w;
        if(w.exec() == QDialog::Accepted){
            this->close();
        }
    }
}
