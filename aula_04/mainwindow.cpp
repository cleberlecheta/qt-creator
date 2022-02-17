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
    QMessageBox::about(this, "Curso C++", "Aprendendo QT Creator");
}


void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::aboutQt(this, "Curso C++");
}


void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::critical(this, "Curso C++", "Falha geral no sistema");
}


void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox::information(this, "Curso C++", "Keep on moving!");
}


void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox::question(this, "Curso C++", "Have you get there?");
}


void MainWindow::on_pushButton_6_clicked()
{
    QMessageBox::warning(this, "Curso C++", "Be safe, keep on the Way.");
}

