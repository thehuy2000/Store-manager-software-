#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "nhanvien.h"
#include "khachhang.h"
#include "hoadon.h"
#include "phieunhaphang.h"
#include "hangtk.h"
namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_pushButton_nhanVien_clicked();

    void on_pushButton_khachHang_clicked();

    void on_pushButton_HoaDon_clicked();

    void on_pushButton_PhieuNH_clicked();

    void on_pushButton_HangTK_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
