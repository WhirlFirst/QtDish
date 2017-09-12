#include "paydialog.h"
#include "ui_paydialog.h"
#include "logic.h"
#include "QStringListModel"
#include "QStringData"
PayDialog::PayDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PayDialog)
{
    ui->setupUi(this);
    QStringList data;
    CurrentTable->reset();
    for(int i=0;i<CurrentTable->size();i++){
        data<<QString::fromStdString(CurrentTable->showSingle()->showName());
    }
    QStringListModel* model = new QStringListModel(this);
    model->setStringList(data);
    ui->DishlistView->setModel(model);
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
    accept();
}
