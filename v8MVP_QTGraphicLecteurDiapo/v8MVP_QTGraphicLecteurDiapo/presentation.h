#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <QObject>
#include <QTimer>
#include "lecteurvue.h"
#include "lecteur.h"

class Presentation : public QObject
{
    Q_OBJECT

private :
    LecteurVue *m_vue ;             // Vue du modèle MVP du projet
    Lecteur *m_lecteur ;            // Lecteur du moèdle MVP du projet (correspondant au modèle)
    QTimer *m_timer;                // Timer permettant le mode automatique
    unsigned int m_nbSecondes = 0;  // Nombre de secondes de défilement du mode automatique


public:
    explicit Presentation(QObject *parent = nullptr);   // Constructeur de l'objet Presentation

    /* 
                                            GETTERS & SETTERS
       Les setters permettent d'attribuer l'objet passé en paramètre à la donnée membre de l'objet Presentation
       Les getters permettent de retourner l'objet membre souhaité de l'objet Presentation
    */
    Lecteur* getLecteur();
    LecteurVue* getVue();
    void setLecteur(Lecteur*);
    void setVue(LecteurVue*);

private slots :
    void demandeAvancer();                      // Permet d'avancer dans le diaporama
    void demandeReculer();                      // Permet de reculer dans le diaporama
    void demandeChargerDiapo();                 // Permet de changer de diaporama
    void demandeChangerVitesseDefilement();     // Permet de changer la vitesse de défilement
    void demandeQuitter();                      // Permet de quitter l'application
    void demandeLancerDiapo();                  // Permet de lancer le diaporama, et de le passer en mode automatique
    void demandeArreterDiapo();                 // Permet d'arrêter le mode automatique du diaporama
    void demandeAProposDe();                    // Permet d'accéder à la page "A propos de ..."
    void demandeEnleverDiapo();                 // Permet d'enlever un diaporama
    void update();                              // Permet de mettre à jour le mode automatique
    void demandeChargerDiapos() ;               // Permet de charger tous les diaporamas et affiche le premier
    

};

#endif // PRESENTATION_H
