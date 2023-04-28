#include "connection.h"

connection::connection()
{
}
bool connection::createconnect()
{bool test=false;
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("ahminy");
    db.setUserName("hend");//inserer nom de l'utilisateur
    db.setPassword("esprit23");//inserer mot de passe de cet utilisateur
    if (db.open())
        test=true;
    return  test;
}
void connection::closeconnect()
{
    db.close();
}
