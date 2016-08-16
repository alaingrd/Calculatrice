#include "enregistrermatrice.h"
#include "ui_enregistrermatrice.h"
#include <Qstring>
EnregistrerMatrice::EnregistrerMatrice(Conteneur &conteneur, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnregistrerMatrice),
    m_conteneur(conteneur)
{
    ui->setupUi(this);
}

EnregistrerMatrice::~EnregistrerMatrice()
{
    delete ui;
}


void EnregistrerMatrice::on_enregMatrice_clicked()
{

    Matrice matriceEnr = m_conteneur.RecupererMatrice(ui->choixMatriceEnreg->currentText().toStdString());


    matriceEnr.enregistrerMatrice(ui->choixMatriceEnreg->currentText().toStdString();

    ui -> m_enregistrement -> setText("La matrice a été enregistrée");
}
