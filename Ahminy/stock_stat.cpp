#include "stock_stat.h"

Stock_stat::Stock_stat(int id_s,double prix,int nb_tot,int nb_res, QDate date_ajout)
{
    this->id_s=id_s;
    this->prix=prix;
    this->nb_res=nb_res;
    this->nb_tot=nb_tot;
    this->date_ajout=date_ajout;

}
Stock_stat::Stock_stat()
{
    this->id_s=0;
    this->prix=0;
    this->nb_res=1;
    this->nb_tot=1;
}
//ajout
bool Stock_stat::ajouter_stock_stat()
{
QSqlQuery query;

query.prepare("INSERT INTO stock_stat(id_s,prix,nb_tot,nb_res,date_ajout)  VALUES(:id_s, :prix, :nb_tot, :nb_res, :date_ajout)");
query.bindValue(":id_s",id_s);
query.bindValue(":prix",prix);
query.bindValue(":nb_tot",nb_tot);
query.bindValue(":nb_res",nb_res);
query.bindValue(":date_ajout",date_ajout);

return query.exec();

}
