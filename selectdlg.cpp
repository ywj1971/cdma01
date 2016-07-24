#include "selectdlg.h"
#include "ui_selectdlg.h"

selectDlg::selectDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectDlg)
{
    ui->setupUi(this);
    isok = false;
}

selectDlg::~selectDlg()
{
    delete ui;
}

void selectDlg::on_pushButton_2_clicked()
{
    close();
}

#define SELECTMSG1 "select mscid,mscpc MSC点码,mscname MSC名称,districtname 区域名称,DATE_FORMAT(createdate,'%Y-%m-%d') 建立时间,descrition 描述 from mscs"
#define SELECTMSG2 "select mscid,mscpc MSC点码,mscname MSC名称,districtname 区域名称,DATE_FORMAT(createdate,'%Y-%m-%d') 建立时间,descrition 描述 from mscs where mscid = %1"
void selectDlg::on_pushButton_clicked()
{
    isok = true;
    if(ui->lineEdit->text().trimmed().isEmpty())
    {
        SQL = SELECTMSG1;
    }
    else
    {
        SQL = QString(SELECTMSG2).arg(ui->lineEdit->text());
    }
    close();
}
