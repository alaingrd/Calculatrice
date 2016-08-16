#ifndef GERERMATRICE_H
#define GERERMATRICE_H

#include <QDialog>
#include <QTableWidget>
#include <QMap>
#include <QString>

#include "conteneur.h"

namespace Ui {
class GererMatrice;
}

class GererMatrice : public QDialog
{
    Q_OBJECT

public:
    explicit GererMatrice(Conteneur &conteneur,QWidget *parent = 0);
    QMap<QString, int> mapLignes;
    QMap<QString, int> mapColonnes;
    ~GererMatrice();

private slots:
    void on_valideGererMatrice_clicked();

    void on_modifMatrice_clicked();

private:
    Ui::GererMatrice *ui;
    Conteneur &m_conteneur;
};

#endif // GERERMATRICE_H
