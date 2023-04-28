#include "stock.h"
#include <QPixmap>
stock::stock(int id_s,QString categorie,QString type,QString sexe_s,double prix,int nb_tot,int nb_res,QString imagePath)
{
this->id_s=id_s;
this->categorie=categorie;
this->type=type;
    this->sexe_s=sexe_s;
    this->prix=prix;
    this->nb_res=nb_res;
    this->nb_tot=nb_tot;
    this->imagePath=imagePath;

}
stock::stock()
{
    this->id_s=0;
    this->categorie="";
    this->type="";
        this->sexe_s="";
        this->prix=0;
        this->nb_res=1;
        this->nb_tot=1;
    this->imagePath="";
}
//ajout
bool stock::ajouter_inv()
{
QSqlQuery query;

query.prepare("INSERT INTO stock(categorie,type,sexe_s,prix,nb_tot,nb_res,imagePath)  VALUES( :categorie, :type, :sexe_s, :prix, :nb_tot, :nb_res,:imagePath)");

query.bindValue(":categorie",categorie);
query.bindValue(":type",type);
query.bindValue(":sexe_s",sexe_s);
query.bindValue(":prix",prix);
query.bindValue(":nb_tot",nb_tot);
query.bindValue(":nb_res",nb_res);

query.bindValue(":imagePath",imagePath);

return query.exec();

}

//afficher

QSqlQueryModel * stock::afficher_inv()
{
QSqlQueryModel * model=new QSqlQueryModel ();
model->setQuery("select id_s,categorie,type,sexe_s,prix,nb_tot,nb_res from stock ");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Categorie"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Sexe"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("Prix"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("N°Total"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("N°Restant"));
return model;

}
QSqlQueryModel * stock::afficher_inv_bilan()
{
QSqlQueryModel * model=new QSqlQueryModel ();
model->setQuery("SELECT stock.type, EXTRACT(MONTH FROM stock_stat.date_ajout) AS mois, (SUM(stock_stat.nb_tot) - SUM(stock_stat.nb_res)) AS nb,  stock.prix as prix_unitaire ,stock.prix*(SUM(stock_stat.nb_tot) - SUM(stock_stat.nb_res)) as prix_total FROM stock_stat ,stock where stock_stat.id_s = stock.id_s GROUP BY EXTRACT(MONTH FROM stock_stat.date_ajout), stock.type, stock.prix; ");
//model->setHeaderData(0,Qt::Horizontal,QObject::tr("Type"));
//model->setHeaderData(1,Qt::Horizontal,QObject::tr("Mois"));
//model->setHeaderData(2,Qt::Horizontal,QObject::tr("Nb"));
//model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prix_Unitaire"));
//model->setHeaderData(4,Qt::Horizontal,QObject::tr("Prix_Total"));
return model;

}
//delete
bool stock::supprimer(int id_s)
{
    QSqlQuery query;

    query.prepare("Delete from stock where id_s=:id_s");
query.bindValue(":id_s",id_s);
    return  query.exec();

}
//modifier
bool stock::modifier(int id_s){

    QSqlQuery query;


    query.prepare(" UPDATE stock SET id_s= :id_s,categorie= :categorie,type= :type,sexe_s= :sexe_s,prix=:prix,nb_tot= :nb_tot,nb_res= :nb_res,imagePath=:imagePath where id_s= :id_s");
    query.bindValue(":id_s",id_s);
    query.bindValue(":categorie",categorie);
    query.bindValue(":type",type);
    query.bindValue(":sexe_s",sexe_s);
    query.bindValue(":prix",prix);
    query.bindValue(":nb_tot",nb_tot);
    query.bindValue(":nb_res",nb_res);
    query.bindValue(":imagePath",imagePath);

    return    query.exec();

}
//recherche dynamique
QSqlQueryModel* stock::Recherche_inv(QString recherche)

    {
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM stock WHERE  categorie LIKE '%"+recherche+"%' OR sexe_s LIKE '%"+recherche+"%' OR id_s LIKE '%"+recherche+"%' OR nb_tot LIKE '%"+recherche+"%' OR prix LIKE '%"+recherche+"%' OR nb_res LIKE '%"+recherche+"%' OR type LIKE '%"+recherche+"%'");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("Categorie"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("Sexe"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("Prix"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("N°Total"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("N°Restant"));

   return model;

}
//verif ajout
bool stock::verif_exist(stock S)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM STOCK WHERE  prix="+QString::number(S.getprix())+"and type='"+S.gettype()+"'");
    query.exec();
    int count=0;
    while(query.next())
    {count ++;
    }
    if (count==1) {return  (true);}
    else {return (false);}

}
int stock::get_nbr_tot(stock S)
{
    QSqlQuery query;
    query.prepare("SELECT nb_tot FROM STOCK WHERE  prix="+QString::number(S.getprix())+"and type='"+S.gettype()+"'");
    query.exec();
    query.next();

    return query.value(0).toInt();
}

int stock::get_nbr_rest(stock S)
{
    QSqlQuery query;
    query.prepare("SELECT nb_res FROM STOCK WHERE  prix="+QString::number(S.getprix())+"and type='"+S.gettype()+"'");
    query.exec();
    query.next();

    return query.value(0).toInt();
}

int stock::get_id_s (stock S)
{
    QSqlQuery query;
    query.prepare("SELECT id_s FROM STOCK WHERE  prix="+QString::number(S.getprix())+"and type='"+S.gettype()+"'");
    query.exec();
    query.next();

    return query.value(0).toInt();
}

void stock::update_nbr_tot(int nb_tot,stock S)
{
    QSqlQuery query;
    query.prepare("update stock set nb_tot="+QString::number(nb_tot)+" where prix="+QString::number(S.getprix())+"and type='"+S.gettype()+"'");
    query.exec();


}

void stock::update_nbr_rest(int nb_res,stock S)
{
    QSqlQuery query;
    query.prepare("update stock set nb_res="+QString::number(nb_res)+" where prix="+QString::number(S.getprix())+"and type='"+S.gettype()+"'");
    query.exec();


}
int stock::get_nbr_res_vendre(int id_s)
{
    QSqlQuery query;
    query.prepare("SELECT nb_res FROM STOCK WHERE id_s= :id_s");
    query.bindValue(":id_s",id_s);
    query.exec();
    query.next();

    return query.value(0).toInt();
}
int stock::get_nbr_tot_vendre(int id_s)
{
    QSqlQuery query;
    query.prepare("SELECT nb_tot FROM STOCK WHERE id_s= :id_s");
    query.bindValue(":id_s",id_s);
    query.exec();
    query.next();

    return query.value(0).toInt();
}
void stock::update_nbr_rest_vendre(int nb_res,int id_s)
{
    QSqlQuery query;
    query.prepare("update stock set nb_res="+QString::number(nb_res)+" where id_s= :id_s");
    query.bindValue(":id_s",id_s);


    query.exec();


}

int stock::get_id_s()
{
    QSqlQuery query;
    query.prepare("SELECT id_s FROM stock ORDER BY id_s DESC LIMIT 1;");
    query.exec();
    query.next();

    return query.value(0).toInt();
}
//tri 1+2+3
QSqlQueryModel * stock::tri_inv_type()
{
QSqlQueryModel * model=new QSqlQueryModel ();
QSqlQuery * qry=new QSqlQuery ();
qry->prepare("select id_s,categorie,type,sexe_s,prix,nb_tot,nb_res from stock order by type ASC");
qry->exec();
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Categorie"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Sexe"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("Prix"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("N°Total"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("N°Restant"));
model->setQuery(*qry);
return model;

}
QSqlQueryModel * stock::tri_inv_categorie()
{
QSqlQueryModel * model=new QSqlQueryModel ();
QSqlQuery * qry=new QSqlQuery ();
qry->prepare("select id_s,categorie,type,sexe_s,prix,nb_tot,nb_res from stock order by categorie ASC");
qry->exec();
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Categorie"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Sexe"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("Prix"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("N°Total"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("N°Restant"));
model->setQuery(*qry);
return model;

}
QSqlQueryModel * stock::tri_inv_prix()
{
QSqlQueryModel * model=new QSqlQueryModel ();
QSqlQuery * qry=new QSqlQuery ();
qry->prepare("select id_s,categorie,type,sexe_s,prix,nb_tot,nb_res from stock order by prix ASC");
qry->exec();
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Categorie"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Sexe"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("Prix"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("N°Total"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("N°Restant"));
model->setQuery(*qry);
return model;

}
//pdf
QList<stock> stock::getDatabaseValues()
{
    QList<stock> Q = {};
    QSqlQuery query;
     query.exec("SELECT * FROM stock");
    int size = 0;
    while (query.next())
        size++;
    int it = 0;
    query.first();
    while (it < size)
    {
        id_s=query.value(0).toInt();
        categorie = query.value(1).toString();
        type = query.value(2).toString();
        sexe_s = query.value(3).toString();
        prix = query.value(4).toDouble();
        nb_tot=query.value(5).toInt();
        nb_res=query.value(6).toInt();
        imagePath=query.value(7).toString();

        Q.append(stock(id_s,categorie,type,sexe_s,prix,nb_tot,nb_res,imagePath));
        query.next();
        it++;
    }
    return Q;
}


int stock::nb_categorie(QString categorie)
{
    QSqlQuery query;

    query.prepare("SELECT COUNT(*) FROM stock WHERE categorie = :categorie");
    query.bindValue(":categorie", categorie);
    if (query.exec() && query.next())
    {
        return query.value(0).toInt();
    }
    else
    {
        return -1;
    }
}
//bilan Excel
double stock::getInventory() const {
    // Requête SQL pour récupérer la valeur de "nb_tot" et "nb_res"
    QSqlQuery query;
    query.prepare("SELECT nb_tot, nb_res FROM stock WHERE id_s = :id_s");
    query.bindValue(":id_s", id_s);
    if (!query.exec()) {
        return -1;
    }
    if (!query.next()) {
        return -1;
    }
    int nb_tot = query.value(0).toInt();
    int nb_res = query.value(1).toInt();

    return nb_tot - nb_res;
}

double stock::getBalance() const{
    // Requête SQL pour récupérer la valeur de "nb_tot", "nb_res" et "prix"
    QSqlQuery query;
    query.prepare("SELECT nb_tot, nb_res, prix FROM stock WHERE id_s = :id_s");
    query.bindValue(":id_s", id_s);
    if (!query.exec()) {
        return -1;
    }
    if (!query.next()) {
        return -1;
    }
    int nb_tot = query.value(0).toInt();
    int nb_res = query.value(1).toInt();
    double prix = query.value(2).toDouble();

    return (nb_tot - nb_res) * prix;
}
QList<stock> stock::getAll() {
    QList<stock> stocks;
    QSqlQuery query("SELECT id_s, categorie, type, sexe_s, prix, nb_tot, nb_res FROM stock");
    while (query.next()) {
        int id_s = query.value(0).toInt();
        QString categorie = query.value(1).toString();
        QString type = query.value(2).toString();
        QString sexe_s = query.value(3).toString();
        double prix = query.value(4).toDouble();
        int nb_tot = query.value(5).toInt();
        int nb_res = query.value(6).toInt();
        stock s(id_s, categorie, type, sexe_s, prix, nb_tot, nb_res,imagePath);
        stocks.append(s);
    }
    return stocks;
}
QString stock::get_type_arduino()
{
    QSqlQuery query;
    query.prepare("SELECT type FROM stock where nb_res=0");
    if (!query.exec()) {
        return NULL;
    }
    if (!query.next()) {
        return NULL;
    }

    return query.value(0).toString();
}
QSqlQueryModel * stock::tri_inv_type_2()
{
QSqlQueryModel * model=new QSqlQueryModel ();
QSqlQuery * qry=new QSqlQuery ();
qry->prepare("select id_s,categorie,type,sexe_s,prix,nb_tot,nb_res from stock order by type DESC");
qry->exec();
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Categorie"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Sexe"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("Prix"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("N°Total"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("N°Restant"));
model->setQuery(*qry);
return model;

}
QSqlQueryModel * stock::tri_inv_categorie_2()
{
QSqlQueryModel * model=new QSqlQueryModel ();
QSqlQuery * qry=new QSqlQuery ();
qry->prepare("select id_s,categorie,type,sexe_s,prix,nb_tot,nb_res from stock order by categorie DESC");
qry->exec();
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Categorie"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Sexe"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("Prix"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("N°Total"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("N°Restant"));
model->setQuery(*qry);
return model;

}
QSqlQueryModel * stock::tri_inv_prix_2()
{
QSqlQueryModel * model=new QSqlQueryModel ();
QSqlQuery * qry=new QSqlQuery ();
qry->prepare("select id_s,categorie,type,sexe_s,prix,nb_tot,nb_res from stock order by prix DESC");
qry->exec();
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Categorie"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Sexe"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("Prix"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("N°Total"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("N°Restant"));
model->setQuery(*qry);
return model;

}
