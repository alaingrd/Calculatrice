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


Operation::Operation(Conteneur &conteneur, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Operation),
    m_conteneur(conteneur)
{
    ui->setupUi(this);
}

Operation::~Operation()
{
    delete ui;
}

void Operation::on_pushButton_clicked()
{
    Matrice premiereMatrice = m_conteneur.RecupererMatrice(ui->selectPremMatrice->currentText().toStdString());
    Matrice deuxiemeMatrice = m_conteneur.RecupererMatrice(ui->selectDeuxiemeMatrice->currentText().toStdString());

    Matrice matriceOperation(premiereMatrice.getLigne(), premiereMatrice.getColonne());
    float impossibilite = 0;


    int choixOperation = ui->choixOperation->currentIndex();

    switch (choixOperation)
    {
        case 0:
        //matriceInv = matriceChInverse.calculerMatriceInverse();
        if (premiereMatrice.getLigne() != deuxiemeMatrice.getLigne() || premiereMatrice.getColonne() != deuxiemeMatrice.getColonne())
        {
            impossibilite = 2;
        }
        else
        {
          matriceOperation =  Matrice::additionner(premiereMatrice, deuxiemeMatrice);
        }
        break;

        case 1:
        if (premiereMatrice.getLigne() != deuxiemeMatrice.getLigne() || premiereMatrice.getColonne() != deuxiemeMatrice.getColonne())
        {
            impossibilite = 2;
        }
        else
        {
             matriceOperation = Matrice::soustraire(premiereMatrice, deuxiemeMatrice);
        }
        //matriceOperation = soustraire(premiereMatrice, deuxiemeMatrice);
        break;

        case 2:
        if (premiereMatrice.getColonne() != deuxiemeMatrice.getLigne())
        {
            impossibilite = 1;
        }
        if (impossibilite == 0)
        {
            matriceOperation = Matrice::multiplier(premiereMatrice, deuxiemeMatrice);
        }
        break;
    }

    if (impossibilite == 0)
    {
        int i, j;

        ui->m_operation->setRowCount(matriceOperation.getLigne());
        ui->m_operation->setColumnCount(matriceOperation.getColonne());


        for (i=0; i<matriceOperation.getLigne(); i++)
        {

            for (j=0; j<matriceOperation.getColonne(); j++)
            {
                QTableWidgetItem *caseTab = new QTableWidgetItem(QString::number(matriceOperation.getCoefficient(i, j)));

                ui -> m_operation ->setItem(i, j, caseTab);
            }
        }

        m_conteneur.RecupererMatrice(ui->choixMatriceResult->currentText().toStdString()) = matriceOperation;
    }
    else if (impossibilite == 1)
    {
        ui -> m_possibilite -> setText("Impossible de multiplier ces deux matrices !");
    }
    else
    {
        ui -> m_possibilite -> setText("Ces deux matrices n'ont pas les mêmes dimensions !");
    }
}
