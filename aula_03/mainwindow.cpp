#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Mannualy-programatically close the form
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    close();
}


void MainWindow::on_pushButton_4_clicked()
{
    QString css = "background-color:#f00; color:#000;";
    ui->label->setStyleSheet(css);
}

