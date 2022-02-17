#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QtDebug>

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
    QMessageBox::StandardButton answer = QMessageBox::question(this, "", "Deseja fechar o programa?", QMessageBox::Yes | QMessageBox::No);
    if(answer == QMessageBox::Yes) {
        QApplication::quit();
    } else {
        qDebug() << "programa não foi encerrado";
        QMessageBox::about(this, "", "programa não foi encerrado");
    }
}

