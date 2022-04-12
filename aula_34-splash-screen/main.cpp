#include "mainwindow.h"
#include <QApplication>

#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen *telaSplash = new QSplashScreen;
    telaSplash->setPixmap(QPixmap("/home/c33byz/dev/qt-creator/aula_34-splash-screen/mainwindow.ui/teclado.jpg"));
    telaSplash->show();

    MainWindow w; 
    QTimer::singleShot(5000, telaSplash, SLOT(close()));
    QTimer::singleShot(5000, &w, SLOT(show()));
    //w.show();

    return a.exec();
}
