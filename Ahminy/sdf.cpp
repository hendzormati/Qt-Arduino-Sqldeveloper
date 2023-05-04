#include "sdf.h"

Sdf::Sdf()
{

}


Sdf::Sdf(QString cin, QString prenom, QString nom, QDate dob, QString sexe, int nb, QDate ent, QDate sor, int num, int m)
{
   cin_b=cin;
   prenom_b=prenom;
   nom_b=nom;
   dob_b=dob;
   sexe_b=sexe;
   nb_pass_b=nb;
   date_ent_b=ent;
   date_sor_b=sor;
   num_ch=num;
   malade_b=m;
}


bool Sdf::ajouter_b()
{
    QSqlQuery query;

    query.prepare("INSERT INTO Beneficiaires VALUES (:cin_b, :prenom_b, :nom_b, :dob_b, :sexe_b, :nb_pass_b, :date_ent_b, :date_sor_b, :num_ch, :malade_b)");
    query.bindValue(":cin_b",cin_b);
    query.bindValue(":prenom_b",prenom_b);
    query.bindValue(":nom_b",nom_b);
    query.bindValue(":dob_b",dob_b);
    query.bindValue(":sexe_b",sexe_b);
    query.bindValue(":nb_pass_b",nb_pass_b);
    query.bindValue(":date_ent_b",date_ent_b);
    query.bindValue(":date_sor_b",date_sor_b);
    query.bindValue(":num_ch",num_ch);
    query.bindValue(":malade_b",malade_b);

    return query.exec();
}


bool Sdf::modifier_b(QString cin_b)
{
    QSqlQuery query;

    query.prepare("UPDATE Beneficiaires SET nb_pass_b=:nb_pass_b, date_ent_b=:date_ent_b, date_sor_b=:date_sor_b, num_ch=:num_ch, malade_b=:malade_b WHERE cin_b=:cin_b");
    query.bindValue(":cin_b",cin_b);
    query.bindValue(":nb_pass_b",nb_pass_b);
    query.bindValue(":date_ent_b",date_ent_b);
    query.bindValue(":date_sor_b",date_sor_b);
    query.bindValue(":num_ch",num_ch);
    query.bindValue(":malade_b",malade_b);

    return query.exec();
}


QSqlQueryModel * Sdf::afficher_b()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select cin_b, prenom_b, nom_b, nb_pass_b, num_ch from Beneficiaires ORDER BY nb_pass_b DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("N°Passage"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("N°Chambre"));

    return model;
}


bool Sdf::supprimer_b(QString cin_b)
{
    QSqlQuery query;

    query.prepare("DELETE FROM Beneficiaires WHERE cin_b=:cin_b");
    query.bindValue(":cin_b",cin_b);

    return query.exec();
}


bool Sdf::recherche_sdf(QString cin_b)
{
    QSqlQuery query;

    query.prepare("SELECT * FROM Beneficiaires WHERE cin_b= :cin_b");
    query.bindValue(":cin_b",cin_b);
    if (query.exec() && query.next())
    {
        return true;
    }
    else
    {
        return false;
    }
}


void Sdf::Get_sdf(Sdf &s, QString cin_b)
{
    QSqlQuery query;

    query.prepare("SELECT * FROM Beneficiaires WHERE cin_b= :cin_b");
    query.bindValue(":cin_b",cin_b);
    if (query.exec())
    {
        while (query.next())
        {
            Sdf S(query.value("cin_b").toString(),
                  query.value("prenom_b").toString(),
                  query.value("nom_b").toString(),
                  query.value("dob_b").toDate(),
                  query.value("sexe_b").toString(),
                  query.value("nb_pass_b").toInt(),
                  query.value("date_ent_b").toDate(),
                  query.value("date_sor_b").toDate(),
                  query.value("num_ch").toInt(),
                  query.value("malade_b").toInt());
            s=S;
        }
    }
}


QSqlQueryModel * Sdf::tri_sdf(int i)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    if(i==0)
    {
        model->setQuery("select * from Beneficiaires ORDER BY nom_b");
    }
    else if (i==3)
    {
        model->setQuery("select * from Beneficiaires ORDER BY prenom_b DESC");
    }
    else if (i==4)
    {
        model->setQuery("select * from Beneficiaires ORDER BY date_ent_b");
    }
    else if (i==7)
    {
        model->setQuery("select * from Beneficiaires ORDER BY date_sor_b DESC");
    }
    else if (i==2)
    {
        model->setQuery("select * from Beneficiaires ORDER BY prenom_b");
    }
    else if (i==5)
    {
        model->setQuery("select * from Beneficiaires ORDER BY date_ent_b DESC");
    }
    else if (i==6)
    {
        model->setQuery("select * from Beneficiaires ORDER BY date_sor_b");
    }
    else if (i==1)
    {
        model->setQuery("select * from Beneficiaires ORDER BY nom_b DESC");
    }

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date Naissance"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Sexe"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("N°Passage"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Date Entree"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Date Sortie"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("N°Chambre"));

    return model;
}


int Sdf::nb_sexe(QString sexe_b)
{
    QSqlQuery query;

    query.prepare("SELECT COUNT(*) FROM Beneficiaires WHERE sexe_b = :sexe_b");
    query.bindValue(":sexe_b", sexe_b);
    if (query.exec() && query.next())
    {
        return query.value(0).toInt();
    }
    else
    {
        return -1;
    }
}


void Sdf::creesdf_pdf(QString cin_b)
{
    QSqlQuery query;

    query.prepare("SELECT * FROM Beneficiaires WHERE cin_b = :cin_b");
    query.bindValue(":cin_b", cin_b);

    if (!query.exec())
    {
         qDebug() << "Error: could not execute query.";
         return;
    }
    Sdf s;
    s.Get_sdf(s,cin_b);
    QString fileName = "PDF_SDF/"+s.Get_nom_b()+"_"+s.Get_prenom_b()+"_"+cin_b+".pdf";

    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly))
    {
        QPdfWriter writer(&file);
        QPainter painter(&writer);
        writer.setPageSize(QPageSize(QPageSize::A4));

        writer.setPageMargins(QMarginsF(30, 30, 30, 30));
        painter.setRenderHint(QPainter::Antialiasing);
        QImage logo(":/images/ahminy.png");
        painter.drawImage(QRectF(-170,-120, 2000, 1500), logo);
        QPen pen("#6b694c");
        painter.setPen(pen);
        painter.setFont(QFont("Baskerville Old Face", 18));

        QFont titleFont("Arial", 30, QFont::Bold);
        painter.setFont(titleFont);
        painter.drawText(2800, 700, "Rapport de beneficiaire");

        QFont headerFont("Arial", 20, QFont::Bold);
        painter.setFont(headerFont);

        int y = 3000;
        while (query.next())
        {
            QString nom_b = query.value("nom_b").toString();
            QString prenom_b = query.value("prenom_b").toString();
            QString cin_b = query.value("cin_b").toString();
            QDate dob_b = query.value("dob_b").toDate();
            QString sexe_b = query.value("sexe_b").toString();
            int nb_pass_b = query.value("nb_pass_b").toInt();
            QDate date_ent_b = query.value("date_ent_b").toDate();
            QDate date_sor_b = query.value("date_sor_b").toDate();
            int num_ch = query.value("num_ch").toInt();

            pen.setColor("#5c4633");
            painter.setPen(pen);
            painter.setFont(QFont("Bell MT", 25,QFont::DemiBold));

            painter.drawText(500, y, "Cin :");
            painter.drawText(5500, y, cin_b);
            y += 800;

            painter.drawText(500, y, "Nom :");
            painter.drawText(5500, y, nom_b);
            y += 800;

            painter.drawText(500, y, "Prenom :");
            painter.drawText(5500, y, prenom_b);
            y += 800;

            painter.drawText(500, y, "Sexe :");
            painter.drawText(5500, y, sexe_b);
            y += 800;

            painter.drawText(500, y, "Date Naissance :");
            painter.drawText(5500, y, dob_b.toString("dd/MM/yyyy"));
            y += 800;

            painter.drawText(500, y, "Nombre De Passage :");
            painter.drawText(5500, y,  QString::number(nb_pass_b));
            y += 800;

            painter.drawText(500, y, "Date D' Entree :");
            painter.drawText(5500, y, date_ent_b.toString("dd/MM/yyyy"));
            y += 800;

            painter.drawText(500, y, "Date De Sortie :");
            if(date_sor_b==date_ent_b)
            {
                painter.drawText(5500, y, "Pas Encore");
            }
            else painter.drawText(5500, y, date_sor_b.toString("dd/MM/yyyy"));
            y += 800;
            painter.drawText(500, y, "Numero de Chambre :");
            painter.drawText(5500, y,  QString::number(num_ch));
            y += 800;


        }
        painter.end();
         QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/HP/Desktop/AhminyFinal/build-Ahminy-Desktop_Qt_5_9_9_MinGW_32bit-Debug/"+fileName));
     }
     else {qDebug() << "Error: could not open file" << fileName;}
}


int Sdf::calcul_date(QDate dateDebut)
{
    QDate dateFin = QDate::currentDate();
    int diffJours = dateDebut.daysTo(dateFin);

    return diffJours;
}


QVector<QString> Sdf::notifsdf()
{
     QSqlQuery query;
     QVector<QString> noms;

     query.prepare("SELECT cin_b, nom_b, prenom_b, date_ent_b, num_ch, malade_b FROM Beneficiaires");
     if (!query.exec())
     {
         qDebug() << "Erreur lors de l'exécution de la requête ";
     }
     else qDebug() << "Done";

     while (query.next())
     {
        QDate date_ent=query.value(3).toDate();
        QString nom = query.value(1).toString();
        QString prenom = query.value(2).toString();
        QString cin = query.value(0).toString();
        int nbch = query.value(4).toInt();
        int mal = query.value(5).toInt();

        int nbjour=calcul_date(date_ent);

        if((nbjour>10)&&(nbch!=0))
        {
            nbjour= nbjour - 10;
            QString nbjr = QString::number(nbjour);
            if(mal==0)
            {
                //qDebug() << nom << prenom << nbjour;
                QString nom_comp = "Veuillez noter que " + nom + " " + prenom + " portant la CIN (" + cin +") a dépassé la durée de séjour autorisée avec une periode de "+nbjr+" jours.";
                noms.push_back(nom_comp);
            }
            else
            {
                QString nom_comp = "Veuillez noter que " + nom + " " + prenom + " portant la CIN (" + cin +") est gravement malade. Ce dernier peut dépassé la durée de séjour autorisée.";
                noms.push_back(nom_comp);
            }
        }
     }

     return noms;
}


void Sdf::historique_sdf(QString cin_b,QString nomprenom)
{
    QSqlQuery query;

    query.prepare("SELECT  prenom_b, nom_b, nb_pass_b, date_ent_b, date_sor_b, num_ch FROM Beneficiaires WHERE cin_b = :cin_b");
    query.bindValue(":cin_b", cin_b);

    if (!query.exec())
    {
        qDebug() << "Erreur lors de l'exécution de la requête SQL :" ;
        return;
    }
    QDate dt;

    QString filen="Historique/" + cin_b + ".txt";

    QFile file(filen);
    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "Erreur lors de l'ouverture du fichier";
        return;
    }

    QTextStream out(&file);

    while (query.next())
    {
        QString nom_b = query.value("nom_b").toString();
        QString prenom_b = query.value("prenom_b").toString();
        int nb_pass_b = query.value("nb_pass_b").toInt();
        QDate date_ent_b = query.value("date_ent_b").toDate();
        int num_ch = query.value("num_ch").toInt();

        if(nb_pass_b==1)
        {
            out <<"                          "+ nom_b << " " << prenom_b << endl;
        }

        out << endl;
        out << "Passage Numero : " << nb_pass_b << endl;
        out << "Ajouté par :" << " "+nomprenom << endl;
        out << "Date d entree : " << date_ent_b.toString("dd/MM/yyyy") << endl;
        out << "Date de sortie : " << dt.currentDate().toString("dd/MM/yyyy") << endl;
        out << "Numero de la chambre : " << num_ch << endl;
        out << endl;
    }

    out.flush();
    file.close();
}


QString Sdf::readtext_sdf(QString cin_b)
{
    QString filen="Historique/" + cin_b + ".txt";
    QFile file(filen);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Erreur lors de l'ouverture du fichier";
    }

    QTextStream in(&file);
    in.setCodec("UTF-8");
    QString texte = in.readAll();
    file.close();

    return texte;
}


QSqlQueryModel * Sdf::filtrage_sdf(QString ch)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("select cin_b, prenom_b, nom_b, nb_pass_b, num_ch FROM Beneficiaires where cin_b LIKE :ch1 or  prenom_b LIKE :ch2 or nom_b LIKE :ch2 or nb_pass_b LIKE :ch1 or num_ch LIKE :ch1 ");
    query.bindValue(":ch", ch.toLower() + "%");
    query.bindValue(":ch1", ch + "%");
    QString ch1=ch.toLower();
    ch1[0]=ch1[0].toUpper();
    query.bindValue(":ch2", ch1 + "%");

    if (query.exec())
    {
        model->setQuery(query);
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("Prenom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("Nom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("N°Passage"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("N°Chambre"));
        while (query.next())
        {
            qDebug() << query.value("nom_b").toString();
        }
     }

     return model;
}


bool Sdf::modifier_l(int num_l,int etat_l,int nb_lit)
{
    QSqlQuery query;

    query.prepare("UPDATE Chambres SET etat_l=:etat_l, nb_lit=:nb_lit WHERE num_l=:num_l");
    query.bindValue(":num_l",num_l);
    query.bindValue(":etat_l",etat_l);
    query.bindValue(":nb_lit",nb_lit);

    return query.exec();
}


int Sdf::Get_nb_lit(int num_l)
{
    QSqlQuery query;

    query.prepare("SELECT nb_lit FROM Chambres WHERE num_l=:num_l");
    query.bindValue(":num_l",num_l);
    if (!query.exec())
    {
        qDebug() << "Erreur lors de l'exécution de la requête SQL :" ;
    }

    while (query.next())
    {
      return query.value("nb_lit").toInt();
    }

    return 0;
}


bool Sdf::Incondie_detecte(int num_l, int incendie)
{
    QSqlQuery query;

    //int num_l_int = num_l.toInt();

    query.prepare("UPDATE Chambres SET incendie=:incendie WHERE num_l=:num_l");
    query.bindValue(":num_l",num_l);
    query.bindValue(":incendie",incendie);

    return query.exec();
}


bool Sdf::modifier_malade(QString cin_b,int malade_b)
{
    QSqlQuery query;

    query.prepare("UPDATE Beneficiaires SET malade_b=:malade_b WHERE cin_b=:cin_b");
    query.bindValue(":cin_b",cin_b);
    query.bindValue(":malade_b",malade_b);

    return query.exec();
}
