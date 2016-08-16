#ifndef OPERATION_H
#define OPERATION_H
#include "conteneur.h"

#include <QDialog>

namespace Ui {
class Operation;
}

class Operation : public QDialog
{
    Q_OBJECT

public:
    explicit Operation(Conteneur &conteneur, QWidget *parent = 0);
    ~Operation();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Operation *ui;
    Conteneur &m_conteneur;
};

#endif // OPERATION_H
