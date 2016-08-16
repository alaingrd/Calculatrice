#include "gerermatrice.h"
#include "ui_gerermatrice.h"
#include "conteneur.h"
#include "saisiematrice.h"
#include "ui_saisiematrice.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTableWidget"
#include "matrice.h"



GererMatrice::GererMatrice(Conteneur &conteneur, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GererMatrice),
    m_conteneur(conteneur)
{
    ui->setupUi(this);
}

GererMatrice::~GererMatrice()
{
    delete ui;
}


void GererMatrice::on_valideGererMatrice_clicked()
{
    //m_conteneur.RecupererMatrice(ui->choixMatrice->currentText().toStdString()) = nouvelleMatrice;

    //(m_conteneur.RecupererMatrice(ui->selectMatrice->currentText().toStdString()));

    Matrice matriceAffiche = m_conteneur.RecupererMatrice(ui->selectMatrice->currentText().toStdString());

    int i, j;

    ui->m_gererMatrice->setRowCount(matriceAffiche.getLigne());
    ui->m_gererMatrice->setColumnCount(matriceAffiche.getColonne());


    for (i=0; i<matriceAffiche.getLigne(); i++)
    {

        for (j=0; j<matriceAffiche.getColonne(); j++)
        {
            QTableWidgetItem *caseTab = new QTableWidgetItem(QString::number(matriceAffiche.getCoefficient(i, j)));

            ui -> m_gererMatrice ->setItem(i, j, caseTab);
        }
    }




    //RecupererMatrice(ui -> selectMatrice->currentText().toStdString());
}


void GererMatrice::on_modifMatrice_clicked()
{
    Matrice nouvelleMatrice = m_conteneur.RecupererMatrice(ui->selectMatrice->currentText().toStdString());

    for (int i=0; i<nouvelleMatrice.getLigne(); i++)
    {
        for (int j=0; j<nouvelleMatrice.getColonne(); j++)
        {
            bool possible;
            QTableWidgetItem *item = ui->m_gererMatrice->item(i, j);
            if(item == NULL)
                continue;

            double valeur = item->text().toDouble(&possible);
            if(possible)
                nouvelleMatrice.setCoefficient(i, j, item->text().toDouble());
        }
    }

    m_conteneur.RecupererMatrice(ui->selectMatrice->currentText().toStdString()) = nouvelleMatrice;
}
