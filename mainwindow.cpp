#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "saisiematrice.h"
#include "gerermatrice.h"
#include "conteneur.h"
#include "operation.h"
#include "determinant.h"
#include "matriceinverse.h"
#include "puissance.h"
#include "norme.h"
#include "trace.h"
#include "transposee.h"
#include "multmatricescalaire.h"
#include "enregistrermatrice.h"
#include "ouvrirmatrice.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SaisieMatrice_clicked()
{
    SaisieMatrice mainwindow(conteneur, this);
    mainwindow.exec();
}

void MainWindow::on_gerermatrice_clicked()
{
    GererMatrice mainwindow(conteneur, this);
    mainwindow.exec();
}


void MainWindow::on_faireOperation_clicked()
{
    Operation mainwindow(conteneur, this);
    mainwindow.exec();
}

void MainWindow::on_calculerDeterminant_clicked()
{
    Determinant mainwindow(conteneur, this);
    mainwindow.exec();
}

void MainWindow::on_determinerMatriceInverse_clicked()
{
    MatriceInverse mainwindow(conteneur, this);
    mainwindow.exec();
}

void MainWindow::on_calculerPuissance_clicked()
{
    Puissance mainwindow(conteneur, this);
    mainwindow.exec();
}

void MainWindow::on_calculerNorme_clicked()
{
    Norme mainwindow(conteneur, this);
    mainwindow.exec();
}

void MainWindow::on_calculerTrace_clicked()
{
    Trace mainwindow(conteneur, this);
    mainwindow.exec();
}

void MainWindow::on_calculerTranspose_clicked()
{
    Transposee mainwindow(conteneur, this);
    mainwindow.exec();
}

void MainWindow::on_multMatriceScal_clicked()
{
    MultMatriceScalaire mainwindow(conteneur, this);
    mainwindow.exec();
}

void MainWindow::on_enregisterMatriceFichier_clicked()
{
    EnregistrerMatrice mainwindow(conteneur, this);
    mainwindow.exec();
}

void MainWindow::on_ouvrireMatriceFichier_clicked()
{
    OuvrirMatrice mainwindow(conteneur, this);
    mainwindow.exec();
}
