#include "uitable.h"
#include "ui_uitable.h"
#include "logic.h"
#include "QString"
Uitable::Uitable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Uitable)
{
    ui->setupUi(this);
}

Uitable::~Uitable()
{
    delete ui;
}
void Uitable::settable(Table* temp){
    tp = temp;
}

void Uitable::settext(string ss){
    ui->pushButton->setText(QString::fromStdString(ss));
}

void Uitable::on_pushButton_clicked()
{
    tp->StartWorking(&CurrentUser);
}
