#include "scriptdlg.h"
#include "ui_scriptdlg.h"

scriptDlg::scriptDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scriptDlg)
{
    ui->setupUi(this);
    islogin = false;
}

scriptDlg::~scriptDlg()
{
    delete ui;
}

void scriptDlg::okBtnClick()
{
    islogin = true;
    SQL = ui->textEdit->toPlainText();

    close();
}

void scriptDlg::cancelBtnClick()
{
    close();
}

void scriptDlg::on_pushButton_clicked()
{

    okBtnClick();
}

void scriptDlg::on_pushButton_2_clicked()
{
    cancelBtnClick();
}
