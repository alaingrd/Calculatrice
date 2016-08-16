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

MatriceInverse::MatriceInverse(Conteneur &conteneur, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MatriceInverse),
    m_conteneur(conteneur)
{
    ui->setupUi(this);
}

MatriceInverse::~MatriceInverse()
{
    delete ui;
}

void MatriceInverse::on_DeterminerMatriceInverse_clicked()
{
    Matrice matriceChInverse = m_conteneur.RecupererMatrice(ui->choixMatriceChInverse->currentText().toStdString());

    if (matriceChInverse.getLigne() == matriceChInverse.getColonne())
    {
        Matrice matriceInv(matriceChInverse.getLigne(),matriceChInverse.getColonne());
        matriceInv = matriceChInverse.calculerMatriceInverse();
        //Matrice matriceInv = calculerMatriceInverse(matriceChInverse);

        int i, j;

        ui->m_matriceInverse->setRowCount(matriceInv.getLigne());
        ui->m_matriceInverse->setColumnCount(matriceInv.getColonne());


        for (i=0; i<matriceInv.getLigne(); i++)
        {

            for (j=0; j<matriceInv.getColonne(); j++)
            {
                QTableWidgetItem *caseTab = new QTableWidgetItem(QString::number(matriceInv.getCoefficient(i, j)));

                ui -> m_matriceInverse ->setItem(i, j, caseTab);
            }
        }

        m_conteneur.RecupererMatrice(ui->choixMatriceInv->currentText().toStdString()) = matriceInv;
    }
    else
    {
        ui -> m_possibilite ->setText("Cette matrice n'est pas carrée !");
    }
}
