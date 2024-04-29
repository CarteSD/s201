#include "image.h"
#include <iostream>
using namespace std;

Image::Image(string pCategorie,
             string pTitre,
             string pChemin) :
    m_categorie(pCategorie),
    m_titre(pTitre),
    m_chemin(pChemin) {

    }

string Image::getCategorie() const {
    return (*this).m_categorie;
}

string Image::getTitre() const {
    return (*this).m_titre;
}

string Image::getChemin() const {
    return (*this).m_categorie;
}

void Image::afficher() const {
    cout << "Titre : ";
    (*this).getTitre() == "" ? cout << "image sans titre" << endl : cout << (*this).getTitre() << endl;
}