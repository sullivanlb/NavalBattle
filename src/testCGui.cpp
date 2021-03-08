#include "CGui.h"

void test () {
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

int main () {

    test();

    return 0;
}