#include "presentation.h"
#include "lecteur.h"
#include "diaporama.h"
#include "image.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QTimer>

Presentation::Presentation(QObject *parent)
    : QObject{parent}
{
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(update()));
}

Lecteur *Presentation::getLecteur()
{
    return this->m_lecteur ;
}

LecteurVue *Presentation::getVue()
{
    return this->m_vue ;
}

void Presentation::setLecteur(Lecteur *pLecteur)
{
    this->m_lecteur = pLecteur ;
}

void Presentation::setVue(LecteurVue *pVue)
{
    this->m_vue = pVue ;
}

void Presentation::demandeAvancer()
{
    if (this->getLecteur()->getMode() == Mode::automatique) {
        this->getLecteur()->setMode(Mode::manuel);
        this->m_timer->stop();
    }
    this->getLecteur()->diaporamaCourant()->avancer();
    this->getVue()->majInterface(this->getLecteur());
}

void Presentation::demandeReculer()
{
    if (this->getLecteur()->getMode() == Mode:: automatique) {
        this->getLecteur()->setMode(Mode::manuel);
        this->m_timer->stop();
    }
    this->getLecteur()->diaporamaCourant()->reculer();
    this->getVue()->majInterface(this->getLecteur());
}

void Presentation::demandeChangerDiapo()
{
    unsigned int numDiapo = QInputDialog::getInt(this->getVue(), "Changement de diaporama", "Quel-est l'indice du diaporama sur lequel vous souhaitez aller ?", 0, 0, 4);
    this->getLecteur()->changerDiaporama(numDiapo);
    this->getVue()->majInterface(this->getLecteur());
}

void Presentation::demandeChangerVitesseDefilement()
{
    qDebug() << "demandeChangerVitesseDefilement() OK";
    // this->getModele()->getLecteur()->diaporamaCourant()->vitesseDefilement();
}

void Presentation::demandeQuitter()
{
    this->getVue()->close();
}

void Presentation::demandeLancerDiapo()
{
    this->getLecteur()->setMode(Mode::automatique);
    this->m_timer->start(1000);


    this->getVue()->majInterface(this->getLecteur());
}

void Presentation::demandeArreterDiapo()
{
    this->getLecteur()->setMode(Mode::manuel);
    this->m_timer->stop();
    this->getVue()->majInterface(this->getLecteur());
    this->m_nbSecondes = 0;
}

void Presentation::demandeAProposDe()
{
    QMessageBox::information(this->getVue(), "À propos de l'application", " Version : MVP_3.0\n Créée le : 13/05/2024 \n Par : CHA Baptiste, DESESSARD Estéban, MARSAN Louis");
}

void Presentation::demandeEnleverDiapo()
{
    this->getLecteur()->enleverDiaporama();
    this->getVue()->majInterface(this->getLecteur());
}

void Presentation::update()
{
    if ((*this).m_nbSecondes % 2 == 0) {
        (*this).getLecteur()->diaporamaCourant()->avancer();
        (*this).getVue()->majInterface((*this).getLecteur());
    }

    (*this).m_nbSecondes ++;
}
