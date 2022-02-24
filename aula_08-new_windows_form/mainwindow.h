#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

/* método 2 - include global */
#include "newwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    /* método 2 - include global */
    NewWindow *nw2;
};
#endif // MAINWINDOW_H
