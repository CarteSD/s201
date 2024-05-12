#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <QObject>
#include "lecteurvue.h"
#include "lecteur.h"

class Presentation : public QObject
{
    Q_OBJECT

private :
    LecteurVue *m_vue ;
    Lecteur *m_lecteur ;

public:
    explicit Presentation(QObject *parent = nullptr);

    Lecteur* getLecteur() ;
    LecteurVue* getVue() ;
    void setLecteur(Lecteur*) ;
    void setVue(LecteurVue*) ;

private slots :
    void demandeAvancer() ; // Permet d'avancer dans le diaporama
    void demandeReculer() ; // Permet de reculer dans le diaporama
    void demandeChangerDiapo() ; // Permet de Changer de diaporama
    void demandeChangerVitesseDefilement() ; // Permet de changer la vitesse de défilement
    void demandeQuitter() ; // Permet de quitter l'application
    void demandeModeManuel() ; // Permet de passer en mode manuel
    void demandeModeAuto() ; // Permet de passer en mode automatique
    void demandeAProposDe() ; // Permet d'accéder à la page "A propos de ..."
    void demandeEnleverDiapo() ; // Permet d'enlever un diaporamat
};

#endif // PRESENTATION_H
