#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>

#define DATABASE_NAME "lakartxela_nodenot_s201"
#define CONNECT_TYPE "QODBC"

class Database
{
public:
    Database();
    bool openDataBase();
    void closeDataBase();
    QSqlQuery executerRequete(QString req);
    bool isOpen();

private :
    QSqlDatabase myDb;
};

#endif // DATABASE_H
