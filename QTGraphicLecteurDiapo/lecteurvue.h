#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>

enum Mode {automatique, manuel} ;

QT_BEGIN_NAMESPACE
namespace Ui { class LecteurVue; }
QT_END_NAMESPACE

// Implémentation de la classe LecteurVue
class LecteurVue : public QMainWindow
{
    Q_OBJECT

public:
    LecteurVue(QWidget *parent = nullptr);
    ~LecteurVue();

private:
    Ui::LecteurVue *ui;

private slots :
    void demandeAvancer() ; // Permet d'avancer dans le diaporama
    void demandeReculer() ; // Permet de reculer dans le diaporama
    void demandeChangerDiapo() ; // Permet de Changer de diaporama
    void demandeChangerVitesseDefilement() ; // Permet de changer la vitesse de défilement
    void demandeQuitter() ; // Permet de quitter l'application
    void demandeModeManuel() ; // Permet de passer en mode manuel
    void demandeModeAuto() ; // Permet de passer en mode automatique
    void demandeAProposDe() ; // Permet d'accéder à la page "A propos de ..."
    void demandeEnleverDiapo() ; // Permet d'enlever un diaporama
};
#endif // LECTEURVUE_H
