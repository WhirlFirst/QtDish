#include "chiefdialog.h"
#include "ui_chiefdialog.h"

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
