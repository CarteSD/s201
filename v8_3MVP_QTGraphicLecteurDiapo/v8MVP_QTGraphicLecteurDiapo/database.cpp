#include "database.h"
#include <QSqlError>

Database::Database()
{

}

bool Database::openDataBase()
{
    // Connexion à la base de données
    myDb = QSqlDatabase::addDatabase(CONNECT_TYPE);
    myDb.setHostName("lakartxela.iutbayonne.univ-pau.fr");
    myDb.setDatabaseName(DATABASE_NAME);
    myDb.setUserName("edesessard_bd");
    myDb.setPassword("edesessard_bd");

    // Récupération du résultat de l'ouverture
    bool result = myDb.open();

    // Retourne le résultat d'exécution
    return result;
}

void Database::closeDataBase()
{
    // Fermeture de la base de données
    myDb.close();
}

QSqlQuery Database::executerRequete(QString pReq)
{
    // Déclaration de la requête de type QSqlQuery
    QSqlQuery query;

    // Exécute la requête
    query.exec(pReq);

    // Retourne les résultats de la requête
    return query;
}

bool Database::isOpen() const
{
    return this->myDb.isOpen();
}
