#include "mainwindow.h"
#include "saisiematrice.h"
#include "matriceinverse.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow fenetrePrincipale;
    fenetrePrincipale.setFixedSize(400, 600);
    fenetrePrincipale.setWindowTitle("Calculatrice Matricielle");
    fenetrePrincipale.show();


    return a.exec();
}
