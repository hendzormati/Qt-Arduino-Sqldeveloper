#include "connection.h"

connection::connection()
{
}
bool connection::createconnect()
{bool test=false;
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("ahminy");
    db.setUserName("louhaichi");
    db.setPassword("esprit");
    if (db.open())
        test=true;
    return  test;
}
void connection::closeconnect()
{
    db.close();
}
