#ifndef SCRIPTDLG_H
#define SCRIPTDLG_H

#include <QDialog>

namespace Ui {
class scriptDlg;
}

class scriptDlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit scriptDlg(QWidget *parent = 0);
    ~scriptDlg();
    QString SQL;
    bool islogin;
private:
    Ui::scriptDlg *ui;
private slots:
    void okBtnClick();
    void cancelBtnClick();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // SCRIPTDLG_H
