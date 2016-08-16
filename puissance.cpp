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

Puissance::Puissance(Conteneur &conteneur, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Puissance),
    m_conteneur(conteneur)
{
    ui->setupUi(this);
}

Puissance::~Puissance()
{
    delete ui;
}

void Puissance::on_calculerPuissance_clicked()
{
    Matrice matriceChPuissance = m_conteneur.RecupererMatrice(ui->choixMatriceChPuissance->currentText().toStdString());

    if (matriceChPuissance.getLigne() == matriceChPuissance.getColonne())
    {
        Matrice matricePuissance(matriceChPuissance.getLigne(), matriceChPuissance.getColonne());
        int a = ui->exposant->value();
        matricePuissance = matriceChPuissance.calculerPuissance(matriceChPuissance, a);

        int i, j;

        ui->m_matricePuissance->setRowCount(matricePuissance.getLigne());
        ui->m_matricePuissance->setColumnCount(matricePuissance.getColonne());


        for (i=0; i<matricePuissance.getLigne(); i++)
        {

            for (j=0; j<matricePuissance.getColonne(); j++)
            {
                QTableWidgetItem *caseTab = new QTableWidgetItem(QString::number(matricePuissance.getCoefficient(i, j)));

                ui -> m_matricePuissance ->setItem(i, j, caseTab);
            }
        }

        m_conteneur.RecupererMatrice(ui->choixMatricePuissance->currentText().toStdString()) = matricePuissance;
    }
    else
    {
        ui -> m_possibilite ->setText("Cette matrice n'est pas carrée !");
    }
}
