#include "lecteur.h"
#include "image.h"
#include "diaporama.h"
#include "database.h"
#include <iostream>
#include <vector>
using namespace std;

Lecteur::Lecteur() :
    m_mode(manuel),
    m_posCourante(0)
    {
    chargerDiaporamas();
}

void Lecteur::setMode(Mode pMode) {
    (*this).m_mode = pMode ;
}

void Lecteur::changerDiaporama(unsigned int pIndDiapo) {
    (*this).m_posCourante = pIndDiapo;
    (*this).diaporamaCourant()->setPosCourante(0);
}

void Lecteur::enleverDiaporama() {
    (*this).m_posCourante = NULL;
}

void Lecteur::chargerDiaporamas() {
    Database db_diaporamas;
    if (db_diaporamas.openDataBase()) {
        QSqlQuery query ;
        query.exec("SELECT * FROM Diaporamas") ;
        do {
            (*this).m_diapos.push_back(new Diaporama(query.value(0).toUInt(), query.value(1).toString(), query.value(2).toUInt()));
        } while (query.next());
        /*
    (*this).m_diapos.push_back(new Diaporama("Diaporama de Pantxika", 2));
    (*this).m_diapos.push_back(new Diaporama("Diaporama de Thierry", 4));
    (*this).m_diapos.push_back(new Diaporama("Diaporama de Yann", 3));
    (*this).m_diapos.push_back(new Diaporama("Diaporama de Manu", 1));
    */

    vector<vector<vector<unsigned int>>> imgs_ind;
    /* Description de imgs_ind :
        - vecteur de vecteur de vecteur, plutôt vecteur de listes de listes : dans chaque sous-liste est contenu en premier élément la position de l'image dans le diaporama.
        Le deuxième élément correspond à la position de l'image dans le vecteur content toutes les images.
    */
    for (unsigned int i = 0; i < (*this).m_diapos.size() - 1; i++) {
            imgs_ind.push_back({});
    }

    Database db_imagesDansDiapo;
    if (db_imagesDansDiapo.openDataBase()) {
        QSqlQuery query;
        query = db_imagesDansDiapo.executerRequete("SELECT * FROM DiaposDansDiaporama");
        for (int i = 0; query.next(); i++) {
            // qDebug() << query.value(0) << query.value(1) << query.value(2);
            imgs_ind[query.value(1).toInt() - 1].push_back({query.value(2).toUInt(), query.value(0).toUInt()});
        }
        db_imagesDansDiapo.closeDataBase();
    }
    // Chargement des images dans chaque diaporama
        // Insertion des indices des images
    /*
        imgs_ind.push_back({{0, 0}, {1, 1}}); // Diaporama par défaut
        imgs_ind.push_back({{3, 3}, {2, 5}, {4, 1}, {1, 2}}); // Diaporama de Pantxika
        imgs_ind.push_back({{1, 3}, {2, 5}, {3, 1}, {4, 2}}); // Diaporama de Thierry
        imgs_ind.push_back({{2, 3}, {1, 5}, {4, 1}, {3, 2}}); // Diaporama de Yann
        imgs_ind.push_back({{4, 3}, {3, 5}, {2, 1}, {1, 2}}); // Diaporama de Manu
        */

        trierImageParOrdreCroissant(imgs_ind);



        // Parcours des diaporamas pour charger leurs images
        for (unsigned int diapoCour = 1; diapoCour < diaporamas().size(); diapoCour++) {

            // Positionnement sur le diaporama correspondant
            changerDiaporama(diapoCour);

            // Chargement des images correspondant au tableaux
            diaporamaCourant()->chargerImages(imgs_ind[diapoCour - 1], imgs_ind[diapoCour - 1].size());
        }

        changerDiaporama(0);
    }
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

void Lecteur::trierImageParOrdreCroissant(vector<vector<vector<unsigned int>>> &vec) {
    unsigned int taille = vec.size();

    // Parcours de tous les diaporamas
    for (unsigned int numDiapo = 0; numDiapo < taille; numDiapo++) {
        unsigned int nbImgDansDiapo = vec[numDiapo].size();

        // Tri à bulles pour chaque diaporama
        for (unsigned int i = 0; i < nbImgDansDiapo - 1; i++) {
            for (unsigned int j = 0; j < nbImgDansDiapo - 1 - i; j++) {
                unsigned int posImg = vec[numDiapo][j][0];
                unsigned int posImgNext = vec[numDiapo][j + 1][0];

                if (posImg > posImgNext) {
                    // Inversion des deux éléments
                    vector<unsigned int> temp = vec[numDiapo][j];
                    vec[numDiapo][j] = vec[numDiapo][j + 1];
                    vec[numDiapo][j + 1] = temp;
                }
            }
        }
    }
}

unsigned int Lecteur::getPosCourante()
{
    return this->m_posCourante;
}



