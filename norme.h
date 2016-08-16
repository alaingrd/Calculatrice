#ifndef NORME_H
#define NORME_H
#include "conteneur.h"

#include <QDialog>

namespace Ui {
class Norme;
}

class Norme : public QDialog
{
    Q_OBJECT

public:
    explicit Norme(Conteneur &conteneur, QWidget *parent = 0);
    ~Norme();

private slots:
    void on_pushButton_clicked();



private:
    Ui::Norme *ui;
    Conteneur &m_conteneur;
};

#endif // NORME_H
