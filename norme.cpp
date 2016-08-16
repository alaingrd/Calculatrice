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
#include "QString"

Norme::Norme(Conteneur &conteneur, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Norme),
    m_conteneur(conteneur)
{
    ui->setupUi(this);
}

Norme::~Norme()
{
    delete ui;
}

void Norme::on_pushButton_clicked()
{
    Matrice matriceChNorme = m_conteneur.RecupererMatrice(ui->selectMatriceNorme->currentText().toStdString());

    float norme = matriceChNorme.calculerNorme();
    //float norme = calculerNorme(matriceChNorme);

    ui -> m_resultatNorme -> setText(QString::number(norme));
}
