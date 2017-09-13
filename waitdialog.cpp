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
}

WaitDialog::~WaitDialog()
{
    delete ui;
}

void WaitDialog::on_exitbtn_clicked()
{
    accept();
}

void WaitDialog::on_Dishviewbtn_clicked()
{
    DishviewDialog d;
    d.exec();
}
