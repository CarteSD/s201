#include "database.h"
#include <QSqlError>

Database::Database()
{

}

bool Database::openDataBase()
{
    myDb = QSqlDatabase::addDatabase(CONNECT_TYPE);
    myDb.setHostName("lakartxela.iutbayonne.univ-pau.fr");
    myDb.setDatabaseName(DATABASE_NAME);
    myDb.setUserName("edesessard_bd");
    myDb.setPassword("edesessard_bd");
    bool result = myDb.open();
    return result;
}

void Database::closeDataBase()
{
    myDb.close();
}

QSqlQuery Database::executerRequete(QString req)
{
    QSqlQuery query;
    if (query.exec(req)) {
        return query;
    }
}

bool Database::isOpen()
{
    return this->myDb.isOpen();
}
