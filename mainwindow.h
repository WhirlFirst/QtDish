#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <uitable.h>
#include <uidish.h>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void fresh();
    void msg();
    void moneyfresh();
private slots:
    void on_actionSign_out_triggered();

    void on_sTableBtn_clicked();

    void on_sDishBtn_clicked();
    void tablefresh();

    void nextpagedish();
    void frontpagedish();
    void createnextbtn();
    void createfrontbtn();
    void on_PayBtn_clicked();

private:
    Ui::MainWindow *ui;
    Uitable *utable[30];
    UiDish *udish[9];
    QPushButton* next;
    QPushButton* front;
};

#endif // MAINWINDOW_H
