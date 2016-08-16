#ifndef CONTENEUR_H
#define CONTENEUR_H
#include "matrice.h"
#include <map>
#include <string>

class Conteneur
{
public:
    Conteneur();

    bool Existe(const std::string &nomVariable) const;
    Matrice& RecupererMatrice(const std::string &nomVariable);
    void SupprimerMatrice(const std::string &nomVariable);

private:
    std::map<std::string, Matrice> m_variables;
};

#endif // CONTENEUR_H
