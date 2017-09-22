#include "paydialog.h"
#include "ui_paydialog.h"
#include "logic.h"
#include "QStringListModel"
#include "QStringData"
#include <QSqlQuery>
PayDialog::PayDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PayDialog)
{
    ui->setupUi(this);
    QStringList data;
    CurrentTable->reset();
    for(int i=0;i<CurrentTable->size();i++){
        data<<CurrentTable->showSingle()->showName();
    }
    QStringListModel* model = new QStringListModel(this);
    model->setStringList(data);
    ui->DishlistView->setModel(model);
    ui->costlabel->setText(CurrentUser->showCost().append(tr("元")));
}

PayDialog::~PayDialog()
{

    delete ui;
}

void PayDialog::on_pushButton_clicked()
{
    CurrentTable->reset();
    for(int i=0;i<CurrentTable->size();i++){
        CurrentTable->showSingle()->changeStatus(Onqueue);
    }
    QSqlQuery query;
    CurrentTable->reset();
    int x = QString::fromStdString(CurrentTable->showNumber()).toInt();
    query.exec(QString("delete from dish%1").arg(QString::fromStdString(CurrentTable->showNumber()).toInt()));
    for(int i=0;i<CurrentTable->size();i++){
        Dish* o = CurrentTable->showSingle();
        query.prepare(QString("insert into dish%1 (number,name,price,status,score)""values(?,?,?,?,?)").arg(x));
        query.addBindValue(QString::number(i));
        query.addBindValue(o->showName());
        query.addBindValue(QString::number(o->showPrice()));
        query.addBindValue(o->showStatus());
        query.addBindValue(QString::number(o->showScore()));
        query.exec();
    }

    query.exec(QString("delete from ttable where number = %1").arg(x));
    query.prepare("insert into ttable(number,name,status) values(?,?,?)");
    query.addBindValue(QString::number(x));
    query.addBindValue(CurrentUser->showName());
    query.addBindValue("Full");
    query.exec();
    accept();
}
