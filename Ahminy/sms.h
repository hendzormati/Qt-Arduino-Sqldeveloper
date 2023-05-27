#ifndef SMS_H
#define SMS_H
#include <QSqlQuery>
#include <QSqlQueryModel>
class SMS
{
    int numero;
    QString message;
public:
    SMS(int numero,QString message);
    int addSMS();
};

#endif // SMS_H
