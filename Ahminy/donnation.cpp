#include "donnation.h"
#include "ui_donnation.h"


donnation::donnation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::donnation)
{
    ui->setupUi(this);


}

void donnation::setmontant(QString cin_d)
{
    CIN=cin_d;
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
    QString resultat=QString::number(montant+anc_mont);
    D.update_montant(CIN,resultat,nb);

    close();
}
