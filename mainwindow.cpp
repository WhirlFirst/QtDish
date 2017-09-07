#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logic.h"
#include "QString"
#include "QMessageBox"
#include "QGridLayout"
#include <QPushButton>
#include <uidish.h>
#include <uitable.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

void MainWindow::fresh(){
     ui->Userlabel->setText(QString::fromStdString(CurrentUser.showName()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSign_out_triggered()
{
    QMessageBox::warning(this, tr("thanks"),tr("感谢使用"),QMessageBox::Yes);
    this->close();
}
int flag=0;
void MainWindow::on_sTableBtn_clicked()
{
    if(flag==0){
        ui->label->deleteLater();
        QGridLayout *layout = ui->gridLayout_2;
        Uitable *table[30];
        for(int i=0;i<30;i++){
            table[i]= new Uitable(this);
            table[i]->settable(&t[i]);
            table[i]->settext(t[i].showNumber());

         }
         int i =0;
            for(int p=0;p<10;p++){
                for(int k=0;k<3;k++){
                    layout->addWidget(table[i],p,k,1,1);
                    i++;
                }
            }
            flag=1;
    }
   else;
}
