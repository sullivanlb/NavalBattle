#include "CGui.h"

void testPositionnerBateaux() {
    cout << "***TEST POSITIONNER BATEAUX***" << endl;

    CGui gui;
    CArmada armada;
    CBateau bateau("naval", pair<int, int> (2, 3), 4);

    for (int i = 0; i < 5; i++)
        armada.ajouterBateau(bateau);

    CArmada* pArmada = &armada;
    CCoups* pCoups = new CCoups();

    gui.setArmadaCoups(pArmada, pCoups);

    cout << "Réussi : " << gui.positionnerBateaux() << endl; 
}

void testAffichage() {
    cout << endl << "***TEST AFFICHAGE***" << endl;

    CGui gui;
    CArmada armada;

    armada.getArmadaFromFile();
    armada.placerAleatoirement();
    
    CArmada* pArmada = &armada;
    CCoups* pCoups = new CCoups();

    gui.setArmadaCoups(pArmada, pCoups);

    cout << gui;

    gui.afficheGagne();
    gui.affichePerdu();
}

void testChoisirAttaque() {
    cout << endl << "***TEST CHOISIR ATTAQUE***" << endl;

    CGui gui;
    CArmada armada;

    armada.getArmadaFromFile();
    armada.placerAleatoirement();
    
    CArmada* pArmada = &armada;
    CCoups* pCoups = new CCoups();

    gui.setArmadaCoups(pArmada, pCoups);

    pair<int, int> p = gui.choisirAttaque();
    cout << "x = " << p.first << " & y = " << p.second << endl;
}

int main () {
    
    //testPositionnerBateaux();
    //testAffichage();
    testChoisirAttaque();

    return 0;
}