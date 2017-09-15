#ifndef CHIEFDIALOG_H
#define CHIEFDIALOG_H

#include <QDialog>

namespace Ui {
class chiefDialog;
}

class chiefDialog : public QDialog
{
    Q_OBJECT

public:
    explicit chiefDialog(QWidget *parent = 0);
    ~chiefDialog();
    void freshdata();
private:
    Ui::chiefDialog *ui;
};

#endif // CHIEFDIALOG_H
