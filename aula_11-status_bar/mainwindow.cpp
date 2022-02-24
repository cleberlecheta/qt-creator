#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Curso C++");
    ui->statusbar->addPermanentWidget(ui->pushButton_2);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->statusbar->showMessage(
                "Nome: " + ui->txtName->text() +
                " | " +
                "E-mail: " + ui->txtMail->text());
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->statusbar->showMessage("Uma nova velha onda");
    QMessageBox::about(this, "Curso C++", "Uma nova velha onda");
}

