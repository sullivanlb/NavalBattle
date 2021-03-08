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
}

int main () {
    
    //testPositionnerBateaux();
    testAffichage();

    return 0;
}