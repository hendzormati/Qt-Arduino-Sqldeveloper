#include "vente.h"
#include "ui_vente.h"
#include "stock.h"

vente::vente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vente)
{
    ui->setupUi(this);
    ui->vendre->setChecked(1);
}

vente::~vente()
{
    delete ui;
}

void vente::max(int nb)
{ n=nb;
    if(n==0)
    {
      ui->vendre->setDisabled(1);
      ui->ajouter->setChecked(1);
      ui->ajouter->setDisabled(1);
      on_ajouter_clicked();
    }
    else     ui->nbresinv->setMaximum(nb);
}
void vente::on_closeinv_clicked()
{
    close();
}


void vente::on_vendinv_clicked()
{
    stock s;

    //int tt = s.get_nbr_tot_vendre(Id);
    int r = s.get_nbr_res_vendre(Id);
    int t=s.get_nbr_tot_vendre(Id);
    int nbres=r-ui->nbresinv->value();
if(ui->vendre->isChecked())
{
    if (nbres<0){
        QMessageBox msgBox;
        msgBox.setStyleSheet("QMessageBox {background:#f8f5f1;border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
        msgBox.setFixedSize(600,600);
        msgBox.setWindowOpacity(0.8);
        QFont bellMTFont("Bell MT");
        msgBox.setFont(bellMTFont);
        msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
        msgBox.setWindowTitle("Ahminy");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("vous n'avez pas cette quantité en stock.\n"
                       "vous ne pouvez pas effectué cette opération"); msgBox.exec();
    }
    else {
        s.update_nbr_rest_vendre(nbres,Id);
            close();
       /* QString type=ui->typeinv_2->currentText();
         data.append(type);
        if (nb_res!=0){data.clear();
            data.append("0");}
        A.write_to_arduino(data);
        QDate currentDate = QDate::currentDate();
        double prix=ui->prixinv_2->value();
        int nb_tot=ui->nb_totinv_2->value();
        Stock_stat s_stat(id_s,prix,nb_tot,nb_res,currentDate);
        s_stat.ajouter_stock_stat();
        */
    }
}
else if (ui->ajouter->isChecked())
{   s.update_nbr_rest_vendre(r+ui->nbresinv->value(),Id);
    s.update_nbr_tot_vendre(t+ui->nbresinv->value(),Id);
     close();
}
}


void vente::on_ajouter_clicked()
{
    ui->nbresinv->setMaximum(std::numeric_limits<int>::max());
    ui->titreveninv->setText("Nombre de pieces à Ajouter");
    ui->vendinv->setText("Ajouter");
}

void vente::on_vendre_clicked()
{
     ui->nbresinv->setMaximum(n);
    ui->titreveninv->setText("Nombre de pieces à Vendre");
    ui->vendinv->setText("Vendre");
}
