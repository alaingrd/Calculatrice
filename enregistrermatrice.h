#ifndef ENREGISTRERMATRICE_H
#define ENREGISTRERMATRICE_H

#include "conteneur.h"
#include <QDialog>

namespace Ui {
class EnregistrerMatrice;
}

class EnregistrerMatrice : public QDialog
{
    Q_OBJECT

public:
    explicit EnregistrerMatrice(Conteneur &conteneur, QWidget *parent = 0);
    ~EnregistrerMatrice();

private slots:
    void on_enregMatrice_clicked();

private:
    Ui::EnregistrerMatrice *ui;
    Conteneur &m_conteneur;
};

#endif // ENREGISTRERMATRICE_H
