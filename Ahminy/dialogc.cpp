#include "dialogc.h"
#include "ui_dialogc.h"


dialogc::dialogc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogc)
{
    ui->setupUi(this);
    ui->resultat->setMaximumBlockCount(60);
    ui->taille->setMaxLength(3);
    ui->poids->setMaxLength(4);
    ui->temperature->setMaxLength(4);
    ui->tension->setMaxLength(3);

}

dialogc::~dialogc()
{
    delete ui;
}

void dialogc::on_confirmerAjouterconst_clicked()
{
    Sdf S;
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1; border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setWindowOpacity(0.8);
    msgBox.setFixedSize(600,600);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");
    msgBox.setIcon(QMessageBox::Information);

    ///Debut controle de saisie:


    QString res=ui->resultat->toPlainText().toLower();
    res[0]=res[0].toUpper();

    bool numtail=true;
    for (int i=0; i<ui->taille->text().length(); i++)
    {
        if (!ui->taille->text()[i].isDigit())
        {
            numtail=false;
            break;
        }
    }

    bool numpoids=true;
    for (int i=0; i<ui->poids->text().length(); i++)
    {
        if (ui->poids->text()[i].isLetter())
        {
            numpoids=false;
            break;
        }
    }

    bool numtens=true;
    for (int i=0; i<ui->tension->text().length(); i++)
    {
        if (ui->tension->text()[i].isLetter())
        {
            numtens=false;
            break;
        }
    }

    bool numtemp=true;
    for (int i=0; i<ui->temperature->text().length(); i++)
    {
        if (ui->temperature->text()[i].isLetter())
        {
            numtemp=false;
            break;
        }
    }

    bool numres=true;
    for (int i=0; i<ui->resultat->toPlainText().length(); i++)
    {
        if (ui->resultat->toPlainText()[i].isDigit())
        {
            numres=false;
            break;
        }
    }

    bool verif=true;

    ///Taille:
    if (ui->taille->text().isEmpty())
    {
        msgBox.setText("Veuillez remplir la taille.");
        msgBox.exec();
        verif=false;
    }
    else if (!numtail)
    {
        msgBox.setText("Taille doit comporter uniquement des chiffres.");
        msgBox.exec();
        verif=false;
    }

    ///Poids:
    else if (ui->poids->text().isEmpty())
    {
        msgBox.setText("Veuillez remplir le poids.");
        msgBox.exec();
        verif=false;
    }
    else if (!numpoids)
    {
        msgBox.setText("Poids doit comporter uniquement des chiffres.");
        msgBox.exec();
        verif=false;
    }

    ///Tension:
    else if (ui->tension->text().isEmpty())
    {
        msgBox.setText("Veuillez remplir la tension.");
        msgBox.exec();
        verif=false;
    }
    else if (!numtens)
    {
        msgBox.setText("Tension doit comporter uniquement des chiffres.");
        msgBox.exec();
        verif=false;
    }

    ///Temperature:
    else if (ui->temperature->text().isEmpty())
    {
        msgBox.setText("Veuillez remplir la temperature.");
        msgBox.exec();
        verif=false;
    }
    else if (!numtemp)
    {
        msgBox.setText("Temperature doit comporter uniquement des chiffres.");
        msgBox.exec();
        verif=false;
    }

    ///Resultat:
    else if (ui->resultat->toPlainText().isEmpty())
    {
        msgBox.setText("Veuillez remplir le resultat.");
        msgBox.exec();
        verif=false;
    }
    else if (!numres)
    {
        msgBox.setText("Resultat ne comporter pas des chiffres.");
        msgBox.exec();
        verif=false;
    }

    ///Fin controle de saisie:

    QDateTime dateRec = QDateTime::currentDateTime();
    consultation C(0,ui->taille->text(),ui->poids->text(),ui->tension->text(),ui->temperature->text(),IDP,CIN,res,dateRec);
    bool test=true;
    if (verif)
    {
        if(etat==1) test=C.ajouter_c();
        else test=C.modifier_c(ID);
        if (test)
        {
            if (malade==1)  S.modifier_malade(CIN,1);
            close();
        }
        else
        {
            msgBox.setText("Non effectué.");
            msgBox.exec();
        }
    }
}

void dialogc::on_closeajoutercons_clicked()
{
    close();
}

void dialogc::affichercons(consultation &c)
{
    ui->taille->setText(c.get_taille_p());
    ui->poids->setText(c.get_poid_p());
    ui->tension->setText(c.get_tension());
    ui->temperature->setText(c.get_temperature());
    ui->resultat->setPlainText(c.get_resultat_c());
    ui->ajoutcons->setText("Modifier une consultation");
}

void dialogc::on_tension_editingFinished()
{
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1; border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setWindowOpacity(0.8);
    msgBox.setFixedSize(600,600);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");
    msgBox.setIcon(QMessageBox::Information);

    float tens=ui->tension->text().toFloat();
    if ((tens>=180)&&(!ui->tension->text().isEmpty())&&("Hypertension"==ant))
    {
        malade=1;
        msgBox.setText("Alerte:\nPatient atteint d'hypertension\nNécessite une attention médicale immédiate!");
        msgBox.exec();
    }
    else if ((tens<90)&&(!ui->tension->text().isEmpty())&&("Hypotension"==ant))
    {
        malade=1;
        msgBox.setText("Alerte:\nPatient atteint d'Hypotension\nNécessite une attention médicale immédiate!");
        msgBox.exec();
    }
}

void dialogc::on_temperature_editingFinished()
{
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1; border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setWindowOpacity(0.8);
    msgBox.setFixedSize(600,600);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");
    msgBox.setIcon(QMessageBox::Information);

    float glyc=ui->temperature->text().toFloat();
    if ((glyc>=13.9)&&(!ui->temperature->text().isEmpty())&&("Hyperglycemie"==ant))
    {
        malade=1;
        msgBox.setText("Alerte:\nPatient atteint d'hyperglycémie\nNécessite une attention médicale immédiate!");
        msgBox.exec();
    }
    else if ((glyc<3.9)&&(!ui->temperature->text().isEmpty())&&("Hypoglycemie"==ant))
    {
        malade=1;
        msgBox.setText("Alerte:\nPatient atteint d'hypoglycemie\nNécessite une attention médicale immédiate!");
        msgBox.exec();
    }
}
