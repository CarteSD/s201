#include "diaporama.h"
#include <vector>
#include <iostream>
using namespace std;

#ifndef LECTEUR_H
#define LECTEUR_H

enum Mode {automatique, manuel} ;
    /* Le Mode correspond au mode de lecture du lecteur de diaporama.
       automatique : grâce à la donnée membre m_vitesseDefilement de l'objet Diaporama, le lecteur basculera
                     automatiquement à l'image suivante du diaporama toutes les [m_vitesseDefilement] secondes
       manuel : si le lecteur est en mode manuel, c'est à l'utilisateur de saisir l'action qu'il souhaite faire
                afin de que l'image suivante / précédente s'affiche. */

class Lecteur {
    protected :
        Mode m_mode;                    // mode de lecteur du diaporama (automatique / manuel)
        unsigned int m_posCourante;     /* position courante du lecteur, c'est à dire l'index du diaporama
                                                 que nous exploitons dans m_diapos */
        vector <Diaporama*> m_diapos;   // vecteur de pointeurs vers les diaporamas présents dans le lecteur

    public :
        Lecteur() ;
            /* But : constructeur de l'objet Lecteur */

        void setMode(Mode pMode);
            /* But : changer le mode de défilement du lecteur */

        void changerDiaporama(unsigned int pIndDiapo);
            /* But : changer de diaporama
                     Le paramètre pIndDiapo correspond à l'indice du diaporama dans le vecteur m_dipoas */

        void enleverDiaporama();
            /* But : enlever le diaporama chargé. Nous avons décidé de rebasculer sur le diaporama par défaut */

        void chargerDiaporamas();
            /* But : charger tous les diaporamas dans le lecteur.
                     Chaque diaporama sera ajouter au vecteur m_diapos */

        vector <Diaporama*> diaporamas() const;
            /* But : retourne la donnée membre m_diapos, le vecteur de pointeurs vers les diaporamas */

        Diaporama* diaporamaCourant() const;
            /* But : retourne l'adresse du diaporama courant du lecteur */

        ~Lecteur();
            /* But : destructeur de la classe Lecteur*/

        Mode getMode();
            /* But : retourne la donnée membre m_mode, le mode de lecteur actuel */

        void trierImageParOrdreCroissant(vector<vector<vector<unsigned int>>> &);
            /* But : ordonne les images dans l'ordre de rang en se basant sur le vecteur passé en paramètre. */

        unsigned int getPosCourante();
            /* But : retourne m_posCourante */
};

#endif
