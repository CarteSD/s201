#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include "lecteur.h"

class Presentation ;

QT_BEGIN_NAMESPACE
namespace Ui { class LecteurVue; }
QT_END_NAMESPACE

// Implémentation de la classe LecteurVue
class LecteurVue : public QMainWindow
{
    Q_OBJECT

public:
    LecteurVue(QWidget *parent = nullptr);  // Constructeur de l'objet LecteurVue
    ~LecteurVue();                          // Destructeur de l'objet LecteurVue

    void nouvConnexion(QObject*);   // Connecte tous les éléments de l'interface graphique avec les slots de l'objet passé en paramètre
    void supprConnexion(QObject*);  // Déconnecte tous les éléments de l'interface graphique des slots de l'objet passé en paramètre

    void majInterface(Lecteur*);    // Met à jour l'interface graphique en fonction du lecteur passé en paramètre

    void afficherTitreImageCourante(Lecteur*);      // Affiche le titre de l'image courante
    void afficherImageCourante(Lecteur*);           // Affiche l'image courante (uniquement pour la v3)
    void afficherTitreDiaporamaCourant(Lecteur*);   // Affiche le titre du diaporama courant

private:
    Ui::LecteurVue *ui;
};
#endif // LECTEURVUE_H
