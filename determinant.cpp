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

Determinant::Determinant(Conteneur &conteneur, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Determinant),
    m_conteneur(conteneur)
{
    ui->setupUi(this);
}

Determinant::~Determinant()
{
    delete ui;
}

void Determinant::on_calculDeterm_clicked()
{
    Matrice matriceChDeterm = m_conteneur.RecupererMatrice(ui->choixMatriceDeterm->currentText().toStdString());

    if (matriceChDeterm.getLigne() == matriceChDeterm.getColonne())
    {
        float determinant = matriceChDeterm.calculerDeterminant();

        ui -> resultatDeterminant -> setText(QString::number(determinant));
    }
    else
    {
        ui -> resultatDeterminant -> setText("Cette matrice n'est pas carrée !");
    }

}
