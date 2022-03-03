#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

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
    QString msg, cor, transp, prog;
    msg = "";
    int ntransp = 0;

    if (ui->rbRed->isChecked()) {
        cor = "Vermelho";
    } else if (ui->rbGreen->isChecked()) {
        cor = "Verde";
    } else if (ui->rbBlue->isChecked()) {
        cor = "Azul";
    }

    if (ui->rbPlane->isChecked()) {
        ntransp = 1;
    } else if (ui->rbCar->isChecked()) {
        ntransp = 2;
    } else if (ui->rbShip->isChecked()) {
        ntransp = 3;
    }
    switch (ntransp) {
        case 1:
            transp = "Avião";
        break;
        case 2:
            transp = "Carro";
        break;
        case 3:
            transp = "Navio";
        break;
        default:
            transp = "Nenhum";
        break;
    }

    QVector<bool> pro;
    pro.push_back(ui->rbC->isChecked());
    pro.push_back(ui->rbCSharp->isChecked());
    pro.push_back(ui->rbJava->isChecked());
    if (pro[0]) {
        prog = "C++";
    }
    if (pro[1]) {
        prog = "C#";
    }
    if (pro[2]) {
        prog = "Java!";
    }

    msg = cor + "\n" + transp + "\n" + prog;
    QMessageBox::information(this, "QTCreator - Radio Button", msg);
}

