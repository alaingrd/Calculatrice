#ifndef SAISIEMATRICE_H
#define SAISIEMATRICE_H

#include <QDialog>
#include <QTableWidget>
#include <QMap>
#include <QString>

#include "conteneur.h"

namespace Ui {
class SaisieMatrice;
}

class SaisieMatrice : public QDialog
{
    Q_OBJECT

public:
    explicit SaisieMatrice(Conteneur &conteneur, QWidget *parent = 0);
    QMap<QString, int> mapLignes;
    QMap<QString, int> mapColonnes;
    ~SaisieMatrice();

private slots:
    void on_validationNomTaille_clicked();

    void on_buttonBox_accepted();

    void on_enregMatrice_clicked();

private:
    Ui::SaisieMatrice *ui;
    Conteneur &m_conteneur;
};

#endif // SAISIEMATRICE_H
