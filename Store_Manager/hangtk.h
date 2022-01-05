#ifndef HANGTK_H
#define HANGTK_H

#include <QDialog>
#include "login.h"
namespace Ui {
class HangTK;
}

class HangTK : public QDialog
{
    Q_OBJECT

public:
    explicit HangTK(QWidget *parent = nullptr);
    ~HangTK();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::HangTK *ui;
};

#endif // HANGTK_H
