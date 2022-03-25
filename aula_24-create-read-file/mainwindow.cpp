#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>

QString local = "/tmp/";
QString nome = "aula_24.txt";

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


void MainWindow::on_btnSave_clicked()
{
    QFile arquivo(local + nome);
    if (!arquivo.open(QFile::WriteOnly|QFile::Text)) { //Append
        QMessageBox::warning(this, "ERRO", "Erro ao abrir o arquivo");
    } else {
        QTextStream saida(&arquivo);
        QString texto = ui->plainTextEdit->toPlainText();

        saida << texto;
        arquivo.flush();
        arquivo.close();

        ui->plainTextEdit->clear();
    }
}


void MainWindow::on_btnRead_clicked()
{
    QFile arquivo(local + nome);
    if (!arquivo.open(QFile::ReadOnly|QFile::Text)) {
        QMessageBox::warning(this, "ERRO", "Erro ao abrir o arquivo");
    } else {
        QTextStream entrada(&arquivo);
        QString texto = entrada.readAll();

        ui->plainTextEdit->setPlainText(texto);
        arquivo.close();
    }
}


void MainWindow::on_pushButton_clicked()
{
    //Caixa de abertura de arquivo
    QString filter = "All Files (*.*) ;; Text Files (*.txt)";
    QString openFile = QFileDialog::getOpenFileName(this, "Open files", "/home/c33byz/", filter);
    QFile file(openFile);

    if (!file.open(QFile::ReadOnly|QFile::Text)) {
        QMessageBox::warning(this, "ERRO", "Erro ao abrir o arquivo");
    }

    QTextStream entrada(&file);
    QString texto = entrada.readAll();

    ui->plainTextEdit->setPlainText(texto);
    file.close();
}

