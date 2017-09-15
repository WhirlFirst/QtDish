#include "waiterdialog.h"
#include "ui_waiterdialog.h"
#include "logic.h"
#include "QString"
#include "QMessageBox"
#include "QGridLayout"
#include <QPushButton>
#include <uidish.h>
#include <uitable.h>
waiterDialog::waiterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::waiterDialog)
{
    ui->setupUi(this);

}

waiterDialog::~waiterDialog()
{
    delete ui;
}

void waiterDialog::showui(){
    QGridLayout *layout = ui->gridLayout;
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
}

void waiterDialog::tablefresh(){
    for(int i=0;i<30;i++){
        if(utable[i]->tp->showStatus() == "Empty"||utable[i]->tp->surveice !=CurrentWaiter) {
            utable[i]->setStyleSheet("background-color:grey;");
            utable[i]->disable();
            }
        }
    CurrentWaiter->cm.reset();
    CurrentWaiter->dm.reset();
    for(int f=0;CurrentWaiter->cm.getSize();f++){
        CustomerMessage* cc = CurrentWaiter->cm.ShowSingle();
        QMessageBox::information(this, tr("提示"),QString::fromStdString(cc->tablenumber).append(tr("号桌:")).append(QString::fromStdString(cc->things)),QMessageBox::Yes);
        CurrentWaiter->cm.deleteFront();
    }
    for(int f=0;CurrentWaiter->dm.getSize();f++){
        DishMessage* cc = CurrentWaiter->dm.ShowSingle();
        QMessageBox::information(this, tr("提示"),QString::number(cc->tablenumber).append(tr("号桌:")).append(QString::fromStdString(cc->dishname)).append(tr("已做好")),QMessageBox::Yes);
        CurrentWaiter->dm.deleteFront();
    }
    ui->tablenumber->setText(QString::number(CurrentWaiter->acount).append(tr("桌")));
}