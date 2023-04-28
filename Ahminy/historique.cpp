#include "historique.h"
#include "ui_historique.h"

Historique::Historique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Historique)
{
    ui->setupUi(this);
}

Historique::~Historique()
{
    delete ui;
}

void Historique::afficherhistorique(QString q)
{
    ui->Historiquetext->setText(q);
}
