#include "CBateau.h"

/**
 * @brief Le constructeur par défaut - initialise les attributs
 */
CBateau::CBateau() {
    m_taille = 0;
    m_nom = "neant";
    m_position.first = 0;
    m_position.second = 0;
    m_pDegats = NULL;
}

/**
 * @brief Le constructeur avec paramètres
 * @pre la taille doit être > 0, le nom et le point ne doivent pas être NULL
 * @param nom - le nom du bateau
 * @param point - le point d'ancrage du bateau
 * @param taille - la taille du bateau 
 */
CBateau::CBateau(string nom, pair<int, int> point, int taille){
    if (nom == "" || point.first < 0 || taille <= 0) {
        throw invalid_argument("CBateau(): paramètre non valide.");
    }

    m_nom = nom;
    m_position = point;
    m_taille = taille;
    m_pDegats = new bool[m_taille];

    for(long unsigned int i = 0; i < sizeof(m_pDegats); i++) {
        m_pDegats[i] = false;
    }

}

/**
 * @brief Le copy-constructor
 * @pre le bateau en paramètre ne doit pas être NULL
 * @param theB - le bateau à copier
 */
CBateau::CBateau(const CBateau& theBToCopy) {
    m_nom = theBToCopy.m_nom;
    m_taille = theBToCopy.m_taille;
    m_position = theBToCopy.m_position;
    m_pDegats = new bool[m_taille];

    for (int i = 0; i < m_taille; i++) {
        m_pDegats[i] = theBToCopy.m_pDegats[i];
    }
}

/**
 * @brief Détruit les objets créé en mémoire
 */
CBateau::~CBateau() {
    if (m_pDegats != NULL) {
        delete[] m_pDegats;
    }
}

/**
 * @brief Test si le bateau est touché à l'endroit du paramètre
 * @param i - index du tableau de degats lié au bateau
 * @return vrai si le bateau a été touché à la case du paramètre, faux sinon
 */
bool CBateau::getDegats(int i) {
    if (m_pDegats[i] == true){
        return true;
    }else{
        return false;
    }
}

/**
 * @brief Retourne le nom du bateau
 * @return l'attribut nom du bateau
 */
string CBateau::getNom() {
    return m_nom;
}

/**
 * @brief Retourne la taille du bateau
 * @return l'attribut taille du bateau
 */
int CBateau::getTaille() {
    return m_taille;
}

/**
 * @brief Retourne le point d'ancrage du bateau
 * @return une pair<int,int> du bateau
 */
pair<int, int> CBateau::getPosition() {
    return  m_position;
}

/**
 * @brief Définis le point d'ancrage du bateau
 * @pre i et j sont compris entre [0;9]
 * @param i - la ligne du point d'ancrage
 * @param j - la colone du point d'ancrage 
 */
void CBateau::setPosition(int i, int j){
    if (i >= 0 && i <= 9 && j >= 0 && j <= 9){
        m_position.first = i;
        m_position.second = j;
    }
}

/**
 * @brief Renvoie vrai si le bateau est coulé
 * @return vrai si lebateau et coulé, faux sinon
 */
bool CBateau::estCoule(){ 
    int i = 0;
    while(i < m_taille){
        if (!m_pDegats[i]){
            return false;
        }
        i++;
    }

    return true;
}

/**
 * @brief Renvoie vrai si la coordonnée passée en paramètre est un tir victorieux
 * @pre la coordonnée doit se trouver sur le bateau pour être victorieux et le bateau ne doit pas être touché à cet endroit
 * @param p - les coordonnées du tir
 * @return vrai si le tir est victorieux, false sinon
 */
bool CBateau::tirAdverse(pair<int, int> p) {
    if (!estCoule()) {
        if (p.first == m_position.first && (p.second >= m_position.second || p.second <= (m_position.second + m_taille))) {
            int tmp = 0;
            int index = 0;
            while (tmp < m_taille){
                if (p.second == m_position.second){
                    index = tmp;
                    tmp = m_taille;
                }
                tmp++;
            }
            if (!m_pDegats[index]) {
                m_pDegats[index] = true;
                return true;
            }
        }
    }
    return false;
}

/**
 * @brief Affiche les caractéristiques du bateau
 * @param os - flux de sortie
 * @param theB - le bateau à afficher
 * @return un flux de sortie contenant les caractéristiques du bateau
 */
ostream& operator<<(ostream& os, CBateau& theB) {
    os << "Nom : " << theB.m_nom << endl;
    os << "Taille : " << theB.m_taille << endl;
    os << "Point d'ancrage : x = " << theB.m_position.first ;
    os << " | y = " << theB.m_position.second << endl;

    os << "Touché ? : ";
    for (int i = 0; i < theB.m_taille; i++){
        os << " | " << theB.m_pDegats[i];
    }
    os << " | " << endl;

    return os;
}

void CBateau::operator=(const CBateau& theBToCopy) {
    if (this != &theBToCopy) {
        this->m_nom = theBToCopy.m_nom;
        this->m_taille = theBToCopy.m_taille;
        this->m_position = theBToCopy.m_position;
        this->m_pDegats = new bool[m_taille];

        for (int i = 0; i < this->m_taille; i++) {
            this->m_pDegats[i] = theBToCopy.m_pDegats[i];
        }
    }
}