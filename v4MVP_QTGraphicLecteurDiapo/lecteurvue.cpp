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
    QObject::connect(ui->actionAProposDe, SIGNAL(triggered()), c, SLOT(demandeAProposDe()));
    QObject::connect(ui->actionEnleverDiapo, SIGNAL(triggered()), c, SLOT(demandeEnleverDiapo()));
    QObject::connect(ui->pushButtonStartDiapo, SIGNAL(clicked()), c, SLOT(demandeLancerDiapo()));
    QObject::connect(ui->pushButtonStopDiapo, SIGNAL(clicked()), c, SLOT(demandeArreterDiapo()));
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
    QObject::disconnect(ui->actionAProposDe, SIGNAL(triggered()), c, SLOT(demandeAProposDe()));
    QObject::disconnect(ui->actionEnleverDiapo, SIGNAL(triggered()), c, SLOT(demandeEnleverDiapo()));
    QObject::disconnect(ui->pushButtonStartDiapo, SIGNAL(clicked()), c, SLOT(demandeLancerDiapo()));
    QObject::disconnect(ui->pushButtonStopDiapo, SIGNAL(clicked()), c, SLOT(demandeArreterDiapo()));
}

void LecteurVue::afficherImageCourante(Lecteur *pLecteur)
{
    QString imgChemin = QString::fromStdString(pLecteur->diaporamaCourant()->imageCourante()->getChemin());
    this->ui->labelImg->setPixmap(QPixmap(imgChemin));
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

    if (pLecteur->getMode() == Mode::manuel) {
        this->ui->pushButtonStopDiapo->setDisabled(true);
    }
    else {
        this->ui->pushButtonStopDiapo->setDisabled(false);
    }
}
