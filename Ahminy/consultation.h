#ifndef CONSULTATION_H
#define CONSULTATION_H
#include<QString>
#include<QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class consultation
{
    int idc;
    QString taille_p;
    QString poid_p;
    QString tension;
    QString temperature;
    QString id_p;
    QString cin_b;
    QString resultat_c;
    QDateTime date_c;
public:
    consultation();
    consultation(int,QString,QString,QString,QString,QString,QString,QString,QDateTime);
    QString get_cin_b(){return cin_b;}
    int get_idc(){return idc;}
    QString get_poid_p(){return poid_p;}
    QString get_taille_p(){return taille_p;}
    QString get_tension(){return tension;}
    QString get_temperature(){return temperature;}
    QString get_id_p(){return id_p;}
    QString get_resultat_c(){return resultat_c;}
    QDateTime get_date_c(){return date_c;}
    void set_cin_b(QString var){cin_b=var;}
    void set_idc(int var){idc=var;}
    void set_poid_p(QString var){poid_p=var;}
    void set_taille_p(QString var){taille_p=var;}
    void set_tension(QString var){tension=var;}
    void set_temperature(QString var){temperature=var;}
    void set_id_p(QString var){id_p=var;}
    void set_resultat_c(QString var){resultat_c=var;}
    void set_date_c(QDateTime var){date_c=var;}
    bool ajouter_c();
    QSqlQueryModel * afficher_c(QString cin_b);
    bool modifier_c(int idc);
    bool supprimer_c(int idc);
    void getconsultation(consultation &c, int idc);
    bool recherche_idc(int idc);
    QSqlQueryModel * filtrageDynamique_c(QString ch,QString cin_b);
    QSqlQueryModel * trier_c(int i,QString cin_b);

};

#endif // CONSULTATION_H
