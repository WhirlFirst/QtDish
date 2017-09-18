#include "adddishdialog.h"
#include "ui_adddishdialog.h"
#include "logic.h"
addDishDialog::addDishDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addDishDialog)
{
    ui->setupUi(this);
}

addDishDialog::~addDishDialog()
{
    delete ui;
}

void addDishDialog::on_pushButton_clicked()
{
    QString name = ui->namelineEdit->text();
    int price = ui->pricelineEdit->text().toInt();
    ww.menu.insert(Dish(price,name));
    close();
}
