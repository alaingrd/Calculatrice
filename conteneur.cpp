#include "conteneur.h"
Matrice& Conteneur::RecupererMatrice(const std::string &nomVariable){
    if(m_variables.count(nomVariable) == 0)
        m_variables.insert(std::pair<std::string, Matrice>(nomVariable, Matrice(1,1)));

    return m_variables.at(nomVariable);
}

Conteneur::Conteneur() : m_variables()
{

}
