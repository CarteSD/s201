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
    ~LecteurVue();

    void nouvConnexion(QObject*);
    void supprConnexion(QObject*);

    void majInterface(Lecteur*);

    void afficherTitreImageCourante(Lecteur*);
    void afficherImageCourante(Lecteur*);
    void afficherTitreDiaporamaCourant(Lecteur*);

private:
    Ui::LecteurVue *ui;
};
#endif // LECTEURVUE_H
