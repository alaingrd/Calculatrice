#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "conteneur.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_SaisieMatrice_clicked();

    void on_gerermatrice_clicked();
    void on_faireOperation_clicked();

    void on_calculerDeterminant_clicked();

    void on_determinerMatriceInverse_clicked();

    void on_calculerPuissance_clicked();

    void on_calculerNorme_clicked();

    void on_calculerTrace_clicked();

    void on_calculerTranspose_clicked();

    void on_multMatriceScal_clicked();

    void on_enregisterMatriceFichier_clicked();

    void on_ouvrireMatriceFichier_clicked();

private:
    Ui::MainWindow *ui;
    Conteneur conteneur;
};

#endif // MAINWINDOW_H
