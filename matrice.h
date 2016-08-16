#ifndef MATRICE_H
#define MATRICE_H
#include <iostream>
#include <string>
#include <vector>
#include <QString>
class Matrice
{

private:


    int ligne;
    int colonne;

    std::vector<std::vector<float> > coefficient;

public:


    Matrice calculerMatriceInverse();

    Matrice calculerComatrice();
    Matrice produitMatriceScalaire(float a);
    Matrice reduireMatrice(int a, int b);

    Matrice calculerTransposee();

    float getCoefficient(int i, int j) {return coefficient[i][j];};
    void setCoefficient(int i, int j, float coeff);

    int getLigne() const {return ligne;};
    int getColonne() const {return colonne;};

    static bool comparerTaille(Matrice &A, Matrice &B);
    float calculerDeterminant();
    float calculerTrace();

    float calculerNorme();

    static Matrice additionner(Matrice &matriceA, Matrice &matriceB);
    static  Matrice soustraire(Matrice &matriceA, Matrice &matriceB);
    static Matrice multiplier(Matrice &matriceA, Matrice &matriceB);

    static Matrice calculerPuissance(Matrice &matriceA, int a);
    void enregistrerMatrice(std::string nom);
    void ouvrirMatrice(std::string nom);


    Matrice(int k,int l);
};

//Matrice soustraire(Matrice matriceA, Matrice matriceB);
//Matrice multiplier(Matrice matriceA, Matrice matriceB);
//float calculerDeterminant(Matrice matriceA);
Matrice calculerMatriceInverse(Matrice matriceA);



#endif // MATRICE_H
