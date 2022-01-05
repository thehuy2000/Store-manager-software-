#ifndef HOADON_H
#define HOADON_H

#include <QDialog>
#include "login.h"
namespace Ui {
class HoaDon;
}

class HoaDon : public QDialog
{
    Q_OBJECT

public:
    explicit HoaDon(QWidget *parent = nullptr);
    ~HoaDon();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::HoaDon *ui;
};

#endif // HOADON_H
