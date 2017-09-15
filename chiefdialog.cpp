#include "chiefdialog.h"
#include "ui_chiefdialog.h"
#include "logic.h"
#include "QString"
#include "QMessageBox"
#include "QGridLayout"

chiefDialog::chiefDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chiefDialog)
{
    ui->setupUi(this);
}



chiefDialog::~chiefDialog()
{
    delete ui;
}


void chiefDialog::freshdata(){
    QStringList headers;
    QTableWidget* s = ui->cheftableWidget;
    s->clear();
    s->setColumnCount(3);
    s->setRowCount(CurrentManager->cheflist.getSize());
    headers << "厨师姓名" << "平均用时"<<"评分";
    s->setHorizontalHeaderLabels(headers);
    s->setEditTriggers(QAbstractItemView::NoEditTriggers);
    s->setSelectionBehavior(QAbstractItemView::SelectRows);
    s->setShowGrid(true);
    s->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    s->resizeRowsToContents();
    CurrentManager->cheflist.reset();
    for(int i=0;i<CurrentManager->cheflist.getSize();i++){
        Chef* p =CurrentManager->cheflist.ShowSingle();
        s->setItem(i,0,new QTableWidgetItem(QString::fromStdString(p->showname())));
        s->setItem(i,1,new QTableWidgetItem(QString::number(p->showtime())));
        s->setItem(i,2,new QTableWidgetItem(QString::number(p->showscore())));
    }
    s->show();

    QStringList headerswaiter;
    QTableWidget* sw = ui->cheftableWidget;
    sw->clear();
    sw->setColumnCount(3);
    sw->setRowCount(1);
    headerswaiter << "服务员姓名" << "服务总数"<<"评分";
    sw->setHorizontalHeaderLabels(headerswaiter);
    sw->setEditTriggers(QAbstractItemView::NoEditTriggers);
    sw->setSelectionBehavior(QAbstractItemView::SelectRows);
    sw->setShowGrid(true);
    sw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    sw->resizeRowsToContents();
//    for(int i=0;i<1;i++){
//        Waiter s = waiterlist[0];
//        sw->setItem(i,0,new QTableWidgetItem(QString::fromStdString(s.showName())));
//        sw->setItem(i,1,new QTableWidgetItem(QString::number(s.acount)));
//        sw->setItem(i,2,new QTableWidgetItem(QString::number(s.showscore())));
//    }
    sw->show();
}
