#include <iostream>
using namespace std;

#ifndef IMAGE_H
#define IMAGE_H

#include <QString>

class Image {
    protected :
        int m_id;              // id de l'image
        QString m_categorie;   // catégorie de l'image
        QString m_titre;       // titre de l'image
        QString m_chemin;      // chemin d'accès de l'image

    public :
        Image(int pId,
              QString pCategorie = "",
              QString pTitre = "sans-titre",
              QString pChemin = "");
            /* But : constructeur de l'objet Image */

        unsigned int getId() const;
            /* But : retourne m_id, l'ID de l'image */
        
        QString getCategorie() const;
            /* But : retourne m_categorie, la catégorie de l'image */

        QString getTitre() const;
            /* But : retourne m_titre, le titre de l'image*/

        QString getChemin() const;
            /* But : retourne m_chemin, le chemin d'accès de l'image*/

        void afficher() const;
            /* But : afficher l'image, c'est à dire sa donnée membre m_titre */
};

#endif
