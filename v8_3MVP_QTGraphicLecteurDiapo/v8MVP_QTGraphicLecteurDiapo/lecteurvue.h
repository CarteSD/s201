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
    LecteurVue(QWidget *parent = nullptr);
        /* But : Constructeur de l'objet LecteurVue */

    ~LecteurVue();
        /* But : Destructeur de l'objet LecteurVue */

    void nouvConnexion(QObject*);
        /* But : Connecte tous les éléments de l'interface graphique avec les slots de l'objet passé en paramètre */

    void supprConnexion(QObject*);
        /* But : Déconnecte tous les éléments de l'interface graphique des slots de l'objet passé en paramètre */

    void majInterface(Lecteur*);
        /* But : Met à jour l'interface graphique en fonction du lecteur passé en paramètre */

    void afficherTitreImageCourante(Lecteur*);
        /* But : Affiche le titre de l'image courante */

    void afficherImageCourante(Lecteur*);
        /* But : Affiche l'image courante */

    void afficherTitreDiaporamaCourant(Lecteur*);
        /* But : Affiche le titre du diaporama courant */

    void desactiverControles();
        /* But : Désactive tous les contrôles du diaporama (avancer, reculer, mode automatique) */

    void activerControles();
        /* But : Active les contrôles du diaorama (avancer, reculer, mode automatique) */

private:
    Ui::LecteurVue *ui;
};
#endif // LECTEURVUE_H
