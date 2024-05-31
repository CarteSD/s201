#include "lecteurvue.h"
#include "ui_lecteurvue.h"
#include "presentation.h"
#include "lecteur.h"

LecteurVue::LecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LecteurVue)
{
    ui->setupUi(this);

    ui->pushButtonAvancer->setDisabled(true);
    ui->pushButtonReculer->setDisabled(true);
    ui->pushButtonStartDiapo->setDisabled(true);
    ui->pushButtonStopDiapo->setDisabled(true);

    ui->actionAvancer->setDisabled(true);
    ui->actionReculer->setDisabled(true);

    ui->labelImg->setText("Lecteur vide") ;
}

LecteurVue::~LecteurVue()
{
    delete ui;
}

void LecteurVue::nouvConnexion(QObject *c)
{
    QObject::connect(ui->pushButtonAvancer, SIGNAL(clicked()), c, SLOT(demandeAvancer()));
    QObject::connect(ui->pushButtonReculer, SIGNAL(clicked()), c, SLOT(demandeReculer()));
    QObject::connect(ui->actionAvancer, SIGNAL(triggered()), c, SLOT(demandeAvancer()));
    QObject::connect(ui->actionReculer, SIGNAL(triggered()), c, SLOT(demandeReculer()));
    QObject::connect(ui->actionChangerVitesseDefilement, SIGNAL(triggered()), c, SLOT(demandeChangerVitesseDefilement()));
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), c, SLOT(demandeQuitter()));
    QObject::connect(ui->actionAProposDe, SIGNAL(triggered()), c, SLOT(demandeAProposDe()));
    QObject::connect(ui->pushButtonStartDiapo, SIGNAL(clicked()), c, SLOT(demandeLancerDiapo()));
    QObject::connect(ui->pushButtonStopDiapo, SIGNAL(clicked()), c, SLOT(demandeArreterDiapo()));
    QObject::connect(ui->actionChargerDiapo, SIGNAL(triggered()), c, SLOT(demandeChargerDiapo()));
    QObject::connect(ui->actionEnleverDiapo, SIGNAL(triggered()), c, SLOT(demandeEnleverDiapo()));

}

void LecteurVue::supprConnexion(QObject *c)
{
    QObject::disconnect(ui->pushButtonAvancer, SIGNAL(clicked()), c, SLOT(demandeAvancer()));
    QObject::disconnect(ui->pushButtonReculer, SIGNAL(clicked()), c, SLOT(demandeReculer()));
    QObject::disconnect(ui->actionAvancer, SIGNAL(triggered()), c, SLOT(demandeAvancer()));
    QObject::disconnect(ui->actionReculer, SIGNAL(triggered()), c, SLOT(demandeReculer()));
    QObject::disconnect(ui->actionChangerVitesseDefilement, SIGNAL(triggered()), c, SLOT(demandeChangerVitesseDefilement()));
    QObject::disconnect(ui->actionQuitter, SIGNAL(triggered()), c, SLOT(demandeQuitter()));
    QObject::disconnect(ui->actionAProposDe, SIGNAL(triggered()), c, SLOT(demandeAProposDe()));
    QObject::disconnect(ui->pushButtonStartDiapo, SIGNAL(clicked()), c, SLOT(demandeLancerDiapo()));
    QObject::disconnect(ui->pushButtonStopDiapo, SIGNAL(clicked()), c, SLOT(demandeArreterDiapo()));
    QObject::disconnect(ui->actionChargerDiapo, SIGNAL(triggered()), c, SLOT(demandeChargerDiapo()));
    QObject::disconnect(ui->actionEnleverDiapo, SIGNAL(triggered()), c, SLOT(demandeEnleverDiapo()));
}

void LecteurVue::afficherImageCourante(Lecteur *pLecteur)
{
    QString imgChemin = pLecteur->diaporamaCourant()->imageCourante()->getChemin();
    this->ui->labelImg->setPixmap(QPixmap(imgChemin));
}

void LecteurVue::afficherTitreImageCourante(Lecteur *pLecteur)
{
    Image* imageCour = pLecteur->diaporamaCourant()->imageCourante();
    if (imageCour->getTitre() == "") {
        this->ui->labelTitreCategorieImage->setText("[image sans nom]");
    }
    else {
        this->ui->labelTitreCategorieImage->setText("Catégorie : " + imageCour->getCategorie() + ", Titre : " + imageCour->getTitre());
    }
    QString numDiapo = QString::number(pLecteur->diaporamaCourant()->getPosCourante() + 1);
    numDiapo = numDiapo + "/" + QString::number(pLecteur->diaporamaCourant()->nbImages());
    this->ui->labelNumImage->setText(numDiapo);
}

void LecteurVue::afficherTitreDiaporamaCourant(Lecteur *pLecteur)
{
    Diaporama* diapoCour = pLecteur->diaporamaCourant();
    this->ui->labelTitreDiapo->setText(diapoCour->getTitre());
}

void LecteurVue::majInterface(Lecteur *pLecteur)
{
    if (pLecteur->getPosCourante() == NULL) {
        ui->labelImg->setText("Lecteur vide");
        ui->labelNumImage->setText("Numero de l'image");
        ui->labelTitreDiapo->setText("Titre du diaporama");
        ui->labelTitreCategorieImage->setText("Titre de l'image");

        ui->pushButtonAvancer->setDisabled(true);
        ui->pushButtonReculer->setDisabled(true);
        ui->pushButtonStartDiapo->setDisabled(true);
        ui->pushButtonStopDiapo->setDisabled(true);

        ui->actionAvancer->setDisabled(true);
        ui->actionReculer->setDisabled(true);
    }
    else {
        ui->pushButtonAvancer->setDisabled(false);
        ui->pushButtonReculer->setDisabled(false);
        ui->pushButtonStartDiapo->setDisabled(false);

        ui->actionAvancer->setDisabled(false);
        ui->actionReculer->setDisabled(false);

        this->afficherTitreDiaporamaCourant(pLecteur);
        this->afficherTitreImageCourante(pLecteur);
        this->afficherImageCourante(pLecteur);

        if (pLecteur->getMode() == Mode::manuel) {
            this->ui->pushButtonStopDiapo->setDisabled(true);
        }
        else {
            this->ui->pushButtonStopDiapo->setDisabled(false);
        }
    }
}
