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

Transposee::Transposee(Conteneur &conteneur, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Transposee),
    m_conteneur(conteneur)
{
    ui->setupUi(this);
}

Transposee::~Transposee()
{
    delete ui;
}

void Transposee::on_calculerMatriceTransposee_clicked()
{
    Matrice matriceChTransposee = m_conteneur.RecupererMatrice(ui->choixMatriceChTransposee->currentText().toStdString());

    Matrice matriceTransposee(matriceChTransposee.getColonne(),matriceChTransposee.getLigne());
    matriceTransposee = matriceChTransposee.calculerTransposee();


    int i, j;
    ui->m_matriceTransposee->setRowCount(matriceTransposee.getLigne());
    ui->m_matriceTransposee->setColumnCount(matriceTransposee.getColonne());


    for (i=0; i<matriceTransposee.getLigne(); i++)
    {

        for (j=0; j<matriceTransposee.getColonne(); j++)
        {
            QTableWidgetItem *caseTab = new QTableWidgetItem(QString::number(matriceTransposee.getCoefficient(i, j)));

            ui -> m_matriceTransposee ->setItem(i, j, caseTab);
        }
    }

    m_conteneur.RecupererMatrice(ui->choixMatriceTransposee->currentText().toStdString()) = matriceTransposee;
}
