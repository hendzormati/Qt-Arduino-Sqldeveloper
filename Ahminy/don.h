#ifndef DON_H
#define DON_H
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QString>
#include <QIntValidator>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
class don
{
private:
    QString cin_d;
    QString nom_d;
    QString prenom_d;
    QString montant_d;
    QString telephone_d;
    int nbr_d;

public:
    don();
    don(QString,QString,QString,QString,QString,int);

    //setters
    void setcin_d(QString cin){cin_d=cin;}
    void setnom_d(QString nom){nom_d=nom;}
    void setprenom_d(QString prenom){prenom_d=prenom;}
    void setmontant_d(QString montant){montant_d=montant;}
    void settelephone(QString telephone){telephone_d=telephone;}
    void setnbr_d(int nbr){nbr_d=nbr;}

    //getters
    QString getcin_d(){return cin_d;}
    QString getnom_d(){return nom_d;}
    QString getprenom_d(){return prenom_d;}
    QString getmontant_d(){return montant_d;}
    QString gettelephone_d(){return telephone_d;}
    int getnbr_d(){return nbr_d;}

    //CRUD
    bool ajouter_d();
    bool modifier_d(QString,QString,QString);
    bool supprimer_d(QString);
    QSqlQueryModel * afficher_d();
    //metier
    bool recherchedon(QString cin_d);
    bool recherchedontel(QString telephone_d);
    bool recherchedontel2(QString telephone_d,QString cindon);
    void Get_don(don &d, QString cin_d);
    QSqlQueryModel * filtrageDynamique_d(QString ch);
    QSqlQueryModel * tri_don(int i);
    int getnbr_donnation(QString cin_d);
    QString getmontant_donnation(QString cin_d);
    void update_montant(QString cin_d, QString montant_d, int nbr_d);
};

#endif // DON_H
