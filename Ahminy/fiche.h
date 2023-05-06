#ifndef FICHE_H
#define FICHE_H
#include<QString>
#include<QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fiche
{
    QString cin_b;
    QString nomprenom;
    QString categorie_ant;
    QString description_ant;
    QDate date_f;


public:
    fiche();
    fiche(QString,QString,QString,QString,QDate);
    QString get_cin_b(){return cin_b;}
    QString get_nomprenom(){return nomprenom;}
    QString get_categorie_ant(){return categorie_ant;}
    QString get_description_ant(){return description_ant;}
    QDate get_date_f(){return date_f;}
    void set_cin_b(QString var){ cin_b=var;}
    void set_nomprenom(QString var){ nomprenom=var;}
    void set_categorie_ant(QString var){ categorie_ant=var;}
    void set_description_ant(QString var){ description_ant=var;}
    void set_date_f(QDate var){ date_f=var;}
    bool ajouter_f();
    QSqlQueryModel * afficher_f();
    bool modifier_f(QString cin_b);
    bool supprimer_f(QString cin_b);
    void getfiche(fiche &f, QString cin_b);
    bool recherche_cin_b(QString cin_b);
     QSqlQueryModel * filtrageDynamique_f(QString ch);
     QSqlQueryModel * trier_f(int i);
};

#endif // FICHE_H
