#include "lecteur.h"
#include "diaporama.h"
#include <iostream>
using namespace std;

Lecteur::Lecteur() :
    m_mode(automatique),
    m_posCourante(0) {

    }

void Lecteur::changerMode(Mode &pMode) {
    (*this).m_mode = pMode ;
}

void Lecteur::changerDiaporama(unsigned int pIndDiapo) {
    if (pIndDiapo >= (*this).diaporamas().size()) {
        cout << "Aucun diaporama ne portant cet indice n'existe" << endl;
    }
    else {
        (*this).m_posCourante = pIndDiapo;
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