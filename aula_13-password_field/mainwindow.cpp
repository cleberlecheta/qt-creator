#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();

    if (username == password) {
        QMessageBox::information(this, "Login", "OK");
        sw2 = new SystemWindow(this);
        sw2->show();
    } else {
        QMessageBox::warning(this, "Login", "Usuário ou senha inválidos");
    }
}

