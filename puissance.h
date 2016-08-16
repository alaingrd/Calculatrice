#ifndef PUISSANCE_H
#define PUISSANCE_H
#include "conteneur.h"

#include <QDialog>

namespace Ui {
class Puissance;
}

class Puissance : public QDialog
{
    Q_OBJECT

public:
    explicit Puissance(Conteneur &conteneur, QWidget *parent = 0);
    ~Puissance();

private slots:
    void on_calculerPuissance_clicked();

private:
    Ui::Puissance *ui;
    Conteneur &m_conteneur;
};

#endif // PUISSANCE_H
