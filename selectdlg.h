#ifndef SELECTDLG_H
#define SELECTDLG_H

#include <QDialog>

namespace Ui {
class selectDlg;
}

class selectDlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit selectDlg(QWidget *parent = 0);
    ~selectDlg();
    QString SQL;
    bool isok;
    
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::selectDlg *ui;
};

#endif // SELECTDLG_H
