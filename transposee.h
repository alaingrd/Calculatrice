#ifndef TRANSPOSEE_H
#define TRANSPOSEE_H
#include "conteneur.h"


#include <QDialog>

namespace Ui {
class Transposee;
}

class Transposee : public QDialog
{
    Q_OBJECT

public:
    explicit Transposee(Conteneur &conteneur, QWidget *parent = 0);
    ~Transposee();

private slots:
    void on_calculerMatriceTransposee_clicked();

private:
    Ui::Transposee *ui;
    Conteneur &m_conteneur;
};

#endif // TRANSPOSEE_H
