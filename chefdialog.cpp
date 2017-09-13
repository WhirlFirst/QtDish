#include "chefdialog.h"
#include "ui_chefdialog.h"

chefDialog::chefDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chefDialog)
{
    ui->setupUi(this);
}

chefDialog::~chefDialog()
{
    delete ui;
}
