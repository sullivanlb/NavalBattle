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

}

pair<int,int> CGui::choisirAttaque() {

}

void CGui::afficheGagne() {

}

void CGui::affichePerdu() {

}

void CGui::remplirDeuxGrilles(ostream& os) {

}
void CGui::afficherLaGrille(ostream& os, string jouOuAdv) {

}