#include "mainwindow.h"
#include "ui_mainwindow.h"

/* método 1 - por include local
#include "newwindow.h"
*/

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
    /* método 1 - por include local
    NewWindow nw2;
    nw2.exec();
    */
    nw2 = new NewWindow(this);
    nw2->show();
}

