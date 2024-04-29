#include <iostream>
using namespace std;

#ifndef IMAGE_H
#define IMAGE_H

class Image {
    protected :
        string m_categorie;   // catégorie de l'image
        string m_titre;       // titre de l'image
        string m_chemin;      // chemin d'accès de l'image

    public :
        Image(string pCategorie = "",
              string pTitre = "sans-titre",
              string pChemin = "");
            /* But : constructeur de l'objet Image */
        
        string getCategorie() const;
            /* But : retourne m_categorie, la catégorie de l'image */

        string getTitre() const;
            /* But : retourne m_titre, le titre de l'image*/

        string getChemin() const;
            /* But : retourne m_chemin, le chemin d'accès de l'image*/

        void afficher() const;
            /* But : afficher l'image, c'est à dire sa donnée membre m_titre */
};

#endif