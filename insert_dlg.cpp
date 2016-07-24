#include "insert_dlg.h"
#include "ui_insert_dlg.h"
#include <QMessageBox>

insert_Dlg::insert_Dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::insert_Dlg)
{
    ui->setupUi(this);
}
insert_Dlg::~insert_Dlg()
{
    delete ui;
}
//#define INSERTMSG "insert into mscs (mscid,mscpc,mscname,districtname,createdate,description)values(10,'2.2.2','msc10','四域',str_to_date('2016-7-5 12:00:00','%Y-%m-%d %H:%i:%s'),'新设备')"

#define INSERTMSG "insert into mscs (mscid,mscpc,mscname,districtname,createdate,descrition)values(%1,'%2','%3','%4',str_to_date('%5','%Y-%m-%d %H:%i:%s'),'%6')"
void insert_Dlg::on_pushButton_clicked()
{
    SQL = QString(INSERTMSG).arg(ui->lineEdit_1->text()).arg(ui->lineEdit_2->text()).arg(ui->lineEdit_3->text()).arg(ui->lineEdit_4->text()).arg(ui->dateEdit->text()).arg(ui->lineEdit_5->text());
    QMessageBox::information(this,"",SQL);

    isok = true;
    close();

}

void insert_Dlg::on_pushButton_2_clicked()
{
    close();
}
