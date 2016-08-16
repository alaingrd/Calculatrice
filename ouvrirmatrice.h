#ifndef OUVRIRMATRICE_H
#define OUVRIRMATRICE_H

#include "conteneur.h"

#include <QDialog>

namespace Ui {
class OuvrirMatrice;
}

class OuvrirMatrice : public QDialog
{
    Q_OBJECT

public:
    explicit OuvrirMatrice(Conteneur &conteneur, QWidget *parent = 0);
    ~OuvrirMatrice();

private slots:
    void on_ourvirMatrice_clicked();

private:
    Ui::OuvrirMatrice *ui;
    Conteneur &m_conteneur;
};

#endif // OUVRIRMATRICE_H
