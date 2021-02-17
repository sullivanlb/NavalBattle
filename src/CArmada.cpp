#include "CArmada.h"

/**
 * @brief Ajoute un bateau dans la liste
 * @param unBat - le bateau à ajouter dans la liste
 */
void CArmada::ajouterBateau(CBateau& unBat) {
    this->m_listeBateaux.push_back(unBat);
}

/**
 * @brief Renvoie le bateau qui se trouve à l'index i
 * @pre i doit être entre 0 et la taille du tableau
 * @param i - l'index du tableau où se situe le bateau 
 * @return CBateau* - l'adresse du bateau à l'index i
 */
CBateau* CArmada::getBateau(int i) {
    if (0 <= i && i < sizeof(m_listeBateaux)) {
        return &m_listeBateaux[i];
    }
}

/**
 * @brief Renvoie le nombre total de bateaux de l'armada
 * @return int - le nombre de bateaux
 */
int CArmada::getEffectifTotal() {
    return sizeof(m_listeBateaux);
}

/**
 * @brief Renvoie le nombre total de cases occupées par l'armada
 * @return int - le nombre de cases
 */
int CArmada::getNbreTotCases() {
    int total =  0;
    for (int i = 0; i < sizeof(m_listeBateaux); i++) {
        total += m_listeBateaux[i].getTaille();
    }
    return total;
}

/**
 * @brief  Renvoie le nombre de bateaux qui ne sont pas encore coulés
 * @return int - le nombre de bateau qui ne sont pas encore coulés
 */
int CArmada::getEffectif() {
    int compteur = 0;
    for (int i = 0; i < sizeof(m_listeBateaux); i++) {
        if (m_listeBateaux[i].estCoule()) compteur++;
    }
    return compteur;
}

/**
 * @brief  Lecture du fichier flotille.txt qui contient la liste complète de tous les bateaux
 */
void CArmada::getArmadaFromFile() {
    const char* file = "flotille.txt";
    ifstream fluxIn (file, ios::in);
    string line;

    // lecture du fichier ligne par ligne
    while (!fluxIn.eof()) {
        getline( fluxIn, line, '\n');
        if (line.front() != '#') {
            // split line en mot
        }
    }
    
    fluxIn.close();
}