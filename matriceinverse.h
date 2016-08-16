#ifndef MATRICEINVERSE_H
#define MATRICEINVERSE_H
#include "conteneur.h"
#include "multmatricescalaire.h"
#include "ui_multmatricescalaire.h"

#include <QDialog>

namespace Ui {
class MatriceInverse;
}

class MatriceInverse : public QDialog
{
    Q_OBJECT

public:
    explicit MatriceInverse(Conteneur &conteneur, QWidget *parent = 0);
    ~MatriceInverse();

private slots:
    void on_DeterminerMatriceInverse_clicked();

private:
    Ui::MatriceInverse *ui;
    Conteneur &m_conteneur;
};

#endif // MATRICEINVERSE_H
