#include "lecteurvue.h"
#include "ui_lecteurvue.h"

LecteurVue::LecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LecteurVue)
{
    ui->setupUi(this);

    // Connection des signaux et des slots
    QObject::connect((*this).ui->pushButtonAvancer, SIGNAL(clicked()), this, SLOT(demandeAvancer()));
    QObject::connect((*this).ui->pushButtonReculer, SIGNAL(clicked()), this, SLOT(demandeReculer()));
    QObject::connect((*this).ui->actionAvancer, SIGNAL(triggered()), this, SLOT(demandeAvancer()));
    QObject::connect((*this).ui->actionReculer, SIGNAL(triggered()), this, SLOT(demandeReculer()));
    QObject::connect((*this).ui->actionChangerDiapo, SIGNAL(triggered()), this, SLOT(demandeChangerDiapo()));
    QObject::connect((*this).ui->actionChangerVitesseDefilement, SIGNAL(triggered()), this, SLOT(demandeChangerVitesseDefilement()));
    QObject::connect((*this).ui->actionQuitter, SIGNAL(triggered()), this, SLOT(demandeQuitter()));
    QObject::connect((*this).ui->actionAuto, SIGNAL(triggered()), this, SLOT(demandeModeAuto()));
    QObject::connect((*this).ui->actionManuel, SIGNAL(triggered()), this, SLOT(demandeModeManuel()));
    QObject::connect((*this).ui->actionAProposDe, SIGNAL(triggered()), this, SLOT(demandeAProposDe()));
    QObject::connect((*this).ui->actionEnleverDiapo, SIGNAL(triggered()), this, SLOT(demandeEnleverDiapo()));
}


// Déclaration des méthodes
LecteurVue::~LecteurVue()
{
    delete ui;
}

void LecteurVue::demandeAvancer()
{
    qDebug("DemandeAvancer OK") ;
}

void LecteurVue::demandeReculer()
{
    qDebug("DemandeReculer OK") ;
}

void LecteurVue::demandeChangerDiapo()
{
    qDebug("demandeChangerDiapo OK") ;
}

void LecteurVue::demandeChangerVitesseDefilement()
{
    qDebug("demandeChangerVitesseDefilement OK") ;
}

void LecteurVue::demandeQuitter()
{
    qDebug("demandeQuitter OK") ;
}

void LecteurVue::demandeModeManuel()
{
    qDebug("demandeModeManuel OK") ;
}

void LecteurVue::demandeModeAuto()
{
    qDebug("demandeModeAuto OK") ;
}


void LecteurVue::demandeAProposDe() {
    qDebug("demandeAProposDe OK") ;
}
void LecteurVue::demandeEnleverDiapo() {
    qDebug("demandeEnleverDiapo OK") ;
}
