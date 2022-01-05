#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}


void Login::on_pushButton_clicked()
{
    QString username, password;
    username = ui->lineEdit_username->text();
    password= ui->lineEdit_password->text();
//    if(!connOpen())
//    {
//        return;
//    }
    connOpen();
    QSqlQuery qry;
    qry.prepare("select * from DangNhap where taiKhoan ='"+username+"' and matKhau ='"+password+"'");
    if(qry.exec())
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if(count ==1 ){
            //ui->label->setText("Tai Khoan, mk dung");
            connClose();
            this->hide();
            Menu menu;
            menu.setModal(true);
            menu.exec();
        }
        if(count !=1) ui->label->setText("Tai Khoan va mat khau khong dung!");
    }
}
