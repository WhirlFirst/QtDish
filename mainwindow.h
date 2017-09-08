#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <uitable.h>
#include <uidish.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void fresh();
private slots:
    void on_actionSign_out_triggered();

    void on_sTableBtn_clicked();

    void on_sDishBtn_clicked();
    void tablefresh();
    void moneyfresh();
private:
    Ui::MainWindow *ui;
    Uitable *utable[30];
    UiDish *udish[9];
};

#endif // MAINWINDOW_H
