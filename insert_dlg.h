#ifndef INSERT_DLG_H
#define INSERT_DLG_H

#include <QDialog>

namespace Ui {
class insert_Dlg;
}

class insert_Dlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit insert_Dlg(QWidget *parent = 0);
    ~insert_Dlg();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

public:
    Ui::insert_Dlg *ui;
    QString SQL;
    bool isok;
};

#endif // INSERT_DLG_H
