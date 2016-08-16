#ifndef MULTMATRICESCALAIRE_H
#define MULTMATRICESCALAIRE_H
#include "conteneur.h"

#include <QDialog>

namespace Ui {
class MultMatriceScalaire;
}

class MultMatriceScalaire : public QDialog
{
    Q_OBJECT

public:
    explicit MultMatriceScalaire(Conteneur &conteneur, QWidget *parent = 0);
    ~MultMatriceScalaire();

private slots:
    void on_calculerMultMatriceScalaire_clicked();

private:
    Ui::MultMatriceScalaire *ui;
    Conteneur &m_conteneur;
};

#endif // MULTMATRICESCALAIRE_H
