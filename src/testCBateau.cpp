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
    try {
        CBateau bErr1("", p1, 5);
    }catch (invalid_argument& ia) {
        cout << ia.what() << endl;
    }

    try {
        p1.first = -1;
        CBateau bErr2("Naval", p1, 6);
    }catch (invalid_argument& ia) {
        cout << ia.what() << endl;
    }

    try {
        p1.first = 12;
        p1.second = -20;
        CBateau bErr3("Naval", p1, 6);
    }catch (invalid_argument& ia) {
        cout << ia.what() << endl;
    }

    try {
        p1.second = 0;
        CBateau bErr4("Naval", p1, -5);
    }catch (invalid_argument& ia) {
        cout << ia.what() << endl;
    }

    // Cas limites
    p1.first = 0;
    p1.second = 0;
    CBateau b5("V", p1, 1);
    cout << endl << b5 << endl;
}

int main() {
    testConstructeur();

    return 0;
}