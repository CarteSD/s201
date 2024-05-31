#include "lecteurvue.h"
#include "presentation.h"
#include "lecteur.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LecteurVue w;
    Presentation *p = new Presentation ;
    Lecteur* lecteur = new Lecteur;

    w.nouvConnexion(p);

    p->setVue(&w) ;
    p->setLecteur(lecteur) ;

    w.show();
    return a.exec();
}
