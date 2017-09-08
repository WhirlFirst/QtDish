#include "uidish.h"
#include "ui_uidish.h"
#include "QString"
#include "logic.h"
using namespace std;
UiDish::UiDish(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UiDish)
{
    ui->setupUi(this);
    ui->pushButton->setText(tr("想吃🤤"));
}

UiDish::~UiDish()
{
    delete ui;
}

void UiDish::on_pushButton_clicked()
{
    CurrentTable->addDish(*d);
    CurrentUser->addCost(d->showPrice());
}

void UiDish::setlabel(string n){
    ui->label->setText(QString::fromStdString(n));
}
