#ifndef TRACE_H
#define TRACE_H
#include "conteneur.h"

#include <QDialog>

namespace Ui {
class Trace;
}

class Trace : public QDialog
{
    Q_OBJECT

public:
    explicit Trace(Conteneur &conteneur, QWidget *parent = 0);
    ~Trace();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Trace *ui;
    Conteneur &m_conteneur;
};

#endif // TRACE_H
