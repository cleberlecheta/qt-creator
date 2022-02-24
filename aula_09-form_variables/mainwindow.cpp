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


void MainWindow::on_pushButton_4_clicked()
{
    QString name = ui->txtNome->text();
    QString phone = ui->txtTel->text();
    QString mail = ui->txtMail->text();

    QMessageBox::information(this, "Dados cadastrais", "Nome: " + name + "\nTelefone: " + phone + "\nE-mail: " + mail);
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->txtNome->clear();
    ui->txtTel->clear();
    ui->txtMail->clear();

    ui->txtNome->setFocus();
}

