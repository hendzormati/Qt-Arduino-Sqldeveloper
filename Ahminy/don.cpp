#include "don.h"

don::don()
{
    cin_d="";
    nom_d="";
    prenom_d="";
    montant_d="";
    telephone_d="";
    nbr_d=1;
}
don::don(QString cin_d,QString nom_d,QString prenom_d,QString montant_d,QString telephone_d,int nbr_d)
{
    this->cin_d=cin_d;
    this->nom_d=nom_d;
    this->prenom_d=prenom_d;
    this->montant_d=montant_d;
    this->telephone_d=telephone_d;
    this->nbr_d=nbr_d;
}
bool don::ajouter_d()
{
    QSqlQuery query;
    query.prepare("insert into DONS values (:cin_d, :nom_d, :prenom_d,:montant_d,:telephone_d,:nbr_d)");
    query.bindValue(":cin_d", cin_d );
    query.bindValue(":nom_d", nom_d);
    query.bindValue(":prenom_d", prenom_d);
    query.bindValue(":montant_d", montant_d);
    query.bindValue(":telephone_d", telephone_d);
    query.bindValue(":nbr_d", nbr_d );
    return query.exec();
}
bool don::modifier_d(QString cin_d, QString montant_d,QString telephone_d)

{
    QSqlQuery query;

    query.prepare("update DONS SET montant_d=:montant_d,telephone_d=:telephone_d where cin_d= :cin_d ");
    query.bindValue(":cin_d",cin_d);
      query.bindValue(":telephone_d",telephone_d);
      query.bindValue(":montant_d",montant_d);
        return    query.exec();


    }
bool don::supprimer_d(QString cin_d)
{
    QSqlQuery query;
    query.prepare("Delete from DONS where cin_d=:cin_d");
    query.bindValue(":cin_d",cin_d );

    return query.exec() ;

}
QSqlQueryModel * don::afficher_d()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select cin_d,nom_d,prenom_d,montant_d,telephone_d from  DONS");
    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prénom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("Montant"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("Téléphone"));
    }
    return model;
}
bool don::recherchedon(QString cin_d)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM DONS WHERE  cin_d=:cin_d");
    query.bindValue(":cin_d",cin_d );
    if (query.exec() && query.next())
    {
        return true;
    }
    else
    {
        return false;
    }

}
bool don::recherchedontel(QString telephone_d)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM DONS WHERE telephone_d=:telephone_d");
    query.bindValue(":telephone_d",telephone_d );
    if (query.exec() && query.next())
    {
        return true;
    }
    else
    {
        return false;
    }

}
bool don::recherchedontel2(QString telephone_d,QString cin_d)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM DONS WHERE telephone_d=:telephone_d and cin_d not like :cin_d");
    query.bindValue(":telephone_d",telephone_d );
    query.bindValue(":cin_d",cin_d );
    if (query.exec() && query.next())
    {
        return true;
    }
    else
    {
        return false;
    }

}
void don::Get_don(don &d, QString cin_d)
{
    QSqlQuery query;

    query.prepare("SELECT * FROM DONS WHERE cin_d= :cin_d");
    query.bindValue(":cin_d",cin_d);
    if (query.exec())
    {
        while (query.next())
        {
            don D(query.value("cin_d").toString(),
                  query.value("nom_d").toString(),
                  query.value("prenom_d").toString(),
                  query.value("montant_d").toString(),
                  query.value("telephone_d").toString(),
                  query.value("nbr_d").toInt());

            d=D;
        }
    }
}
QSqlQueryModel * don::filtrageDynamique_d(QString ch)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select cin_d,nom_d,prenom_d,montant_d,telephone_d from DONS where   cin_d LIKE :ch or  nom_d LIKE :ch2 or prenom_d LIKE :ch2 or montant_d LIKE :ch or telephone_d LIKE :ch ");
    query.bindValue(":ch", ch.toLower() + "%");
    query.bindValue(":ch1", ch.toUpper() + "%");
    QString ch1=ch.toLower();
    ch1[0]=ch1[0].toUpper();
    query.bindValue(":ch2", ch1 + "%");
    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prénom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("Montant"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("Téléphone"));
        while (query.next()) {
            qDebug() << query.value("nom_p").toString();
        }
    }
    else qDebug() << "mehouch mawjoud" << endl;
    return model;}
QSqlQueryModel * don::tri_don(int i)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    if (i==0)
    {
        model->setQuery("SELECT * FROM DONS ORDER BY cin_d");
    }
    else if (i==1)
    {
        model->setQuery("SELECT * FROM DONS ORDER BY cin_d DESC");
    }
    else if (i==2)
    {
        model->setQuery("SELECT * FROM DONS ORDER BY nom_d");
    }
    else if (i==3)
    {
        model->setQuery("SELECT * FROM DONS ORDER BY nom_d DESC");
    }
    else if (i==4)
    {
        model->setQuery("SELECT * FROM DONS ORDER BY prenom_d");
    }
    else if (i==5)
    {
        model->setQuery("SELECT * FROM DONS ORDER BY prenom_d DESC");
    }
    else if (i==6)
    {
        model->setQuery("SELECT * FROM DONS ORDER BY montant_d");
    }
    else if (i==7)
    {
        model->setQuery("SELECT * FROM DONS ORDER BY montant_d DESC");
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin_d"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_d"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom_d"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("montant_d"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("telephone_d"));

    return model;
}
