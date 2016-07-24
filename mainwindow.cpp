#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "mymysql.h"
#include "insert_dlg.h"
#include "selectdlg.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //    setFixedSize(700,430);

    mdiarea = new QMdiArea;
    setCentralWidget(mdiarea);
    mdiarea->setBackground(Qt::NoBrush);
    mdiarea->setStyleSheet("background-image:url(:/new/prefix1/img/back.jpg);");

    mdiarea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiarea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showsub()
{


    scriptDlg script;
    script.exec();

    if(script.islogin)
    {
        script_msg(script.SQL.toStdString().data());
    }



    //    if(db.sql_exec("insert into table1(name,sex,age,class) values('李总理','�,56,'中共中央')") == -1)
    //        {
    //            QMessageBox::information(this,"exec失败",db.geterror());
    //        }
    //        else
    //        {
    //            QMessageBox::information(this,"","exec成功");
    //        }


    //    QWidget *w1 = new QWidget;
    //    w1->setAttribute(Qt::WA_DeleteOnClose);
    //    mdiarea->addSubWindow(w1);

    //    w1->setStyleSheet("background-image:url(:/new/prefix1/img/green.jpg);");


    //    w1->show();
    //    mdiarea->activeSubWindow()->resize(width()-100,height()-100);
}

void MainWindow::on_action_login_triggered()
{
    loginDlg login;
    login.exec();


    if(login.islogin)
    {
        //        mymysql db;
        int ret = db.sqlConnect(login.hostip.toStdString().data(),
                                login.userid.toStdString().data(),
                                login.passwd.toStdString().data(),
                                login.dbname.toStdString().data());
        if(ret == -1)
        {
            QMessageBox::information(this,"","登陆失败",db.geterror());
        }
        else
        {
            QMessageBox::information(this,"","登陆成功");
            ui->action_12->setEnabled(true);
            ui->action_logout->setEnabled(true);
        }
    }

}

void MainWindow::on_action_logout_triggered()
{
    //    QMessageBox::information(this,"脤谩脢戮","脥脣鲁枚掳麓脜楼卤禄碌楼禄梅");

    QMessageBox::StandardButton button;
    button = QMessageBox::question(this,"脤谩脢戮","脢脟路帽露脧驴陋",QMessageBox::Yes | QMessageBox::No);
    if (button == QMessageBox::Yes)
    {
        db.sql_disconnect();;
        ui->action_12->setEnabled(false);
        ui->action_logout->setEnabled(false);
    }


}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this,"脤谩脢戮","脢脟路帽脥脣鲁枚",QMessageBox::Yes | QMessageBox::No);
    if (button == QMessageBox::Yes)
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }


    //    QMessageBox::information(this,"脤谩脢戮","鹿脴卤脮脢脗录艧卤禄麓楼路垄");
}

void MainWindow::showView()
{
    QStandardItemModel *moudle = new QStandardItemModel(5,3);

    moudle->setHeaderData(0,Qt::Horizontal,"臑脮脙没");
    moudle->setHeaderData(1,Qt::Horizontal,"臑脭卤臒");
    moudle->setHeaderData(2,Qt::Horizontal,"脛锚脕盲");

    moudle->setData(moudle->index(0,0,QModelIndex()),"脮脜脠谋");
    moudle->setData(moudle->index(0,1,QModelIndex()),"脛臑");
    moudle->setData(moudle->index(0,2,QModelIndex()),"20");


    moudle->setData(moudle->index(1,0,QModelIndex()),"脌卯脣脛");
    moudle->setData(moudle->index(1,1,QModelIndex()),"脛臑");
    moudle->setData(moudle->index(1,2,QModelIndex()),"21");

    QTableView *view1 = new QTableView;

    view1->setAttribute(Qt::WA_DeleteOnClose);
    mdiarea->addSubWindow(view1);
    view1->setStyleSheet("background-image:url(:/new/prefix1/img/green.jpg);");

    view1->setModel(moudle);
    view1->show();
    mdiarea->activeSubWindow()->resize(width()-100,height()-100);
}

void MainWindow::script_msg(const char *SQL)
{
    int res = 0;
    if((strncmp(SQL,"SELECT",6) == 0) || (strncmp(SQL,"select",6) == 0))
    {
        QStandardItemModel *moudel = NULL;
        res = db.sql_open(SQL,&moudel);

        QTableView *view1 = new QTableView;
        view1->setAttribute(Qt::WA_DeleteOnClose);
        mdiarea->addSubWindow(view1);

        view1->setModel(moudel);
        view1->show();

        mdiarea->activeSubWindow()->resize(width()-100,height()-100);

    }
    else
    {
        res = db.sql_exec(SQL);
    }
    if(res == -1)

    {
        QMessageBox::information(this,"执行失败",db.geterror());
    }
    else
    {
        QMessageBox::information(this,"","执行成功");
    }
}




void MainWindow::on_action_12_triggered()
{
    showsub();

    //    if(db.sql_exec("delete from table1 where name='脮脜脠谋'") == -1)
    //    {
    //        QMessageBox::information(this,"exec脢搂掳脺",db.geterror());
    //    }
    //    else
    //    {
    //        QMessageBox::information(this,"","exec鲁脡鹿娄");
    //    }



    //    showView();

}

void MainWindow::cengdieWindow()
{

    mdiarea->cascadeSubWindows();
}

void MainWindow::binglieWindow()
{
    mdiarea->tileSubWindows();
}

void MainWindow::on_action_14_triggered()
{
    cengdieWindow();
}

void MainWindow::on_action_15_triggered()
{
    binglieWindow();
}

void MainWindow::on_action_2_triggered()
{
    QMessageBox::information(this,"掳茂脰煤","脳脭脩搂鲁脡虏脜");
}

void MainWindow::on_action_triggered()
{
    QMessageBox::information(this,"鹿脴脫脷","掳忙脠篓脣霉脫臑拢卢脣忙卤茫脢鹿脫脙拢卢虏禄脢脮路脩");
}

void MainWindow::on_action_MSC_triggered()
{
    insert_Dlg insert;
    insert.exec();

    if(insert.isok)
    {
        script_msg(insert.SQL.toStdString().data());
    }
}



void MainWindow::on_action_MSC_3_triggered()
{
    selectDlg select;
    select.exec();
    if(select.isok)
    {
        script_msg(select.SQL.toStdString().data());
    }
}
