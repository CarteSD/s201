#include "lecteurvue.h"
#include "ui_lecteurvue.h"
#include "presentation.h"
#include "lecteur.h"

LecteurVue::LecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LecteurVue)
{
    ui->setupUi(this);

    // Désactive les contrôles car aucun ne diaporamma n'est chargé
    this->desactiverControles();

    // Affiche un lecteur vide
    ui->labelImg->setText("Lecteur vide") ;
}

LecteurVue::~LecteurVue()
{
    delete ui;
}

void LecteurVue::nouvConnexion(QObject *c)
{
    // Connecte tous les objets de l'interface graphique avec les procédures slot de l'objet
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
    // Déconnecte tous les objets de l'interface graphique des procédures slot de l'objet
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

void LecteurVue::desactiverControles()
{
    ui->pushButtonAvancer->setDisabled(true);
    ui->pushButtonReculer->setDisabled(true);
    ui->pushButtonStartDiapo->setDisabled(true);
    ui->pushButtonStopDiapo->setDisabled(true);

    ui->actionAvancer->setDisabled(true);
    ui->actionReculer->setDisabled(true);
}

void LecteurVue::activerControles()
{
    ui->pushButtonAvancer->setDisabled(false);
    ui->pushButtonReculer->setDisabled(false);
    ui->pushButtonStartDiapo->setDisabled(false);

    ui->actionAvancer->setDisabled(false);
    ui->actionReculer->setDisabled(false);
}

void LecteurVue::afficherImageCourante(Lecteur *pLecteur)
{
    // Récupère le chemin de l'image
    QString imgChemin = pLecteur->diaporamaCourant()->imageCourante()->getChemin();

    // Génère un pixmap avec le chemin de l'image
    this->ui->labelImg->setPixmap(QPixmap(imgChemin));
}

void LecteurVue::afficherTitreImageCourante(Lecteur *pLecteur)
{
    Image* imageCour = pLecteur->diaporamaCourant()->imageCourante();

    // Si l'image n'a pas de titre, affichage d'une image sans nom
    if (imageCour->getTitre() == "") {
        this->ui->labelTitreCategorieImage->setText("[image sans nom]");
    }

    // Sinon, affichage du nom de l'image
    else {
        this->ui->labelTitreCategorieImage->setText("Catégorie : " + imageCour->getCategorie() + ", Titre : " + imageCour->getTitre());
    }

    // Affichage du numéro de l'image
    QString numDiapo = QString::number(pLecteur->diaporamaCourant()->getPosCourante() + 1); // + 1 car l'indicde de vecteur commence à 0
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
        this->desactiverControles();
        ui->labelImg->setText("Lecteur vide");
        ui->labelNumImage->setText("Numero de l'image");
        ui->labelTitreDiapo->setText("Titre du diaporama");
        ui->labelTitreCategorieImage->setText("Titre de l'image");
    }
    else {
        this->activerControles();
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
