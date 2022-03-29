#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_actionAbrir_triggered();

    void on_actionNovo_triggered();

    void on_actionSalvar_Novo_triggered();

    void on_actionSlavar_triggered();

    void on_actionFechar_triggered();

    void on_actionCopiar_triggered();

    void on_actionRecortar_triggered();

    void on_actionColar_triggered();

    void on_actionDesfazer_triggered();

private:
    Ui::MainWindow *ui;
    QString file_place;
};
#endif // MAINWINDOW_H
