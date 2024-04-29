#include <iostream>
#include "image.h"
#include "diaporama.h"
#include "lecteur.h"
using namespace std;

int main(void) {

    // Déclaration des variables
    Lecteur lecteur;                    // lecteur de diaporama
    char choixAction;                   /* action que décide de faire l'utilisateur (Avancer, Reculer, Changer
                                        de diaporama, Quitter) */
    unsigned int choixDiapo;            // indice du diaporama que souhaite afficher l'utilisateur
    vector<vector<unsigned int>> imgs;  /* vecteur contenant les vecteurs correspondant aux indices des images de 
                                        chaque diaporama.
                                        Nous utilisons un vecteur de vecteurs afin de réaliser un tableau multidimensionnels à taille variable (tous les diaporamas ne contiennent pas le même nombre d'images)*/



    // Création et chargement des diaporamas
    lecteur.chargerDiaporamas();
    
    // Chargement des images dans chaque diaporama
        // Insertion des indices des images
        imgs.push_back({0, 1});
        imgs.push_back({3, 1, 4, 2});
        imgs.push_back({4, 1, 2, 3});
        imgs.push_back({1, 4, 3, 2});
        imgs.push_back({3, 2, 1, 4});
        /* Les images ont été reprises dans le code fourni dans la v0.
        Cependant, n'ayant pas d'idée de la manière de retranscription de l'ordre des images dans les diaporamas, nous les avons ordonnées à la main. */
    
        // Parcours des diaporamas pour charger leurs images
        for (unsigned int diapoCour = 0; diapoCour < lecteur.diaporamas().size(); diapoCour++) {

            // Positionnement sur le diaporama correspondant
            lecteur.changerDiaporama(diapoCour);
            
            // Chargement des images correspondant au tableaux
            lecteur.diaporamaCourant()->chargerImages(imgs[diapoCour], imgs[diapoCour].size());
        }
        
    // Repositionnement sur le diaporama par défaut (d'index 0) et affichage de son titre ainsi que de sa première image.
    lecteur.changerDiaporama(0);
    cout << lecteur.diaporamaCourant()->getTitre() << endl;
    lecteur.diaporamaCourant()->imageCourante()->afficher();

    // Boucle d'interactions de l'utilisateur
    while(choixAction != 'Q') {

        // Saisie du choix de l'utilisateur
        cout << endl << "Menu des actions possibles :" << endl;
        cout << "A: Avancer, R: Reculer, C: Changer de diaporama, Q: Quitter" << endl;
        cout << "Votre choix ? : ";
        cin >> choixAction;

        // Exécution de l'action demandée
        switch (choixAction) {
            case 'A': // avancer
                lecteur.diaporamaCourant()->avancer();
                system("cls");
                lecteur.diaporamaCourant()->imageCourante()->afficher();
                break;
                
            case 'R': // reculer
                lecteur.diaporamaCourant()->reculer();
                system("cls");
                lecteur.diaporamaCourant()->imageCourante()->afficher();
                break;
                
            case 'C': // changer de diaporama
                cout << endl << "Changer de diaporama (saisir l'indice du diaporama) ? : ";
                cin >> choixDiapo;
                lecteur.changerDiaporama(choixDiapo);
                system("cls");
                cout << lecteur.diaporamaCourant()->getTitre() << endl;
                lecteur.diaporamaCourant()->imageCourante()->afficher();
                break;
                
            case 'Q': // quitter
                system("cls");
                cout << "Au revoir !" << endl;
                break;
                
            default: // défaut
                system("cls");
                cout << "Choix invalide. Veuillez saisir A(vancer), R(eculer), C(hanger de diaporama) ou Q(uitter)." << endl;
        }

    }

    return 0;

}
