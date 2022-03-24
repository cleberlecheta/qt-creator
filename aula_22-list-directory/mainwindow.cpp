#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QMessageBox>

QString dir_folder = "/home";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDir local_places;
    foreach(QFileInfo qfi, local_places.drives()) {
        ui->comboBox->addItem(qfi.absolutePath());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->listWidget->clear();
    QDir list_dir(arg1);
    foreach(QFileInfo qfi, list_dir.entryInfoList()) {
        if (qfi.isDir()) {
            ui->listWidget->addItem(qfi.absoluteFilePath());
        } /*else if (qfi.isFile()) {
            ui->listWidget->addItem("File: " + qfi.absoluteFilePath());
        }*/
    }
}


void MainWindow::on_pushButton_clicked()
{
    QString place = ui->listWidget->currentItem()->text();
    QString file = "/" + ui->lineEdit->text();
    QDir directory(place + file);
    if (directory.exists()) {
        QMessageBox::about(this, "Diretório já existe", place + file);
    } else {
        directory.mkdir(place + file); //HERE

        ui->listWidget->clear();
        ui->listWidget->addItem(ui->comboBox->currentText());
        QDir list_dir(ui->comboBox->currentText());
        foreach(QFileInfo qfi, list_dir.entryInfoList()) {
            if (qfi.isDir()) {
                ui->listWidget->addItem(qfi.absoluteFilePath());
            }
        }
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    QString place = ui->listWidget->currentItem()->text();
    QString file = "/" + ui->lineEdit->text();
    QDir directory(place + file);
    if (!directory.exists()) {
        QMessageBox::about(this, "Diretório NÃO existe", place + file);
    } else {
        directory.rmdir(place + file); //AND HERE

        ui->listWidget->clear();
        ui->listWidget->addItem(ui->comboBox->currentText());
        QDir list_dir(ui->comboBox->currentText());
        foreach(QFileInfo qfi, list_dir.entryInfoList()) {
            if (qfi.isDir()) {
                ui->listWidget->addItem(qfi.absoluteFilePath());
            }
        }
    }
}

