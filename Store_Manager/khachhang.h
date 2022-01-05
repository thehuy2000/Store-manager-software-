#ifndef KHACHHANG_H
#define KHACHHANG_H

#include <QDialog>
#include "login.h"
namespace Ui {
class khachhang;
}

class khachhang : public QDialog
{
    Q_OBJECT

public:
    explicit khachhang(QWidget *parent = nullptr);
    ~khachhang();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::khachhang *ui;
};

#endif // KHACHHANG_H
