#include "lecteurvue.h"
#include "ui_lecteurvue.h"
#include "presentation.h"
#include "lecteur.h"

LecteurVue::LecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LecteurVue)
{
    ui->setupUi(this);

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
    QObject::connect(ui->actionChangerDiapo, SIGNAL(triggered()), c, SLOT(demandeChangerDiapo()));
    QObject::connect(ui->actionChangerVitesseDefilement, SIGNAL(triggered()), c, SLOT(demandeChangerVitesseDefilement()));
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), c, SLOT(demandeQuitter()));
    QObject::connect(ui->actionAuto, SIGNAL(triggered()), c, SLOT(demandeModeAuto()));
    QObject::connect(ui->actionManuel, SIGNAL(triggered()), c, SLOT(demandeModeManuel()));
    QObject::connect(ui->actionAProposDe, SIGNAL(triggered()), c, SLOT(demandeAProposDe()));
    QObject::connect(ui->actionEnleverDiapo, SIGNAL(triggered()), c, SLOT(demandeEnleverDiapo()));
}

void LecteurVue::supprConnexion(QObject *c)
{
    QObject::disconnect(ui->pushButtonAvancer, SIGNAL(clicked()), c, SLOT(demandeAvancer()));
    QObject::disconnect(ui->pushButtonReculer, SIGNAL(clicked()), c, SLOT(demandeReculer()));
    QObject::disconnect(ui->actionAvancer, SIGNAL(triggered()), c, SLOT(demandeAvancer()));
    QObject::disconnect(ui->actionReculer, SIGNAL(triggered()), c, SLOT(demandeReculer()));
    QObject::disconnect(ui->actionChangerDiapo, SIGNAL(triggered()), c, SLOT(demandeChangerDiapo()));
    QObject::disconnect(ui->actionChangerVitesseDefilement, SIGNAL(triggered()), c, SLOT(demandeChangerVitesseDefilement()));
    QObject::disconnect(ui->actionQuitter, SIGNAL(triggered()), c, SLOT(demandeQuitter()));
    QObject::disconnect(ui->actionAuto, SIGNAL(triggered()), c, SLOT(demandeModeAuto()));
    QObject::disconnect(ui->actionManuel, SIGNAL(triggered()), c, SLOT(demandeModeManuel()));
    QObject::disconnect(ui->actionAProposDe, SIGNAL(triggered()), c, SLOT(demandeAProposDe()));
    QObject::disconnect(ui->actionEnleverDiapo, SIGNAL(triggered()), c, SLOT(demandeEnleverDiapo()));
}

void LecteurVue::afficherImageCourante(Lecteur *pLecteur)
{

}

void LecteurVue::afficherTitreImageCourante(Lecteur *pLecteur)
{
    Image* imageCour = pLecteur->diaporamaCourant()->imageCourante();
    if (QString::fromStdString(imageCour->getTitre()) == "") {
        this->ui->labelTitreCategorieImage->setText("image sans nom");
    }
    else {
        this->ui->labelTitreCategorieImage->setText(QString::fromStdString("Catégorie : " + imageCour->getCategorie() + ", Titre : " + imageCour->getTitre()));
    }
    QString numDiapo = QString::number(pLecteur->diaporamaCourant()->getPosCourante() + 1);
    numDiapo = numDiapo + "/" + QString::number(pLecteur->diaporamaCourant()->nbImages());
    this->ui->labelNumImage->setText(numDiapo);
}

void LecteurVue::afficherTitreDiaporamaCourant(Lecteur *pLecteur)
{
    Diaporama* diapoCour = pLecteur->diaporamaCourant();
    this->ui->labelTitreDiapo->setText(QString::fromStdString(diapoCour->getTitre()));
}

void LecteurVue::majInterface(Lecteur *pLecteur)
{
    this->afficherTitreDiaporamaCourant(pLecteur);
    this->afficherTitreImageCourante(pLecteur);
    this->afficherImageCourante(pLecteur);
}
