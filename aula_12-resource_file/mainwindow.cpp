#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap keybordImg(":/imgs/assets_img/IMG_20220212_181836062.jpg");
    ui->label->setPixmap(keybordImg);
}

MainWindow::~MainWindow()
{
    delete ui;
}

