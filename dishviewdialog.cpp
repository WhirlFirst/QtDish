#include "dishviewdialog.h"
#include "ui_dishviewdialog.h"
#include <QTableWidget>
#include <QStringList>
#include <QTableWidgetItem>
#include <QString>
#include <QDebug>
#include "logic.h"
DishviewDialog::DishviewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DishviewDialog)
{
    ui->setupUi(this);
    QStringList headers;
    QTableWidget* s  = ui->tableWidget;
    s->setColumnCount(2);
    s->setRowCount(CurrentTable->size());
    headers << "菜名" <<"状态";
    s->setHorizontalHeaderLabels(headers);
    s->setEditTriggers(QAbstractItemView::NoEditTriggers);
    s->setSelectionBehavior(QAbstractItemView::SelectRows);
    s->setShowGrid(true);
    s->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    s->resizeRowsToContents();
    CurrentTable->reset();
    for(int i=0;i<CurrentTable->size();i++){
        Dish* p =CurrentTable->showSingle();
        s->setItem(i,0,new QTableWidgetItem(QString::fromStdString(p->showName())));
        s->setItem(i,1,new QTableWidgetItem(QString::number(p->showScore())));
    }
    s->show();
}

DishviewDialog::~DishviewDialog()
{
    delete ui;
}

void DishviewDialog::on_freshbtn_clicked()
{
    QStringList headers;
    QTableWidget* s  = ui->tableWidget;
    s->setColumnCount(2);
    s->setRowCount(CurrentTable->size());
    headers << "菜名" <<"状态";
    s->setHorizontalHeaderLabels(headers);
    s->setEditTriggers(QAbstractItemView::NoEditTriggers);
    s->setSelectionBehavior(QAbstractItemView::SelectRows);
    s->setShowGrid(true);
    s->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    s->resizeRowsToContents();
    CurrentTable->reset();
    for(int i=0;i<CurrentTable->size();i++){
        Dish* p =CurrentTable->showSingle();
        s->setItem(i,0,new QTableWidgetItem(QString::fromStdString(p->showName())));
        s->setItem(i,1,new QTableWidgetItem(QString::fromStdString(p->showStatus())));
    }
    s->show();
}

void DishviewDialog::on_exitbtn_clicked()
{
    close();
}
