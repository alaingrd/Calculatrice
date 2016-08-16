#include "ouvrirmatrice.h"
#include "ui_ouvrirmatrice.h"

#include "matriceinverse.h"
#include "ui_matriceinverse.h"

#include "determinant.h"
#include "ui_determinant.h"
#include "operation.h"
#include "ui_operation.h"
#include "matrice.h"
#include "gerermatrice.h"
#include "ui_gerermatrice.h"
#include "conteneur.h"
#include "saisiematrice.h"
#include "ui_saisiematrice.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTableWidget"
#include "multmatricescalaire.h"
#include "ui_multmatricescalaire.h"

OuvrirMatrice::OuvrirMatrice(Conteneur &conteneur, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OuvrirMatrice),
    m_conteneur(conteneur)
{
    ui->setupUi(this);
}

OuvrirMatrice::~OuvrirMatrice()
{
    delete ui;
}

void OuvrirMatrice::on_ourvirMatrice_clicked()
{

    Matrice ouverteMatrice = m_conteneur.RecupererMatrice(ui->choixMatriceOuvrir->currentText().toStdString());

    ouverteMatrice.ouvrirMatrice(ui->choixMatriceOuvrir->currentText().toStdString());

    int i, j;

    ui->m_ouverture->setRowCount(ouverteMatrice.getLigne());
    ui->m_ouverture->setColumnCount(ouverteMatrice.getColonne());


    for (i=0; i<ouverteMatrice.getLigne(); i++)
    {

        for (j=0; j<ouverteMatrice.getColonne(); j++)
        {
            QTableWidgetItem *caseTab = new QTableWidgetItem(QString::number(ouverteMatrice.getCoefficient(i, j)));

            ui -> m_ouverture ->setItem(i, j, caseTab);
        }
    }


}
