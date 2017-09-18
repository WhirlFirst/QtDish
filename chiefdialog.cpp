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
    s->setRowCount(ww.chefmap.size());
    headers << "厨师姓名" << "平均用时"<<"评分";
    s->setHorizontalHeaderLabels(headers);
    s->setEditTriggers(QAbstractItemView::NoEditTriggers);
    s->setSelectionBehavior(QAbstractItemView::SelectRows);
    s->setShowGrid(true);
    s->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    s->resizeRowsToContents();
    ChefMap::iterator cd ;
    int i=0;
    for(cd = ww.chefmap.begin();cd!= ww.chefmap.end();cd++){
        s->setItem(i,0,new QTableWidgetItem(cd.value().showname()));
        s->setItem(i,1,new QTableWidgetItem(cd.value().showtime()));
        s->setItem(i,2,new QTableWidgetItem(QString::number(cd.value().showscore())));
        i++;
    }
    s->show();

    QStringList headerswaiter;
    QTableWidget* sw = ui->waitertableWidget;
    sw->clear();
    sw->setColumnCount(3);
    sw->setRowCount(ww.waitermap.size());
    headerswaiter << "服务员姓名" << "服务总数"<<"评分";
    sw->setHorizontalHeaderLabels(headerswaiter);
    sw->setEditTriggers(QAbstractItemView::NoEditTriggers);
    sw->setSelectionBehavior(QAbstractItemView::SelectRows);
    sw->setShowGrid(true);
    sw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    sw->resizeRowsToContents();
    WaiterMap::iterator it;
    int yy =0;
    for(it = ww.waitermap.begin();it!=ww.waitermap.end();it++){
        sw->setItem(yy,0,new QTableWidgetItem(QString::fromStdString(it.value().showName())));
        sw->setItem(yy,1,new QTableWidgetItem(QString::number(it.value().acount)));
        sw->setItem(yy,2,new QTableWidgetItem(QString::number(it.value().showscore())));
        yy++;
    }
    sw->show();
}
