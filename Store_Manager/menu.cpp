#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_nhanVien_clicked()
{
    Nhanvien *nv;
    nv = new Nhanvien(this);
    nv->show();
}

void Menu::on_pushButton_khachHang_clicked()
{
    khachhang *khach;
    khach = new khachhang(this);
    khach->show();
}

void Menu::on_pushButton_HoaDon_clicked()
{
    HoaDon *hd;
    hd = new HoaDon(this);
    hd->show();
}

void Menu::on_pushButton_PhieuNH_clicked()
{
    PhieuNhapHang *phieuNH;
    phieuNH = new PhieuNhapHang(this);
    phieuNH->show();
}

void Menu::on_pushButton_HangTK_clicked()
{
    HangTK *hangtk;
    hangtk = new HangTK(this);
    hangtk->show();
}
