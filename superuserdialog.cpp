#include "superuserdialog.h"
#include "ui_superuserdialog.h"
#include "logic.h"
#include <QTableWidget>
#include <QStringList>
#include <QTableWidgetItem>
#include <QString>
#include <QDebug>
#include "QGridLayout"
SuperUserDialog::SuperUserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SuperUserDialog)
{
    ui->setupUi(this);
}

SuperUserDialog::~SuperUserDialog()
{
    delete ui;
}



void SuperUserDialog::on_menuButton_clicked()
{
        QStringList headers;
        QTableWidget* s = ui->tableWidget;
        s->setColumnCount(3);
        s->setRowCount(ww.menu.size());
        headers << "菜名" << "价格"<<"评分";
        s->setHorizontalHeaderLabels(headers);
        s->setEditTriggers(QAbstractItemView::NoEditTriggers);
        s->setSelectionBehavior(QAbstractItemView::SelectRows);
        s->setShowGrid(true);
        s->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        s->resizeRowsToContents();
        qDebug()<<"1";
        ww.menu.reset();
        for(int i=0;i<ww.menu.size();i++){
            Dish* p =ww.menu.showSingle();
            s->setItem(i,0,new QTableWidgetItem(QString::fromStdString(p->showName())));
            s->setItem(i,1,new QTableWidgetItem(QString::number(p->showPrice())));
            s->setItem(i,2,new QTableWidgetItem(QString::number(p->showScore())));
        }
        s->show();
}
