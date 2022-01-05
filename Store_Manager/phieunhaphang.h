#ifndef PHIEUNHAPHANG_H
#define PHIEUNHAPHANG_H

#include <QDialog>
#include"login.h"
namespace Ui {
class PhieuNhapHang;
}

class PhieuNhapHang : public QDialog
{
    Q_OBJECT

public:
    explicit PhieuNhapHang(QWidget *parent = nullptr);
    ~PhieuNhapHang();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::PhieuNhapHang *ui;
};

#endif // PHIEUNHAPHANG_H
