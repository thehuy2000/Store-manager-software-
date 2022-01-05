#include "nhanvien.h"
#include "ui_nhanvien.h"
#include<QMessageBox>

Nhanvien::Nhanvien(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nhanvien)
{
    ui->setupUi(this);
}

Nhanvien::~Nhanvien()
{
    delete ui;
}

void Nhanvien::on_pushButton_clicked()
{
    Login conn;
    QString idNV,ten,tuoi,sdt,gioiTinh,ngayVL;
    idNV = ui->lineEdit_idNV->text();
    ten= ui->lineEdit_ten->text();
    tuoi=ui->lineEdit_tuoi->text();
    sdt=ui->lineEdit_sdt->text();
    gioiTinh=ui->lineEdit_gioiTinh->text();
    ngayVL = ui->lineEdit_NVL->text();
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into NhanVien (ID_NV,Ten,Tuoi,GioiTinh,Sdt,NgayVaoLam) values ('"+idNV+"','"+ten+"','"+tuoi+"','"+sdt+"','"+gioiTinh+"','"+ngayVL+"')");
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

void Nhanvien::on_pushButton_2_clicked()
{
    Login conn;
    QString idNV,ten,tuoi,sdt,gioiTinh,ngayVL;
    idNV = ui->lineEdit_idNV->text();
    ten= ui->lineEdit_ten->text();
    tuoi=ui->lineEdit_tuoi->text();
    sdt=ui->lineEdit_sdt->text();
    gioiTinh=ui->lineEdit_gioiTinh->text();
    ngayVL = ui->lineEdit_NVL->text();
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("update NhanVien set ID_NV = '"+idNV+"', Ten = '"+ten+"',Tuoi = '"+tuoi+"',Sdt = '"+sdt+"',GioiTinh = '"+gioiTinh+"',NgayVaoLam = '"+ngayVL+"'where ID_NV='"+idNV+"'");
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

void Nhanvien::on_pushButton_3_clicked()
{
    Login conn;
    QString idNV,ten,tuoi,sdt,gioiTinh,ngayVL;
    idNV = ui->lineEdit_idNV->text();
    ten= ui->lineEdit_ten->text();
    tuoi=ui->lineEdit_tuoi->text();
    sdt=ui->lineEdit_sdt->text();
    gioiTinh=ui->lineEdit_gioiTinh->text();
    ngayVL = ui->lineEdit_NVL->text();
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Delete from NhanVien where ID_NV ='"+idNV+"'");
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

void Nhanvien::on_pushButton_4_clicked()
{
    Login conn;
    QSqlQueryModel *modal= new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery *qry = new QSqlQuery(conn.mydb);
    qry->prepare("Select * from NhanVien");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
    qDebug()<< (modal->rowCount());
}

void Nhanvien::on_tableView_activated(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString();
    Login conn;
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Select * from NhanVien where ID_NV ='"+val+"'or Ten ='"+val+"'or Tuoi ='"+val+"'or GioiTinh ='"+val+"'or Sdt ='"+val+"'or NgayVaoLam ='"+val+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_idNV->setText(qry.value(0).toString());
            ui->lineEdit_ten->setText(qry.value(1).toString());
            ui->lineEdit_tuoi->setText(qry.value(2).toString());
            ui->lineEdit_gioiTinh->setText(qry.value(3).toString());
            ui->lineEdit_sdt->setText(qry.value(4).toString());
            ui->lineEdit_NVL->setText(qry.value(5).toString());
        }
    conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Loi..."),qry.lastError().text());
    }
}

QString escapedCSV(QString unexc)
{
    if (!unexc.contains(QLatin1Char(',')))
        return unexc;
    return '\"' + unexc.replace(QLatin1Char('\"'), QStringLiteral("\"\"")) + '\"';
}

void queryToCsv()
{
    Login conn;
    conn.connOpen();
    QSqlQuery query;
    query.prepare(" select * from NhanVien");
    QFile csvFile ("nhanVien.csv");
    if (!csvFile.open(QFile::WriteOnly | QFile::Text)){
        qDebug("failed to open csv file");
        return;
    }
    if (!query.exec()){
        qDebug("failed to run query");
        return;
    }
    QTextStream outStream(&csvFile);
    outStream.setCodec("UTF-8");
    while (query.next()){
        const QSqlRecord record = query.record();
        for (int i=0, recCount = record.count() ; i<recCount ; ++i){
            if (i>0)
                outStream << ',';
            outStream << escapedCSV(record.value(i).toString());
        }
        outStream << '\n';
    }
}

void Nhanvien::on_pushButton_5_clicked()
{
    queryToCsv();
}
