#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap driveImg("/opt/118690_drive_512x512.png");
    ui->label_via_codigo->setPixmap(driveImg.scaled(512, 512, Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

