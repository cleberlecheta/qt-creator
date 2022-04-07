#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>
#include <QDateTime>

int cont = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tempo = new QTimer(this);
    connect(tempo, SIGNAL(timeout()), this, SLOT(printToConsole()));
    tempo->start(1000);

    relogio = new QTimer(this);
    connect(relogio, SIGNAL(timeout()), this, SLOT(atualizarRelogio()));
    relogio->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printToConsole() {
    cont++;
    qDebug() << cont << "Segundos";
}

void MainWindow::atualizarRelogio() {
    QTime tempoAtual = QTime::currentTime();
    QString tempoText = tempoAtual.toString("hh:mm:ss");
    ui->label->setText(tempoText);
}
