#ifndef STOCK_STAT_H
#define STOCK_STAT_H
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QDate>
class Stock_stat
{
    int id_s,nb_res,nb_tot;
    double prix;
    QDate date_ajout;
    //Date date_ajout;
public:
    Stock_stat(int,double,int,int,QDate);
    Stock_stat();
    //Getters

    int getid_s() {return id_s ;}
    double getprix() {return  prix;}
    int getnb_res() {return  nb_res;}
    int getnb_tot() {return  nb_tot;}
    QDate getDate_ajout(){return date_ajout;}
    //Setters
    void setid_s (int id) {(id_s=id);}
    void setprix (double p) {(prix=p);}
    void setnb_res (int n) {(nb_res=n);}
    void setnb_tot (int nt) {(nb_tot=nt);}
    void setDate_ajout(QDate dt_a){(date_ajout=dt_a);}

    //Fonctionnalités de Base relatives
    bool ajouter_stock_stat();


};
#endif // STOCK_STAT_H
