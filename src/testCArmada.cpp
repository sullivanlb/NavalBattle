#include "CArmada.h"

void testAjoutBateau() {
    CArmada armada;

    pair<int, int> p1 (0, 5);
    CBateau b1("Bateau 1", p1, 2);

    p1.first = 1;
    p1.second = 3;
    CBateau b2("Bateau 2", p1, 4);

    armada.ajouterBateau(b1);
    armada.ajouterBateau(b2);

    cout << *armada.getBateau(0) << endl;
    cout << *armada.getBateau(1) << endl;
}

void testGet() {
    CArmada armada;

    armada.getArmadaFromFile();

    cout << "Effectif Total : " << armada.getEffectifTotal() << endl;
    cout << "Nombre de cases total : " << armada.getNbreTotCases() << endl;
    cout << "Effectif : " << armada.getEffectif() << endl;
}

int main() {
    //testAjoutBateau();
    testGet();


    return 0;
}