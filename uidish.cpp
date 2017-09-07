#include "uidish.h"
#include "ui_uidish.h"
#include "QString"
using namespace std;
UiDish::UiDish(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UiDish)
{
    ui->setupUi(this);
}

UiDish::~UiDish()
{
    delete ui;
}

void UiDish::on_pushButton_clicked()
{

}

void UiDish::setBtntext(string s){
    ui->pushButton->setText(QString::fromStdString(s));
}
