#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>

#define DATABASE_NAME "lakartxela_s201"
#define CONNECT_TYPE "QODBC"

class Database
{
public:
    Database();
        /* But : constructeur de l'objet Database */

    bool openDataBase();
        /* But : permet d'ouvrir la base de données.
                 La fonction renvoie true si l'ouverture s'est déroulée avec succès.
                 La fonction renvoie false si l'ouverture à échoué. */

    void closeDataBase();
        /* But : ferme la base de données. */

    QSqlQuery executerRequete(QString pReq);
        /* But : exécute la requête pReq passée en paramètre et retourne les résulats sous forme de QSqlQuery. */

    bool isOpen() const;
        /* But : analyse l'état de la base de données.
                 La fonction renvoie true si la base de données est ouvrte.
                 La fonction renvoie false si la base de données est fermée. */

private :
    QSqlDatabase myDb;  // base de données de l'objet
};

#endif // DATABASE_H
