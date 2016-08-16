#include "multmatricescalaire.h"
#include "ui_multmatricescalaire.h"

#include "transposee.h"
#include "ui_transposee.h"

#include "trace.h"
#include "ui_trace.h"

#include "norme.h"
#include "ui_norme.h"
#include "puissance.h"
#include "ui_puissance.h"
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

MultMatriceScalaire::MultMatriceScalaire(Conteneur &conteneur, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MultMatriceScalaire),
    m_conteneur(conteneur)
{
    ui->setupUi(this);
}

MultMatriceScalaire::~MultMatriceScalaire()
{
    delete ui;
}

void MultMatriceScalaire::on_calculerMultMatriceScalaire_clicked()
{
    Matrice matriceChMultScal = m_conteneur.RecupererMatrice(ui->choixMatriceMultScal->currentText().toStdString());

    Matrice matriceMultScal(matriceChMultScal.getLigne(), matriceChMultScal.getColonne());

    float a = ui->choixScalaire->value();
    matriceMultScal = matriceChMultScal.produitMatriceScalaire(a);


    int i, j;

    ui->m_multMatriceScalaire->setRowCount(matriceMultScal.getLigne());
    ui->m_multMatriceScalaire->setColumnCount(matriceMultScal.getColonne());


    for (i=0; i<matriceMultScal.getLigne(); i++)
    {

        for (j=0; j<matriceMultScal.getColonne(); j++)
        {
            QTableWidgetItem *caseTab = new QTableWidgetItem(QString::number(matriceMultScal.getCoefficient(i, j)));

            ui -> m_multMatriceScalaire ->setItem(i, j, caseTab);
        }
    }

    m_conteneur.RecupererMatrice(ui->matriceResultProdMatriceScal->currentText().toStdString()) = matriceMultScal;
}
