#include "saisiematrice.h"
#include "ui_saisiematrice.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTableWidget"
#include "matrice.h"
#include <QMap>
#include <QString>

SaisieMatrice::SaisieMatrice(Conteneur &conteneur, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaisieMatrice),
    m_conteneur(conteneur)
{
    ui->setupUi(this);
}

SaisieMatrice::~SaisieMatrice()
{
    delete ui;
}

void SaisieMatrice::on_validationNomTaille_clicked()
{
    QMap<QString, int> mapLignes;
    QMap<QString, int> mapColonnes;

    ui->m_matrice->setRowCount(ui->spBoxLignes->value());
    ui->m_matrice->setColumnCount(ui->spBoxColonnes->value());

    mapLignes["ui->choixMatrice->currentText().toStdString()"] = ui->spBoxLignes->value();
    mapColonnes["ui->choixMatrice->currentText().toStdString()"] = ui->spBoxColonnes->value();
}



void SaisieMatrice::on_buttonBox_accepted()
{
    Matrice nouvelleMatrice(ui->spBoxLignes->value(),ui->spBoxColonnes->value());

    for (int i=0; i<ui->spBoxLignes->value(); i++)
    {
        for (int j=0; j<ui->spBoxColonnes->value(); j++)
        {
            bool possible;
            QTableWidgetItem *item = ui->m_matrice->item(i, j);
            if(item == NULL)
                continue;

            double valeur = item->text().toDouble(&possible);
            if(possible)
                nouvelleMatrice.setCoefficient(i, j, item->text().toDouble());
        }
    }

    m_conteneur.RecupererMatrice(ui->choixMatrice->currentText().toStdString()) = nouvelleMatrice;
}



void SaisieMatrice::on_enregMatrice_clicked()
{
    Matrice nouvelleMatrice(ui->spBoxLignes->value(),ui->spBoxColonnes->value());

    for (int i=0; i<ui->spBoxLignes->value(); i++)
    {
        for (int j=0; j<ui->spBoxColonnes->value(); j++)
        {
            bool possible;
            QTableWidgetItem *item = ui->m_matrice->item(i, j);
            if(item == NULL)
                continue;

            double valeur = item->text().toDouble(&possible);
            if(possible)
                nouvelleMatrice.setCoefficient(i, j, item->text().toDouble());
        }
    }

    m_conteneur.RecupererMatrice(ui->choixMatrice->currentText().toStdString()) = nouvelleMatrice;
}
