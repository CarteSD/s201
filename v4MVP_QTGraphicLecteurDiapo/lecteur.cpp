#include "lecteur.h"
#include "image.h"
#include "diaporama.h"
#include <iostream>
#include <vector>
using namespace std;

Lecteur::Lecteur() :
    m_mode(manuel),
    m_posCourante(0)
    {

    vector<vector<unsigned int>> imgs;


    // Création et chargement des diaporamas
    chargerDiaporamas();

    // Chargement des images dans chaque diaporama
        // Insertion des indices des images
        imgs.push_back({0, 1});
        imgs.push_back({3, 1, 4, 2});
        imgs.push_back({4, 1, 2, 3});
        imgs.push_back({1, 4, 3, 2});
        imgs.push_back({3, 2, 1, 4});
        /* Les images ont été reprises dans le code fourni dans la v0.
        Cependant, n'ayant pas d'idée de la manière de retranscription de l'ordre des images dans les diaporamas, nous les avons ordonnées à la main. */

        // Parcours des diaporamas pour charger leurs images
        for (unsigned int diapoCour = 0; diapoCour < diaporamas().size(); diapoCour++) {

            // Positionnement sur le diaporama correspondant
            changerDiaporama(diapoCour);

            // Chargement des images correspondant au tableaux
            diaporamaCourant()->chargerImages(imgs[diapoCour], imgs[diapoCour].size());
        }

        changerDiaporama(1);

    }

void Lecteur::setMode(Mode pMode) {
    (*this).m_mode = pMode ;
}

void Lecteur::changerDiaporama(unsigned int pIndDiapo) {
    if (pIndDiapo >= (*this).diaporamas().size()) {
        // qDebug() << "test";
        //("Aucun diaporama ne portant cet indice n'existe");
    }
    else {
        (*this).m_posCourante = pIndDiapo;
        (*this).diaporamaCourant()->setPosCourante(0);
    }
}

void Lecteur::enleverDiaporama() {
    (*this).changerDiaporama(0);
}

void Lecteur::chargerDiaporamas() {
    (*this).m_diapos.push_back(new Diaporama("Diaporama par défaut", 1));
    (*this).m_diapos.push_back(new Diaporama("Diaporama de Pantxika", 2));
    (*this).m_diapos.push_back(new Diaporama("Diaporama de Thierry", 4));
    (*this).m_diapos.push_back(new Diaporama("Diaporama de Yann", 3));
    (*this).m_diapos.push_back(new Diaporama("Diaporama de Manu", 1));
}

vector <Diaporama*> Lecteur::diaporamas() const {
    return (*this).m_diapos;
}

Diaporama* Lecteur::diaporamaCourant() const {
    return (*this).m_diapos[(*this).m_posCourante];
}

Lecteur::~Lecteur() {
    
}

Mode Lecteur::getMode()
{
    return (*this).m_mode;
}
