#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), SLOT(changeText()));
}

void MainWindow::changeText() {
    ui->label->setText("Curso C++");
}

MainWindow::~MainWindow()
{
    delete ui;
}

