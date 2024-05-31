#include "diaporama.h"
#include "image.h"
#include "database.h"
#include <iostream>
#include <vector>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
using namespace std;

Diaporama::Diaporama(unsigned int pId, QString pTitre,
                     unsigned int pVitesseDefilement) :
    m_id(pId),
    m_nom(pTitre),
    m_vitesseDefilement(pVitesseDefilement),
    m_posCourante(0){

    }

void Diaporama::avancer() {
    if ((*this).m_posCourante < (*this).m_images.size() - 1) {
        (*this).m_posCourante++;
    }
    else {
        (*this).m_posCourante = 0;
    }
    (*this).m_images.at((*this).m_posCourante);
}

void Diaporama::reculer() {
    if ((*this).m_posCourante > 0) {
        (*this).m_posCourante--;
    }
    else {
        (*this).m_posCourante = (*this).nbImages() - 1;
    }
    (*this).m_images.at((*this).m_posCourante);
}

unsigned int Diaporama::nbImages() {
    return (*this).m_images.size();
}

void Diaporama::setVitesseDefilement(unsigned int pVitesse) {
    (*this).m_vitesseDefilement = pVitesse;
}

unsigned int Diaporama::getVitesseDefilement()
{
    return this->m_vitesseDefilement;
}

void Diaporama::chargerImages(vector<vector<unsigned int>> pTab, unsigned int pTailleTab) {
    Database db_images;
    if (!db_images.isOpen()) {
        db_images.openDataBase();
    }

    vector <Image*> allImages;
    QSqlQuery query;
    query = db_images.executerRequete("SELECT * FROM Diapos JOIN Familles ON Diapos.idFam = Familles.idFamille ORDER BY Diapos.idphoto");
    // for (int i = 0; query.next(); i++) {
        // qDebug() << query.value(0) << query.value(1) << query.value(2) << query.value(3) << query.value(5);
        // allImages.push_back(new Image(query.value(0).toInt(), query.value(5).toString(), query.value(1).toString(), ":///images" + query.value(3).toString()));
    // }
    /*
    while (query.next()) {
        // qDebug() << query.value(0) << query.value(1) << query.value(2) << query.value(3) << query.value(5);
        allImages.push_back(new Image(query.value(0).toInt(), query.value(5).toString(), query.value(1).toString(), ":///images" + query.value(3).toString()));
    }
    */
    query.next();
    do {
        // qDebug() << query.value(0) << query.value(1) << query.value(2) << query.value(3) << query.value(5);
        allImages.push_back(new Image(query.value(0).toInt(), query.value(5).toString(), query.value(1).toString(), ":///images" + query.value(3).toString()));
    } while(query.next());


    /*
    allImages.push_back(new Image("objet", "", ":///images/cartesDisney/Disney_tapis.gif"));
    allImages.push_back(new Image("personnage", "Alice", ":///images/cartesDisney/Disney_2.gif"));
    allImages.push_back(new Image("animal", "Mickey", ":///images/cartesDisney/Disney_19.gif"));
    allImages.push_back(new Image("personnage", "Pinnochio", ":///images/cartesDisney/Disney_29.gif"));
    allImages.push_back(new Image("objet", "chateau", ":///images/cartesDisney/Disney_0.gif"));
    allImages.push_back(new Image("personnage", "Blanche Neige", ":///images/cartesDisney/Disney_4.gif"));
    allImages.push_back(new Image("personnage", "Minnie", ":///images/cartesDisney/Disney_14.gif"));
    allImages.push_back(new Image("animal", "Bambi", ":///images/cartesDisney/Disney_3.gif"));
    */

    // Parcours du tableau passé en paramètre
    for (unsigned int i = 0; i < pTailleTab; i++) {
        (*this).m_images.push_back(allImages[pTab[i][1] - 1]);
    }
    db_images.closeDataBase();

}

Image* Diaporama::imageCourante() const {
    return (*this).m_images[(*this).m_posCourante];
}

QString Diaporama::getTitre() const {
    return (*this).m_nom;
}

unsigned int Diaporama::getPosCourante() const {
    return (*this).m_posCourante;
}

void Diaporama::setPosCourante(unsigned int pNum)
{
    (*this).m_posCourante = pNum;
}
