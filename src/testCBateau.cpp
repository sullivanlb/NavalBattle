#include "CBateau.h"

void testConstructeur() {
    // Cas normaux
    CBateau b1;
    cout << b1 << endl;

    pair<int, int> p1 (3, 4);
    CBateau b2("Naval", p1, 4);
    cout << b2 << endl;

    CBateau b3(b2);
    cout << b3 << endl;

    // Cas d'erreurs
    CBateau bErr1("", p1, 5);

    p1.first = -1;
    CBateau bErr2("Naval", p1, 6);

}

int main() {
    try {
        testConstructeur();
    } catch (invalid_argument& ia) {
        cout << ia.what() << endl;
        
    }

    return 0;
}