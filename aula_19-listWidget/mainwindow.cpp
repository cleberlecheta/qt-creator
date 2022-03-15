#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
QVector<int> selectedItens;

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


void MainWindow::on_btn_Add_clicked()
{
    ui->listWidget->addItem(ui->lineEdit->text());
    ui->lineEdit->clear();
    ui->lineEdit->setFocus();
}


void MainWindow::on_btn_addAll_clicked()
{
    QListWidgetItem *item1 = new QListWidgetItem("C++");
    QListWidgetItem *item2 = new QListWidgetItem("Java");

    ui->listWidget->addItem(item1);
    ui->listWidget->addItem(item2);
}


void MainWindow::on_btn_select_clicked()
{
    ui->listWidget->currentItem()->setForeground(Qt::lightGray);
    ui->listWidget->currentItem()->setBackground(Qt::darkGreen);
    selectedItens.push_back(ui->listWidget->currentRow());
    qDebug() << "selected items: " << selectedItens;
}


void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->currentItem()->setForeground(Qt::black);
    ui->listWidget->currentItem()->setBackground(Qt::white);
    selectedItens.erase(selectedItens.begin() + ui->listWidget->currentRow());
    qDebug() << "selected items: " << selectedItens;
}


void MainWindow::on_pushButton_2_clicked()
{
    while (!selectedItens.empty()) {
        ui->listWidget->setCurrentRow(selectedItens.last());
        ui->listWidget->currentItem()->setForeground(Qt::black);
        ui->listWidget->currentItem()->setBackground(Qt::white);
        selectedItens.pop_back();
    }
}

