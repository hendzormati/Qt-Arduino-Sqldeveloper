#ifndef SDF_H
#define SDF_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVector>
#include <QDebug>
#include <QFile>
#include <QPdfWriter>
#include <QPainter>
#include <QDir>
#include <QTextStream>


class Sdf
{
    QString cin_b;
    QString prenom_b;
    QString nom_b;
    QDate dob_b;
    QString sexe_b;
    int nb_pass_b;
    QDate date_ent_b;
    QDate date_sor_b;
    int num_ch;
    int malade_b;

public:

    ///Constructeurs:
    Sdf();
    Sdf(QString, QString, QString, QDate, QString, int, QDate, QDate, int, int);

    ///Getters:
    QString Get_cin_b(){return cin_b;}
    QString Get_prenom_b(){return prenom_b;}
    QString Get_nom_b(){return nom_b;}
    QDate Get_dob_b(){return dob_b;}
    QString Get_sexe_b(){return sexe_b;}
    int Get_nb_pass_b(){return nb_pass_b;}
    QDate Get_date_ent_b(){return date_ent_b;}
    QDate Get_date_sor_b(){return date_sor_b;}
    int Get_num_ch(){return num_ch;}
    int Get_malade_b(){return malade_b;}

    ///Setters:
    void Set_cin_b(QString cin){cin_b=cin;}
    void Set_prenom_b(QString prenom){prenom_b=prenom;}
    void Set_nom_b(QString nom){nom_b=nom;}
    void Set_dob_b(QDate dob){dob_b=dob;}
    void Set_sexe_b(QString sexe){sexe_b=sexe;}
    void Set_nb_pass_b(int nb){nb_pass_b=nb;}
    void Set_date_ent_b(QDate ent){date_ent_b=ent;}
    void Set_date_sor_b(QDate sor){date_sor_b=sor;}
    void Set_num_ch(int num){num_ch=num;}
    void Set_malade_b(int m){malade_b=m;}

    ///CRUD:
    bool ajouter_b();
    bool modifier_b(QString);
    QSqlQueryModel * afficher_b();
    bool supprimer_b(QString);

    ///Fonctions(METIERS):
    bool recherche_sdf(QString);
    void Get_sdf(Sdf &, QString);
    QSqlQueryModel * tri_sdf(int);
    int nb_sexe(QString);
    void creesdf_pdf(QString);
    int calcul_date(QDate);
    QVector<QString> notifsdf();
    void historique_sdf(QString cin_b,QString nomprenom);
    QString readtext_sdf(QString cin_b);
    QSqlQueryModel * filtrage_sdf(QString);
    bool modifier_l(int num_l,int etat_l,int nb_lit);
    int Get_nb_lit(int num_l);
    bool Incondie_detecte(int num_l, int incendie);
    bool modifier_malade(QString,int);

};

#endif // SDF_H
