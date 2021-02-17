#include "CBateau.h"

void testConstructeur() {
    cout << "***TEST CONSTRUCTEURS***" << endl;

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

void testAccesseurs() {
    cout << "***TEST ACCESSEURS***" << endl;

    pair<int, int> p1 (3, 4);
    CBateau b1("Naval", p1, 4);
    cout << "Nom : " << b1.getNom() << endl;
    cout << "Position : x = " << b1.getPosition().first << " | y = " << b1.getPosition().second << endl;
    cout << "Taille : " << b1.getTaille() << endl;

    cout << "Touché ? : ";
    for (int i = 0; i < b1.getTaille(); i++){
        cout << " | " << b1.getDegats(i);
    }
    cout << " | " << endl;
}

void testTir() {
    cout << endl << "***TEST TIR***" << endl;

    pair<int, int> p1 (3, 4);
    CBateau b1("Naval", p1, 4);

    pair<int, int> p2 (3, 6);
    if (b1.tirAdverse(p2)) cout << "Test Tir 1 OK" << endl;
    else cout << "Test Tir 1 Erreur" << endl;

    p2.first = 0;
    p2.second = 0;
    if (!b1.tirAdverse(p2)) cout << "Test Tir 2 OK" << endl;
    else cout << "Test Tir 2 Erreur" << endl;
}

void testOperateurEgal() {
    cout << endl << "***TEST OPERATEUR EGAL***" << endl;

    pair<int, int> p1 (1, 1);
    CBateau b1("Bateau 1", p1, 1);

    pair<int, int> p2 (2, 2);
    CBateau b2("Bateau 2", p2, 2);

    cout << b1 << endl;
    cout << b2 << endl;

    b2 = b1;
    cout << "b2 = b1 : " << endl << b2 << endl;
}

int main() {
    testConstructeur();
    testAccesseurs();
    testTir();
    testOperateurEgal();

    return 0;
}