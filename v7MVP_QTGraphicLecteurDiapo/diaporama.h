#include <iostream>
#include <vector>
#include "image.h"

using namespace std;

#ifndef DIAPORAMA_H
#define DIAPORAMA_H

class Diaporama {
    protected :
        unsigned int m_id;
        vector <Image*> m_images;             // vecteur de pointeurs vers les images présentes dans le diaporama
        QString m_nom;                         // nom du diaporama
        unsigned int m_vitesseDefilement;     /* vitesse de défilement du diaporama lorsque le lecteur est en
                                                 mode automatique */
        unsigned int m_posCourante;           /* position courante du diaporama, c'est à dire l'index de l'image
                                                 que nous affichons dans m_images */


    public :
        Diaporama(unsigned int pId, QString pTitre = "Sans titre",
                  unsigned int pVitesseDefilement = 2);
            /* But : constructeur par défaut */

        void avancer();
            /* But : avancer au sein du vecteur d'images m_images */

        void reculer();
            /* But : reculer au sein du vecteur d'images m_images */

        unsigned int nbImages();
            /* But : retourne le nombre d'images, correspondant à la taille du vecteur m_images*/

        void setVitesseDefilement(unsigned int pVitesse = 2);
            /* But : modifier la vitesse de défilement lorsque le lecteur est en mode automatique.
               Par défaut, si aucun paramètre n'est passé, la vitesse de défilement sera établie à 2 secondes. */

        unsigned int getVitesseDefilement();
            /* But : retourne m_vitesseDefilement, correspondant à la vitesse de défilement du diaporama lorsqu'il est en mode automatique. */

        void chargerImages(vector<vector<unsigned int>> pTab, unsigned int pTailleTab);
            /* But : charge les images d'un diaporama grâce au tableau pTab passé en paramètre.
               Ce tableau pTab contient les indices des images que doit afficher le diaporama, trié par ordre d'affichage*/

        Image* imageCourante() const;
            /* But : retourne l'adresse de l'image courante du diaporama */

        QString getTitre() const;
            /* But : retourne m_nom, le titre du diaporama */

        unsigned int getPosCourante() const;
            /* But : retourne m_posCourante, la position de l'image dans le diaporama */

        void setPosCourante(unsigned int);
            /* But : assigne le paramètre pLecteur à la donnée membre m_posCourante */


};

#endif
