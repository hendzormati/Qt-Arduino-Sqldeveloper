#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{ QDate d;

    ui->setupUi(this);
    this->resize(1035,700);
    ui->tableViewP->horizontalScrollBar()->setDisabled(true);

    ui->nom_prenom_P->setVisible(false);
    ui->barpersonnel->setCurrentIndex(-1);
    ui->barpersonnel->setVisible(false);
    ui->profil_p->setVisible(false);
    ui->warninglogin->setHidden(1);
    ui->dobsdf->setDate(d.currentDate());
    ui->dobperso->setDate(d.currentDate());
    ui->rechercherper->setHidden(1);
    ui->modifierp->setHidden(1);
    ui->supprimerp->setHidden(1);
    ui->ajoutrfidp->setHidden(1);
    ui->afficherp->setHidden(1);
    ui->typetrip->setHidden(1);
    ui->pdfp->setHidden(1);
    setsalaire(0);
    ui->cinperso->setMaxLength(8);
    ui->numtelperso->setMaxLength(8);
    ui->nomperso->setMaxLength(10);
    ui->prenomperso->setMaxLength(10);
    ui->adresseperso->setMaxLength(20);
    ui->mailperso->setMaxLength(50);
    ui->mailperso_2->setMaxLength(50);
    ui->numtelperso_2->setMaxLength(8);
    ui->adresseperso_2->setMaxLength(20);
    ui->rfidlogin->setHidden(1);
    ui->iconrfidlogin->setHidden(1);
    ui->lancerlescanlogin->setHidden(1);
    ui->coderfid->setHidden(1);
    ui->retour->setHidden(1);
    /// arduino personnel
    int ret=A_per.connect_rfidpers(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to port : "<< A_per.getarduino_port_namepers();connectardper=true;
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A_per.getarduino_port_namepers();connectardper=false;
        break;
    case(-1):qDebug() << "arduino is not available";connectardper=false;
    }
    ////sdf
    ui->tableViewsdf->setModel(Stmp.afficher_b());
    ui->dobsdf->setDate(d.currentDate());
    Stmp.modifier_l(0,0,0);

    //Boutons:
    ui->supprimersdf->setHidden(1);
    ui->modsdf->setHidden(1);
    ui->recherchersdf->setHidden(1);
    ui->affsdf->setHidden(1);
    ui->selectrisdf->setHidden(1);
    ui->pdfsdf->setHidden(1);
    ui->textsdf->setHidden(1);
    ui->fichierhistorique->setHidden(1);

    //Controle de saisie:
    ui->cinsdf->setMaxLength(8);
    ui->nomsdf->setMaxLength(20);
    ui->prenomsdf->setMaxLength(20);


    //Notifications Au Debut:
    QSystemTrayIcon *notifyIcon;
    notifyIcon=new QSystemTrayIcon();
    notifyIcon->setIcon(QIcon(":/images/ahminy.png"));
    QVector <QString> tab=Stmp.notifsdf();
    qDebug() << "taille " <<tab.size();
    if(tab.size()!=0)
    {
   for (int i = 0; i < tab.size(); i++)
        {
            notifyIcon->show();
            QString num = QString::number(i+1);
            notifyIcon->showMessage("Notification "+ num , tab[i], QSystemTrayIcon::Information);
        }

    }


    ///Arduino:
    int ret2=A_sdf.connect_incondie();
    switch(ret2){
    case(0):{
        qDebug()<< "arduino is available and connected to port : "<< A_sdf.getincondie_port_name();
        QSqlQuery query;
        bool test;
        query.prepare("SELECT * FROM Chambres WHERE incendie = 1");
        if (query.exec() && query.next())
        {
            test=true;
        }
        else test=false;
        if(test==true)
        {
            A_sdf.write_to_incondie("1");
            AlerteIncondie d;
            d.setWindowTitle("Alerte Incendie");
            connect(&d, SIGNAL(dialogClosed()), this, SLOT(on_dialogClosed()));
            d.exec();
        }
        break;
    }
    case(1):qDebug() << "arduino is available but not connected to :" <<A_sdf.getincondie_port_name();
        break;
    case(-1):qDebug() << "arduino is not available";
        break;
    }
    QObject::connect(A_sdf.getserialsdf(),SIGNAL(readyRead()),this,SLOT(Incondie()));
    ////inv
    /*int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }*/
    //QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
    /*data.append("0");
    A.write_to_arduino(data);
    data.clear();
    data.append(S1.get_type_arduino());
    A.write_to_arduino(data);
    data=NULL;*/

    ui->tableView_inv->setModel(S1.afficher_inv());

    ui->annuler_imageinv->setVisible(false);
    ui->image_name_inv->setVisible(false);
    ui->tableView_excel_inv->setVisible(false);

    ui->suppmodifinv->setHidden(1);
    ui->modifierinv_2->setHidden(1);
    ui->supprimerinv->setHidden(1);
    ui->vendre_inv->setHidden(1);

    ui->triinv->setEnabled(1);
    ui->bilaninv->setEnabled(1);
    ui->affichplus->setHidden(1);
    ui->statinv->setEnabled(1);
    ui->pdfinv->setEnabled(1);
    ui->rechercherinv_2->setEnabled(1);
    ui->triinv_combo->setHidden(1);
    //MAYSSA
    ui->tableView_d->setModel(D.afficher_d());
    ui->lineEdit_recherche->setHidden(1);
    ui->comboBox_triDon->setHidden(1);
    /////lfouk
    ui->modifier_d->setHidden(1);
    ui->supprimer_d->setHidden(1);
    ui->don_d->setHidden(1);
    ui->qr_code_2->setHidden(1);
    //// alajnab
    ui->stat_d->setEnabled(1);
    ui->execldon->setEnabled(1);
    ui->pdf_d->setEnabled(1);
    ui->Meilleur_d->setEnabled(1);
    ui->recherchedon->setEnabled(1);
    ui->tri_d->setEnabled(1);

    ui->cindon->setMaxLength(8);
    ui->nomdon->setMaxLength(20);
    ui->prenomdon->setMaxLength(20);
    ui->telephonedon->setMaxLength(8);
    ui->telephonedon_3->setMaxLength(8);
    ui->montantdon->setMaxLength(8);
    ui->montantdon_3->setMaxLength(8);

}
void MainWindow::Incondie()
{
    data_sdf=A_sdf.read_from_incondie();
    if(data_sdf != "0")
    {
        int num_l = data_sdf.toInt();
        qDebug() << num_l << endl;
        Stmp.Incondie_detecte(num_l ,1);
        AlerteIncondie d;
        d.setWindowTitle("Alerte Incendie");
        connect(&d, SIGNAL(dialogClosed()), this, SLOT(on_dialogClosed()));
        d.exec();
    }
}

void MainWindow::on_dialogClosed()
{
    A_sdf.write_to_incondie("0");
}

MainWindow::~MainWindow()
{

    delete ui;
}

//LOGIN + ACCESS


void MainWindow::on_showpswd_pressed()
{
    ui->password->setEchoMode(QLineEdit::Normal);
}

void MainWindow::on_showpswd_released()
{
    ui->password->setEchoMode(QLineEdit::Password);
}

void MainWindow::on_quitlogin_clicked()
{
    A_per.write_to_rfidpers("fin");
    close();
}

void MainWindow::on_username_returnPressed()
{
    ui->password->setFocus();
}

void MainWindow::on_password_returnPressed()
{

    on_confirm_clicked();
}

void MainWindow::on_confirm_clicked()
{
    int x;
    QByteArray br = ui->password->text().toUtf8();
    QByteArray result= QCryptographicHash::hash(br,QCryptographicHash::Md5);
    QString res= QString(result.toHex());
    bool test=P.se_connecter(ui->username->text().toUpper(),res);
    if(test)
    {
        P.getperso(P,ui->username->text().toUpper());
        x=ui->metierperso_2->findText(P.get_metier());
        ui->barpersonnel->setCurrentIndex(-1);
        this->resize(1400,750);
        QRect screenGeometry = QApplication::desktop()->screenGeometry();
        int x = (screenGeometry.width() - this->width()) / 2;
        int y = (screenGeometry.height() - this->height()) / 2;
        this->move(x, y);
    }
    else
    { ui->warninglogin->setHidden(0);
        x=-1;
    }
    currentRole = x;
    getacces(x);
}
void MainWindow::getacces(int i)
{  if (i==-1) {ui->exigo->setCurrentIndex(0);ui->tabpersonnel->setCurrentIndex(0);}
    else {
        ui->barpersonnel->setVisible(true);
        ui->nom_prenom_P->setVisible(true);
        ui->profil_p->setVisible(true);
        ui->nom_prenom_P->setText(P.get_nom_p()+" "+P.get_prenom_p());
        ui->nom_prenom_P->setAlignment(Qt::AlignCenter);
        for(int i = 0; i < ui->barpersonnel->count(); i++) {
            QVariant vAlign(Qt::AlignLeft);
            ui->barpersonnel->setItemData(i, vAlign, Qt::TextAlignmentRole);
        }
        switch(currentRole)
        {
        case 0: ui->nom_prenom_P->setStyleSheet("#nom_prenom_P{border: 2px solid white;border-radius: 7px;color:#425180;font-weight: bold;font-size: 18px;background: white;}");
            if(P.get_sexe_p()=="Femme")
                ui->profil_p->setStyleSheet("#profil_p{border-image: url(:/images/profilpersof.png);}");
            else ui->profil_p->setStyleSheet("#profil_p{border-image: url(:/images/profilpersoh.png);}");
            break;
        case 1: ui->nom_prenom_P->setStyleSheet("#nom_prenom_P{border: 2px solid white;border-radius: 7px;color:#62865C;font-weight: bold;font-size: 18px;background: white;}");
            if(P.get_sexe_p()=="Femme")
                ui->profil_p->setStyleSheet("#profil_p{border-image: url(:/images/profilsdff.png);}");
            else ui->profil_p->setStyleSheet("#profil_p{border-image: url(:/images/profilsdfh.png);}");
            break;
        case 2: ui->nom_prenom_P->setStyleSheet("#nom_prenom_P{border: 2px solid white;border-radius: 7px;color:#d7837f;font-weight: bold;font-size: 18px;background: white;}");
            if(P.get_sexe_p()=="Femme")
                ui->profil_p->setStyleSheet("#profil_p{border-image: url(:/images/profilinvf.png);}");
            else ui->profil_p->setStyleSheet("#profil_p{border-image: url(:/images/profilinvh.png);}");
            break;
        case 3: ui->nom_prenom_P->setStyleSheet("#nom_prenom_P{border: 2px solid white;border-radius: 7px;color:#52794a;font-weight: bold;font-size: 18px;background: white;}");
            if(P.get_sexe_p()=="Femme")
                ui->profil_p->setStyleSheet("#profil_p{border-image: url(:/images/profiltref.png);}");
            else ui->profil_p->setStyleSheet("#profil_p{border-image: url(:/images/profiltreh.png);}");
            break;
        case 4: ui->nom_prenom_P->setStyleSheet("#nom_prenom_P{border: 2px solid white;border-radius: 7px;color:#425180;font-weight: bold;font-size: 18px;background: white;}");
            if(P.get_sexe_p()=="Femme")
                ui->profil_p->setStyleSheet("#profil_p{border-image: url(:/images/profilmedf.png);}");
            else ui->profil_p->setStyleSheet("#profil_p{border-image: url(:/images/profilmedh.png);}");
            break;
        }
        if(i==0) {ui->tabpersonnel->setCurrentIndex(1); ui->tableViewP->setModel(P.afficher_p());}
        else ui->exigo->setCurrentIndex(i); }
}

void MainWindow::on_exigo_currentChanged(int index)
{
    if(index!=currentRole)
    { if (currentRole==-1) {ui->exigo->setCurrentIndex(0); ui->barpersonnel->setVisible(false);ui->nom_prenom_P->setVisible(false);ui->profil_p->setVisible(false);}
        else ui->exigo->setCurrentIndex(currentRole);}
}
void MainWindow::on_tabpersonnel_currentChanged(int index)
{
    if(index==0) {ui->barpersonnel->setVisible(false);ui->nom_prenom_P->setVisible(false);ui->profil_p->setVisible(false);}
}
//hend personnel

void MainWindow::on_ajouterperso_clicked()
{
    ui->rechercherper->setHidden(1);
    ui->modifierp->setHidden(1);
    ui->supprimerp->setHidden(1);
    ui->ajoutrfidp->setHidden(1);
    ui->trierp->setEnabled(0);
    ui->mailp->setEnabled(0);
    ui->afficherp->setHidden(1);
    ui->statp->setEnabled(0);
    ui->pdfp->setHidden(1);
    ui->rechercheperso->setEnabled(0);
    ui->typetrip->setHidden(1);
    ui->perso->setCurrentIndex(1);
}

void MainWindow::on_closeajouterperso_clicked()
{   on_home_p_clicked();
}

void MainWindow::on_confirmerAjouterperso_clicked()
{       bool verif=verif_ajoutperso();
        if(verif)
        {
            QString idp;
            QString cinp=ui->cinperso->text();
            QString nomp=ui->nomperso->text().toLower();
            nomp[0]=nomp[0].toUpper();
            QString prenomp=ui->prenomperso->text().toLower();
            prenomp[0]=prenomp[0].toUpper();
            QDate date=ui->dobperso->date();
            QString sexep;
            if(ui->femmeperso->isChecked()) sexep="Femme"; else sexep="Homme";
            QString adresse=ui->adresseperso->text().toLower();
            adresse[0]=adresse[0].toUpper();
            QString numtel=ui->numtelperso->text();
            QString mail_p=ui->mailperso->text();
            QString metier=ui->metierperso->currentText();
            int salaire=ui->salaireperso->text().toUInt();
            idp=P.createid_p(cinp,metier,sexep);
            QMessageBox msgBox;
            msgBox.setStyleSheet("QMessageBox {background:#f8f5f1;border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
            msgBox.setFixedSize(600,600);
            msgBox.setWindowOpacity(0.8);
            QFont bellMTFont("Bell MT");
            msgBox.setFont(bellMTFont);
            msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
            msgBox.setWindowTitle("Ahminy");
            if (P.recherche_cin_p(cinp))
            {
                msgBox.setIcon(QMessageBox::Critical);
                msgBox.setText("Cin déjà enregistré."); msgBox.exec();
            }
            else if (P.recherche_tel_p(numtel))
            {
                msgBox.setIcon(QMessageBox::Critical);
                msgBox.setText("Numero de Téléphone déjà enregistré."); msgBox.exec();
            }
            else if (P.recherche_mail_p(mail_p))
            {
                msgBox.setIcon(QMessageBox::Critical);
                msgBox.setText("Email déjà enregistré."); msgBox.exec();
            }
            else { ////cryptage
                QByteArray br = cinp.toUtf8();
                QByteArray result= QCryptographicHash::hash(br,QCryptographicHash::Md5);
                QString res= QString(result.toHex());
                Personnel p(idp,cinp, nomp,prenomp,date,sexep,metier,numtel,mail_p,adresse,res,res,salaire,"","",date.currentDate());// lors de la creation le mot de passe =cin
                bool test=p.ajouter_p();
                if(test)
                {   ui->perso->setCurrentIndex(0);
                    on_home_p_clicked();
                    ui->tableViewP->setModel(P.afficher_p());
                }
                else {msgBox.setIcon(QMessageBox::Critical);
                    msgBox.setText("Ajout Non effectué."); msgBox.exec(); }
            }}
}
void MainWindow::on_cinperso_returnPressed()
{
    ui->nomperso->setFocus();
}

void MainWindow::on_nomperso_returnPressed()
{
    ui->prenomperso->setFocus();
}

void MainWindow::on_prenomperso_returnPressed()
{
    ui->femmeperso->setChecked(true);
    ui->prenomperso->clearFocus();
}
void MainWindow::on_femmeperso_clicked()
{ ui->hommeperso->setChecked(false);
}

void MainWindow::on_hommeperso_clicked()
{ ui->femmeperso->setChecked(false);
}
void MainWindow::on_confirmersuivantperso_clicked()
{
    ui->perso->setCurrentIndex(2);
}

void MainWindow::on_closeajouterperso2_clicked()
{   on_home_p_clicked();
}

void MainWindow::on_numtelperso_returnPressed()
{
    ui->mailperso->setFocus();
}
void MainWindow::on_mailperso_returnPressed()
{
    ui->adresseperso->setFocus();
}
void MainWindow::setsalaire(int i)
{
    switch(i) {
    case 0:
        ui->salaireperso->setText("400");
        break;
    case 1:
        ui->salaireperso->setText("350");
        break;
    case 2:
        ui->salaireperso->setText("450");
        break;
    case 3:
        ui->salaireperso->setText("400");
        break;
    case 4:
        ui->salaireperso->setText("350");
        break;
    }
}
void MainWindow::on_metierperso_activated(int index)
{
    setsalaire(index);
}
void MainWindow::on_precedentajouterperso2_clicked()
{
    ui->perso->setCurrentIndex(1);
}
void MainWindow::on_supprimerp_clicked()
{
    QString idp=ui->rechercherper->text().toUpper();
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1;border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setFixedSize(600,600);
    msgBox.setWindowOpacity(0.8);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");
    ui->rechercherper->clear();
    bool test2=P.supprimer_p(idp);
    if(test2)
    {ui->tableViewP->setModel(P.afficher_p());
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText("Suppression éffectué."); msgBox.exec(); on_home_p_clicked();}
    else {        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Suppression non éffectué."); msgBox.exec();}

    ui->rechercheperso->setEnabled(1);
    ui->statp->setEnabled(1);
    ui->trierp->setEnabled(1);
}
void MainWindow::clearajoutperso()
{QDate d;
    ui->nomperso->clear();
    ui->prenomperso->clear();
    ui->cinperso->clear();
    ui->dobperso->setDate(d.currentDate());
    ui->femmeperso->setAutoExclusive(false);
    ui->femmeperso->setChecked(false);
    ui->hommeperso->setAutoExclusive(false);
    ui->hommeperso->setChecked(false);
    ui->numtelperso->clear();
    ui->mailperso->clear();
    ui->adresseperso->clear();
    ui->salaireperso->clear();
    ui->metierperso->setCurrentIndex(0);
    setsalaire(0);

}
void MainWindow::on_modifierp_clicked()
{
    QString id=ui->rechercherper->text().toUpper();
    Personnel p1;
    ui->rechercherper->setEnabled(0);
    ui->modifierp->setEnabled(0);
    ui->supprimerp->setEnabled(0);
    ui->ajoutrfidp->setEnabled(0);
    ui->afficherp->setEnabled(0);
    ui->pdfp->setEnabled(0);
    ui->rechercheperso->setEnabled(0);
    ui->statp->setEnabled(0);
    ui->trierp->setEnabled(0);
    ui->mailp->setEnabled(0);
    P.getperso(p1,id);
    ui->perso->setCurrentIndex(3);

    QString num=p1.get_numtel();
    QString mail=p1.get_mail_p();
    QString adresse=p1.get_adresse();
    QString metier=p1.get_metier();
    ui->numtelperso_2->setText(num);
    ui->adresseperso_2->setText(adresse);
    ui->metierperso_2->setCurrentIndex(ui->metierperso_2->findText(metier));
    ui->metierperso_2->setDisabled(1);
    ui->mailperso_2->setText(mail);}
void MainWindow::on_closemodifierperso_clicked()
{
    ui->perso->setCurrentIndex(0);
    ui->tableViewP->setModel(P.afficher_p());
    ui->modifierp->setEnabled(1);
    ui->supprimerp->setEnabled(1);
    ui->ajoutrfidp->setEnabled(1);
    ui->afficherp->setEnabled(1);
    ui->pdfp->setEnabled(1);
    ui->rechercheperso->setEnabled(1);
    ui->statp->setEnabled(1);
    ui->trierp->setEnabled(1);
    ui->mailp->setEnabled(1);
}
void MainWindow::on_confirmerModifierperso_clicked()
{  bool verif=verif_modifierperso();
    if(verif)
    {
        QString adresse=ui->adresseperso_2->text().toLower();
        adresse[0]=adresse[0].toUpper();
        QString num=ui->numtelperso_2->text();
        QString mail=ui->mailperso_2->text();
        Personnel p1;
        QString id=ui->rechercherper->text().toUpper();
        P.getperso(p1,id);
        p1.set_numtel(num);
        p1.set_adresse(adresse);
        p1.set_mail_p(mail);
        //// update les donnée mtaa li connectée
        if(p1.get_id_p()==P.get_id_p()) P=p1;
        bool test=p1.modifier_p(id);
        //on_home_p_clicked();
        QMessageBox msgBox;
        msgBox.setStyleSheet("QMessageBox {background:#f8f5f1;border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
        msgBox.setFixedSize(600,600);
        msgBox.setWindowOpacity(0.8);
        QFont bellMTFont("Bell MT");
        msgBox.setFont(bellMTFont);
        msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
        msgBox.setWindowTitle("Ahminy");
        if(test)
        {   ui->perso->setCurrentIndex(0);
            ui->tableViewP->setModel(p1.afficher_p());
            ui->modifierp->setEnabled(1);
            ui->supprimerp->setEnabled(1);
            ui->ajoutrfidp->setEnabled(1);
            ui->afficherp->setEnabled(1);
            ui->pdfp->setEnabled(1);
            ui->rechercheperso->setEnabled(1);
            ui->statp->setEnabled(1);
            ui->trierp->setEnabled(1);
            ui->mailp->setEnabled(1);
        }
        else {        msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText("Modification non éffectué."); msgBox.exec();}
    }}

bool MainWindow::verif_ajoutperso()
{
    bool verif=true;
    QDate dob = QDate::currentDate();
    QString cinp=ui->cinperso->text(),prenomp=ui->prenomperso->text(),nomp=ui->nomperso->text(),telp=ui->numtelperso->text(),mailp=ui->mailperso->text(),adressep=ui->adresseperso->text();
    bool   numcin=true;
    for (int i=0; i<cinp.length(); i++)
    {
        if (!cinp[i].isDigit()) {
            numcin=false;
            break;
        }
    }
    bool   charprenom=true;
    for (int i=0; i<prenomp.length(); i++)
    {
        if (!prenomp[i].isLetter()) {
            charprenom=false;
            break;
        }
    }
    bool   charnom=true;
    for (int i=0; i<nomp.length(); i++)
    {
        if (!nomp[i].isLetter()) {
            charnom=false;
            break;
        }
    }
    bool   numtel=true;
    for (int i=0; i<telp.length(); i++)
    {
        if (!telp[i].isDigit()) {
            numtel=false;
            break;
        }
    }
    bool   numcaradd=true;
    for (int i=0; i<adressep.length(); i++)
    {
        if (!adressep[i].isLetterOrNumber())
        {
            numcaradd=false;
            break;
        }
    }
    bool email_valide=true;

    // Vérifie si l'adresse e-mail correspond au format "nomprenom@esprit.tn"
    QRegularExpression regex("^[A-Za-z0-9._%+-]+@esprit\\.tn$");
    email_valide=regex.match(mailp).hasMatch();
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1;border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setFixedSize(600,600);
    msgBox.setWindowOpacity(0.8);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");
    msgBox.setIcon(QMessageBox::Information);
    if (cinp.isEmpty())
    {
        ui->perso->setCurrentIndex(1);
        msgBox.setText("Cin Vide"); msgBox.exec();
        verif=false;
    }
    else if((cinp.length()!=8)||!numcin)
    {
        ui->perso->setCurrentIndex(1);
        msgBox.setText("Cin doit comporter 8 caractères et seulement des numeros."); msgBox.exec();
        verif=false;
    }

    else if(nomp.isEmpty())
    {
        ui->perso->setCurrentIndex(1);
        msgBox.setText("Nom Vide"); msgBox.exec();
        verif=false;
    }
    else if(nomp.length()<4 || !charnom)
    {
        ui->perso->setCurrentIndex(1);
        msgBox.setText("Nom doit comporter minimum 3 caractères et seulement des caractères."); msgBox.exec();
        verif=false;
    }
    else if(prenomp.isEmpty() )
    {
        ui->perso->setCurrentIndex(1);
        msgBox.setText("Prenom Vide"); msgBox.exec();
        verif=false;
    }
    else if(prenomp.length()<4 || !charprenom)
    {
        ui->perso->setCurrentIndex(1);
        msgBox.setText("Prenom doit comporter minimum 3 caractères et seulement des caractères."); msgBox.exec();
        verif=false;
    }
    else if (!ui->femmeperso->isChecked() && !ui->hommeperso->isChecked())
    {
        ui->perso->setCurrentIndex(1);
        msgBox.setText("Veuillez sélectionner le sexe"); msgBox.exec();
        verif=false;
    }
    else  if (ui->dobperso->date() > dob)
    {
        ui->perso->setCurrentIndex(1);
        msgBox.setText("La date saisie dépasse la date actuelle."); msgBox.exec();
        verif=false;
    }
    else if(telp.isEmpty() )
    {
        ui->perso->setCurrentIndex(2);
        msgBox.setText("Numero De Téléphone Vide"); msgBox.exec();
        verif=false;
    }
    else if(telp.length()!=8 || !numtel)
    {
        ui->perso->setCurrentIndex(2);
        msgBox.setText("Numero doit comporter 8 caractères et seulement des nombres."); msgBox.exec();
        verif=false;
    }
    else if(!email_valide)
    {
        ui->perso->setCurrentIndex(2);
        msgBox.setText("email doit etre de la forme @esprit.tn ."); msgBox.exec();
        verif=false;
    }
    else if(adressep.isEmpty() )
    {
        ui->perso->setCurrentIndex(2);
        msgBox.setText("Adresse Vide"); msgBox.exec();
        verif=false;
    }
    else if(adressep.length()<4 || !numcaradd)
    {
        ui->perso->setCurrentIndex(2);
        msgBox.setText("Adresse doit comporter minimum 3 caractères et sans caractères spéciaux."); msgBox.exec();
        verif=false;
    }

    return verif;
}
bool MainWindow::verif_modifierperso()
{ bool verif=true;
    bool   numtel=true;
    QString telp=ui->numtelperso_2->text(),adressep=ui->adresseperso_2->text(),mailp=ui->mailperso_2->text();
    for (int i=0; i<telp.length(); i++)
    {
        if (!telp[i].isDigit()) {
            numtel=false;
            break;
        }
    }
    bool email_valide=true;

    // Vérifie si l'adresse e-mail correspond au format "nomprenom@esprit.tn"
    QRegularExpression regex("^[A-Za-z0-9._%+-]+@esprit\\.tn$");
    email_valide=regex.match(mailp).hasMatch();
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1;border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setFixedSize(600,600);
    msgBox.setWindowOpacity(0.8);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");
    msgBox.setIcon(QMessageBox::Information);

    if(telp.isEmpty() )
    {
        ui->perso->setCurrentIndex(3);
        msgBox.setText("Numero De Téléphone Vide."); msgBox.exec();
        verif=false;
    }
    else if(telp.length()!=8 || !numtel)
    {
        ui->perso->setCurrentIndex(3);
        msgBox.setText("Numero doit comporter 8 caractères et seulement des nombres."); msgBox.exec();
        verif=false;
    }
    else if(!email_valide)
    {
        ui->perso->setCurrentIndex(3);
        msgBox.setText("email doit etre de la forme @esprit.tn ."); msgBox.exec();
        verif=false;
    }
    else if(adressep.isEmpty() )
    {
        ui->perso->setCurrentIndex(3);
        msgBox.setText("Adresse Vide"); msgBox.exec();
        verif=false;
    }
    else if(adressep.length()<4)
    {
        ui->perso->setCurrentIndex(3);
        msgBox.setText("Adresse doit comporter minimum 3 caractères."); msgBox.exec();
        verif=false;
    }
    return verif;
}
void MainWindow::on_rechercheperso_clicked()
{
    ui->statp->setEnabled(1);
    ui->trierp->setEnabled(1);
    ui->mailp->setEnabled(1);
    ui->rechercherper->setHidden(0);
    ui->typetrip->setHidden(1);
    ui->rechercherper->clear();
    ui->tableViewP->setModel(P.afficher_p());
    ui->rechercherper->setEnabled(1);
    ui->modifierp->setHidden(1);
    ui->supprimerp->setHidden(1);
    ui->ajoutrfidp->setHidden(1);
    ui->afficherp->setHidden(1);
    ui->pdfp->setHidden(1);
    ui->perso->setCurrentIndex(0);
}

void MainWindow::on_trierp_clicked()
{
    on_home_p_clicked();
    ui->rechercheperso->setEnabled(1);
    ui->statp->setEnabled(1);
    ui->mailp->setEnabled(1);
    ui->typetrip->setHidden(0);
    ui->typetrip->setCurrentIndex(0);
    ui->tableViewP->setModel(P.afficher_p());
    ui->perso->setCurrentIndex(0);
}


void MainWindow::on_typetrip_activated(int index)
{
    ui->tableViewP->setModel(P.trier_p(index));
}
void MainWindow::on_afficherp_clicked()
{
    QString id=ui->rechercherper->text().toUpper();
    Personnel p1;
    P.getperso(p1,id);
    DialogP d;
    d.setWindowIcon(QIcon(":/images/ahminy.png"));
    d.afficher_P(p1);
    d.exec();
}
void MainWindow::on_ajoutrfidp_clicked()
{
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1;border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setFixedSize(600,600);
    msgBox.setWindowOpacity(0.8);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");
    if(!connectardper)
    {
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Capteur RFID indisponnible Pour Le Moment."); msgBox.exec();
    }
    else
    {A_per.write_to_rfidpers("0"); //  lancez le scan
        QString id=ui->rechercherper->text().toUpper();
        Personnel p1;
        P.getperso(p1,id);
        ui->perso->setCurrentIndex(5);}



}
void MainWindow::on_pdfp_clicked()
{
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1;border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setFixedSize(600,600);
    msgBox.setWindowOpacity(0.8);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");
    P.generatePDFReport(ui->rechercherper->text());
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText("Pdf généré avec succés."); msgBox.exec();
}
void MainWindow::on_statp_clicked()
{
    on_home_p_clicked();
    int nbper,nbsdf,nbinv,nbtre,nbmed;
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) from PERSONNEL where metier = :metier");
    query.bindValue(":metier", "Responsable RH");
    if (query.exec() && query.next())
    {
        nbper=query.value(0).toInt();
    }
    else
    {
        nbper= -1;
    }
    query.prepare("SELECT COUNT(*) from PERSONNEL where metier = :metier");
    query.bindValue(":metier", "Receptionniste");
    if (query.exec() && query.next())
    {
        nbsdf=query.value(0).toInt();
    }
    else
    {
        nbsdf= -1;
    }
    query.prepare("SELECT COUNT(*) from PERSONNEL where metier = :metier");
    query.bindValue(":metier", "Gestionnaire De Stock");
    if (query.exec() && query.next())
    {
        nbinv=query.value(0).toInt();
    }
    else
    {
        nbinv= -1;
    }
    query.prepare("SELECT COUNT(*) from PERSONNEL where metier = :metier");
    query.bindValue(":metier", "Tresorier");
    if (query.exec() && query.next())
    {
        nbtre=query.value(0).toInt();
    }
    else
    {
        nbtre= -1;
    }
    query.prepare("SELECT COUNT(*) from PERSONNEL where metier = :metier");
    query.bindValue(":metier", "Medecin");
    if (query.exec() && query.next())
    {
        nbmed=query.value(0).toInt();
    }
    else
    {
        nbmed= -1;
    }
    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.35);
    //nbper,nbsdf,nbinv,nbtre,nbmed;
    if(qMax(qMax(qMax(nbper,nbsdf),qMax(nbtre,nbinv)),nbmed)==0)
    {
        QMessageBox msgBox;
        msgBox.setStyleSheet("QMessageBox {background:#f8f5f1;border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
        msgBox.setFixedSize(600,600);
        msgBox.setWindowOpacity(0.8);
        QFont bellMTFont("Bell MT");
        msgBox.setFont(bellMTFont);
        msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
        msgBox.setWindowTitle("Ahminy");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Base De donnée vide."); msgBox.exec();
    }
    else
    {if (qMax(qMax(qMax(nbper,nbsdf),qMax(nbtre,nbinv)),nbmed)==nbper)
        {
            if(nbsdf !=0) {QPieSlice *slice1 = series->append("Standardiste", nbsdf);slice1->setLabelVisible();}
            else series->append("Standardiste", nbsdf);
            if(nbtre !=0) {QPieSlice *slice2 = series->append("Tresorier", nbtre); slice2->setLabelVisible();}
            else series->append("Tresorier", nbtre);
            if(nbinv !=0) {QPieSlice *slice3 = series->append("Gest.. De Stock", nbinv);slice3->setLabelVisible();}
            else series->append("Gest..De Stock", nbinv);
            if(nbmed !=0) {QPieSlice *slice4 = series->append("Medecin", nbmed);slice4->setLabelVisible();}
            else series->append("Medecin", nbmed);
            if(nbper !=0) {QPieSlice *slice  = series->append("Resp.. RH", nbper); slice->setExploded();slice->setLabelVisible();}
            else series->append("Resp.. RH", nbper);
        }
        else if(qMax(qMax(qMax(nbper,nbsdf),qMax(nbtre,nbinv)),nbmed)==nbsdf)
        {
            if(nbsdf !=0) {QPieSlice *slice1 = series->append("Receptionniste", nbsdf); slice1->setExploded();slice1->setLabelVisible();}
            else series->append("Standardiste", nbsdf);
            if(nbtre !=0) {QPieSlice *slice2 = series->append("Tresorier", nbtre); slice2->setLabelVisible();}
            else series->append("Tresorier", nbtre);
            if(nbinv !=0) {QPieSlice *slice3 = series->append("Gest.. De Stock", nbinv);slice3->setLabelVisible();}
            else series->append("Gest..De Stock", nbinv);
            if(nbmed !=0) {QPieSlice *slice4 = series->append("Medecin", nbmed);slice4->setLabelVisible();}
            else series->append("Medecin", nbmed);
            if(nbper !=0) {QPieSlice *slice  = series->append("Resp.. RH", nbper); slice->setLabelVisible();}
            else series->append("Resp.. RH", nbper);
        }
        else if(qMax(qMax(qMax(nbper,nbsdf),qMax(nbtre,nbinv)),nbmed)==nbtre)
        {

            if(nbsdf !=0) {QPieSlice *slice1 = series->append("Standardiste", nbsdf); slice1->setLabelVisible();}
            else series->append("Standardiste", nbsdf);
            if(nbtre !=0) {QPieSlice *slice2 = series->append("Tresorier", nbtre);slice2->setExploded(); slice2->setLabelVisible();}
            else series->append("Tresorier", nbtre);
            if(nbinv !=0) {QPieSlice *slice3 = series->append("Gest.. De Stock", nbinv);slice3->setLabelVisible();}
            else series->append("Gest..De Stock", nbinv);
            if(nbmed !=0) {QPieSlice *slice4 = series->append("Medecin", nbmed);slice4->setLabelVisible();}
            else series->append("Medecin", nbmed);
            if(nbper !=0) {QPieSlice *slice  = series->append("Resp.. RH", nbper); slice->setLabelVisible();}
            else series->append("Resp.. RH", nbper);
        }
        else if(qMax(qMax(qMax(nbper,nbsdf),qMax(nbtre,nbinv)),nbmed)==nbinv)
        {
            if(nbsdf !=0) {QPieSlice *slice1 = series->append("Standardiste", nbsdf); slice1->setLabelVisible();}
            else series->append("Standardiste", nbsdf);
            if(nbtre !=0) {QPieSlice *slice2 = series->append("Tresorier", nbtre); slice2->setLabelVisible();}
            else series->append("Tresorier", nbtre);
            if(nbinv !=0) {QPieSlice *slice3 = series->append("Gest.. De Stock", nbinv);slice3->setExploded();slice3->setLabelVisible();}
            else series->append("Gest..De Stock", nbinv);
            if(nbmed !=0) {QPieSlice *slice4 = series->append("Medecin", nbmed);slice4->setLabelVisible();}
            else series->append("Medecin", nbmed);
            if(nbper !=0) {QPieSlice *slice  = series->append("Resp.. RH", nbper); slice->setLabelVisible();}
            else series->append("Resp.. RH", nbper);
        }
        else if(qMax(qMax(qMax(nbper,nbsdf),qMax(nbtre,nbinv)),nbmed)==nbmed)
        {
            if(nbsdf !=0) {QPieSlice *slice1 = series->append("Standardiste", nbsdf); slice1->setLabelVisible();}
            else series->append("Standardiste", nbsdf);
            if(nbtre !=0) {QPieSlice *slice2 = series->append("Tresorier", nbtre); slice2->setLabelVisible();}
            else series->append("Tresorier", nbtre);
            if(nbinv !=0) {QPieSlice *slice3 = series->append("Gest..De Stock", nbinv);slice3->setLabelVisible();}
            else series->append("Gest..De Stock", nbinv);
            if(nbmed !=0) {QPieSlice *slice4 = series->append("Medecin", nbmed);slice4->setExploded();slice4->setLabelVisible();}
            else series->append("Medecin", nbmed);
            if(nbper !=0) {QPieSlice *slice  = series->append("Resp.. RH", nbper); slice->setLabelVisible();}
            else series->append("Resp.. RH", nbper);
        }
        ///Design de la charte:
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->setTheme(QChart::ChartThemeBlueIcy);
        QColor bgColor("#f8f5f1");
        QBrush bgBrush(bgColor);
        QPen bgPen("#f8f5f1");
        bgPen.setWidth(35);
        chart->setBackgroundBrush(bgBrush);
        chart->setBackgroundPen(bgPen);
        QChartView *chartview = new QChartView(chart);
        chartview->setRenderHint(QPainter::Antialiasing);

        chartview->setParent(ui->statperso);
        ui->perso->setCurrentIndex(4);
    }


}

void MainWindow::on_closestatperso_clicked()
{

    ui->perso->setCurrentIndex(0);
}
void MainWindow::on_closerfid_clicked()
{
    ui->perso->setCurrentIndex(0);
}
void MainWindow::on_tableViewP_clicked(const QModelIndex &index)
{
    ui->rechercherper->setHidden(0);
    ui->modifierp->setHidden(0);
    ui->supprimerp->setHidden(0);
    ui->ajoutrfidp->setHidden(0);
    ui->pdfp->setHidden(0);
    ui->afficherp->setHidden(0);
    ui->modifierp->setEnabled(1);
    ui->supprimerp->setEnabled(1);
    ui->ajoutrfidp->setEnabled(1);
    ui->pdfp->setEnabled(1);
    ui->afficherp->setEnabled(1);
    ui->typetrip->setCurrentIndex(0);
    ui->typetrip->setHidden(1);
    ui->rechercherper->setText(ui->tableViewP->model()->data(ui->tableViewP->model()->index(index.row(),0)).toString());
    ui->rechercherper->setEnabled(0);
    ui->rechercheperso->setEnabled(1);
    ui->trierp->setEnabled(1);
    ui->statp->setEnabled(1);
    ui->mailp->setEnabled(1);
}
void MainWindow::on_home_p_clicked()
{
    clearajoutperso();
    ui->rechercheperso->setEnabled(1);
    ui->trierp->setEnabled(1);
    ui->statp->setEnabled(1);
    ui->mailp->setEnabled(1);
    ui->rechercherper->setHidden(1);
    ui->modifierp->setHidden(1);
    ui->supprimerp->setHidden(1);
    ui->ajoutrfidp->setHidden(1);
    ui->afficherp->setHidden(1);
    ui->pdfp->setHidden(1);
    ui->typetrip->setHidden(1);
    ui->typetrip->setCurrentIndex(0);
    ui->tableViewP->setModel(P.afficher_p());
    ui->perso->setCurrentIndex(0);

}
void MainWindow::on_rechercherper_returnPressed()
{
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1;border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setFixedSize(600,600);
    msgBox.setWindowOpacity(0.8);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");
    if(ui->rechercherper->text().isEmpty())
    {
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Aucune Donnée Saisie."); msgBox.exec();
    }
}
void MainWindow::on_rechercherper_textEdited(const QString &arg1)
{
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1; border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setWindowOpacity(0.8);
    msgBox.setFixedSize(600,600);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");
    QString ch=arg1;
    if (P.filtrageDynamique_p(ch)->rowCount() == 0) {
        msgBox.setIcon(QMessageBox::Critical);

        msgBox.setText("Aucune Correspondance."); msgBox.exec();
    } else {
        ui->tableViewP->setModel(P.filtrageDynamique_p(ch));
    }


}
void MainWindow::on_barpersonnel_activated(int index)
{ P.getperso(P,ui->username->text().toUpper());
    if(index==2)
    { A_per.write_to_rfidpers("-1");
        currentRole = -1; // c bon trah jareb nahi breakpoint
        ui->tabpersonnel->setCurrentIndex(0);
        ui->warninglogin->setHidden(1);
        if(ui->sesouvenirdemoi->isChecked())
            ui->password->clear();
        else { ui->username->clear(); ui->password->clear();}
        ui->exigo->setCurrentIndex(0);
        this->resize(1035,700);
        QRect screenGeometry = QApplication::desktop()->screenGeometry();
        int x = (screenGeometry.width() - this->width()) / 2;
        int y = (screenGeometry.height() - this->height()) / 2;
        this->move(x, y);
    }
    else if(index==1)
    {
        modifmdp d;
        d.affichermail_P(P);
        d.setWindowIcon(QIcon(":/images/ahminy.png"));
        d.exec();
    }
    else if(index==0)
    {
        DialogP d;
        d.setWindowIcon(QIcon(":/images/ahminy.png"));
        d.afficher_P(P);
        d.exec();
    }
    ui->barpersonnel->setCurrentIndex(-1);
}
void MainWindow::on_mailp_clicked()
{
    mailingp d;
    d.affichermail_P(P);
    d.affichermailDest();
    d.setWindowIcon(QIcon(":/images/ahminy.png"));
    d.exec();
}
void MainWindow::on_lancerlescan_clicked()
{
    datapers=A_per.read_from_rfidpers();
    QString rfid=datapers.mid(0,7);

    qDebug() << " fel ajout" << rfid << endl;

    /// fel arduino twali todhhor scan terminé w lampe bleu wala haja
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1;border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setFixedSize(600,600);
    msgBox.setWindowOpacity(0.8);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");
    if(rfid=="") {
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Veuillez repassez La Carte."); msgBox.exec();
    }
    else if (P.recherche_rfid_p(rfid))
    {   A_per.write_to_rfidpers("1"); // affectation  ma saretch
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Carte déjà enregistrée."); msgBox.exec();

    }
    else
    {   A_per.write_to_rfidpers("2"); // affectation saret
        QString id=ui->rechercherper->text().toUpper();
        QString code;
        const int length = 4;
        const QString chars = "0123456789";

        for (int i = 0; i < length; ++i) {
            const int index = qrand() % chars.length();
            code.append(chars.at(index));
        }
        qDebug() << "code l carte random : " << code ;
        P.affecterrfid_p(id,rfid,code);
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText("Carte attribuée."); msgBox.exec();
        on_home_p_clicked();

    }
}
void MainWindow::on_cartelogin_clicked()
{
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1;border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setFixedSize(600,600);
    msgBox.setWindowOpacity(0.8);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");
    if(!connectardper)
    {
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Capteur RFID indisponnible Pour Le Moment."); msgBox.exec();
    }
    else {ui->warninglogin->setHidden(1);
        ui->usernameL->setHidden(1);
        ui->username->setHidden(1);
        ui->passwordL->setHidden(1);
        ui->password->setHidden(1);
        ui->confirm->setHidden(1);
        ui->sesouvenirdemoi->setHidden(1);
        ui->showpswd->setHidden(1);
        A_per.write_to_rfidpers("3");
        ui->rfidlogin->setHidden(0);
        ui->iconrfidlogin->setHidden(0);
        ui->lancerlescanlogin->setHidden(0);
        ui->retour->setHidden(0);
        ui->coderfid->clear();
        ui->coderfid->setHidden(1);
        ui->rfidlogin->setText("Veuillez Scannez La Carte");
        ui->rfidlogin->move(150,30);

    }
}
void MainWindow::on_retour_clicked()
{
    ui->warninglogin->setText("Identifiant ou Mot de Passe Incorrect");
    ui->warninglogin->move(70,20);
    ui->warninglogin->setHidden(1);
    ui->usernameL->setHidden(0);
    ui->username->setHidden(0);
    ui->passwordL->setHidden(0);
    ui->password->setHidden(0);
    ui->password->clear();
    ui->confirm->setHidden(0);
    ui->sesouvenirdemoi->setHidden(0);
    ui->showpswd->setHidden(0);
    // retour etat initial
    ui->rfidlogin->setHidden(1);
    ui->iconrfidlogin->setHidden(1);
    ui->lancerlescanlogin->setHidden(1);
    ui->coderfid->setHidden(1);
    ui->retour->setHidden(1);
}
void MainWindow::on_lancerlescanlogin_clicked()
{
    datapers=A_per.read_from_rfidpers();
    rfid=datapers.mid(0,7);
    /// fel arduino twali todhhor scan terminé w lampe bleu wala haja
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#fbf9f9;border:8px double #e6e4ea;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color: #604628; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color: #604628;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setFixedSize(600,600);
    msgBox.setWindowOpacity(0.8);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");

    qDebug() << "fe login" << rfid << endl;

    if(rfid=="") {
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Veuillez repassez La Carte."); msgBox.exec();
    }
    else if (!P.recherche_rfid_p(rfid))
    {   A_per.write_to_rfidpers("3"); // login  ma saretch
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Vérifiez Votre Carte ."); msgBox.exec();
    }
    else
    {
        ui->rfidlogin->setText("Saisisez Votre Code.");
        ui->rfidlogin->move(180,30);
        ui->iconrfidlogin->setHidden(1);
        ui->lancerlescanlogin->setHidden(1);
        ui->coderfid->setHidden(0);

    }
}
void MainWindow::on_coderfid_returnPressed()
{
    int x;
    bool test=P.se_connecterrfid(rfid,ui->coderfid->text());
    if(test)
    { on_retour_clicked();
        P.getpersorfid(P,rfid);
        QString nomprenom=P.get_nom_p()+" "+P.get_prenom_p();
        A_per.write_to_rfidpers(nomprenom.toUtf8());
        x=ui->metierperso_2->findText(P.get_metier());
        ui->barpersonnel->setCurrentIndex(-1);
        this->resize(1400,750);
        QRect screenGeometry = QApplication::desktop()->screenGeometry();
        int x = (screenGeometry.width() - this->width()) / 2;
        int y = (screenGeometry.height() - this->height()) / 2;
        this->move(x, y);
    }
    else
    {    A_per.write_to_rfidpers("4");
        ui->rfidlogin->move(170,45);
        ui->warninglogin->setHidden(0);
        ui->warninglogin->setText("Code Incorrect");
        ui->warninglogin->move(210,20);
        x=-1;
    }
    currentRole = x;
    getacces(x);
}
//nour acceuil

void MainWindow::clear_sdf()
{
    QDate d;

    ///Ajouter:
    ui->cinsdf->clear();
    ui->nomsdf->clear();
    ui->prenomsdf->clear();
    ui->femmesdf->setAutoExclusive(false);
    ui->femmesdf->setChecked(false);
    ui->hommesdf->setAutoExclusive(false);
    ui->hommesdf->setChecked(false);
    ui->dobsdf->setDate(d.currentDate());

    ///Modifier:
    ui->nbpassagesdf->clear();

    ///Recherche:
    ui->recherchersdf->clear();
}


void MainWindow::on_tableViewsdf_clicked(const QModelIndex &index)
{
    ui->recherchersdf->setText(ui->tableViewsdf->model()->data(ui->tableViewsdf->model()->index(index.row(),0)).toString());
    ui->recherchersdf->setHidden(0);
    ui->modsdf->setHidden(0);
    ui->supprimersdf->setHidden(0);
    ui->pdfsdf->setHidden(0);
    ui->affsdf->setHidden(0);
    ui->textsdf->setHidden(0);
    ui->fichierhistorique->setHidden(0);
    ui->sdfnotif->setHidden(0);
    ui->selectrisdf->setHidden(1);

    ui->selectrisdf->setCurrentIndex(0);

    ui->recherchesdf->setEnabled(1);
    ui->modsdf->setEnabled(1);
    ui->supprimersdf->setEnabled(1);
    ui->pdfsdf->setEnabled(1);
    ui->affsdf->setEnabled(1);
    ui->textsdf->setEnabled(1);
    ui->fichierhistorique->setEnabled(1);
    ui->triersdf->setEnabled(1);
    ui->statsdfsexe->setEnabled(1);
    ui->recherchersdf->setEnabled(0);
    ui->sdfnotif->setEnabled(1);
}


void MainWindow::on_cinsdf_returnPressed()
{
    ui->nomsdf->setFocus();
}


void MainWindow::on_nomsdf_returnPressed()
{
    ui->prenomsdf->setFocus();
}


void MainWindow::on_prenomsdf_returnPressed()
{
    ui->femmesdf->setChecked(true);
    ui->prenomsdf->clearFocus();
}


void MainWindow::on_femmesdf_clicked()
{
    ui->hommesdf->setChecked(false);
}


void MainWindow::on_hommesdf_clicked()
{
    ui->femmesdf->setChecked(false);
}


void MainWindow::on_recherchesdf_clicked()
{
    //Boutons:
    ui->recherchersdf->clear();

    ui->recherchersdf->setHidden(0);
    ui->supprimersdf->setHidden(1);
    ui->modsdf->setHidden(1);
    ui->affsdf->setHidden(1);
    ui->pdfsdf->setHidden(1);
    ui->textsdf->setHidden(1);
    ui->fichierhistorique->setHidden(1);
    ui->selectrisdf->setHidden(1);

    ui->triersdf->setEnabled(1);
    ui->statsdfsexe->setEnabled(1);
    ui->recherchersdf->setEnabled(1);
    ui->sdfnotif->setEnabled(1);

    ui->selectrisdf->setCurrentIndex(0);
    ui->Sdf->setCurrentIndex(0);
    ui->tableViewsdf->setModel(Stmp.afficher_b());
}


void MainWindow::on_recherchersdf_returnPressed()
{
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1;border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setWindowOpacity(0.8);
    msgBox.setFixedSize(600,600);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");
    if(ui->recherchersdf->text().isEmpty())
    {
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Aucune Donnée Saisie.");
        msgBox.exec();
    }
}


void MainWindow::on_recherchersdf_textEdited(const QString &arg1)
{
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1; border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setWindowOpacity(0.8);
    msgBox.setFixedSize(600,600);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");
    QString ch=arg1;
    if (Stmp.filtrage_sdf(ch)->rowCount() == 0) {
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Aucune Correspondance.");
        msgBox.exec();
    } else {
        ui->tableViewsdf->setModel(Stmp.filtrage_sdf(ch));
    }
}


void MainWindow::on_homesdf_clicked()
{
    clear_sdf();

    ui->recherchersdf->setHidden(1);
    ui->modsdf->setHidden(1);
    ui->supprimersdf->setHidden(1);
    ui->pdfsdf->setHidden(1);
    ui->affsdf->setHidden(1);
    ui->selectrisdf->setHidden(1);
    ui->textsdf->setHidden(1);
    ui->fichierhistorique->setHidden(1);

    ui->tableViewsdf->setModel(Stmp.afficher_b());
    ui->Sdf->setCurrentIndex(0);
    ui->selectrisdf->setCurrentIndex(0);

    ui->recherchesdf->setEnabled(1);
    ui->triersdf->setEnabled(1);
    ui->statsdfsexe->setEnabled(1);
    ui->sdfnotif->setEnabled(1);
}


void MainWindow::on_selectrisdf_activated(int index)
{
    ui->tableViewsdf->setModel(Stmp.tri_sdf(index));
}


void MainWindow::on_triersdf_clicked()
{
    on_homesdf_clicked();

    //Boutons:
    ui->selectrisdf->setHidden(0);
    ui->recherchersdf->setHidden(1);

    ui->statsdfsexe->setEnabled(1);
    ui->recherchersdf->setEnabled(1);
    ui->sdfnotif->setEnabled(1);

    ui->tableViewsdf->setModel(Stmp.afficher_b());

    ui->Sdf->setCurrentIndex(0);
    ui->selectrisdf->setCurrentIndex(0);
}


void MainWindow::on_affsdf_clicked()
{
    Dialogs dia;
    dia.setWindowTitle("Affichage");
    QString cin_b=ui->recherchersdf->text();
    Sdf S;
    Stmp.Get_sdf(S,cin_b);
    dia.afficherunsdf(S);
    dia.exec();

    //ui->recherchersdf->clear();
}


void MainWindow::on_statsdfsexe_clicked()
{
    //Boutons:
    on_homesdf_clicked();

    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1; border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setWindowOpacity(0.8);
    msgBox.setFixedSize(600,600);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");

    int nbf=Stmp.nb_sexe("Femme");
    int nbh=Stmp.nb_sexe("Homme");

    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.35);

    if(nbf==0)
    {
        series->append("Homme", nbh);
        series->append("Femme", nbf);
    }
    else if(nbh==0)
    {
        series->append("Femme", nbf);
        series->append("Homme", nbh);
    }
    else if (nbf>=nbh)
    {
        series->append("Femme", nbf);
        QPieSlice *slice = series->append("Homme", nbh);
        slice->setExploded();
        slice->setLabelVisible();
    }
    else if (nbf<nbh)
    {
        series->append("Homme", nbh);
        QPieSlice *slice = series->append("Femme", nbf);
        slice->setExploded();
        slice->setLabelVisible();
    }

    ///Design de la charte:
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setTheme(QChart::ChartThemeQt);
    QColor bgColor("#f8f5f1");
    QBrush bgBrush(bgColor);
    QPen bgPen("#f8f5f1");
    bgPen.setWidth(35);
    chart->setBackgroundBrush(bgBrush);
    chart->setBackgroundPen(bgPen);
    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);

    chartview->setParent(ui->statsexesdf);
    if ((nbf==0) && (nbh==0))
    {
        ui->Sdf->setCurrentIndex(0);
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText("Base de donnée vide");
        msgBox.exec();
    }
    else ui->Sdf->setCurrentIndex(3);
}


void MainWindow::on_closestatsdf_clicked()
{
    //Boutons:
    ui->Sdf->setCurrentIndex(0);
}


void MainWindow::on_sdfnotif_clicked()
{
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1; border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setWindowOpacity(0.8);
    msgBox.setFixedSize(600,600);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));

    //Boutons:
    //on_homesdf_clicked();
    QVector<QString> tab=Stmp.notifsdf();

    //Notifications:
    QSystemTrayIcon *notifyIcon;
    notifyIcon=new QSystemTrayIcon(this);
    notifyIcon->setIcon(QIcon(":/images/ahminy.png"));


    if(tab.size()==0)
    {
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText("Aucun bénéficiaire n'a dépassé sa durée attribuée.");
        msgBox.exec();
    }

    else
    {
        for (int i = 0; i < tab.size(); i++)
        {
            notifyIcon->show();
            QString num = QString::number(i+1);
            notifyIcon->showMessage("Notification "+ num , tab[i], QSystemTrayIcon::Information);
        }

    }
}
void MainWindow::on_closenotifsdf_clicked()
{
    //Boutons:
    ui->Sdf->setCurrentIndex(0);
}


void MainWindow::on_pdfsdf_clicked()
{
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1; border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setWindowOpacity(0.8);
    msgBox.setFixedSize(600,600);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");

    QString cin_b=ui->recherchersdf->text();
    Stmp.creesdf_pdf(cin_b);
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText("PDF Généré");
    msgBox.exec();

    //ui->recherchersdf->clear();
}


void MainWindow::on_textsdf_clicked()
{
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1; border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setWindowOpacity(0.8);
    msgBox.setFixedSize(600,600);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");
    QString cin_b=ui->recherchersdf->text();

    QDate dt;
    Sdf S;
    Stmp.Get_sdf(S,cin_b);
    if(S.Get_num_ch()!=0)
    {
        int etat_l;
        int nb_lit=S.Get_nb_lit(S.Get_num_ch())+1;
        if(nb_lit==0) etat_l=1;
        else etat_l=0;
        bool test1=S.modifier_l(S.Get_num_ch(),etat_l,nb_lit);

        S.Set_date_sor_b(dt.currentDate());
        Stmp.historique_sdf(cin_b,P.get_nom_p()+" "+P.get_prenom_p());
        S.Set_num_ch(0);
        bool test=S.modifier_b(cin_b);
        if((test)&&(test1))
        {
            ui->tableViewsdf->setModel(Stmp.afficher_b()); //refresh
        }
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText("Ce beneficiaire a quitté le centre.");
        msgBox.exec();

    }
    else
    {
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText("Ce beneficiaire n'a pas encore de chambre affectée .");
        msgBox.exec();
    }
    //ui->recherchersdf->clear();
}


void MainWindow::on_fichierhistorique_clicked()
{
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1; border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setWindowOpacity(0.8);
    msgBox.setFixedSize(600,600);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");
    Historique d;
    d.setWindowTitle("Historique");
    QString cin_b=ui->recherchersdf->text();
    if(Stmp.readtext_sdf(cin_b).isEmpty())
    {
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Historique Indisponnible.");
        msgBox.exec();
    }
    else {d.afficherhistorique(Stmp.readtext_sdf(cin_b));
        d.exec();}

    //ui->recherchersdf->clear();
}


void MainWindow::on_ajoutersdf_clicked()
{
    ui->Sdf->setCurrentIndex(1);

    //Boutons:
    ui->supprimersdf->setHidden(1);
    ui->modsdf->setHidden(1);
    ui->recherchersdf->setHidden(1);
    ui->affsdf->setHidden(1);
    ui->pdfsdf->setHidden(1);
    ui->textsdf->setHidden(1);
    ui->fichierhistorique->setHidden(1);
    ui->selectrisdf->setHidden(1);

    ui->recherchesdf->setEnabled(0);
    ui->statsdfsexe->setEnabled(0);
    ui->triersdf->setEnabled(0);
    ui->sdfnotif->setEnabled(0);
}


void MainWindow::on_confirmerAjoutersdf_clicked()
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



    QDate date;
    QString sexe_b;
    if(ui->femmesdf->isChecked()) sexe_b="Femme";
    else sexe_b="Homme";
    QString cin_b=ui->cinsdf->text();
    QString prenom_b=ui->prenomsdf->text().toLower();
    prenom_b[0]=prenom_b[0].toUpper();
    QString nom_b=ui->nomsdf->text().toLower();
    nom_b[0]=nom_b[0].toUpper();
    QDate dob_b=ui->dobsdf->date();

    ///Debut controle de saisie:

    bool verif=true;

    bool numcin=true;
    for (int i=0; i<cin_b.length(); i++)
    {
        if (!cin_b[i].isDigit())
        {
            numcin=false;
            break;
        }
    }

    bool numnom=true;
    for (int i=0; i<nom_b.length(); i++)
    {
        if (!nom_b[i].isLetter())
        {
            numnom=false;
            break;
        }
    }

    bool numprenom=true;
    for (int i=0; i<prenom_b.length(); i++)
    {
        if (!prenom_b[i].isLetter())
        {
            numprenom=false;
            break;
        }
    }

    QDate dateRec = QDate::currentDate();

    //CIN:
    if (cin_b.isEmpty())
    {
        ui->Sdf->setCurrentIndex(1);
        msgBox.setText("Veuillez remplir le cin du sdf.");
        msgBox.exec();
        verif=false;
    }

    else if ((cin_b.length()!=8)||(!numcin))
    {
        ui->Sdf->setCurrentIndex(1);
        msgBox.setText("Cin doit comporter 8 caractères et seulement des numeros.");
        msgBox.exec();
        verif=false;
    }

    else if(Stmp.recherche_sdf(cin_b))
    {
        ui->Sdf->setCurrentIndex(1);
        msgBox.setText("Cin doit etre unique.");
        msgBox.exec();
        verif=false;
    }

    //NOM:
    else if (ui->nomsdf->text().isEmpty())
    {
        ui->Sdf->setCurrentIndex(1);
        msgBox.setText("Veuillez remplir le nom du sdf.");
        msgBox.exec();
        verif=false;
    }

    else if (!numnom)
    {
        ui->Sdf->setCurrentIndex(1);
        msgBox.setText("Le nom ne comporte pas des numeros et des symboles.");
        msgBox.exec();
        verif=false;
    }

    //PRENOM:
    else if (ui->prenomsdf->text().isEmpty())
    {
        ui->Sdf->setCurrentIndex(1);
        msgBox.setText("Veuillez remplir le prenom du sdf.");
        msgBox.exec();
        verif=false;
    }

    else if (!numprenom)
    {
        ui->Sdf->setCurrentIndex(1);
        msgBox.setText("Le prenom ne comporte pas des numeros et des symboles.");
        msgBox.exec();
        verif=false;
    }

    //DATE:
    else if (dob_b > dateRec)
    {
        ui->Sdf->setCurrentIndex(1);
        msgBox.setText("La date saisie dépasse la date actuelle.");
        msgBox.exec();
        verif=false;
    }

    //SEXE:
    else if (!ui->femmesdf->isChecked() && !ui->hommesdf->isChecked())
    {
        ui->Sdf->setCurrentIndex(1);
        msgBox.setText("Veuillez sélectionner le sexe.");
        msgBox.exec();
        verif=false;
    }

    ///Fin controle de saisie:

    Sdf S(cin_b, prenom_b, nom_b, dob_b, sexe_b, 0, date.currentDate(), date.currentDate(), 0);

    bool test=true;
    if (verif)
    {
        test=S.ajouter_b();

        if (test)
        {
            ui->tableViewsdf->setModel(Stmp.afficher_b()); //refresh
            clear_sdf();
            ui->Sdf->setCurrentIndex(0);
            //Boutons:
            ui->recherchersdf->clear();

            ui->recherchesdf->setEnabled(1);
            ui->statsdfsexe->setEnabled(1);
            ui->triersdf->setEnabled(1);
            ui->sdfnotif->setEnabled(1);
        }
        else
        {
            msgBox.setText("Ajout non effectué.");
            msgBox.exec();
        }
    }
}


void MainWindow::on_closeajoutersdf_clicked()
{
    ui->Sdf->setCurrentIndex(0);
    clear_sdf();

    //Boutons:
    ui->recherchersdf->clear();

    ui->recherchesdf->setEnabled(1);
    ui->statsdfsexe->setEnabled(1);
    ui->triersdf->setEnabled(1);
    ui->sdfnotif->setEnabled(1);
}


void MainWindow::on_supprimersdf_clicked()
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

    QString cin_b=ui->recherchersdf->text();

    bool test=Stmp.supprimer_b(cin_b);
    if(test)
    {
        ui->tableViewsdf->setModel(Stmp.afficher_b()); //refresh

        msgBox.setText("Suppression effectuée.");
        msgBox.exec();

        ///Supression de fichier historique:
        /*QFile file("Historique/" + cin_b + ".txt");

                if (file.exists()) {
                    if (file.remove()) {
                        qDebug() << "Le fichier a été supprimé avec succès";
                    } else {
                        qDebug() << "Erreur lors de la suppression du fichier";
                    }
                } else {
                    qDebug() << "Le fichier n'existe pas";
                }*/
    }
    else
    {
        msgBox.setText("Suppression non effectuée.");
        msgBox.exec();
    }

    //ui->recherchersdf->clear();
    on_homesdf_clicked();
}


void MainWindow::on_modsdf_clicked()
{
    QString cin_b=ui->recherchersdf->text();
    Sdf S;
    Stmp.Get_sdf(S,cin_b);
    int sexe_l;
    if(S.Get_sexe_b()=="Femme") sexe_l=0;
    else sexe_l=1;

    ///Select lit:
    ui->num_lit->clear();
    QStringList num_lit;
    QSqlQuery query;
    query.prepare("SELECT num_l FROM Chambres WHERE etat_l = 0 AND num_l <> 0 AND sexe_l=:sexe_l AND num_l!=:num_l");
    query.bindValue(":sexe_l",sexe_l);
    query.bindValue(":num_l",S.Get_num_ch());
    if (!query.exec())
    {
        qDebug() << "Error: could not execute query.";
        return;
    }
    while (query.next())
    {
        QString num = query.value(0).toString();
        num_lit.append(num);
    }
    ui->num_lit->insertItems(0,num_lit);

    ui->Sdf->setCurrentIndex(2);

    Stmp.Get_sdf(S,cin_b);
    QString nb_ps = QString::number(S.Get_nb_pass_b());
    ui->nbpassagesdf->setText(nb_ps);
    if(S.Get_num_ch()==0) ui->affchambre->setChecked(true);
    else ui->modchambre->setChecked(true);

    //Boutons:
    ui->supprimersdf->setEnabled(0);
    ui->modsdf->setEnabled(0);
    ui->affsdf->setEnabled(0);
    ui->pdfsdf->setEnabled(0);
    ui->textsdf->setEnabled(0);
    ui->fichierhistorique->setEnabled(0);

    ui->recherchersdf->setEnabled(0);
    ui->recherchesdf->setEnabled(0);
    ui->triersdf->setEnabled(0);
    ui->statsdfsexe->setEnabled(0);
    ui->sdfnotif->setEnabled(0);

}


void MainWindow::on_num_lit_currentTextChanged(const QString &arg1)
{
    int numch=(&arg1)->toInt();
    int nb_lit=Stmp.Get_nb_lit(numch);
    QString nblit = QString::number(nb_lit);
    ui->nblit->setText("Nombre de lit restant: "+ nblit);
}


void MainWindow::on_confirmerModifiersdf_clicked()
{
    MainWindow w;
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1; border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setWindowOpacity(0.8);
    msgBox.setFixedSize(600,600);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");



    Sdf S;
    QString cin_b=ui->recherchersdf->text();
    Stmp.Get_sdf(S,cin_b);
    QDate dateRec = QDate::currentDate();

    if(ui->affchambre->isChecked())
    {
        S.Set_nb_pass_b(S.Get_nb_pass_b()+1);
        S.Set_date_ent_b(dateRec);
    }

    int etat_l;
    int numch= ui->num_lit->currentText().toInt();

    int nb_lit=S.Get_nb_lit(S.Get_num_ch())+1;
    if(nb_lit==0) etat_l=1;
    else etat_l=0;
    bool test1=S.modifier_l(S.Get_num_ch(),etat_l,nb_lit);

    S.Set_num_ch(numch);

    bool test=S.modifier_b(cin_b);
    nb_lit=S.Get_nb_lit(numch)-1;
    if(nb_lit==0) etat_l=1;
    else etat_l=0;
    bool test2=S.modifier_l(numch,etat_l,nb_lit);

    if((test)&&(test2)&&(test1))
    {
        ui->Sdf->setCurrentIndex(0);
        ui->tableViewsdf->setModel(Stmp.afficher_b()); //refresh

        //Boutons
        ui->supprimersdf->setEnabled(1);
        ui->modsdf->setEnabled(1);
        ui->affsdf->setEnabled(1);
        ui->pdfsdf->setEnabled(1);
        ui->textsdf->setEnabled(1);
        ui->fichierhistorique->setEnabled(1);

        //ui->recherchersdf->setEnabled(1);
        ui->recherchesdf->setEnabled(1);
        ui->triersdf->setEnabled(1);
        ui->statsdfsexe->setEnabled(1);
        ui->sdfnotif->setEnabled(1);
    }
    else
    {
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText("Modification non affectuée.");
        msgBox.exec();
    }
}


void MainWindow::on_closeModifiersdf_clicked()
{
    ui->Sdf->setCurrentIndex(0);

    //Boutons:
    ui->supprimersdf->setEnabled(1);
    ui->modsdf->setEnabled(1);
    ui->affsdf->setEnabled(1);
    ui->pdfsdf->setEnabled(1);
    ui->textsdf->setEnabled(1);
    ui->fichierhistorique->setEnabled(1);

    //ui->recherchersdf->setEnabled(1);
    ui->recherchesdf->setEnabled(1);
    ui->triersdf->setEnabled(1);
    ui->statsdfsexe->setEnabled(1);
    ui->sdfnotif->setEnabled(1);
}

//yassmine inventaire

//mayssa donation


//loujain consultation

void MainWindow::on_ajoutermed_clicked()
{
    ui->med->setCurrentIndex(1);
}

void MainWindow::on_confirmerAjoutermed_clicked()
{
    ui->med->setCurrentIndex(0);
}

void MainWindow::on_closeajoutermed_clicked()
{
    ui->med->setCurrentIndex(0);
}

void MainWindow::on_cinpatient_activated()
{
    ui->descriptionpatient->setFocus();
}


















































void MainWindow::on_ajouterinventaire_clicked()
{
    on_homeinv_clicked();
    ui->statinv->setEnabled(0);
    ui->triinv->setEnabled(0);
    ui->bilaninv->setEnabled(0);
    ui->pdfinv->setEnabled(0);
    ui->inv->setCurrentIndex(1);
}

void MainWindow::on_closeajouterinv_clicked()
{
    on_homeinv_clicked();
}

void MainWindow::on_annuler_imageinv_clicked()
{
    ui->imageinv_2->setVisible(true);
    ui->annuler_imageinv->setVisible(false);
    ui->image_name_inv->setText("");
    ui->image_name_inv->setVisible(false);
}

void MainWindow::on_confirmerAjouterinv_clicked()
{
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1; border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setWindowOpacity(0.8);
    msgBox.setFixedSize(600,600);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");

    int id_s=0;

    ui->inv->setCurrentIndex(0);
    QString categorie=ui->categorieinv->currentText();
    QString type=ui->typeinv->currentText();
    QString sexe_s=ui->sexeinv->currentText();
    double prix=ui->prixinv->value();
    int nb_tot=ui->nb_totinv->value();
    int nb_res=ui->nb_totinv->value();
    QString imagePath = ui->image_name_inv->text();
    stock S(id_s,categorie,type,sexe_s,prix,nb_tot,nb_res,imagePath);
    if (S.verif_exist(S)==true)
    {
        int c,r;
        c=S.get_nbr_tot(S);
        r=S.get_nbr_rest(S);
        S.update_nbr_tot(c+nb_tot,S);
        S.update_nbr_rest(r+nb_res,S);
        id_s=S.get_id_s(S);
        QDate currentDate = QDate::currentDate();
        Stock_stat s_stat(id_s,prix,nb_tot,nb_res,currentDate);
        s_stat.ajouter_stock_stat();
        ui->tableView_inv->setModel(S1.afficher_inv());
        ui->imageinv_2->setVisible(true);
        ui->annuler_imageinv->setVisible(false);
        ui->image_name_inv->setText("");
        ui->image_name_inv->setVisible(false);
        ui->categorieinv->setCurrentIndex(0);


        QStringList haut= {"Pull sans manche","Pull manche courte","Pull manche longue","Veste","Manteau"};
        ui->typeinv->clear(); ui->typeinv->insertItems(0,haut);
        ui->sexeinv->setCurrentIndex(0);
        ui->prixinv->setValue(0);
        ui->nb_totinv->setValue(0);
    }
    else {
        bool test=S.ajouter_inv();
        id_s=S.get_id_s(S);
        QDate currentDate = QDate::currentDate();
        Stock_stat s_stat(id_s,prix,nb_tot,nb_res,currentDate);
        s_stat.ajouter_stock_stat();
        ui->imageinv_2->setVisible(true);
        ui->annuler_imageinv->setVisible(false);
        ui->image_name_inv->setText("");
        ui->image_name_inv->setVisible(false);
        ui->categorieinv->setCurrentIndex(0);


        QStringList haut= {"Pull sans manche","Pull manche courte","Pull manche longue","Veste","Manteau"};
        ui->typeinv->clear(); ui->typeinv->insertItems(0,haut);
        ui->sexeinv->setCurrentIndex(0);
        ui->prixinv->setValue(0);
        ui->nb_totinv->setValue(0);

        if(test)
        { ui->tableView_inv->setModel(S1.afficher_inv());
        }
        else
        {
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText("Ajout non effectué.");
            msgBox.exec();
        }
    }

    S = stock();
}

void MainWindow::on_imageinv_2_clicked()
{
    QString imagePath = QFileDialog::getOpenFileName(this, tr("Choisir une image"), "", tr("Images (*.png *.jpg *.jpeg)"));
    ui->imageinv_2->setVisible(false);
    ui->annuler_imageinv->setVisible(true);
    ui->image_name_inv->setText(imagePath);
    ui->image_name_inv->setVisible(true);
}

void MainWindow::on_homeinv_clicked()
{
    ui->suppmodifinv->setHidden(1);
    ui->modifierinv_2->setHidden(1);
    ui->supprimerinv->setHidden(1);
    ui->vendre_inv->setHidden(1);
    ui->triinv->setEnabled(1);
    ui->bilaninv->setEnabled(1);
    ui->affichplus->setHidden(1);
    ui->statinv->setEnabled(1);
    ui->pdfinv->setEnabled(1);

    ui->rechercherinv_2->setEnabled(1);
    ui->triinv_combo->setHidden(1);
    ui->triinv_combo->setCurrentIndex(0);
    ui->inv->setCurrentIndex(0);
    ui->tableView_inv->setModel(S1.afficher_inv());
}

void MainWindow::on_categorieinv_activated(int index)
{
    QStringList bas= {"Short","Pantalon","Jupe","Robe"};
    QStringList haut= {"Pull sans manche","Pull manche courte","Pull manche longue","Veste","Manteau"};
    QStringList chaussure= {"Snikers","Bottes","Chaussures a talon","Sandales","Claquettes"};
    QStringList accesoire= {"Chaussettes","Gants","Bonnets","Cache Col","Colants","Sous-vetements"};
    switch (index) {
    case 0:{ui->typeinv->clear(); ui->typeinv->insertItems(0,haut);break;}
    case 1:{ui->typeinv->clear(); ui->typeinv->insertItems(0,bas);break;}
    case 2:{ui->typeinv->clear(); ui->typeinv->insertItems(0,chaussure);break;}
    case 3:{ui->typeinv->clear(); ui->typeinv->insertItems(0,accesoire);break;}

    }
}

void MainWindow::on_rechercherinv_2_clicked()
{
    on_homeinv_clicked();
    ui->suppmodifinv->clear();
    ui->suppmodifinv->setHidden(0);
    ui->suppmodifinv->setEnabled(1);
}

void MainWindow::on_suppmodifinv_textEdited(const QString &arg1)
{
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1; border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setWindowOpacity(0.8);
    msgBox.setFixedSize(600,600);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");
    QString ch=arg1;
    if (S1.Recherche_inv(ch)->rowCount() == 0) {
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Aucune Correspondance.");
        msgBox.exec();
    } else {
        ui->tableView_inv->setModel(S1.Recherche_inv(ch));
    }
}

void MainWindow::on_suppmodifinv_returnPressed()
{
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1;border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setWindowOpacity(0.8);
    msgBox.setFixedSize(600,600);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");
    if(ui->suppmodifinv->text().isEmpty())
    {
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Aucune Donnée Saisie.");
        msgBox.exec();
    }
}

void MainWindow::on_tableView_inv_clicked(const QModelIndex &index)
{
    ui->suppmodifinv->setText(ui->tableView_inv->model()->data(ui->tableView_inv->model()->index(index.row(),0)).toString());
    ui->suppmodifinv->setHidden(0);
    ui->modifierinv_2->setHidden(0);
    ui->supprimerinv->setHidden(0);
    ui->vendre_inv->setHidden(0);
    ui->affichplus->setHidden(0);
    ui->triinv_combo->setHidden(1);
    ui->triinv_combo->setCurrentIndex(0);
    ui->rechercherinv_2->setEnabled(1);
    ui->triinv->setEnabled(1);
    ui->statinv->setEnabled(1);
    ui->suppmodifinv->setEnabled(0);
    ui->bilaninv->setEnabled(1);
    ui->pdfinv->setEnabled(1);
}

void MainWindow::on_statinv_clicked()
{  on_homeinv_clicked();
    stock s;
    int haut=s.nb_categorie("Haut");
    int bas=s.nb_categorie("Bas");
    int accesoire=s.nb_categorie("Accessoires");
    int chaussure=s.nb_categorie("Chaussures");
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1; border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setWindowOpacity(0.8);
    msgBox.setFixedSize(600,600);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");
    // Création du graphique
    QPieSeries* series = new QPieSeries();
    series->setHoleSize(0.35);
    series->append("Bas",bas);
    series->append("Accesoire",accesoire);
    series->append("chaussure",chaussure);
    QPieSlice* slice=series->append("Haut",haut);


    slice->setExploded();
    slice->setLabelVisible();
    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setTitle("Stocks par Categorie");
    chart->setTheme(QChart::ChartThemeQt);
    QColor bgColor("#f8f5f1");
    QBrush bgBrush(bgColor);
    QPen bgPen("#f8f5f1");
    bgPen.setWidth(35);
    chart->setBackgroundBrush(bgBrush);
    chart->setBackgroundPen(bgPen);
    QChartView* chartview= new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setParent(ui->horizontalFrame);
    if ((haut==0) && (bas==0)&&(accesoire==0) && (chaussure==0))
    {
        ui->inv->setCurrentIndex(0);
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText("Base de donnée vide");
        msgBox.exec();
    }
    ui->inv->setCurrentIndex(3);

}

void MainWindow::on_closestatinv_clicked()
{
    ui->inv->setCurrentIndex(0);
}

void MainWindow::on_bilaninv_clicked()
{
    on_homeinv_clicked();
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1; border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setWindowOpacity(0.8);
    msgBox.setFixedSize(600,600);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");
    QString systemDate = QDate::currentDate().toString("dd_MMMM_yyyy");
    qDebug() << systemDate;

    QString defaultPath = qApp->applicationDirPath()+"/../bilan_inventaire/";
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), defaultPath + "bilan_" + systemDate + ".xls",
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;
    ui->tableView_excel_inv->setModel(S1.afficher_inv_bilan());
    excel obj(fileName, "mydata", ui->tableView_excel_inv);

    // Columns to export
    obj.addField(0, "type", "char(30)");
    obj.addField(1, "Mois", "char(30)");
    obj.addField(2, "Nb", "char(30)");
    obj.addField(3, "Prix_Unitaire", "char(30)");
    obj.addField(4, "Prix_Total", "char(30)");



    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText("Excel Généré avec succés. ");
        msgBox.exec();
    }



}

void MainWindow::on_triinv_clicked()
{
    on_homeinv_clicked();
    ui->suppmodifinv->setEnabled(1);
    ui->statinv->setEnabled(1);
    ui->bilaninv->setEnabled(1);
    ui->pdfinv->setEnabled(1);
    ui->triinv_combo->setHidden(0);
    ui->triinv_combo->setCurrentIndex(0);
    ui->tableView_inv->setModel(S1.afficher_inv());
    ui->inv->setCurrentIndex(0);
}

void MainWindow::on_triinv_combo_activated(int index)
{
    switch (index) {
    case 0:{ui->tableView_inv->setModel(S1.tri_inv_categorie());break;}
    case 1:{ui->tableView_inv->setModel(S1.tri_inv_categorie_2());break;}
    case 3:{ui->tableView_inv->setModel(S1.tri_inv_type_2());break;}
    case 2:{ui->tableView_inv->setModel(S1.tri_inv_type());break;}
    case 4:{ui->tableView_inv->setModel(S1.tri_inv_prix());break;}
    case 5:{ui->tableView_inv->setModel(S1.tri_inv_prix_2());break;}

    }
}

void MainWindow::on_supprimerinv_clicked()
{
    int id_s = ui->suppmodifinv->text().toInt();

    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1;border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setFixedSize(600,600);
    msgBox.setWindowOpacity(0.8);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");
    ui->rechercherper->clear();
    bool test=S1.supprimer(id_s);
    if(test)
    {
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText("Suppression éffectué."); msgBox.exec(); on_homeinv_clicked();}
    else {        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Suppression non éffectué."); msgBox.exec();}
}

void MainWindow::on_affichplus_clicked()
{



    QString id_s = ui->suppmodifinv->text();
    QSqlQuery query;
    query.prepare("SELECT imagePath FROM stock WHERE id_s= :id_s");
    query.bindValue(":id_s",id_s);
    query.exec();
    QString imagePath;
    while (query.next()) {
        imagePath = query.value(0).toString();

    }
    if(imagePath.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setStyleSheet("QMessageBox {background:#f8f5f1;border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
        msgBox.setFixedSize(600,600);
        msgBox.setWindowOpacity(0.8);
        QFont bellMTFont("Bell MT");
        msgBox.setFont(bellMTFont);
        msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
        msgBox.setWindowTitle("Ahminy");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Aucune Image Associée."); msgBox.exec();
        //on_homeinv_clicked();
    }
    else {
        ui->inv->setCurrentIndex(4);
        ui->affiche_image_inv->setStyleSheet("#affiche_image_inv{border-image: url("+imagePath+");}");
        /*QPixmap image(imagePath);
        ui->affiche_image_inv->setPixmap(image);
        ui->affiche_image_inv->show();*/

    }
}

void MainWindow::on_closeaffiche_image_inv_clicked()
{
    on_homeinv_clicked();
}

void MainWindow::on_modifierinv_2_clicked()
{
    //on_homeinv_clicked();
        ui->inv->setCurrentIndex(2);
    ui->rechercherinv_2->setEnabled(0);
    ui->suppmodifinv->setHidden(0);
    ui->suppmodifinv->setEnabled(0);

    ui->modifierinv_2->setEnabled(0);
    ui->affichplus->setEnabled(0);
    ui->supprimerinv->setEnabled(0);
    ui->vendre_inv->setEnabled(0);

    ui->triinv->setEnabled(0);
    ui->bilaninv->setEnabled(0);
    ui->statinv->setEnabled(0);
    ui->pdfinv->setEnabled(0);
    QString id_s = ui->suppmodifinv->text();
    QSqlQuery query;
    query.prepare("SELECT id_s, categorie, type, sexe_s, prix, nb_tot, nb_res,imagePath FROM stock WHERE id_s= :id_s");
    query.bindValue(":id_s",id_s);
    if (!query.exec()) {
        QMessageBox::critical(nullptr, QObject::tr("Modifier is not open"),
                              QObject::tr("connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }

    while (query.next()) {
        QString id_s = query.value(0).toString();
        QString categorie = query.value(1).toString();
        QString type = query.value(2).toString();
        QString sexe_s = query.value(3).toString();
        double prix = query.value(4).toDouble();
        int nb_tot = query.value(5).toInt();
        QString nb_res = query.value(6).toString();
        QString imagePath = query.value(7).toString();

        //ui->lineEdit_id_s_modifier->setReadOnly(true);

        QStringList bas= {"Short","Pantalon","Jupe","Robe"};
        QStringList haut= {"Pull sans manche","Pull manche courte","Pull manche longue","Veste","Manteau"};
        QStringList chaussure= {"Snikers","Bottes","Chaussures a talon","Sandales","Claquettes"};
        QStringList accesoire= {"Chaussettes","Gants","Bonnets","Cache Col","Colants","Sous-vetements"};
        switch (ui->categorieinv_2->findText(categorie)) {
        case 0:{ui->typeinv_2->clear(); ui->typeinv_2->insertItems(0,haut);break;}
        case 1:{ui->typeinv_2->clear(); ui->typeinv_2->insertItems(0,bas);break;}
        case 2:{ui->typeinv_2->clear(); ui->typeinv_2->insertItems(0,chaussure);break;}
        case 3:{ui->typeinv_2->clear(); ui->typeinv_2->insertItems(0,accesoire);break;}

        }
        // Afficher les données dans les QLineEdit correspondants
        //ui->lineEdit_id_s_modifier->setText(id_s);
        int index_categorie = ui->categorieinv_2->findText(categorie);
        ui->categorieinv_2->setCurrentIndex(index_categorie);
        int index_type = ui->typeinv_2->findText(type);
        ui->typeinv_2->setCurrentIndex(index_type);
        int index_sexe = ui->sexeinv_2->findText(sexe_s);
        ui->sexeinv_2->setCurrentIndex(index_sexe);
        ui->prixinv_2->setValue(prix);
        ui->nb_totinv_2->setValue(nb_tot);
        ui->nb_resinv->setText(nb_res);
        ui->image_name_inv_2->setText(imagePath);


    }
}

void MainWindow::on_closeajouterinv_2_clicked()
{
    ui->rechercherinv_2->setEnabled(1);
    ui->suppmodifinv->setHidden(0);
    ui->suppmodifinv->setEnabled(0);

    ui->modifierinv_2->setEnabled(1);
    ui->affichplus->setEnabled(1);
    ui->supprimerinv->setEnabled(1);
    ui->vendre_inv->setEnabled(1);

    ui->triinv->setEnabled(1);
    ui->bilaninv->setEnabled(1);
    ui->statinv->setEnabled(1);
    ui->pdfinv->setEnabled(1);
    ui->tableView_inv->setModel(S1.afficher_inv());
    ui->inv->setCurrentIndex(0);
}

void MainWindow::on_categorieinv_2_activated(int index)
{
    QStringList bas= {"Short","Pantalon","Jupe","Robe"};
    QStringList haut= {"Pull sans manche","Pull manche courte","Pull manche longue","Veste","Manteau"};
    QStringList chaussure= {"Snikers","Bottes","Chaussures a talon","Sandales","Claquettes"};
    QStringList accesoire= {"Chaussettes","Gants","Bonnets","Cache Col","Colants","Sous-vetements"};
    switch (index) {
    case 0:{ui->typeinv_2->clear(); ui->typeinv_2->insertItems(0,haut);break;}
    case 1:{ui->typeinv_2->clear(); ui->typeinv_2->insertItems(0,bas);break;}
    case 2:{ui->typeinv_2->clear(); ui->typeinv_2->insertItems(0,chaussure);break;}
    case 3:{ui->typeinv_2->clear(); ui->typeinv_2->insertItems(0,accesoire);break;}

    }
}

void MainWindow::on_imageinv_3_clicked()
{
    QString imagePath = QFileDialog::getOpenFileName(this, tr("Choisir une image"), "", tr("Images (*.png *.jpg *.jpeg)"));
    ui->imageinv_3->setVisible(false);
    ui->annuler_imageinv_2->setVisible(true);
    ui->image_name_inv_2->setText(imagePath);
    ui->image_name_inv_2->setVisible(true);
}

void MainWindow::on_annuler_imageinv_2_clicked()
{
    ui->imageinv_3->setVisible(true);
    ui->annuler_imageinv_2->setVisible(false);
    ui->image_name_inv_2->setText("");
    ui->image_name_inv_2->setVisible(false);
}

void MainWindow::on_modifierinv_page2_clicked()
{   QByteArray data;
    int id_s = ui->suppmodifinv->text().toInt();
    QString categorie=ui->categorieinv_2->currentText();
    QString type=ui->typeinv_2->currentText();
    QString sexe_s=ui->sexeinv_2->currentText();
    double prix=ui->prixinv_2->value();
    int nb_tot=ui->nb_totinv_2->value();
    QString image_path=ui->image_name_inv_2->text();
    int nb_res=ui->nb_resinv->text().toInt();

    stock S(id_s,categorie,type,sexe_s,prix,nb_tot,nb_res,image_path);
    bool test=S.modifier(id_s);
    data.append(type);
    if (nb_res!=0){data.clear();
        data.append("0");}
    A.write_to_arduino(data);


    data=NULL;

    QDate currentDate = QDate::currentDate();
    Stock_stat s_stat(id_s,prix,nb_tot,nb_res,currentDate);
    s_stat.ajouter_stock_stat();
    //on_homeinv_clicked();
    ui->inv->setCurrentIndex(0);
    ui->tableView_inv->setModel(S1.afficher_inv());
    ui->rechercherinv_2->setEnabled(1);
    ui->suppmodifinv->setHidden(0);
    ui->suppmodifinv->setEnabled(0);

    ui->modifierinv_2->setEnabled(1);
    ui->affichplus->setEnabled(1);
    ui->supprimerinv->setEnabled(1);
    ui->vendre_inv->setEnabled(1);

    ui->triinv->setEnabled(1);
    ui->bilaninv->setEnabled(1);
    ui->statinv->setEnabled(1);
    ui->pdfinv->setEnabled(1);
    ui->imageinv_3->setVisible(false);
    ui->annuler_imageinv_2->setVisible(true);
    ui->image_name_inv_2->setText(image_path);
    ui->image_name_inv_2->setVisible(true);

    if(!test){
        QMessageBox msgBox;
        msgBox.setStyleSheet("QMessageBox {background:#f8f5f1;border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
        msgBox.setFixedSize(600,600);
        msgBox.setWindowOpacity(0.8);
        QFont bellMTFont("Bell MT");
        msgBox.setFont(bellMTFont);
        msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
        msgBox.setWindowTitle("Ahminy");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Modifier non  effectué."); msgBox.exec();
    }

}

void MainWindow::on_pdfinv_clicked()
{   on_homeinv_clicked();
    // Création du document PDF
    QPrinter printer (QPrinter::ScreenResolution);
    printer.setPaperSize(QPrinter::A4);
    printer.setOrientation(QPrinter::Landscape);
    printer.setOutputFormat (QPrinter::PdfFormat); printer.setOutputFileName ("consultation.pdf");
    printer.setOutputFileName("PDF_inv/stock.pdf");
    // Définition des styles d'écriture et de couleurs

    QTextDocument doc;
    stock s;
    QList<stock> S=s.getDatabaseValues();
    QString h("");
    QString title("<h1 style='text-align: center; font-size:24px; border-bottom:2px solid black; padding-bottom:10px;'>Stocks</h1>");

    h = "<html>"
        "<head>"
        "<style>"
        "table {"
        "border-collapse: collapse;"
        "width: 100%;"
        "}"
        "th, td {"
        "text-align: center;"
        "padding: 8px;"
        "}"
        "th {"
        "background-color: #4CAF50;"
        "color: white;"
        "}"
        "tr:nth-child(even){background-color: #f2f2f2}"
        "</style>"
        "</head>"
        "<body>"
            + title +
            "<table border='1' text-align: center; width='100%'>"
            "<tr>"
            "<th>ID</th>"
            "<th>Catégorie</th>"
            "<th>Type</th>"
            "<th>Sexe</th>"
            "<th>Prix</th>"
            "<th>Nombre total</th>"
            "<th>Nombre restant</th>"
            "</tr>";
    for (int it = 0; it < S.size(); it++)
    {
        h +="<tr>"
            "<td>" +
                QString::number(S[it].getid_s()) + "</td>"
                                                   "<td>" +
                S[it].getcategorie()  + "</td>"
                                        "<td>" +
                S[it].getsexe_s()  + "</td>"
                                     "<td>" +
                S[it].gettype()  + "</td>"
                                   "<td>"+
                QString::number(S[it].getprix()) + "</td>"
                                                   "<td>" +
                QString::number (S[it].getnb_tot()) + "</td>"
                                                      "<td>"+
                QString::number (S[it].getnb_res()) + "</td>"
                                                      "</tr>";
    }
    h +="</table>"
        "</body>"
        "</html>";


    doc.setHtml(h);
    // Enregistrement et fermeture du document
    doc.print(&printer);

    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1;border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setFixedSize(600,600);
    msgBox.setWindowOpacity(0.8);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText("PDF généré."); msgBox.exec();
}

void MainWindow::on_vendre_inv_clicked()
{
    ui->suppmodifinv->setHidden(0);
    ui->suppmodifinv->setEnabled(0);
    ui->modifierinv_2->setHidden(0);
    ui->supprimerinv->setHidden(0);
    ui->vendre_inv->setHidden(0);
    ui->triinv->setEnabled(0);
    ui->bilaninv->setEnabled(0);
    ui->statinv->setEnabled(0);
    ui->pdfinv->setEnabled(0);
    ui->rechercherinv_2->setEnabled(1);
    ui->triinv_combo->setHidden(1);
  vente d;
    d.setWindowTitle("Vente Stock");
    int id_s = ui->suppmodifinv->text().toInt();
    d.setidinv(id_s);
        int nb=S1.get_nbr_res_vendre(id_s);
    qDebug() << nb;
    if(nb==0)
    {
        QMessageBox msgBox;
        msgBox.setStyleSheet("QMessageBox {background:#f8f5f1;border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
        msgBox.setFixedSize(600,600);
        msgBox.setWindowOpacity(0.8);
        QFont bellMTFont("Bell MT");
        msgBox.setFont(bellMTFont);
        msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
        msgBox.setWindowTitle("Ahminy");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Stock epuisé."); msgBox.exec();
    }
    else
    {d.max(nb);
    d.exec();}
//on_homeinv_clicked();

}

/*void MainWindow::on_closevendre_inv_clicked()
{
    on_homeinv_clicked();
}*/

/*void MainWindow::on_vendreinv_clicked()
{
    stock S;
    int id_s = ui->suppmodifinv->text().toInt();
    int nb_res=ui->nb_resinv_2->value();

    int r = S.get_nbr_res_vendre(id_s);
    if (r < nb_res){
        QMessageBox::critical(nullptr, QObject::tr("Stock épuisé"),
                              QObject::tr("vous n'avez pas cette quantité en stock.\n"
                                          "vous ne pouvez pas effectué cette opération"), QMessageBox::Cancel);
    }
    else {
        S.update_nbr_rest_vendre(r-nb_res,id_s);
        QString type=ui->typeinv_2->currentText();

        data.append(type);
        if (nb_res!=0){data.clear();
            data.append("0");}
        A.write_to_arduino(data);

        QDate currentDate = QDate::currentDate();
        double prix=ui->prixinv_2->value();
        int nb_tot=ui->nb_totinv_2->value();
        Stock_stat s_stat(id_s,prix,nb_tot,nb_res,currentDate);
        s_stat.ajouter_stock_stat();
        on_homeinv_clicked();
    }


}*/












































void MainWindow::on_ajouterdon_clicked()
{
    on_homedon_clicked();
    ui->stat_d->setEnabled(0);
    ui->execldon->setEnabled(0);
    ui->pdf_d->setEnabled(0);
    ui->Meilleur_d->setEnabled(0);
    ui->recherchedon->setEnabled(0);
    ui->tri_d->setEnabled(0);
    ui->don->setCurrentIndex(1);
}

void MainWindow::on_closeajouterdon_clicked()
{
    on_homedon_clicked();
}

void MainWindow::on_confirmerAjouterdon_clicked()
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
    QString cin_d=ui->cindon->text();
    QString nom_d=ui->nomdon->text().toLower();
    nom_d[0]=nom_d[0].toUpper();
    QString prenom_d=ui->prenomdon->text().toLower();
    prenom_d[0]=prenom_d[0].toUpper();
    QString montant_d=ui->montantdon->text();
    float montdon=montant_d.toFloat();
    QString telephone_d=ui->telephonedon->text();
    don E (cin_d,nom_d,prenom_d,montant_d,telephone_d,1);

    ///Debut controle de saisie:

    bool verif=true;

    bool numcin=true;
    for (int i=0; i<cin_d.length(); i++)
    {
        if (!cin_d[i].isDigit())
        {
            numcin=false;
            break;
        }
    }

    bool numnom=true;
    for (int i=0; i<nom_d.length(); i++)
    {
        if (!nom_d[i].isLetter())
        {
            numnom=false;
            break;
        }
    }

    bool numprenom=true;
    for (int i=0; i<prenom_d.length(); i++)
    {
        if (!prenom_d[i].isLetter())
        {
            numprenom=false;
            break;
        }
    }
    bool numtel=true;
    for (int i=0; i<telephone_d.length(); i++)
    {
        if (!telephone_d[i].isDigit())
        {
            numtel=false;
            break;
        }
    }
    if (cin_d.isEmpty())
    {
        ui->don->setCurrentIndex(1);
        msgBox.setText("Veuillez remplir le cin du donnateur.");
        msgBox.exec();
        verif=false;
    }

    else if ((cin_d.length()!=8)||(!numcin))
    {
        ui->don->setCurrentIndex(1);
        msgBox.setText("Cin doit comporter 8 caractères et seulement des numeros.");
        msgBox.exec();
        verif=false;
    }

    else if(D.recherchedon(cin_d))
    {
        ui->don->setCurrentIndex(1);
        msgBox.setText("Cin doit etre unique.");
        msgBox.exec();
        verif=false;
    }
    else if (ui->nomdon->text().isEmpty())
    {
        ui->don->setCurrentIndex(1);
        msgBox.setText("Veuillez remplir le nom du donnateur.");
        msgBox.exec();
        verif=false;
    }

    else if (!numnom)
    {
        ui->don->setCurrentIndex(1);
        msgBox.setText("Le nom ne comporte pas des numeros et des symboles.");
        msgBox.exec();
        verif=false;
    }
    else if (ui->prenomdon->text().isEmpty())
    {
        ui->don->setCurrentIndex(1);
        msgBox.setText("Veuillez remplir le prenom du donnateur.");
        msgBox.exec();
        verif=false;
    }

    else if (!numprenom)
    {
        ui->don->setCurrentIndex(1);
        msgBox.setText("Le prenom ne comporte pas des numeros et des symboles.");
        msgBox.exec();
        verif=false;
    }

    else if (telephone_d.isEmpty())
    {
        ui->don->setCurrentIndex(1);
        msgBox.setText("Veuillez remplir le numero de telephone.");
        msgBox.exec();
        verif=false;
    }
    else if ((telephone_d.length()!=8)||(!numtel))
    {
        ui->don->setCurrentIndex(1);
        msgBox.setText("Telephone doit comporter 8 caractères et seulement des numeros.");
        msgBox.exec();
        verif=false;
    }

    else if(D.recherchedontel(telephone_d))
    {
        ui->don->setCurrentIndex(1);
        msgBox.setText("Telephone doit etre unique.");
        msgBox.exec();
        verif=false;
    }
    else if (montant_d.isEmpty())
    {
        ui->don->setCurrentIndex(1);
        msgBox.setText("Veuillez remplir le montant du donnateur.");
        msgBox.exec();
        verif=false;
    }
    else if (montdon<=0)
    {
        ui->don->setCurrentIndex(1);
        msgBox.setText("Le montant doit etre strictement positif.");
        msgBox.exec();
        verif=false;
    }
    don D1(cin_d,nom_d,prenom_d,montant_d,telephone_d,1);
    bool test=true;
    if (verif)
    {
        test=D1.ajouter_d();

        if (test)
        {
            on_homedon_clicked();
        }
        else
        {
            msgBox.setText("Ajout non effectué.");
            msgBox.exec();
        }
    }

}
void MainWindow::on_cindon_returnPressed()
{
    ui->nomdon->setFocus();
}

void MainWindow::on_nomdon_returnPressed()
{
    ui->prenomdon->setFocus();
}

void MainWindow::on_prenomdon_returnPressed()
{

    ui->telephonedon->setFocus();
}
void MainWindow::on_telephonedon_returnPressed()
{

    ui->montantdon->setFocus();
}

void MainWindow::on_recherchedon_clicked()
{
    on_homedon_clicked();
    ui->lineEdit_recherche->clear();
    ui->lineEdit_recherche->setHidden(0);
    ui->lineEdit_recherche->setEnabled(1);
}

void MainWindow::on_homedon_clicked()
{

    ui->lineEdit_recherche->setHidden(1);
    ui->modifier_d->setHidden(1);
    ui->supprimer_d->setHidden(1);
    ui->don_d->setHidden(1);
    ui->qr_code_2->setHidden(1);

    ui->stat_d->setEnabled(1);
    ui->execldon->setEnabled(1);
    ui->pdf_d->setEnabled(1);
    ui->Meilleur_d->setEnabled(1);
    ui->recherchedon->setEnabled(1);
    ui->tri_d->setEnabled(1);
    ui->recherchedon->setEnabled(1);

    ui->comboBox_triDon->setHidden(1);
    ui->comboBox_triDon->setCurrentIndex(0);
    ui->don->setCurrentIndex(0);
    ui->tableView_d->setModel(D.afficher_d());
    ui->cindon->clear();
    ui->nomdon->clear();
    ui->prenomdon->clear();
    ui->montantdon->clear();
    ui->telephonedon->clear();
    ui->identite->clear();
    ui->telephonedon_3->clear();
    ui->montantdon_3->clear();
}

void MainWindow::on_supprimer_d_clicked()
{
    QString cin_d = ui->lineEdit_recherche->text();

    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1;border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setFixedSize(600,600);
    msgBox.setWindowOpacity(0.8);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");
    bool test=D.supprimer_d(cin_d);
    if(test)
    {

        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText("Suppression éffectué."); msgBox.exec();  ui->lineEdit_recherche->clear(); on_homedon_clicked();}
    else {        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Suppression non éffectué."); msgBox.exec(); ui->lineEdit_recherche->clear();}
}

void MainWindow::on_tableView_d_clicked(const QModelIndex &index)
{
    ui->lineEdit_recherche->setText(ui->tableView_d->model()->data(ui->tableView_d->model()->index(index.row(),0)).toString());
    ui->lineEdit_recherche->setHidden(0);
    ui->modifier_d->setHidden(0);
    ui->supprimer_d->setHidden(0);
    ui->don_d->setHidden(0);
    ui->qr_code_2->setHidden(0);
    ui->comboBox_triDon->setHidden(1);
    ui->comboBox_triDon->setCurrentIndex(0);
    ui->recherchedon->setEnabled(1);
    ui->tri_d->setEnabled(1);
    ui->stat_d->setEnabled(1);
    ui->lineEdit_recherche->setEnabled(0);
    ui->execldon->setEnabled(1);
    ui->pdf_d->setEnabled(1);
    ui->Meilleur_d->setEnabled(1);
    ui->modifier_d->setEnabled(1);
    ui->supprimer_d->setEnabled(1);
    ui->don_d->setEnabled(1);
    ui->qr_code_2->setEnabled(1);
}

void MainWindow::on_lineEdit_recherche_returnPressed()
{
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1;border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setWindowOpacity(0.8);
    msgBox.setFixedSize(600,600);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");
    if(ui->lineEdit_recherche->text().isEmpty())
    {
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Aucune Donnée Saisie.");
        msgBox.exec();
    }
}

void MainWindow::on_modifier_d_clicked()
{
    // ui->lineEdit_recherche->setEnabled(0);
    ui->comboBox_triDon->setHidden(1);
    /////lfouk
    ui->modifier_d->setEnabled(0);
    ui->supprimer_d->setEnabled(0);
    ui->don_d->setEnabled(0);
    ui->qr_code_2->setEnabled(0);
    //// alajnab
    ui->stat_d->setEnabled(0);
    ui->execldon->setEnabled(0);
    ui->pdf_d->setEnabled(0);
    ui->Meilleur_d->setEnabled(0);
    ui->recherchedon->setEnabled(0);
    ui->tri_d->setEnabled(0);
    ui->don->setCurrentIndex(2);
    don D1;
    QString cin_d=ui->lineEdit_recherche->text();
    D.Get_don(D1,cin_d);


    ui->identite->setText(D1.getnom_d()+" "+D1.getprenom_d());
    ui->montantdon_3->setText(D1.getmontant_d());
    ui->telephonedon_3->setText(D1.gettelephone_d());
}

void MainWindow::on_closemodifdon_clicked()
{
    ui->don->setCurrentIndex(0);
    ui->tableView_d->setModel(D.afficher_d());
    //ui->lineEdit_recherche->setEnabled(1);
    ui->comboBox_triDon->setHidden(1);
    /////lfouk
    ui->modifier_d->setEnabled(1);
    ui->supprimer_d->setEnabled(1);
    ui->don_d->setEnabled(1);
    ui->qr_code_2->setEnabled(1);
    //// alajnab
    ui->stat_d->setEnabled(1);
    ui->execldon->setEnabled(1);
    ui->pdf_d->setEnabled(1);
    ui->Meilleur_d->setEnabled(1);
    ui->recherchedon->setEnabled(1);
    ui->tri_d->setEnabled(1);
}

void MainWindow::on_confirmermodifdon_clicked()
{
    QString cindon=ui->lineEdit_recherche->text();
    QString montdon=ui->montantdon_3->text();
    QString telephone_d=ui->telephonedon_3->text();
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1; border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setWindowOpacity(0.8);
    msgBox.setFixedSize(600,600);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");
    msgBox.setIcon(QMessageBox::Information);
    bool numtel=true;
    for (int i=0; i<telephone_d.length(); i++)
    {
        if (!telephone_d[i].isDigit())
        {
            numtel=false;
            break;
        }
    }
    bool verif=true;
    if (telephone_d.isEmpty())
    {
        ui->don->setCurrentIndex(2);
        msgBox.setText("Veuillez remplir le numero de telephone.");
        msgBox.exec();
        verif=false;
    }
    else if ((telephone_d.length()!=8)||(!numtel))
    {
        ui->don->setCurrentIndex(2);
        msgBox.setText("Telephone doit comporter 8 caractères et seulement des numeros.");
        msgBox.exec();
        verif=false;
    }

    else if(D.recherchedontel2(telephone_d,cindon))
    {
        ui->don->setCurrentIndex(2);
        msgBox.setText("Telephone doit etre unique.");
        msgBox.exec();
        verif=false;
    }
    else if (montdon.isEmpty())
    {
        ui->don->setCurrentIndex(2);
        msgBox.setText("Veuillez remplir le montant du donnateur.");
        msgBox.exec();
        verif=false;
    }
    else if (montdon<=0)
    {
        ui->don->setCurrentIndex(1);
        msgBox.setText("Le montant doit etre strictement positif.");
        msgBox.exec();
        verif=false;
    }

    if (verif)
    {   bool test=true;
        test=D.modifier_d(cindon,montdon,telephone_d);

        if (test)
        { on_closemodifdon_clicked();
        }
        else {        msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText("Modification non éffectué."); msgBox.exec();}
    }
}