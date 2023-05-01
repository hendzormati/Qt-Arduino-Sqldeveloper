#ifndef STOCK_H
#define STOCK_H
#include<QSqlQueryModel>
#include<QSqlQuery>
#include <QString>
class stock
{
    QString categorie,type,sexe_s,imagePath;
    int id_s,nb_res,nb_tot;
    double prix;

public:

    stock(int,QString,QString,QString,double,int,int,QString);
    stock();
    //Getters
    QString getcategorie() {return categorie; }
    QString gettype() {return type; }
    QString getsexe_s() {return sexe_s; }
    int getid_s() {return id_s ;}
    double getprix() {return  prix;}
    int getnb_res() {return  nb_res;}
    int getnb_tot() {return  nb_tot;}
    QString getimage() {return imagePath; }

    //Setters
    void setcategorie (QString c) {(categorie=c);}
    void settype (QString t) {(type=t);}
    void setsexe (QString s) {(sexe_s=s);}
    void setid_s (int id) {(id_s=id);}
    void setprix (double p) {(prix=p);}
    void setnb_res (int n) {(nb_res=n);}
    void setnb_tot (int nt) {(nb_tot=nt);}
    void setiamge(QString i) {(imagePath=i);}


    //Fonctionnalités de Base relatives
    bool ajouter_inv();
    QSqlQueryModel * afficher_inv ();
    QSqlQueryModel * tri_inv_type();
    QSqlQueryModel * tri_inv_categorie();
    QSqlQueryModel * tri_inv_prix();

    bool supprimer (int);
    bool verif_exist(stock  S);
    int get_nbr_tot (stock S);
    int get_id_s(stock S);
    void update_nbr_tot(int nb_tot,stock S);
    QSqlQueryModel* Recherche_inv(QString recherche);
    bool modifier(int);
    int get_nbr_rest(stock S);
    void update_nbr_rest(int nb_res,stock S);
    int nb_categorie(QString categorie);
    int get_id_s();

    QList<stock> getDatabaseValues();

    double getInventory() const ;
    double getBalance() const;
    QList<stock> getAll() ;
    QString get_type_arduino();
    int get_nbr_res_vendre(int id_s);
    int get_nbr_tot_vendre(int id_s);
    void update_nbr_rest_vendre(int nb_res,int id_s);
    QSqlQueryModel * afficher_inv_bilan();
    QSqlQueryModel * tri_inv_type_2();
    QSqlQueryModel * tri_inv_categorie_2();
    QSqlQueryModel * tri_inv_prix_2();

};

#endif // STOCK_H
