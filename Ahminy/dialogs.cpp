#include "dialogs.h"
#include "ui_dialogs.h"

Dialogs::Dialogs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogs)
{
    ui->setupUi(this);
}

Dialogs::~Dialogs()
{
    delete ui;
}

void Dialogs::afficherunsdf(Sdf &S)
{
    S.Get_nom_b()[0].toUpper();
    S.Get_prenom_b()[0].toUpper();
    ui->titresdf->setText(S.Get_nom_b()+' '+S.Get_prenom_b()+":");
    ui->diacinsdf->setText(S.Get_cin_b());
    ui->dianbpassagesdf->setValue(S.Get_nb_pass_b());
    ui->dianumchsdf->setValue(S.Get_num_ch());
    ui->diadateentsdf->setDate(S.Get_date_ent_b());
    if(S.Get_date_ent_b()==S.Get_date_sor_b())
    {
        ui->diadatesorsdf->setHidden(1);

    }
    else
    {
        ui->nondtsdf->setHidden(1);
        ui->diadatesorsdf->setDate(S.Get_date_sor_b());
    }
}

