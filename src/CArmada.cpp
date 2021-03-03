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
CBateau* CArmada::getBateau(unsigned int i) {
    if (0 <= i && i < sizeof(m_listeBateaux)) {
        return &m_listeBateaux[i];
    }
    return NULL;
}

/**
 * @brief Renvoie le nombre total de bateaux de l'armada
 * @return int - le nombre de bateaux
 */
int CArmada::getEffectifTotal() {
    return m_listeBateaux.size();
}

/**
 * @brief Renvoie le nombre total de cases occupées par l'armada
 * @return int - le nombre de cases
 */
int CArmada::getNbreTotCases() {
    int total =  0;
    for (unsigned int i = 0; i < m_listeBateaux.size(); i++) {
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
    for (unsigned int i = 0; i < m_listeBateaux.size(); i++) {
        if (!m_listeBateaux[i].estCoule()) compteur++;
    }
    return compteur;
}

/**
 * @brief  Lecture du fichier flotille.txt qui contient la liste complète de tous les bateaux
 */
void CArmada::getArmadaFromFile() {
    const char* nomFichier = "flotille.txt";
    ifstream infile (nomFichier, ios::in);
    string line;

    // lecture du fichier ligne par ligne
    cout << "before line" << endl;
    while (getline(infile, line, '\n')) {
        cout << "line" << endl;
        if (line.front() != '#') {
            istringstream iss(line);

            string nomBateau;
            iss >> nomBateau;

            cout << line << endl;
            cout << "hello : " << nomBateau << endl;

            exit(1);

           // pair<int, int> position (ligne, -1);

            //CBateau bateau(nomBateau, position, taille);
            //this->ajouterBateau(bateau);
        }
    }
    
    infile.close();
}

bool CArmada::placerAleatoirement() {
    srand (time(NULL));
    bool test = false;

    for (unsigned int i = 0; i < sizeof(m_listeBateaux); i++) {
        int randNumber = rand() % ((TAILLE_GRILLE-2) + 1);

        for (unsigned int j = 0; j < MAX_ESSAIS; j++) {
            test = false;

            for (unsigned int k = 0; k < sizeof(m_listeBateaux); k++) {

                //si le bateau est a la meme ligne de celui que l'on veut placer
                if (m_listeBateaux[i].getPosition().first == m_listeBateaux[k].getPosition().first) {
                    
                    // si le numero aleatoire n'est pas sur un bateau
                    if (randNumber < m_listeBateaux[k].getPosition().second || randNumber >= (m_listeBateaux[k].getPosition().second + m_listeBateaux[k].getTaille())) {
                        
                        // si le bateau a placer ne touche pas la partie gauche d'un autre bateau
                        if (randNumber + m_listeBateaux[i].getTaille() < m_listeBateaux[k].getPosition().second) {

                            // si le bateau a placer ne touche pas la partie droite d'un autre bateau
                            if (m_listeBateaux[k].getPosition().second + m_listeBateaux[k].getTaille() < randNumber) {
                                m_listeBateaux[i].setPosition(m_listeBateaux[i].getPosition().first, randNumber);
                                test = true;
                            }else{
                                test = false;
                            }
                        }else{
                            test = false;
                        }
                    }else{
                        test = false;
                    }
                }else{
                    test = false;
                }

                if (test) {
                    k = sizeof(m_listeBateaux);
                }
            }

            if (test) {
                j = MAX_ESSAIS;
            }else {
                randNumber = rand() % ((TAILLE_GRILLE-2) + 1);
            }
        }
    }
    
    return test;
}