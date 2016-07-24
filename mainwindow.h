#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <logindlg.h>
#include <QCloseEvent>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QStandardItemModel>
#include <QTableView>
#include <scriptdlg.h>
#include <mymysql.h>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showsub();


private slots:
    void on_action_login_triggered();

    void on_action_logout_triggered();

    void on_action_12_triggered();

    void cengdieWindow();

    void binglieWindow();


    void on_action_14_triggered();

    void on_action_15_triggered();

    void on_action_2_triggered();

    void on_action_triggered();

    void on_action_MSC_triggered();

    void on_action_MSC_3_triggered();

private:
    Ui::MainWindow *ui;

    void closeEvent(QCloseEvent *event);
    QMdiArea *mdiarea;
    void showView();
    mymysql db;
    void script_msg(const char *SQL);

};

#endif // MAINWINDOW_H
