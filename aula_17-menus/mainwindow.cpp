#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dialog.h"
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


void MainWindow::on_actionNovo_triggered()
{
    Dialog d_novo;
    d_novo.exec();
}

void MainWindow::on_actionSalvar_triggered()
{
    QMessageBox::information(this, "Salvador", "Jesus!");
}


void MainWindow::on_actionSair_triggered()
{
    //close();
    QApplication::quit();
}

