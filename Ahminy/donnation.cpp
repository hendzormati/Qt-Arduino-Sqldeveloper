#include "donnation.h"
#include "ui_donnation.h"


donnation::donnation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::donnation)
{
    ui->setupUi(this);


}

void donnation::setmontant(QString cin_d,Personnel &p)
{

    CIN=cin_d;
     P=p;
    int nbfois=D.getnbr_donnation(CIN);
    QString nb=QString::number(nbfois+1);
    ui->nbfois->setText(nb);
    QString anc_mont=D.getmontant_donnation(CIN);
    ui->montant->setPlaceholderText("Total Des Donnations: "+anc_mont+ " Dt");
}

donnation::~donnation()
{
    delete ui;
}

void donnation::on_annuler_clicked()
{
    close();
}

void donnation::on_ajouter_clicked()
{
    float montant=ui->montant->text().toFloat();
     int nb=ui->nbfois->text().toInt();
     float anc_mont=D.getmontant_donnation(CIN).toFloat();
        D.Get_don(D,CIN);
     QString nomprenomd=D.getprenom_d()+" "+D.getnom_d();
     qDebug() << "nomprenom= " << nomprenomd <<"cin" << CIN ;

     QDateTime dt;
     QSqlQuery query;
     query.prepare("insert into historiquedon values (:id_p, :cin, :nomprenom,:montant,:date_d,:NOMPRENOM_D)");
     query.bindValue(":id_p",P.get_id_p() );
     query.bindValue(":cin", CIN );
     query.bindValue(":nomprenom",P.get_prenom_p()+" "+P.get_nom_p());
     query.bindValue(":montant", ui->montant->text());
     query.bindValue(":date_d",dt.currentDateTime().toString("dd/MM/yyyy hh:mm:ss"));
     query.bindValue(":NOMPRENOM_D",nomprenomd);
      query.exec();
     QString resultat=QString::number(montant+anc_mont);
     D.update_montant(CIN,resultat,nb);
     close();
}
