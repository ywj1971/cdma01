#include "logindlg.h"
#include "ui_logindlg.h"

loginDlg::loginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDlg)
{
    ui->setupUi(this);

//    setFixedSize(197,169);

    setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/new/prefix1/img/green.jpg")));

    setPalette(palette);





    islogin = false;
}

loginDlg::~loginDlg()
{
    delete ui;
}

void loginDlg::on_pushButton_clicked()
{
    userid = ui->useridLinEdit->text();
    passwd = ui->passwdLinEdit->text();
    dbname = ui->dbnameLinEdit->text();
    hostip = ui->hostipLinEdit->text();
    islogin = true;

    close();



}

void loginDlg::on_pushButton_2_clicked()
{
    close();
}
