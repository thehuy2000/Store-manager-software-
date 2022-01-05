#include "hangtk.h"
#include "ui_hangtk.h"
#include<QMessageBox>
HangTK::HangTK(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HangTK)
{
    ui->setupUi(this);
}

HangTK::~HangTK()
{
    delete ui;
}

void HangTK::on_pushButton_clicked()
{
    Login conn;
    QString idMH,tenSP,nhaCC,donGia,sl,ghiChu;
    idMH = ui->lineEdit_idMH->text();
    tenSP= ui->lineEdit_tenSP->text();
    nhaCC=ui->lineEdit_nhaCC->text();
    donGia=ui->lineEdit_donGia->text();
    sl=ui->lineEdit_sl->text();
    ghiChu = ui->lineEdit_ghiChu->text();
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into HangTonKho (ID_MH,TenSP,NhaCC,DonGia,SL,GhiChu) values ('"+idMH+"','"+tenSP+"','"+nhaCC+"','"+donGia+"','"+sl+"','"+ghiChu+"')");
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

void HangTK::on_pushButton_2_clicked()
{

    Login conn;
    QString idMH,tenSP,nhaCC,donGia,sl,ghiChu;
    idMH = ui->lineEdit_idMH->text();
    tenSP= ui->lineEdit_tenSP->text();
    nhaCC=ui->lineEdit_nhaCC->text();
    donGia=ui->lineEdit_donGia->text();
    sl=ui->lineEdit_sl->text();
    ghiChu = ui->lineEdit_ghiChu->text();
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("update HangTonKho set ID_MH = '"+idMH+"', TenSP = '"+tenSP+"',NhaCC = '"+nhaCC+"',DonGia = '"+donGia+"',SL= '"+sl+"',GhiChu = '"+ghiChu+"'where ID_MH='"+idMH+"'");
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

void HangTK::on_pushButton_3_clicked()
{

    Login conn;
    QString idMH,tenSP,nhaCC,donGia,sl,ghiChu;
    idMH = ui->lineEdit_idMH->text();
    tenSP= ui->lineEdit_tenSP->text();
    nhaCC=ui->lineEdit_nhaCC->text();
    donGia=ui->lineEdit_donGia->text();
    sl=ui->lineEdit_sl->text();
    ghiChu = ui->lineEdit_ghiChu->text();
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Delete from HangTonKho where ID_MH ='"+idMH+"'");
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

void HangTK::on_pushButton_4_clicked()
{
    Login conn;
    QSqlQueryModel *modal= new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery *qry = new QSqlQuery(conn.mydb);
    qry->prepare("Select * from HangTonKho");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
    qDebug()<< (modal->rowCount());
}

void HangTK::on_tableView_activated(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString();
    Login conn;
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Select * from HangTonKho where ID_MH ='"+val+"'or TenSP ='"+val+"'or NhaCC='"+val+"'or DonGia ='"+val+"'or SL ='"+val+"'or GhiChu ='"+val+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_idMH->setText(qry.value(0).toString());
            ui->lineEdit_tenSP->setText(qry.value(1).toString());
            ui->lineEdit_nhaCC->setText(qry.value(2).toString());
            ui->lineEdit_donGia->setText(qry.value(3).toString());
            ui->lineEdit_sl->setText(qry.value(4).toString());
            ui->lineEdit_ghiChu->setText(qry.value(5).toString());
        }
    conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Loi..."),qry.lastError().text());
    }
}
