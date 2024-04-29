#include "diaporama.h"
#include "image.h"
#include <iostream>
#include <vector>
using namespace std;

Diaporama::Diaporama(string pTitre,
                     unsigned int pVitesseDefilement) :
    m_nom(pTitre),
    m_vitesseDefilement(pVitesseDefilement),
    m_posCourante(0) {

    }

void Diaporama::avancer() {
    if ((*this).m_posCourante < (*this).m_images.size() - 1) {
        (*this).m_posCourante++;
        (*this).m_images.at((*this).m_posCourante);
    }
}

void Diaporama::reculer() {
    if ((*this).m_posCourante > 0) {
        (*this).m_posCourante--;
        (*this).m_images.at((*this).m_posCourante);
    }
}

unsigned int Diaporama::nbImages() {
    return (*this).m_images.size();
}

void Diaporama::vitesseDefilement(unsigned int pVitesse) {
    (*this).m_vitesseDefilement = pVitesse;
}

void Diaporama::chargerImages(vector <unsigned int> pTab, unsigned int pTailleTab) {
    vector <Image*> allImages;
    allImages.push_back(new Image("objet", "", "C:\\cartesDisney\\Disney_tapis.gif"));
    allImages.push_back(new Image("personnage", "Alice", "C:\\cartesDisney\\Disney_2.gif"));
    allImages.push_back(new Image("animal", "Mickey", "C:\\cartesDisney\\Disney_19.gif"));
    allImages.push_back(new Image("personnage", "Pinnochio", "C:\\cartesDisney\\Disney_29.gif"));
    allImages.push_back(new Image("objet", "chateau", "C:\\cartesDisney\\Disney_0.gif"));
    allImages.push_back(new Image("personnage", "Blanche Neige", "C:\\cartesDisney\\Disney_4.gif"));
    allImages.push_back(new Image("personnage", "Minnie", "C:\\cartesDisney\\Disney_14.gif"));
    allImages.push_back(new Image("animal", "Bambi", "C:\\cartesDisney\\Disney_3.gif"));
    
    // Parcours du tableau passé en paramètre
    for (unsigned int i = 0; i < pTailleTab; i++) {
        (*this).m_images.push_back(allImages[pTab[i]]);
    }
}

Image* Diaporama::imageCourante() const {
    return (*this).m_images[(*this).m_posCourante];
}

string Diaporama::getTitre() const {
    return (*this).m_nom;
}