#ifndef CGUI_H
#define CGUI_H

#include "BiblioStd.h"
#include "CBaseJeu.h"
#include "CArmada.h"
#include "CCoups.h"

class CGui : public CBaseJeu {

	private:
        char m_grilleJou[TAILLE_GRILLE - 1][TAILLE_GRILLE - 1];
        char m_grilleAdv[TAILLE_GRILLE - 1][TAILLE_GRILLE - 1];
        CArmada* m_pArmada;
        CCoups* m_pCoups;

	public:
                CGui();
                CGui(CArmada* pArmada, CCoups* pCoups);
                virtual ~CGui();

                void setArmadaCoups(CArmada* pArmada, CCoups* pCoups);
                friend ostream& operator<<(ostream& os, CGui& theG);
		bool positionnerBateaux() override;
		pair<int,int> choisirAttaque() override;
		void afficheGagne() override;
		void affichePerdu() override;

	private:
		void remplirDeuxGrilles(ostream& os) override;
		void afficherLaGrille(ostream& os, string jouOuAdv) override;

};

#endif
