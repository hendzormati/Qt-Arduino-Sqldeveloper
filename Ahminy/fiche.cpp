#include "fiche.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
using namespace std;
fiche::fiche()
{

}

fiche::fiche(QString cin ,QString nompre,QString cat,QString desc,QDate date )
{
    cin_b=cin;
    nomprenom=nompre;
    categorie_ant=cat;
    description_ant=desc;
    date_f=date;
}
bool fiche::ajouter_f()
{
    QSqlQuery query;
    query.prepare("INSERT INTO fiche VALUES(:cin_b, :nomprenom, :categorie_ant, :description_ant, :date_f)");
    query.bindValue(":cin_b",cin_b);
    query.bindValue(":nomprenom",nomprenom);
    query.bindValue(":categorie_ant",categorie_ant);
    query.bindValue(":description_ant",description_ant);
    query.bindValue(":date_f",date_f);
    return query.exec();
}
QSqlQueryModel * fiche::afficher_f()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select cin_b,nomprenom,categorie_ant, description_ant from fiche ORDER BY date_f DESC ");
    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_Prénom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("Antécédent"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("Description"));
    }
    return model;
}
bool fiche::modifier_f(QString cin_b)
{
    QSqlQuery query;
    query.prepare("UPDATE fiche SET categorie_ant=:categorie_ant,description_ant=:description_ant,date_f=:date_f WHERE cin_b=:cin_b");
    query.bindValue(":cin_b",cin_b);
    query.bindValue(":categorie_ant",categorie_ant);
    query.bindValue(":description_ant",description_ant);
    query.bindValue(":date_f",date_f);
    return query.exec();
}
bool fiche::supprimer_f(QString cin_b)
{
    QSqlQuery query;
    query.prepare("DELETE FROM fiche WHERE cin_b=:cin_b");
    query.bindValue(":cin_b",cin_b);
    return query.exec();
}
void fiche::getfiche(fiche &f, QString cin_b)
{
    QSqlQuery query;

    query.prepare("SELECT * FROM fiche where cin_b= :cin_b");
    query.bindValue(":cin_b",cin_b);
    if (query.exec())
    {
        while (query.next()) {
            f.set_cin_b(query.value("cin_b").toString());
            f.set_nomprenom(query.value("nomprenom").toString());
            f.set_categorie_ant(query.value("categorie_ant").toString());
            f.set_description_ant(query.value("description_ant").toString());
            f.set_date_f(query.value("date_f").toDate());

        }

    }
    else
    {
        qDebug() << "Query failed lel get fiche " << query.lastError().text();

    }
}
bool fiche::recherche_cin_b(QString cin_b)
{
    QSqlQuery query;

    query.prepare("SELECT * FROM fiche where cin_b= :cin_b");
    query.bindValue(":cin_b",cin_b);
    if (query.exec() && query.next())
    {
        return true;
    }
    else
    {
        qDebug() << "Query failed fel recherche cin_b: " << query.lastError().text();
        return false;
    }
}
QSqlQueryModel * fiche::filtrageDynamique_f(QString ch)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select cin_b,nomprenom,categorie_ant, description_ant from fiche  where   cin_b LIKE :ch or  nomprenom LIKE :ch1 or categorie_ant LIKE :ch2 or description_ant LIKE :ch2 ORDER BY date_f DESC");
    query.bindValue(":ch", ch.toLower() + "%");
    QString ch1=ch.toLower();
    ch1[0]=ch1[0].toUpper();
    query.bindValue(":ch2", ch1 + "%");
    QString ch2=ch.toLower();
    ch2[0] =ch2[0].toUpper();
    query.bindValue(":ch1", ch2 + "%");
    std::size_t space_pos = ch2.toStdString().find(" ");
    qDebug() << "spacepos" << space_pos << "length" << ch2.length();
    if (space_pos != std::string::npos && space_pos+1 != static_cast<unsigned int>(ch2.length()))
        {
    ch2[space_pos+1] =ch2[space_pos+1].toUpper();
    query.bindValue(":ch1", ch2 + "%");
        }
    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_Prénom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("Antécédent"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("Description"));
    }
    else qDebug() << "mehouch mawjoud" << endl;
    return model;
}
QSqlQueryModel * fiche::trier_f(int i)
{
    QSqlQueryModel * model= new QSqlQueryModel();
        switch(i)
        { case 0:  model->setQuery("select cin_b,nomprenom,categorie_ant, description_ant,date_f from fiche ORDER BY cin_b");
            break;
        case 1:  model->setQuery("select cin_b,nomprenom,categorie_ant, description_ant,date_f from fiche ORDER BY cin_b DESC");
            break;
        case 2:  model->setQuery("select cin_b,nomprenom,categorie_ant, description_ant,date_f from fiche ORDER BY nomprenom");
            break;
        case 3:  model->setQuery("select cin_b,nomprenom,categorie_ant, description_ant,date_f from fiche ORDER BY nomprenom DESC");
            break;
        case 4:  model->setQuery("select cin_b,nomprenom,categorie_ant, description_ant,date_f from fiche ORDER BY date_f");
            break;
        case 5:  model->setQuery("select cin_b,nomprenom,categorie_ant, description_ant,date_f from fiche ORDER BY date_f DESC");
            break;
        }
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_Prénom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("Antécédent"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("Description"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date D'ajout"));
        return model;
    }
