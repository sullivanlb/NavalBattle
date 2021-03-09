#include "CGui.h"

CGui::CGui() {
    m_pArmada = NULL;
    m_pCoups = NULL;
}

CGui::CGui(CArmada* pArmada, CCoups* pCoups) {
    m_pArmada = pArmada;
    m_pCoups = pCoups;
}

CGui::~CGui() {

    m_pArmada = NULL;
    delete m_pArmada;

    m_pCoups = NULL;
    delete m_pCoups;
}

void CGui::setArmadaCoups (CArmada* pArmada, CCoups* pCoups) {
    m_pArmada = pArmada;
    m_pCoups = pCoups;
}

bool CGui::positionnerBateaux() {
    bool test = false;
    
    if (m_pArmada->placerAleatoirement()) {
        test = true;
    }

    return test;
}

ostream& operator<<(ostream& os, CGui& theG) {
    theG.remplirDeuxGrilles(os);
    return os;
}

pair<int,int> CGui::choisirAttaque() {
    cout << "Attaque : " << endl;

    bool test = false;
    int ligne;
    while (!test) {
        cout << " - Ligne -> x = ";
        cin >> ligne;

        if (ligne >= 0 && ligne < TAILLE_GRILLE) {
            test = true;
        }else {
            cout << "La ligne spécifié n'est pas dans la grille, recommencez :" << endl;
        }
    }

    test = false;
    int colonne;
    while (!test) {
        cout << " - Colonne -> y = ";
        cin >> colonne;

        if (colonne >= 0 && colonne < TAILLE_GRILLE) {
            test = true;
        }else {
            cout << "La colonne spécifié n'est pas dans la grille, recommencez :" << endl;
        }
    }

    return pair<int, int> (ligne, colonne);
}

void CGui::afficheGagne() {
    cout << "La partie est gagné !" << endl;
}

void CGui::affichePerdu() {
    cout << "La partie est perdu.." << endl;
}

void CGui::remplirDeuxGrilles(ostream& os) {
    // initialisation de la grille joueur
    for (int i = 0; i < TAILLE_GRILLE-1; i++) {
        for (int j = 0; j < TAILLE_GRILLE-1; j++) {
            m_grilleJou[i][j] = '-';
        }
    }

    // place les bateaux sur la grille joueur
    for (int i = 0; i < m_pArmada->getEffectifTotal(); i++) {
        CBateau bateau = *m_pArmada->getBateau(i);
        int ligne = bateau.getPosition().first;
        int colonne = bateau.getPosition().second;
        int taille = bateau.getTaille();

        for (int j = colonne; j < taille + colonne; j++) {
            m_grilleJou[ligne][j] = 'B';
        }
    }
    

    // place les tirs adverses
    for (int i = 0; i < m_pArmada->getEffectifTotal(); i++) {
        for (int j = 0; j < m_pArmada->getBateau(i)->getTaille(); j++) {
            if (m_pArmada->getBateau(i)->getDegats(j) == 1) {
                int ligne = m_pArmada->getBateau(i)->getPosition().first;
                int colonne = m_pArmada->getBateau(i)->getPosition().second;
                m_grilleJou[ligne][colonne] = 'X';
            }
        }
    }

    // place les plouf adverses
    for (int i = 0; i < m_pCoups->getTaille("ploufAdverse"); i++) {
        int ligne = m_pCoups->getPair("ploufAdverse", i).first;
        int colonne = m_pCoups->getPair("ploufAdverse", i).second;
        m_grilleJou[ligne][colonne] = 'O';
    }

    afficherLaGrille(os, "joueur");

    // initialisation de la grille adverse 
    for (int i = 0; i < TAILLE_GRILLE-1; i++) {
        for (int j = 0; j < TAILLE_GRILLE-1; j++) {
            m_grilleAdv[i][j] = '-';
        }
    }

    // place les plouf sur la grille adverse
    for (int i = 0; i < m_pCoups->getTaille("dansLEau"); i++) {
        int ligne = m_pCoups->getPair("dansLEau", i).first;
        int colonne = m_pCoups->getPair("dansLEau", i).second;
        m_grilleAdv[ligne][colonne] = 'O';
    }

    // place les tir réussi sur la grille adverse
    for (int i = 0; i < m_pCoups->getTaille("touche"); i++) {
        int ligne = m_pCoups->getPair("touche", i).first;
        int colonne = m_pCoups->getPair("touche", i).second;
        m_grilleAdv[ligne][colonne] = 'X';
    }

    afficherLaGrille(os, "adversaire");
    
}

void CGui::afficherLaGrille(ostream& os, string jouOuAdv) {
    if (jouOuAdv.compare("joueur") == 0) {
        os << endl;
        os << "♦ Ma grille : " << endl;
    } else {
        os << endl;
        os << "♦ La grille adverse : " << endl;
    }

    os << endl;
    // numérotation en haut de la grille adverse
    for (int i = 0; i < TAILLE_GRILLE-1; i++) {
        os << "\t" << i;
    }
    os << endl;

    // si on demande la grille joueur
    if (jouOuAdv.compare("joueur") == 0) {
        for (int i = 0; i < TAILLE_GRILLE-1; i++) {
            os << i;
            for (int j = 0; j < TAILLE_GRILLE-1; j++) {
                os << "\t" << m_grilleJou[i][j];
            }
            os << endl;
        }
    // si on demande la grille adverse
    } else {
        for (int i = 0; i < TAILLE_GRILLE-1; i++) {
            os << i;
            for (int j = 0; j < TAILLE_GRILLE-1; j++) {
                os << "\t" << m_grilleAdv[i][j];
            }
            os << endl;
        }
    }
    
}