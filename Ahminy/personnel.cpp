#include "personnel.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <QPdfWriter>
#include <QPainter>
#include <QPageSize>
#include <QFile>
#include <QDir>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
using namespace std;
Personnel::Personnel()
{
}
Personnel::Personnel(QString id,QString cin,QString nom,QString prenom,QDate dob,QString sexe,QString met,QString num ,QString mail,QString ad,QString mdp,QString mdp2,int sal,QString rfid,QString code,QDate datedeb)
{
    id_p=id;
    cin_p=cin;
    nom_p=nom;
    prenom_p=prenom;
    dob_p=dob;
    sexe_p=sexe;
    metier=met;
    numtel=num;
    mail_p=mail;
    adresse=ad;
    mdp_p=mdp;
    ancmdp=mdp2;
    salaire=sal;
    rfid_p=rfid;
    code_p=code;
    datedeb_p=datedeb;
}
bool Personnel::ajouter_p()
{ QSqlQuery query;
    query.prepare("INSERT INTO personnel VALUES(:id_p, :cin_p, :nom_p, :prenom_p, :dob_p, :sexe_p, :metier, :numtel, :adresse, :mdp_p, :ancmdp, :salaire, :mail_p,:rfid_p,:code_p,:datedeb_p)");
    query.bindValue(":id_p",id_p);
    query.bindValue(":cin_p",cin_p);
    query.bindValue(":nom_p",nom_p);
    query.bindValue(":prenom_p",prenom_p);
    query.bindValue(":dob_p",dob_p);
    query.bindValue(":sexe_p",sexe_p);
    query.bindValue(":metier",metier);
    query.bindValue(":numtel",numtel);
    query.bindValue(":mail_p",mail_p);
    query.bindValue(":adresse",adresse);
    query.bindValue(":mdp_p",mdp_p);
    query.bindValue(":ancmdp",ancmdp);
    query.bindValue(":salaire",salaire);
    query.bindValue(":rfid_p",rfid_p);
    query.bindValue(":code_p",code_p);
    query.bindValue(":datedeb_p",datedeb_p);
    return query.exec();
}
QSqlQueryModel * Personnel::afficher_p()
{ QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select ID_P,NOM_P,PRENOM_P, metier,salaire from PERSONNEL ORDER BY datedeb_p DESC ");
    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prénom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("Metier"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("Salaire"));
        while (query.next()) {
            qDebug() << query.value("nom_p").toString();
        }
    }
    return model;
}
bool Personnel::modifier_p(QString id_p)
{ QSqlQuery query;
    query.prepare("UPDATE personnel SET numtel=:numtel,adresse=:adresse,mail_p=:mail_p WHERE id_p=:id_p");
    query.bindValue(":id_p",id_p);
    query.bindValue(":mail_p",mail_p);
    query.bindValue(":numtel",numtel);
    query.bindValue(":adresse",adresse);
    return query.exec();
}
bool Personnel::modifiermdp_p(QString id_p)
{ QSqlQuery query;
    query.prepare("UPDATE personnel SET mdp_p=:mdp_p,ancmdp_p=:ancmdp_p,mail_p=:mail_p WHERE id_p=:id_p");
    query.bindValue(":id_p",id_p);
    query.bindValue(":ancmdp_p",ancmdp);
    query.bindValue(":mdp_p",mdp_p);
    query.bindValue(":mail_p",mail_p);

    return query.exec();
}
bool Personnel::affecterrfid_p(QString id_p,QString rfid_p,QString code_p)
{
    QSqlQuery query;
        query.prepare("UPDATE personnel SET rfid_p=:rfid_p,code_p=:code_p WHERE id_p=:id_p");
        query.bindValue(":id_p",id_p);
        query.bindValue(":rfid_p",rfid_p);
        query.bindValue(":code_p",code_p);
        return query.exec();
}
bool Personnel::supprimer_p(QString id_p)
{   QSqlQuery query;
    query.prepare("DELETE FROM PERSONNEL WHERE id_p=:id_p");
    query.bindValue(":id_p",id_p);
    return query.exec();
}
void Personnel::getperso(Personnel &p, QString id_p)
{
    QSqlQuery query;

    query.prepare("SELECT * FROM personnel where id_p= :id_p");
    query.bindValue(":id_p",id_p);
    if (query.exec())
    {
        while (query.next()) {
            p.set_id_p(query.value("id_p").toString());
            p.set_cin_p(query.value("cin_p").toString());
            p.set_nom_p(query.value("nom_p").toString());
            p.set_prenom_p(query.value("prenom_p").toString());
            p.set_dob_p(query.value("dob_p").toDate());
            p.set_sexe_p(query.value("sexe_p").toString());
            p.set_metier(query.value("metier").toString());
            p.set_numtel(query.value("numtel").toString());
            p.set_mail_p(query.value("mail_p").toString());
            p.set_adresse(query.value("adresse").toString());
            p.set_mdp_p(query.value("mdp_p").toString());
            p.set_ancmdp(query.value("ancmdp_p").toString());
            p.set_salaire(query.value("salaire").toInt());
            p.set_rfid_p(query.value("rfid_p").toString());
            p.set_code_p(query.value("code_p").toString());
            p.set_datedeb_p(query.value("datedeb_p").toDate());
        }

    }
    else
    {
        qDebug() << "Query failed lel get perso " << query.lastError().text();

    }
}
void Personnel::getpersorfid(Personnel &p, QString rfid_p)
{
    QSqlQuery query;

    query.prepare("SELECT * FROM personnel where rfid_p= :rfid_p");
    query.bindValue(":rfid_p",rfid_p);
    if (query.exec())
    {
        while (query.next()) {
            p.set_id_p(query.value("id_p").toString());
            p.set_cin_p(query.value("cin_p").toString());
            p.set_nom_p(query.value("nom_p").toString());
            p.set_prenom_p(query.value("prenom_p").toString());
            p.set_dob_p(query.value("dob_p").toDate());
            p.set_sexe_p(query.value("sexe_p").toString());
            p.set_metier(query.value("metier").toString());
            p.set_numtel(query.value("numtel").toString());
            p.set_mail_p(query.value("mail_p").toString());
            p.set_adresse(query.value("adresse").toString());
            p.set_mdp_p(query.value("mdp_p").toString());
            p.set_ancmdp(query.value("ancmdp_p").toString());
            p.set_salaire(query.value("salaire").toInt());
            p.set_rfid_p(query.value("rfid_p").toString());
            p.set_code_p(query.value("code_p").toString());
            p.set_datedeb_p(query.value("datedeb_p").toDate());
        }

    }
    else
    {
        qDebug() << "Query failed lel get perso " << query.lastError().text();

    }
}
QString Personnel::createid_p(QString cin, QString metier, QString sexe)
{
    QString Cin=cin;
    QString Met;
    if(metier=="Responsable RH") Met="PER";
    else if(metier=="Receptionniste") Met="ACC";
    else if(metier=="Medecin") Met="MED";
    else if(metier=="Tresorier") Met="TRE";
    else if(metier=="Gestionnaire De Stock") Met="INV";
    QString Sexe="F";
    if(sexe=="Homme") Sexe="M";
    QString username;
    for(int i=0;i<5;i++)
    {  Cin=cin.mid(i,4);
       username=Met+Sexe+Cin;
       qDebug() <<"cin maksousa "<< Cin << "cin adeya"<< cin << "username "<< i << " =" << username << endl;
       if(!recherche_id_p(username)) return username;

    }
    reverse(Cin.begin(), Cin.end());
    qDebug() << Cin ;
    for(int i=0;i<5;i++)
    {
       Cin=cin.mid(i,4);
       username=Met+Sexe+Cin;
       qDebug() << "username "<< i << " =" << username << endl;
       if(!recherche_id_p(username)) return username;

    }
return username;
}
bool Personnel::recherche_id_p(QString id_p)
{
    QSqlQuery query;

    query.prepare("SELECT * FROM personnel where id_p= :id_p");
    query.bindValue(":id_p",id_p);
    if (query.exec() && query.next())
    {
        return true;
    }
    else
    {
        qDebug() << "Query failed fel recherche id_p: " << query.lastError().text();
        return false;
    }
}
bool Personnel::recherche_cin_p(QString cin_p)
{
    QSqlQuery query;

    query.prepare("SELECT * FROM personnel where cin_p= :cin_p");
    query.bindValue(":cin_p",cin_p);
    if (query.exec() && query.next())
    {
        return true;
    }
    else
    {
        qDebug() << "Query failed fel recherche cin_p: " << query.lastError().text();
        return false;
    }
}
bool Personnel::recherche_mail_p(QString mail_p)
{
    QSqlQuery query;

    query.prepare("SELECT * FROM personnel where mail_p= :mail_p");
    query.bindValue(":mail_p",mail_p);
    if (query.exec() && query.next())
    {
        return true;
    }
    else
    {
        qDebug() << "Query failed fel recherche mail_p: " << query.lastError().text();
        return false;
    }
}
bool Personnel::recherche_tel_p(QString numtel)
{
    QSqlQuery query;

    query.prepare("SELECT * FROM personnel where numtel= :numtel");
    query.bindValue(":numtel",numtel);
    if (query.exec() && query.next())
    {
        return true;
    }
    else
    {
        qDebug() << "Query failed fel recherche numtel_p: " << query.lastError().text();
        return false;
    }
}
bool Personnel::recherche_rfid_p(QString rfid_p)
{
    QSqlQuery query;

    query.prepare("SELECT * FROM personnel where rfid_p= :rfid_p");
    query.bindValue(":rfid_p",rfid_p);
    if (query.exec() && query.next())
    {
        return true;
    }
    else
    {
        qDebug() << "Query failed fel recherche rfid_p: " << query.lastError().text();
        return false;
    }
}
QSqlQueryModel * Personnel::trier_p(int i)
{ QSqlQueryModel * model= new QSqlQueryModel();
    switch(i)
    { case 0:  model->setQuery("select ID_P,NOM_P,PRENOM_P, metier,salaire from PERSONNEL ORDER BY id_p");
        break;
    case 1:  model->setQuery("select ID_P,NOM_P,PRENOM_P, metier,salaire from PERSONNEL ORDER BY id_p DESC");
        break;
    case 2:  model->setQuery("select ID_P,NOM_P,PRENOM_P, metier,salaire from PERSONNEL ORDER BY metier");
        break;
    case 3:  model->setQuery("select ID_P,NOM_P,PRENOM_P, metier,salaire from PERSONNEL ORDER BY metier DESC");
        break;
    case 4:  model->setQuery("select ID_P,NOM_P,PRENOM_P, metier,salaire from PERSONNEL ORDER BY salaire");
        break;
    case 5:  model->setQuery("select ID_P,NOM_P,PRENOM_P, metier,salaire from PERSONNEL ORDER BY salaire DESC");
        break;

    }
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prénom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Metier"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Salaire"));
    return model;
}
int Personnel::nombremetier(int salaire) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM personnel WHERE salaire = :salaire");
    query.bindValue(":salaire", salaire);
    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    } else {
        qDebug() << "Failed to execute query nombremetier:" << query.lastError().text();
        return -1;
    }
}
void Personnel::generatePDFReport(QString id)
{
    QSqlQuery query;
    query.prepare("SELECT NOM_P,PRENOM_P FROM personnel where id_p= :id_p");
    query.bindValue(":id_p",id);
    if (!query.exec()) {
        qDebug() << "Error: could not execute query.";
        return;
    }
    qDebug() << "connected";
    Personnel p1;
    p1.getperso(p1,id);

    QString fileName = "pdfpersonnel/"+p1.get_nom_p()+"_"+p1.get_prenom_p()+"_"+p1.get_cin_p()+".pdf";

    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        QPdfWriter writer(&file);
        QPainter painter(&writer);
        writer.setPageSize(QPageSize(QPageSize::A4));
        /// version 2  // Draw the report title
        writer.setPageMargins(QMarginsF(30, 30, 30, 30));
        painter.setRenderHint(QPainter::Antialiasing);
        QImage logo(":/images/ahminy.png");
        painter.drawImage(QRectF(-170,-120, 2000, 1500), logo);
        //////////////date li lfouk

        ///l loun text
        QPen pen("#6b694c");
        painter.setPen(pen);
        /// type lektiba wel kobr
        painter.setFont(QFont("Baskerville Old Face", 18));

        QDate d;
        QDateTime dt;
        QString ch="Éditée le "+d.currentDate().toString("dddd dd MMMM yyyy");
        painter.drawText(5500, 400,ch);
        QString ch1=dt.currentDateTime().toString("hh:mm:ss");
        painter.drawText(7400, 700,ch1);
        painter.drawText(5400, 13250,"Éditée par "+nom_p+" "+prenom_p);
        ///////////titre
        pen.setColor("#c4c08c");
        painter.setPen(pen);
        QFont font("Bell MT", 35,QFont::Bold);
        font.setUnderline(1);
        painter.setFont(font);
        painter.drawText(2800, 1800, "Fiche Personnel");

        ////// les entetee
        pen.setColor("#5c4633");
        painter.setPen(pen);
        painter.setFont(QFont("Bell MT", 25,QFont::DemiBold));
        painter.drawText(700, 2800, "Matricule");
        painter.drawText(700, 3800, "Nom");
        painter.drawText(700, 4800, "Prénom");
        painter.drawText(700, 5800, "Poste");
        painter.drawText(700, 6800, "Mail");
        painter.drawText(700, 7800, "Carte d'Identité  Nationale   :");
        painter.drawText(700, 8800, "Sexe");
        painter.drawText(700, 9800, "Date de Naissance    :");
        painter.drawText(700, 10800, "Téléphone");
        painter.drawText(700, 11800, "Adresse");
        painter.drawText(2700, 2800, ":");
        painter.drawText(2700, 3800, ":");
        painter.drawText(2700, 4800, ":");
        painter.drawText(2700, 5800, ":");
        painter.drawText(2700, 6800, ":");
        painter.drawText(2700, 8800, ":");
        painter.drawText(2700, 10800, ":");
        painter.drawText(2700, 11800, ":");


        //// les données
        pen.setColor("#846649");
        painter.setPen(pen);
        painter.setFont(QFont("Baskerville Old Face", 20,QFont::DemiBold));
        painter.drawText(3000, 2800, p1.get_id_p());
        painter.drawText(3000, 3800, p1.get_nom_p());
        painter.drawText(3000, 4800, p1.get_prenom_p());
        painter.drawText(3000, 5800, p1.get_metier());
        painter.drawText(3000, 6800,p1.get_mail_p());
        painter.drawText(5800, 7800, p1.get_cin_p());
        painter.drawText(3000, 8800, p1.get_sexe_p());
        painter.drawText(4500, 9800,p1.get_dob_p().toString("dd MMMM yyyy"));
        painter.drawText(3000, 10800, p1.get_numtel());
        painter.drawText(3000, 11800, p1.get_adresse());
        painter.end();
        qDebug() << "PDF generated successfully.";
        qDebug() << "Current working directory:" << QDir::currentPath();
        QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/HP/Desktop/AhminyFinal/build-Ahminy-Desktop_Qt_5_9_9_MinGW_32bit-Debug/"+fileName));
    } else {
        qDebug() << "Error: could not open file" << fileName;
    }
}
QSqlQueryModel * Personnel::filtrageDynamique_p(QString ch)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select ID_P,NOM_P,PRENOM_P, metier,salaire from PERSONNEL where   ID_P LIKE :ch1 or  NOM_P LIKE :ch2 or PRENOM_P LIKE :ch2 or metier LIKE :ch2 or salaire LIKE :ch ");
    query.bindValue(":ch", ch.toLower() + "%");
    query.bindValue(":ch1", ch.toUpper() + "%");
    QString ch1=ch.toLower();
    ch1[0]=ch1[0].toUpper();
    query.bindValue(":ch2", ch1 + "%");
    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prénom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("Metier"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("Salaire"));
        while (query.next()) {
            qDebug() << query.value("nom_p").toString();
        }
    }
    else qDebug() << "mehouch mawjoud" << endl;
    return model;}
bool Personnel::se_connecter(QString id_p,QString mdp_p)
{
    QSqlQuery query;

    query.prepare("SELECT * FROM personnel where id_p= :id_p and mdp_p= :mdp_p");
    query.bindValue(":id_p",id_p);
    query.bindValue(":mdp_p",mdp_p);
    if (query.exec() && query.next())
    {
        return true;
    }
    else
    {
        qDebug() << "mdp wala id ghalet " << "idp = " <<id_p << "mdp = " << mdp_p;
        return false;
    }
}
bool Personnel::se_connecterrfid(QString rfid_p, QString code_p)
{
    QSqlQuery query;

    query.prepare("SELECT * FROM personnel where rfid_p= :rfid_p and code_p= :code_p");
    query.bindValue(":rfid_p",rfid_p);
    query.bindValue(":code_p",code_p);
    if (query.exec() && query.next())
    {
        return true;
    }
    else
    {
        qDebug() << "code ghalet " << "code  = " << code_p;
        return false;
    }
}
QStringList Personnel::listemail()
{
    QSqlQuery query;
    QStringList emails;
    query.prepare("SELECT mail_p FROM personnel WHERE mail_p NOT LIKE :mail_p");
    query.bindValue(":mail_p",mail_p);
    if (query.exec()) {
        while (query.next()) {
            QString email = query.value(0).toString();
            emails.append(email);
        }
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête SQL : " << query.lastError().text();
    }
    return emails;
}
