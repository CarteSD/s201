#include "image.h"
#include <iostream>
using namespace std;

Image::Image(int pId,
             QString pCategorie,
             QString pTitre,
             QString pChemin) :
    m_id(pId),
    m_categorie(pCategorie),
    m_titre(pTitre),
    m_chemin(pChemin) {

    }

QString Image::getCategorie() const {
    return (*this).m_categorie;
}

QString Image::getTitre() const {
    return (*this).m_titre;
}

QString Image::getChemin() const {
    return (*this).m_chemin;
}

/*
void Image::afficher() const {
    // REFAIRE POUR POUVOIR AFFICHER SUR NOTRE FENETRE QT
    cout << "Titre : ";
    (*this).getTitre() == "" ? cout << "image sans titre" << endl : cout << (*this).getTitre() << endl;
}
*/
