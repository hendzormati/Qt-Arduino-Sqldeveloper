#ifndef PERSONNEL_H
#define PERSONNEL_H

#include<QString>
#include<QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>

class Personnel
{
    QString id_p;
    QString cin_p;
    QString nom_p;
    QString prenom_p;
    QDate dob_p;
    QString sexe_p;

    QString metier;
    QString numtel;
    QString mail_p;
    QString adresse;
    QString mdp_p;
    QString ancmdp;
    int salaire;
    QString rfid_p;
    QString code_p;
    QDate datedeb_p;
public:

    /// CONSTRUCTEUR

    Personnel();
    Personnel(QString,QString,QString,QString,QDate,QString,QString,QString,QString,QString,QString,QString,int,QString,QString,QDate);

    ///Getter

    QDate get_dob_p(){return dob_p;}
    QDate get_datedeb_p(){return datedeb_p;}


    QString get_metier(){return metier;}
    int get_salaire(){return salaire;}

    QString get_id_p(){return id_p;}
    QString get_cin_p(){return cin_p;}
    QString get_nom_p(){return nom_p;}
    QString get_prenom_p(){return prenom_p;}
    QString get_adresse(){return adresse;}
    QString get_mdp_p(){return mdp_p;}
    QString get_ancmdp(){return ancmdp;}
    QString get_numtel(){return numtel;}
    QString get_mail_p(){return mail_p;}
    QString get_sexe_p(){return sexe_p;}
    QString get_rfid_p(){return rfid_p;}
    QString get_code_p(){return code_p;}
    /// SETTER
    void set_salaire(int var){ salaire=var;}
    void set_metier(QString var){ metier=var;}

    void set_dob_p(QDate var){dob_p=var;}
    void set_datedeb_p(QDate var){datedeb_p=var;}

    void set_cin_p(QString var){ cin_p=var;}
    void set_sexe_p(QString var){ sexe_p=var;}
    void set_numtel(QString var){ numtel=var;}
    void set_mail_p(QString var){ mail_p=var;}
    void set_id_p(QString var){ id_p=var;}
    void set_nom_p(QString var){ nom_p=var;}
    void set_prenom_p(QString var){ prenom_p=var;}
    void set_adresse(QString var){ adresse=var;}
    void set_mdp_p(QString var){ mdp_p=var;}
    void set_ancmdp(QString var){ ancmdp=var;}
    void set_rfid_p(QString var){ rfid_p=var;}
    void set_code_p(QString var){ code_p=var;}
    /// CRUD
    QString createid_p(QString cin, QString metier, QString sexe);
    bool ajouter_p();
    QSqlQueryModel * afficher_p();
    bool modifier_p(QString id_p);
    bool supprimer_p(QString var);

    /// metier
    void getperso(Personnel &p, QString id);
    void getpersorfid(Personnel &p, QString rfid_p);
    bool recherche_id_p(QString id_p);
    bool recherche_cin_p(QString cin_p);
    bool recherche_mail_p(QString mail_p);
    bool recherche_tel_p(QString numtel);
    bool recherche_rfid_p(QString rfid_p);
    QSqlQueryModel * trier_p(int i);
    int nombremetier(int salaire);
    void generatePDFReport(QString id);
    QSqlQueryModel * filtrageDynamique_p(QString ch);
    bool se_connecter(QString id_p,QString mdp_p);
    bool se_connecterrfid(QString rfid_p,QString code_p);
    bool modifiermdp_p(QString id_p);
    bool affecterrfid_p(QString id_p,QString rfid_p,QString code_p);
    QStringList listemail();
};

#endif // PERSONNEL_H
