#ifndef DETERMINANT_H
#define DETERMINANT_H
#include "conteneur.h"

#include <QDialog>

namespace Ui {
class Determinant;
}

class Determinant : public QDialog
{
    Q_OBJECT

public:
    explicit Determinant(Conteneur &conteneur, QWidget *parent = 0);
    ~Determinant();

private slots:
    void on_calculDeterm_clicked();

private:
    Ui::Determinant *ui;
    Conteneur &m_conteneur;
};

#endif // DETERMINANT_H
