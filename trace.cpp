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

Trace::Trace(Conteneur &conteneur, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Trace),
    m_conteneur(conteneur)
{
    ui->setupUi(this);
}

Trace::~Trace()
{
    delete ui;
}

void Trace::on_pushButton_clicked()
{
    Matrice matriceChTrace = m_conteneur.RecupererMatrice(ui->selectMatriceTrace->currentText().toStdString());

    if (matriceChTrace.getLigne() == matriceChTrace.getColonne())
    {
        float trace = matriceChTrace.calculerTrace();
        ui -> resultatTrace -> setText(QString::number(trace));
    }
    else
    {
        ui -> resultatTrace -> setText("Cette matrice n'est pas carrée !");
    }

}
