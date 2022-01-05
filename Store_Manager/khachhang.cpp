#include "khachhang.h"
#include "ui_khachhang.h"
#include<QMessageBox>
khachhang::khachhang(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::khachhang)
{
    ui->setupUi(this);
}

khachhang::~khachhang()
{
    delete ui;
}

void khachhang::on_pushButton_clicked()
{
    Login conn;
    QString idKH,ten,tuoi,sdt,gioiTinh;
    idKH = ui->lineEdit_idKH->text();
    ten= ui->lineEdit_ten->text();
    tuoi=ui->lineEdit_tuoi->text();
    sdt=ui->lineEdit_sdt->text();
    gioiTinh=ui->lineEdit_gioiTinh->text();
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into KhachHang (ID_KH,Ten,Tuoi,GioiTinh,Sdt) values ('"+idKH+"','"+ten+"','"+tuoi+"','"+sdt+"','"+gioiTinh+"')");
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

void khachhang::on_pushButton_2_clicked()
{
    Login conn;
    QString idKH,ten,tuoi,sdt,gioiTinh,ngayVL;
    idKH = ui->lineEdit_idKH->text();
    ten= ui->lineEdit_ten->text();
    tuoi=ui->lineEdit_tuoi->text();
    sdt=ui->lineEdit_sdt->text();
    gioiTinh=ui->lineEdit_gioiTinh->text();
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("update KhachHang set ID_KH = '"+idKH+"', Ten = '"+ten+"',Tuoi = '"+tuoi+"',Sdt = '"+sdt+"',GioiTinh = '"+gioiTinh+"'where ID_KH='"+idKH+"'");
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

void khachhang::on_pushButton_3_clicked()
{
    Login conn;
    QString idKH,ten,tuoi,sdt,gioiTinh,ngayVL;
    idKH = ui->lineEdit_idKH->text();
    ten= ui->lineEdit_ten->text();
    tuoi=ui->lineEdit_tuoi->text();
    sdt=ui->lineEdit_sdt->text();
    gioiTinh=ui->lineEdit_gioiTinh->text();
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Delete from NhanVien where ID_NV ='"+idKH+"'");
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

void khachhang::on_pushButton_5_clicked()
{
    Login conn;
    QSqlQueryModel *modal= new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery *qry = new QSqlQuery(conn.mydb);
    qry->prepare("Select * from KhachHang");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
    qDebug()<< (modal->rowCount());
}



void khachhang::on_tableView_activated(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString();
    Login conn;
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Select * from KhachHang where ID_KH ='"+val+"'or Ten ='"+val+"'or Tuoi ='"+val+"'or GioiTinh ='"+val+"'or Sdt ='"+val+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_idKH->setText(qry.value(0).toString());
            ui->lineEdit_ten->setText(qry.value(1).toString());
            ui->lineEdit_tuoi->setText(qry.value(2).toString());
            ui->lineEdit_gioiTinh->setText(qry.value(3).toString());
            ui->lineEdit_sdt->setText(qry.value(4).toString());

        }
    conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Loi..."),qry.lastError().text());
    }
}
