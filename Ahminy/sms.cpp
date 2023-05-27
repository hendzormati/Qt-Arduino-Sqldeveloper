#include "sms.h"

SMS::SMS(int numero,QString message)
{
    this->numero = numero;
    this->message = message;
}

int SMS::addSMS()
{
    QSqlQuery query;
    query.prepare("insert into SMS (NUMERO,MESSAGE) values(:numero,:message)");
    query.bindValue(":numero",numero);
    query.bindValue(":message",message);
    return query.exec();
}
