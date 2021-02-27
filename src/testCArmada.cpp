#include "CArmada.h"

void testAjoutBateau() {
    CArmada armada;

    pair<int, int> p1 = (0, 5);
    CBateau b1("Bateau 1", p1, 2);

    p1.first = 1;
    p1.second = 3;
    CBateau b2("Bateau 2", p1, 4);

    armada.ajouterBateau(b1);
    armada.ajouterBateau(b2);
}

int main() {
    testAjoutBateau();


    return 0;
}