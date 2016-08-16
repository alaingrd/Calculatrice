#include "matrice.h"
#include <string>
#include <vector>
#include "determinant.h"
#include "ui_determinant.h"
#include "operation.h"
#include "ui_operation.h"
#include "matrice.h"
#include "gerermatrice.h"
#include "ui_gerermatrice.h"
#include "conteneur.h"
#include "saisiematrice.h"
#include "ui_saisiematrice.h"
#include "mainwindow.h"
#include "QTableWidget"
#include <math.h>
#include "multmatricescalaire.h"
#include "ui_multmatricescalaire.h"
#include "QFile"
#include <QFile>
#include <QTextStream>


Matrice::Matrice(int k,int l)
{
    ligne=k;
    colonne=l;

    coefficient.resize(ligne);
    for (int a = 0; a < ligne; a++) { coefficient[a].resize(colonne);}
}



Matrice Matrice::produitMatriceScalaire(float a)
{
    int i, j;
    Matrice matriceScal(ligne, colonne);
    for (i=0; i<ligne; i++)
    {
        for (j=0; j<colonne; j++)
        {
            matriceScal.setCoefficient(i, j, a*coefficient[i][j]);
        }
    }
    return matriceScal;
}

Matrice Matrice::calculerPuissance(Matrice &matriceChePuissance, int puissance)
{   //on cree deux matrices l'une pour le calcul de l'inverse et l'autre pour le resultat
    Matrice puissanceMatrice(matriceChePuissance.getLigne(),matriceChePuissance.getColonne());
    Matrice matriceInverse(matriceChePuissance.getLigne(),matriceChePuissance.getColonne());
    int i;
    // on appelle la fonction inverse pour mettre la valeur dans matriceInverse
    matriceInverse = matriceChePuissance.calculerMatriceInverse();
    // on appelle la fonction multiplier avec comme paramettre la matrice et son inverse : matrice puissance devient la matrice identité
    puissanceMatrice = Matrice::multiplier(matriceChePuissance,matriceInverse);
    // si la puissance recherché est inferieur à 0 on multiplie puissanceMatrice par matriceInverse n fois, n correspondant à la valeur de la variable puissance
    for (i=-1;i>=puissance;i--)
    {
        puissanceMatrice = Matrice::multiplier(puissanceMatrice,matriceInverse);
    }
    // si la puissance est superieur à 0 on realise la meme operation mais en multipliant cette fois par la matrice dont on cherche la puissance
    for (i=1;i<=puissance;i++)
    {
        puissanceMatrice = Matrice::multiplier(puissanceMatrice,matriceChePuissance);
    }
    return puissanceMatrice;
}
/*
Matrice Matrice::calculerPuissance(int a)
{
    int i,j,k,l;
    Matrice matricePuissance(ligne, colonne);

    Matrice matriceInter(A.getLigne(), A.getColonne());
    matriceInter = A;

    if (a==0)
    {
        int j, k;
        for (j=0; j<matricePuissance.getLigne(); j++)
        {
            for (k=0; k<matricePuissance.getColonne(); k++)
            {

                if (j == k)
                {
                    matricePuissance.setCoefficient(j, k, 1);
                }
                else
                {
                    matricePuissance.setCoefficient(j, k, 0);
                }
            }
        }
    }
    else if (a==1)
    {
        matricePuissance = A;
    }
    else if (a==2)
    {
        matricePuissance.multiplier(A, A);
    }
    else
    {
        for (i=1; i<a; i++)
        {
            ///Attention: donner dabord matriceInter en argument
            matricePuissance.multiplier(matriceInter, A);
            matriceInter = matricePuissance;
        }
    }
    return matricePuissance;
}
*/
//Matrice additionner(Matrice matriceA, Matrice matriceB) {}
//Matrice soustraire(Matrice matriceA, Matrice matriceB) {}
//Matrice multiplier(Matrice matriceA, Matrice matriceB) {}






Matrice Matrice::additionner(Matrice &A, Matrice &B)
{
    int i;
    int j;
    Matrice matriceSomme(A.getLigne(), A.getColonne());
    for (i=0; i<A.getLigne(); i++)
    {
        for (j=0; j<A.getColonne(); j++)
        {
            matriceSomme.setCoefficient(i,j,A.getCoefficient(i,j) + B.getCoefficient(i,j));
        }
    }
    return matriceSomme;
}

Matrice Matrice::soustraire(Matrice &A, Matrice &B)
{
    int i;
    int j;
    Matrice matriceDiff(A.getLigne(), A.getColonne());
    for (i=0; i<A.getLigne(); i++)
    {
        for (j=0; j<A.getColonne(); j++)
        {
            matriceDiff.setCoefficient(i,j,A.getCoefficient(i,j) - B.getCoefficient(i,j));
        }
    }
    return matriceDiff;
}


Matrice Matrice::multiplier(Matrice &A, Matrice &B)
{
    int i;
    int j;
    int k;
    std::vector<std::vector<float> > coeffTransition;
    coeffTransition.resize(A.getLigne());
        for (int a = 0; a < A.getLigne(); a++) { coeffTransition[a].resize(B.getColonne());}

        Matrice matriceProduit(A.getLigne(), B.getColonne());
        for (i=0; i<A.getLigne(); i++)
        {
            for (j=0; j<B.getColonne(); j++)
            {
                for (k=0; k<A.getColonne(); k++)
                {
                    coeffTransition[i][j] += (A.getCoefficient(i,k) * B.getCoefficient(k, j));
                }
                matriceProduit.setCoefficient(i,j,coeffTransition[i][j]);
            }
        }
        return matriceProduit;

    ///AB != BA
}


//float calculerDeterminant(Matrice matriceA) {}
float Matrice::calculerDeterminant(){
    // on cree un tableau dynamique pour pouvoir effectuer les transformations necessaire sans modifier la matrice necessaire
     std::vector<std::vector<float> > coeffTransition;
     coeffTransition.resize(ligne);
         for (int a = 0; a < ligne; a++) { coeffTransition[a].resize(colonne);}
         coeffTransition=coefficient;

    int a;
    int b;
    int c;
    //on cree une variable determinant qui va contenir le resultat final, le determinant etant obtenue par multiplication, on l'initialyse à 1
    float determinant = 1;

    float diviseur;
    int nonNul;
    //on parcourt la matrice
    for (a=0;a<colonne-1;a++)
    {
        //si le coefficient sur la diagnale est nul, on regarde si un des coefficient sur la memme colonne est nul
        if (coeffTransition[a][a]==0)
        {
            nonNul=0;
              for (int i=a+1;i<ligne;i++)
              {
                  if (coeffTransition[i][a]!=0)
                  {
                      nonNul=i;
                  }
              }
              //s'il y en a un non nul, on echange la ligne de ce coefficient avec celle de celui nul
              if (nonNul!=0)
              {
                  std::vector<float> ligneTransition;
                  ligneTransition.resize(ligne);
                  ligneTransition=coeffTransition[a];
                  coeffTransition[a]=coeffTransition[nonNul];
                  //on multiplie le determinant par -1 car on a echangé les lignes
                  coeffTransition[nonNul]=ligneTransition;

                  determinant = determinant*(-1);
              }
              // s'il n'y en a aucun non nul on passe à la ligne suivante
              else
              {
                  continue;
              }
        }
        // si le coefficient de la diagonale est non nul, on parcourt la colonne en commencant par le coefficient un rang au dessus de celui de la diagonale
            for (b=a+1;b<ligne;b++)
            {

              if (coeffTransition[b][a]!=0){
               diviseur = coeffTransition[b][a];
                  for(c=a;c<colonne;c++)
                {
// s'il est non nul, on multiplie la ligne de ce coefficient par celui de la diagonale/ce coefficient
                   coeffTransition[b][c] = coeffTransition[b][c]*coeffTransition[a][a]/diviseur;
// on soustrait la ligne du coefficient sur la digonale à celle de ce coefficient : ce coefficient devient nul
                   coeffTransition[b][c]=coeffTransition[b][c]-coeffTransition[a][c];
                }
                  //comme on à multiplié une ligne par un facteur on multiplie le determinant par l'inverse de ce facteur
                determinant = determinant*diviseur/coeffTransition[a][a];
              }
            }


   }
    // la matrice etant diagonale, le determinant est le produit des coefficients diagonaux
    for (a=0;a<colonne;a++)
    {
        determinant = determinant*coeffTransition[a][a];
    }
    return determinant;
}


//Matrice calculerMatriceInverse(Matrice matriceA) {}



//float calculerTrace(Matrice matriceA) {}



/*
float Matrice::calculerDeterminant(){
     std::vector<std::vector<float> > coeffTransition;
     coeffTransition.resize(ligne);
         for (int a = 0; a < ligne; a++) { coeffTransition[a].resize(colonne);}
         coeffTransition=coefficient;

    int a;
    int b;
    int c;
    float determinant = 1;

    for (a=0;a<colonne-1;a++)
    {
        for (b=a+1;b<ligne;b++)
        {
          if (coeffTransition[b][a]!=0){
            for(c=a;c<colonne;c++)
            {
               coeffTransition[b][c] = coeffTransition[b][c]*coeffTransition[a][a]/coeffTransition[b][a]-coeffTransition[c][a];
            }
            determinant = determinant*coeffTransition[b][a];
          }
        }
    }
    for (a=0;a<colonne;a++)
    {
        determinant = determinant*coeffTransition[a][a];
    }
    return determinant;
}
*/

float Matrice::calculerNorme()
{
    float norme = 0;
    for (int i=0; i<ligne; i++)
    {
        for (int j=0; j<colonne; j++)
        {
            norme += pow(coefficient[i][j], 2);
        }
    }
    norme = pow(norme, 0.5);
    return norme;
}

float Matrice::calculerTrace(){
    float trace = 0;
    for(int i=0;i<ligne;i++)
    {
        trace += coefficient[i][i];
    }
    return trace;
}

/*Nouvel ajout 19/12/2014*/
Matrice Matrice::calculerMatriceInverse(){
   Matrice inverse(ligne,colonne);
   inverse = this->calculerComatrice();
   inverse = inverse.calculerTransposee();
   inverse = inverse.produitMatriceScalaire(1/(this->calculerDeterminant()));

   return inverse;
}


Matrice Matrice::calculerComatrice(){
    Matrice comatrice(colonne,ligne);
    int i,j;
    //pour chaque coefficient de la comatrice,
    for (i=0;i<ligne;i++)
    {
        for (j=0;j<colonne;j++)
        {
            //on cree et on initialise la matrice reduite
            Matrice matriceReduite(ligne-1,colonne-1);
           // matriceReduite=comatrice;
            matriceReduite = this->reduireMatrice(i,j);
            //on calcul le determinant de la matrice reduite et on le met dans la comatrice
            comatrice.setCoefficient(i,j,matriceReduite.calculerDeterminant());
            comatrice.setCoefficient(i,j,comatrice.getCoefficient(i,j)*pow(-1,i+j));

        }
    }
    return comatrice;
}
Matrice Matrice::reduireMatrice(int a, int b){
    Matrice matriceReduite(ligne-1, colonne-1);
    int i, j;
    int k=0;
    int l=0;
    //on parcourt les ligne de la matrice initiale
    for (i=0;i<=matriceReduite.getLigne();i++)
    {
        //si numero de la ligne est different de celui du coefficient de la comatrice,
        if (i!=a)
        {
            //on parcourt les colonnes de la matrice initiale
            for (j=0;j<=matriceReduite.getColonne();j++)
            {
                //si numero de la colonne est different de celui du coefficient de la comatrice,
                if (j!=b)
                {
                    //on place le coefficient dans la nouvelle matrice
                        matriceReduite.setCoefficient(k,l,coefficient[i][j]);
                        //comme on a place un coefficient dans la nouvelle matrice, on incremente le numero de la colonne de la seconde matrice
                        l++;
                }
            }
            //comme on a placé les cofficients dans la ligne, on incremente le numero de la ligne
            k++;
            l=0;
        }
    }
return matriceReduite;
}


Matrice Matrice::calculerTransposee(){
    int i,j;
    Matrice transposee(colonne, ligne);
    for (i=0;i<ligne;i++)
    {
        for(j=0;j<colonne;j++)
        {
            transposee.setCoefficient(j,i,coefficient[i][j]);
        }
    }
    return transposee;
}




/*bool Matrice::comparerTaille(Matrice &A, Matrice &B){
    return (A.getLigne() == B.getLigne() && A.getColonne() == B.getColonne());
}
*/

void Matrice::setCoefficient(int i, int j, float coeff){
    coefficient[i][j] = coeff;
}


void Matrice::enregistrerMatrice(std::string nom){
    int i,j;
/*char nomDuFichier[5];
nomDuFichier[0] = nom;
nomDuFichier[1] ='.';
nomDuFichier[2]= 't';
nomDuFichier[3]= 'x';
nomDuFichier[4]  */
    QFile file;//nom.c_str()
    file.setFileName(nom);
    // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    // Création d'un objet QTextStream à partir de notre objet QFile
    QTextStream flux(&file);
    flux.setCodec("UTF-8");

    // Écriture des différentes lignes dans le fichier
    flux << ligne << colonne;

    for (i=0;i<ligne;i++)
                   {
                       for (j=0;j<colonne;j++)
                       {
                          flux << coefficient[i][j];
                       }
                   }

file.close();


}


void Matrice::ouvrirMatrice(std::string nom)
{
    int i,j;

    QFile file; file.setFileName(nom);
    // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    // Création d'un objet QTextStream à partir de notre objet QFile
    QTextStream flux(&file);

    // Écriture des différentes lignes dans le fichier

    flux >> ligne >> colonne;
    coefficient.resize(ligne);
    for (int a = 0; a < ligne; a++) { coefficient[a].resize(colonne);}
    for (i=0;i<=ligne;i++)
                   {
                       for (j=0;j<colonne;j++)
                       {
                          flux << coefficient[i][j];
                       }
                   }

file.close();

}


/*
Matrice Matrice::calculerMatriceInverse(){
   Matrice inverse(ligne,colonne);
 return inverse;
}
*/
