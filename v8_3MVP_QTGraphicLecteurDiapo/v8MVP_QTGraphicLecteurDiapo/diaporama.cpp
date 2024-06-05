#include "diaporama.h"
#include "image.h"
#include "database.h"
#include <iostream>
#include <vector>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
using namespace std;

Diaporama::Diaporama(unsigned int pId,
                     QString pTitre,
                     unsigned int pVitesseDefilement) :
    m_id(pId),
    m_nom(pTitre),
    m_vitesseDefilement(pVitesseDefilement),
    m_posCourante(0)  {

    }

void Diaporama::avancer()
{
    // Si la position courante du diaporama est inférieure à la taille de celui-ci (-1 car l'indice de départ est 0)
    if ((*this).m_posCourante < (*this).m_images.size() - 1) {
        (*this).m_posCourante++;
    }

    // Sinon, retour à 0 pour reboucler au début du diaporama
    else {
        (*this).m_posCourante = 0;
    }

    // Mise à jour de la position dans le vecteur d'images
    (*this).m_images.at((*this).m_posCourante);
}

void Diaporama::reculer()
{
    // Si la position courante du diaporama est supérieure à 0
    if ((*this).m_posCourante > 0) {
        (*this).m_posCourante--;
    }

    // Sinon, retour à la fin (-1 car l'indic démarre à 0) pour reboucler
    else {
        (*this).m_posCourante = (*this).nbImages() - 1;
    }

    // Mise à jour de la position dans le vecteur d'images
    (*this).m_images.at((*this).m_posCourante);
}

unsigned int Diaporama::nbImages() const
{
    return (*this).m_images.size();
}

void Diaporama::setVitesseDefilement(unsigned int pVitesse)
{

    // Déclaration de la requête (query) de type QSqlQuery
    QSqlQuery query;

    // Définition de la requête de type QString
    QString req = "UPDATE Diaporamas SET vitesseDefilement = :vitesse WHERE idDiaporama = :id";

    // Préparation de la requête
    query.prepare(req);

    // Attribution des paramètres
    query.bindValue(":vitesse", pVitesse);
    query.bindValue(":id", this->getId());

    // Exécution de la requête
    if (!query.exec()) {
        qDebug() << "Une erreur est survenue lors de la mise à jour dans la base de données.";
    }
    else {
        (*this).m_vitesseDefilement = pVitesse;
    }
}

unsigned int Diaporama::getVitesseDefilement() const
{
    return this->m_vitesseDefilement;
}

void Diaporama::chargerImages(vector<vector<unsigned int>> pTab, unsigned int pTailleTab, vector <Image*> pAllImages)
{
    // Attribution des images dans le diaporama
    // Parcours du tableau passé en paramètre pour attribuer les images
    for (unsigned int i = 0; i < pTailleTab; i++) {

        // Récupération de l'image dans le vectuer conteant toutes les images
        (*this).m_images.push_back(pAllImages[pTab[i][1] - 1]);
    }
}

Image* Diaporama::imageCourante() const
{
    return (*this).m_images[(*this).m_posCourante];
}

QString Diaporama::getTitre() const
{
    return (*this).m_nom;
}

unsigned int Diaporama::getPosCourante() const
{
    return (*this).m_posCourante;
}

void Diaporama::setPosCourante(unsigned int pNum)
{
    (*this).m_posCourante = pNum;
}

unsigned int Diaporama::getId() const
{
    return this->m_id;
}
