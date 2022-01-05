#include "phieunhaphang.h"
#include "ui_phieunhaphang.h"
#include <QMessageBox>
PhieuNhapHang::PhieuNhapHang(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PhieuNhapHang)
{
    ui->setupUi(this);
}

PhieuNhapHang::~PhieuNhapHang()
{
    delete ui;
}

void PhieuNhapHang::on_pushButton_clicked()
{
    Login conn;
    QString idPhieu,idMH,tenSP,ngayNhap,donVi,nhaCC,donGia,sl,thanhTien;
    idPhieu = ui->lineEdit_idPhieu->text();
    idMH = ui->lineEdit_idMH->text();
    tenSP= ui->lineEdit_tenSP->text();
    ngayNhap=ui->lineEdit_ngayNhap->text();
    donVi=ui->lineEdit_donVi->text();
    nhaCC=ui->lineEdit_nhaCC->text();
    donGia=ui->lineEdit_donGia->text();
    sl=ui->lineEdit_soLuong->text();
    thanhTien = ui->lineEdit_thanhTien->text();
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into PhieuNH (ID_Phieu,ID_MH,TenSP,NgayNhap,DonVi,NhaCC,DonGia,SL,ThanhTien) values ('"+idPhieu+"','"+idMH+"','"+tenSP+"','"+ngayNhap+"','"+donVi+"','"+nhaCC+"','"+donGia+"','"+sl+"','"+donGia+"'*'"+sl+"')");
    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Thong Bao"),tr("Da Luu"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Loi..."),qry.lastError().text());
    }
}

void PhieuNhapHang::on_pushButton_2_clicked()
{
    Login conn;
    QString idPhieu,idMH,tenSP,ngayNhap,donVi,nhaCC,donGia,sl,thanhTien;
    idPhieu = ui->lineEdit_idPhieu->text();
    idMH = ui->lineEdit_idMH->text();
    tenSP= ui->lineEdit_tenSP->text();
    ngayNhap=ui->lineEdit_ngayNhap->text();
    donVi=ui->lineEdit_donVi->text();
    nhaCC=ui->lineEdit_nhaCC->text();
    donGia=ui->lineEdit_donGia->text();
    sl=ui->lineEdit_soLuong->text();
    thanhTien = ui->lineEdit_thanhTien->text();
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("update PhieuNH set ID_Phieu = '"+idPhieu+"', ID_MH = '"+idMH+"',TenSP = '"+tenSP+"',NgayNhap = '"+ngayNhap+"',DonVi='"+donVi+"',NhaCC='"+nhaCC+"',DonGia = '"+donGia+"',SL = '"+sl+"', ThanhTien='"+donGia+"'*'"+sl+"'where ID_Phieu='"+idPhieu+"'");
    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Thong Bao"),tr("Da Sua"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Loi..."),qry.lastError().text());
    }
}

void PhieuNhapHang::on_pushButton_3_clicked()
{
    Login conn;
    QString idPhieu,idMH,tenSP,ngayNhap,donVi,nhaCC,donGia,sl,thanhTien;
    idPhieu = ui->lineEdit_idPhieu->text();
    idMH = ui->lineEdit_idMH->text();
    tenSP= ui->lineEdit_tenSP->text();
    ngayNhap=ui->lineEdit_ngayNhap->text();
    donVi=ui->lineEdit_donVi->text();
    nhaCC=ui->lineEdit_nhaCC->text();
    donGia=ui->lineEdit_donGia->text();
    sl=ui->lineEdit_soLuong->text();
    thanhTien = ui->lineEdit_thanhTien->text();
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Delete from PhieuNH where ID_Phieu ='"+idPhieu+"'");
    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Thong Bao"),tr("Da Xoa"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Loi..."),qry.lastError().text());
    }
}

void PhieuNhapHang::on_pushButton_4_clicked()
{
    Login conn;
    QSqlQueryModel *modal= new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery *qry = new QSqlQuery(conn.mydb);
    qry->prepare("Select * from PhieuNH");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
    qDebug()<< (modal->rowCount());
}

void PhieuNhapHang::on_tableView_activated(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString();
    Login conn;
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Select * from PhieuNH where ID_Phieu ='"+val+"'or ID_MH ='"+val+"' or TenSP ='"+val+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_idPhieu->setText(qry.value(0).toString());
            ui->lineEdit_idMH->setText(qry.value(1).toString());
            ui->lineEdit_tenSP->setText(qry.value(2).toString());
            ui->lineEdit_ngayNhap->setText(qry.value(3).toString());
            ui->lineEdit_donVi->setText(qry.value(2).toString());
            ui->lineEdit_nhaCC->setText(qry.value(2).toString());
            ui->lineEdit_donGia->setText(qry.value(4).toString());
            ui->lineEdit_soLuong->setText(qry.value(5).toString());
            ui->lineEdit_thanhTien->setText(qry.value(6).toString());
        }
    conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Loi..."),qry.lastError().text());
    }
}
