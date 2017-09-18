#include "waitdialog.h"
#include "ui_waitdialog.h"
#include "QGridLayout"
#include "uratingdish.h"
#include "logic.h"
#include "dishviewdialog.h"
#include "QStringData"
#include <QSqlQuery>
WaitDialog::WaitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WaitDialog)
{
    ui->setupUi(this);

}
int rat = 0;
WaitDialog::~WaitDialog()
{
    if(waiterdialogflag==1){
        QSqlQuery query;
        QMap<string,string>::iterator iit;
        if(CurrentWaiter!=0){
            query.prepare("select * from message? order by number desc limit 1");
            query.addBindValue(QString::fromStdString(CurrentTable->showNumber()).toInt());
            while(query.next()){
                messageflag = query.value(0).toInt();
            }
            for(iit = CurrentWaiter->cm.begin();iit!= CurrentWaiter->cm.end();iit++){
                query.prepare("insert into message? (number,thing) values(?,?)");
                query.addBindValue(QString::fromStdString(CurrentTable->showNumber()).toInt());
                query.addBindValue(QString::number(messageflag));
                query.addBindValue(QString::fromStdString(iit.value()));
                query.exec();
                qDebug()<<QString::fromStdString(iit.value());
                messageflag++;
            }
        }
    }
    delete ui;
}



void WaitDialog::on_Dishviewbtn_clicked()
{
    DishviewDialog d;
    d.exec();
}

void WaitDialog::on_servicebtn_clicked()
{
    int y = QString::fromStdString(CurrentTable->showNumber()).toInt();
    Waiter* s = t[y].surveice;
    WaiterMap::iterator iu = ww.waitermap.find(QString::fromStdString(s->showName()));
    string r = "backon";
    iu.value().cm.insert(CurrentTable->showNumber(),r);
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
    QSqlQuery query;
    CurrentWaiter->rating(rat);
    int x = QString::fromStdString(CurrentTable->showNumber()).toInt();
    query.exec(QString("delete from dish%1").arg(QString::fromStdString(CurrentTable->showNumber()).toInt()));
    query.exec(QString("delete from ttable where number = %1").arg(x));
    accept();
}

void WaitDialog::fresh(){
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
    //qDebug()<<CurrentWaiter->showName();
}
