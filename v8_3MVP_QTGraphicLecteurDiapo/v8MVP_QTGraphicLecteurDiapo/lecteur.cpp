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
    // Déclaration de la base des données (db_diaporamas) de type Database
    Database db;

    // Déclaration de la requête (query) de type QSqlQuery
    QSqlQuery query;

    // Ouverture de la base de données si celle-ci est fermée
    if (!db.isOpen()) {
        db.openDataBase();
    }

    // Exécution de la requête
    query = db.executerRequete("SELECT * FROM Diaporamas");

        do {
            (*this).m_diapos.push_back(new Diaporama(query.value(0).toUInt(), query.value(1).toString(), query.value(2).toUInt()));
        } while (query.next());


    vector<vector<vector<unsigned int>>> imgs_ind;
    /* Description de imgs_ind :
        - vecteur de vecteur de vecteur, plutôt vecteur de listes de listes : dans chaque sous-liste est contenu en premier élément la position de l'image dans le diaporama.
        Le deuxième élément correspond à la position de l'image dans le vecteur content toutes les images.
    */
    for (unsigned int i = 0; i < (*this).m_diapos.size() - 1; i++) {
            imgs_ind.push_back({});
    }

    query = db.executerRequete("SELECT * FROM DiaposDansDiaporama");
    for (int i = 0; query.next(); i++) {
        imgs_ind[query.value(1).toInt() - 1].push_back({query.value(2).toUInt(), query.value(0).toUInt()});
    }

    vector <Image*> allImages;
    query = db.executerRequete("SELECT * FROM Diapos JOIN Familles ON Diapos.idFam = Familles.idFamille ORDER BY Diapos.idphoto");
    query.next();
    // Remplissage du vecteur contenant toutes les images
    do {
        allImages.push_back(new Image(query.value(0).toInt(),                   // id
                                      query.value(5).toString(),                // catégorie
                                      query.value(1).toString(),                // titre
                                      ":///images" + query.value(3).toString()  // chemin d'accès
                                      ));
    } while(query.next()); // boucle tant que nous pouvons avancer dans les enregistrements

    trierImageParOrdreCroissant(imgs_ind);

    // Parcours des diaporamas pour charger leurs images
    for (unsigned int diapoCour = 1; diapoCour < diaporamas().size(); diapoCour++) {

        // Positionnement sur le diaporama correspondant
        changerDiaporama(diapoCour);

        // Chargement des images correspondant au tableaux
        diaporamaCourant()->chargerImages(imgs_ind[diapoCour - 1], imgs_ind[diapoCour - 1].size(), allImages);
    }

    changerDiaporama(0);
}

vector <Diaporama*> Lecteur::diaporamas() const {
    return (*this).m_diapos;
}

Diaporama* Lecteur::diaporamaCourant() const {
    return (*this).m_diapos[(*this).m_posCourante];
}

Lecteur::~Lecteur() {

}

Mode Lecteur::getMode() const
{
    return (*this).m_mode;
}

void Lecteur::trierImageParOrdreCroissant(vector<vector<vector<unsigned int>>> &pVec) {
    unsigned int taille = pVec.size();

    // Parcours de tous les diaporamas
    for (unsigned int numDiapo = 0; numDiapo < taille; numDiapo++) {
        unsigned int nbImgDansDiapo = pVec[numDiapo].size();

        // Tri à bulles pour chaque diaporama
        for (unsigned int i = 0; i < nbImgDansDiapo - 1; i++) {
            for (unsigned int j = 0; j < nbImgDansDiapo - 1 - i; j++) {
                unsigned int posImg = pVec[numDiapo][j][0];
                unsigned int posImgNext = pVec[numDiapo][j + 1][0];

                if (posImg > posImgNext) {
                    // Inversion des deux éléments
                    vector<unsigned int> temp = pVec[numDiapo][j];
                    pVec[numDiapo][j] = pVec[numDiapo][j + 1];
                    pVec[numDiapo][j + 1] = temp;
                }
            }
        }
    }
}

unsigned int Lecteur::getPosCourante() const
{
    return this->m_posCourante;
}



