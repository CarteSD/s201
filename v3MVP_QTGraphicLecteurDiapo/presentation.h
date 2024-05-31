#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <QObject>
#include "lecteurvue.h"
#include "lecteur.h"

class Presentation : public QObject
{
    Q_OBJECT

private :
    LecteurVue *m_vue ;     // Vue du modèle MVP du projet
    Lecteur *m_lecteur ;    // Lecteur du moèdle MVP du projet (correspondant au modèle)

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
    void demandeChangerDiapo();                 // Permet de changer de diaporama
    void demandeChangerVitesseDefilement();     // Permet de changer la vitesse de défilement
    void demandeQuitter();                      // Permet de quitter l'application
    void demandeModeManuel();                   // Permet de passer en mode manuel
    void demandeModeAuto();                     // Permet de passer en mode automatique
    void demandeAProposDe();                    // Permet d'accéder à la page "A propos de ..."
    void demandeEnleverDiapo();                 // Permet d'enlever un diaporama
};

#endif // PRESENTATION_H
