#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <QDialog>
#include "login.h"
namespace Ui {
class Nhanvien;
}

class Nhanvien : public QDialog
{
    Q_OBJECT

public:
    explicit Nhanvien(QWidget *parent = nullptr);
    ~Nhanvien();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_5_clicked();

private:
    Ui::Nhanvien *ui;
};

#endif // NHANVIEN_H
