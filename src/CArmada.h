#ifndef CARMADA_H
#define CARMADA_H

#include "BiblioStd.h"
#include "CBateau.h"

#define MAX_ESSAIS 20

class CArmada {

    private:
        vector<CBateau> m_listeBateaux;

    public:
        void ajouterBateau(CBateau& unBat);
        CBateau* getBateau(int i);
        int getEffectifTotal();
        int getNbreTotCases();
        int getEffectif();
        void getArmadaFromFile();
        bool placerAleatoirement();
        
};

#endif