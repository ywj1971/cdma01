#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>
#include <QPalette>
#include <QString>

namespace Ui {
class loginDlg;
}

class loginDlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit loginDlg(QWidget *parent = 0);
    ~loginDlg();

    QString userid,passwd,dbname,hostip;
    bool islogin;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::loginDlg *ui;


};

#endif // LOGINDLG_H
