#include "consultation.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
using namespace std;
consultation::consultation()
{

}
consultation::consultation( int id,QString taille,QString poid,QString tens,QString temp,QString idp,QString cin,QString resultat,QDateTime date)
{
    idc=id;
    taille_p=taille;
    poid_p=poid;
    tension=tens;
    temperature=temp;
    id_p=idp;
    cin_b=cin;
    resultat_c=resultat;
    date_c=date;
}
bool consultation::ajouter_c()
{
    QSqlQuery query;
    query.prepare("INSERT INTO consultations(cin_b, taille_p, poid_p, tension,temperature, id_p,resultat_c ,date_c) VALUES(:cin_b, :taille_p, :poid_p, :tension,:temperature, :id_p,:resultat_c ,:date_c)");
    query.bindValue(":cin_b",cin_b);
    query.bindValue(":taille_p",taille_p);
    query.bindValue(":poid_p",poid_p);
    query.bindValue(":tension",tension);
    query.bindValue(":temperature",temperature);
    query.bindValue(":id_p",id_p);
    query.bindValue(":resultat_c",resultat_c);
    query.bindValue(":date_c",date_c.toString("dd/MM/yyyy hh:mm:ss"));
    return query.exec();
}
QSqlQueryModel * consultation::afficher_c(QString cin_b)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select idc,taille_p,poid_p, tension,temperature,resultat_c,date_c from consultations WHERE cin_b=:cin_b");
    query.bindValue(":cin_b",cin_b);
    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("Taille: Cm"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("Poid: Kg"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("Tension: mmHg"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("Glycemie: mmol/L"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("Resultat"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("Date de la Con.."));
    }
    return model;
}
bool consultation::modifier_c(int idc)
{
    QSqlQuery query;
    query.prepare("UPDATE consultations SET taille_p=:taille_p, poid_p=:poid_p, tension=:tension,temperature=:temperature,resultat_c=:resultat_c,date_c=:date_c WHERE idc=:idc");
    query.bindValue(":idc",idc);
    query.bindValue(":taille_p",taille_p);
    query.bindValue(":poid_p",poid_p);
    query.bindValue(":tension",tension);
    query.bindValue(":temperature",temperature);
    query.bindValue(":resultat_c",resultat_c);
    query.bindValue(":date_c",date_c.toString("dd/MM/yyyy hh:mm:ss"));
    return query.exec();
}
bool consultation::supprimer_c(int idc)
{
    QSqlQuery query;
    query.prepare("DELETE FROM consultations WHERE idc=:idc");
    query.bindValue(":idc",idc);
    return query.exec();
}
void consultation::getconsultation(consultation &c, int idc)
{
    QSqlQuery query;

    query.prepare("SELECT * FROM consultations where idc= :idc");
    query.bindValue(":idc",idc);
    if (query.exec())
    {
        while (query.next()) {
            c.set_cin_b(query.value("id_p").toString());
            c.set_idc(query.value("idc").toInt());
            c.set_poid_p(query.value("poid_p").toString());
            c.set_taille_p(query.value("taille_p").toString());
            c.set_tension(query.value("tension").toString());
            c.set_temperature(query.value("temperature").toString());
            c.set_id_p(query.value("id_p").toString());
            c.set_resultat_c(query.value("resultat_c").toString());
            c.set_date_c(QDateTime::fromString(query.value("date_c").toString(), "dd/MM/yyyy hh:mm:ss"));

        }

    }
    else
    {
        qDebug() << "Query failed lel get consultation " << query.lastError().text();

    }
}
bool consultation::recherche_idc(int idc)
{
    QSqlQuery query;

    query.prepare("SELECT * FROM consultations where idc= :idc");
    query.bindValue(":idc",idc);
    if (query.exec() && query.next())
    {
        return true;
    }
    else
    {
        qDebug() << "Query failed fel recherche idc: " << query.lastError().text();
        return false;
    }
}
QSqlQueryModel * consultation::filtrageDynamique_c(QString ch,QString cin_b)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select idc,taille_p,poid_p, tension,temperature,resultat_c,date_c FROM consultations where cin_b like :cin_b and (idc LIKE :ch or  taille_p LIKE :ch or poid_p LIKE :ch or tension LIKE :ch or temperature like :ch or resultat_c LIKE :ch2 ) ORDER BY TO_DATE(date_c, 'DD/MM/YYYY HH24:MI:SS') DESC");
    query.bindValue(":cin_b",cin_b);
    query.bindValue(":ch", ch.toLower() + "%");
    QString ch1=ch.toLower();
    ch1[0]=ch1[0].toUpper();
    query.bindValue(":ch2", ch1 + "%");
    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("Taille: Cm"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("Poid: Kg"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("Tension: mmHg"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("Glycemie: mmol/L"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("Resultat"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("Date de la Con.."));
    }
    else qDebug() << "mehouch mawjoud" << endl;
    return model;
}
QSqlQueryModel * consultation::trier_c(int i,QString cin_b)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    switch(i)
    { case 0:  model->setQuery("select idc,taille_p,poid_p, tension,temperature,resultat_c,date_c FROM consultations WHERE cin_b = " + cin_b + "ORDER BY CAST(taille_p AS numeric)");
        break;
    case 1:  model->setQuery("select idc,taille_p,poid_p, tension,temperature,resultat_c,date_c FROM consultations WHERE cin_b = " + cin_b + " ORDER BY CAST(taille_p AS numeric) DESC");
        break;
    case 2:  model->setQuery("select idc,taille_p,poid_p, tension,temperature,resultat_c,date_c FROM consultations WHERE cin_b = " + cin_b + "  ORDER BY CAST(poid_p AS numeric)");
        break;
    case 3:  model->setQuery("select idc,taille_p,poid_p, tension,temperature,resultat_c,date_c FROM consultations WHERE cin_b = " + cin_b + "ORDER BY CAST(poid_p AS numeric) DESC");
        break;
    case 4:  model->setQuery("select idc,taille_p,poid_p, tension,temperature,resultat_c,date_c FROM consultations WHERE cin_b = " + cin_b + " ORDER BY CAST(tension AS numeric)");
        break;
    case 5:  model->setQuery("select idc,taille_p,poid_p, tension,temperature,resultat_c,date_c FROM consultations WHERE cin_b = " + cin_b + " ORDER BY CAST(tension AS numeric) DESC");
        break;
    case 6:  model->setQuery("select idc,taille_p,poid_p, tension,temperature,resultat_c,date_c FROM consultations WHERE cin_b = " + cin_b + " ORDER BY  TO_DATE(date_c, 'DD/MM/YYYY HH24:MI:SS')");
        break;
    case 7:  model->setQuery("select idc,taille_p,poid_p, tension,temperature,resultat_c,date_c FROM consultations WHERE cin_b = " + cin_b + " ORDER BY  TO_DATE(date_c, 'DD/MM/YYYY HH24:MI:SS') DESC");
        break;
    }
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Taille: Cm"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Poid: Kg"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Tension: mmHg"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Glycemie: mmol/L"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Resultat"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Date de la Con.."));
    return model;
}
