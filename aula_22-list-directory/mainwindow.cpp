#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
QString dir_folder = "/home/c33byz/git/qt-creator/aula_22-list-directory";

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
            ui->listWidget->addItem("Dir.: " + qfi.absoluteFilePath());
        } else if (qfi.isFile()) {
            ui->listWidget->addItem("File: " + qfi.absoluteFilePath());
        }
    }
}

