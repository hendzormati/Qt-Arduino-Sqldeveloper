#include "dialogp.h"
#include "ui_dialogp.h"
#include <QCryptographicHash>
#include <QDebug>
DialogP::DialogP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogP)
{
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width() - this->width()+100) / 2;
    int y = (screenGeometry.height() - this->height()-150) / 2;
    this->move(x, y);
    ui->setupUi(this);
}

DialogP::~DialogP()
{
    delete ui;
}
void DialogP::afficher_P(Personnel &p)
{
    QString id_p=p.get_id_p();
    QString cin_p=p.get_cin_p();
    QString nom_p=p.get_nom_p();
    QString prenom_p=p.get_prenom_p();
    QDate dob_p=p.get_dob_p();
    QString sexe_p=p.get_sexe_p();
    QString metier=p.get_metier();
    QString numtel=p.get_numtel();
    QString adresse=p.get_adresse();
    QString mail_p=p.get_mail_p();
    QString salaire=QString::number(p.get_salaire());
    nom_p[0]=nom_p[0].toUpper();
    prenom_p[0]=prenom_p[0].toUpper();
    QString nom_prenom= nom_p+" "+prenom_p+" :";

    ui->titreafficherp->setText(nom_prenom);
    ui->cinperso->setText(cin_p);
    ui->idperso->setText(id_p);
    ui->dobperso->setDate(dob_p);
    ui->dobperso->setEnabled(0);
    ui->mailperso->setText(mail_p);
    if(sexe_p=="Femme")
        ui->femmeperso->setChecked(1);
    else ui->hommeperso->setChecked(1);
    ui->metierperso->setCurrentText(metier);
    ui->numtelperso->setText(numtel);
    ui->adresseperso->setText(adresse);
    ui->salaireperso->setText(salaire);

}

void DialogP::on_closeafficherperso_clicked()
{
    close();
}
