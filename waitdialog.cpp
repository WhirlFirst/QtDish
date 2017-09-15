#include "waitdialog.h"
#include "ui_waitdialog.h"
#include "QGridLayout"
#include "uratingdish.h"
#include "logic.h"
#include "dishviewdialog.h"
WaitDialog::WaitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WaitDialog)
{
    ui->setupUi(this);
    QGridLayout* p = ui->DishgridLayout;
    for(int i =0;i<8;i++){
        urdish[i] = new URatingDish(this);
    }
    CurrentTable->reset();
    for(int r=0;r<CurrentTable->size();r++){
        urdish[r]->setDish(CurrentTable->showSingle());
    }
    int x=0;
    for(int q=0;q<2;q++){
        for(int y = 0;y<4;y++){
            if(urdish[x]->s!=0) p->addWidget(urdish[x],q,y);
            else urdish[x]->hide();
            x++;
        }
    }
    CurrentWaiter = CurrentTable->surveice;
}
int rat = 0;
WaitDialog::~WaitDialog()
{
    delete ui;
}



void WaitDialog::on_Dishviewbtn_clicked()
{
    DishviewDialog d;
    d.exec();
}

void WaitDialog::on_servicebtn_clicked()
{
    CurrentWaiter->cm.insert(CurrentTable->showNumber(),"beckon");
}

void WaitDialog::on_btn1_clicked()
{
    rat =1;
}

void WaitDialog::on_btn2_clicked()
{
    rat =2;
}

void WaitDialog::on_btn3_clicked()
{
    rat =3;
}

void WaitDialog::on_btn4_clicked()
{
    rat =4;
}

void WaitDialog::on_btn5_clicked()
{
    rat =5;
}

void WaitDialog::on_exitbtn_clicked()
{
    CurrentWaiter->rating(rat);
    accept();
}
