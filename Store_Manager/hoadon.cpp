#include "hoadon.h"
#include "ui_hoadon.h"
#include<QMessageBox>
HoaDon::HoaDon(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HoaDon)
{
    ui->setupUi(this);
}

HoaDon::~HoaDon()
{
    delete ui;
}

void HoaDon::on_pushButton_clicked()
{
    Login conn;
    QString idHD,idMH,tenSP,donGia,sl,thanhTien,ngayMua;
    idHD = ui->lineEdit_idHD->text();
    idMH = ui->lineEdit_idMH->text();
    tenSP= ui->lineEdit_tenSP->text();
    donGia=ui->lineEdit_donGia->text();
    sl=ui->lineEdit_sl->text();
    ngayMua=ui->lineEdit_ngayMua->text();
    thanhTien = ui->lineEdit_thanhTien->text();
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into HoaDon (ID_HD,ID_MH,TenSP,NgayMua,DonGia,SL,ThanhTien) values ('"+idHD+"','"+idMH+"','"+tenSP+"','"+ngayMua+"','"+donGia+"','"+sl+"','"+donGia+"'*'"+sl+"')");
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

void HoaDon::on_pushButton_2_clicked()
{
    Login conn;
    QString idHD,idMH,tenSP,donGia,sl,thanhTien,ngayMua;
    idHD = ui->lineEdit_idHD->text();
    idMH = ui->lineEdit_idMH->text();
    tenSP= ui->lineEdit_tenSP->text();
    donGia=ui->lineEdit_donGia->text();
    sl=ui->lineEdit_sl->text();
    ngayMua=ui->lineEdit_ngayMua->text();
    thanhTien = ui->lineEdit_thanhTien->text();
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("update HoaDon set ID_HD = '"+idHD+"', ID_MH = '"+idMH+"',TenSP = '"+tenSP+"',NgayMua = '"+ngayMua+"',DonGia = '"+donGia+"',SL = '"+sl+"', ThanhTien='"+thanhTien+"'where ID_HD='"+idHD+"'");
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

void HoaDon::on_pushButton_3_clicked()
{
    Login conn;
    QString idHD,idMH,tenSP,donGia,sl,thanhTien,ngayMua;
    idHD = ui->lineEdit_idHD->text();
    idMH = ui->lineEdit_idMH->text();
    tenSP= ui->lineEdit_tenSP->text();
    donGia=ui->lineEdit_donGia->text();
    sl=ui->lineEdit_sl->text();
    ngayMua=ui->lineEdit_ngayMua->text();
    thanhTien = ui->lineEdit_thanhTien->text();
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Delete from HoaDon where ID_HD ='"+idHD+"'");
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

void HoaDon::on_pushButton_4_clicked()
{
    Login conn;
    QSqlQueryModel *modal= new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery *qry = new QSqlQuery(conn.mydb);
    qry->prepare("Select * from HoaDon");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
    qDebug()<< (modal->rowCount());
}

void HoaDon::on_tableView_activated(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString();
    Login conn;
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Select * from HoaDon where ID_NV ='"+val+"'or Ten ='"+val+"'or Tuoi ='"+val+"'or GioiTinh ='"+val+"'or Sdt ='"+val+"'or NgayVaoLam ='"+val+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_idHD->setText(qry.value(0).toString());
            ui->lineEdit_idMH->setText(qry.value(1).toString());
            ui->lineEdit_tenSP->setText(qry.value(2).toString());
            ui->lineEdit_ngayMua->setText(qry.value(3).toString());
            ui->lineEdit_donGia->setText(qry.value(4).toString());
            ui->lineEdit_sl->setText(qry.value(5).toString());
            ui->lineEdit_thanhTien->setText(qry.value(6).toString());
        }
    conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Loi..."),qry.lastError().text());
    }
}
