#include "modifmdp.h"
#include "ui_modifmdp.h"
#include <QString>
modifmdp::modifmdp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifmdp)
{

    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width() - this->width()+100) / 2;
    int y = (screenGeometry.height() - this->height()-150) / 2;
    this->move(x, y);
    ui->setupUi(this);
    client_ = NULL;

    ui->verifemailp->setHidden(0);
    ui->confirmercodep->setHidden(1);
    ui->quittermdp->setEnabled(1);
    ui->nouveaumdp->setHidden(1);
    ui->strengthmdp->setHidden(1);
    ui->strengthmdpL->setHidden(1);
    ui->showpswd->setVisible(0);
    nbtentative=3;
    nbmail=3;
    ui->nbtentativeL->setHidden(1);
    ui->nbtentative->setHidden(1);
    ui->renvoyer->setEnabled(0);

}

modifmdp::~modifmdp()
{
    delete ui;
}
void modifmdp::on_quittermodifmdp_clicked()
{
    qDebug() << "wtf bro nezel al close!????";
}


void modifmdp::on_showpswd_pressed()
{
    ui->nouveaumdp->setEchoMode(QLineEdit::Normal);
}

void modifmdp::on_showpswd_released()
{
    ui->nouveaumdp->setEchoMode(QLineEdit::Password);
}

void modifmdp::on_quittermdp_clicked()
{
    close();
}


void modifmdp::on_renvoyer_clicked()
{
    ui->titrep->setText("Renvoie En Cours...");
    sendcodemail();
    ui->quittermdp->setEnabled(0);
    ui->renvoyer->setEnabled(0);
}
void modifmdp::onStatus(Status::e status, QString errorMessage)
{
    switch (status)
    {
    case Status::Success:
    {   QMessageBox msgBox;
        msgBox.setStyleSheet("QMessageBox {background:#f8f5f1; border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
        msgBox.setWindowOpacity(0.8);
        msgBox.setFixedSize(600,600);
        QFont bellMTFont("Bell MT");
        msgBox.setFont(bellMTFont);
        msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
        msgBox.setWindowTitle("Ahminy");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText("Code envoyé !");
        nbmail--;
        nbtentative=3;
        ui->titrep->setText("saisir le code de vérification ");
        ui->quittermdp->setEnabled(1);
        ui->confirmercodep->setEnabled(1);
        ui->confirmercodep->clear();
        ui->verifemailp->setHidden(1);
        ui->confirmercodep->setHidden(0);
        ui->nbtentativeL->setHidden(0);
        ui->nbtentative->setHidden(0);
        ui->nbtentative->setText(QString::number(nbtentative));
        ui->strengthmdpL->setHidden(0);
        ui->strengthmdpL->setText(code);
        break;}
    case Status::Failed:
    {
        QMessageBox::warning(NULL, tr("Ahminy"), tr("Vérifier votre email saisie !"));
        qCritical() << errorMessage;
    }
        break;
    default:
        break;
    }

    // Delete the client pointer
    client_->deleteLater();
}
void modifmdp::affichermail_P(Personnel &p)
{
    P=p;
    ui->verifemailp->setText(P.get_mail_p());
}

void modifmdp::on_verifemailp_returnPressed()
{
    email=ui->verifemailp->text();
    sendcodemail();
    ui->titrep->setText("Envoie En Cours...");
    ui->quittermdp->setEnabled(0);
}
void modifmdp::sendcodemail()
{
    // Create the email object
    Email email = createcodemail();

    // Create the SMTPClient
    client_ = new SMTPClient("smtp.gmail.com",
                             465);

    // Connection used to receive the results
    connect(client_, SIGNAL(status(Status::e, QString)),
            this, SLOT(onStatus(Status::e, QString)), Qt::UniqueConnection);
    // Try to send the email
    client_->sendEmail(email);
}
Email modifmdp::createcodemail()
{
    code="";
    // Create the credentials EmailAddress
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    srand(time(NULL)); // Initialisation de la graine aléatoire

    for (int i = 0; i <8; ++i)
    {
        code += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    EmailAddress credentials("hend.zormati@esprit.tn",
                             "211JFT8977");

    // Create the from EmailAddress
    EmailAddress from("hend.zormati@esprit.tn");

    // Create the to EmailAddress
    EmailAddress to(email);
    QString nomprenom=P.get_prenom_p()+" "+P.get_nom_p();
    QString mailcode = "Bonjour " + nomprenom + ",\n\n"
                 + "Nous avons bien reçu votre demande de modification de mot de passe pour votre compte utilisateur dans notre application de gestion. Pour garantir la sécurité de votre compte, nous avons envoyé un code d'authentification à votre adresse e-mail enregistrée.\n\n"
                 + "Veuillez trouver ci-dessous le code d'authentification nécessaire pour procéder à cette opération :\n\n"
                 + "Code d'authentification : " + code + "\n\n"
                 + "Si vous n'avez pas demandé la modification de votre mot de passe, veuillez ignorer ce message et ne pas divulguer le code à quiconque.\n\n"
                 + "Si vous avez des questions ou des problèmes pour modifier votre mot de passe, n'hésitez pas à contacter notre service d'assistance à la clientèle.\n\n"
                 + "Cordialement,\n\n"
                 + "Ahminy";


    // Create the email
    Email email(credentials,
                from,
                to,
                "Ahminy: Code d'authentification pour réinitialisation de mot de passe",
                mailcode);

    return email;
}

void modifmdp::on_confirmercodep_returnPressed()
{
    QString nbMail=QString::number(nbmail);
    if(ui->confirmercodep->text()==code)
    {
        ui->titrep->setText("Saisir Votre Nouveau Mot De Passe");
        ui->confirmercodep->setHidden(1);
        ui->renvoyer->setHidden(1);
        ui->nbtentative->setHidden(1);
        ui->nbtentativeL->setHidden(1);
        ui->nouveaumdp->setHidden(0);
        ui->showpswd->setVisible(1);
        ui->strengthmdpL->setHidden(0);
        ui->strengthmdpL->clear();

    }
    else if(nbtentative>0)
    {
        nbtentative--;
        ui->nbtentative->setText(QString::number(nbtentative));
        ui->titrep->setText(" Code de vérification Incorrect ");
    }
    if(nbtentative==0 && nbmail==0)
    {
        ui->titrep->setText("Modification Impossible !");
        ui->nbtentative->setHidden(1);
        ui->nbtentativeL->setHidden(1);
        ui->confirmercodep->setEnabled(0);
    }
    else if(nbtentative==0 && nbmail!=0)
    {
        ui->titrep->setText("Vous Avez Droit à "+nbMail+ " Renvoi(s) De Code ");
        ui->strengthmdpL->setHidden(0);
        ui->strengthmdpL->setText(" clicker pour renvoyer");
        ui->renvoyer->setEnabled(1);
        ui->nbtentative->setHidden(1);
        ui->nbtentativeL->setHidden(1);
        ui->confirmercodep->setEnabled(0);

    }
}

void modifmdp::on_nouveaumdp_returnPressed()
{
    QByteArray br = ui->nouveaumdp->text().toUtf8();
    QByteArray result= QCryptographicHash::hash(br,QCryptographicHash::Md5);
    QString res= QString(result.toHex());
    if(res==P.get_ancmdp())
    {
        ui->titrep->setText("Ancien Mot De Passe Saisie");
    }
    else if(res==P.get_mdp_p())
    {
        ui->titrep->setText(" Mot De Passe actuel Saisie");
    }
    else if(ui->strengthmdp->value()<50)
    {
        ui->titrep->setText(" Mot De Passe doit être moyen/fort ");
    }
    else
    {P.set_ancmdp(P.get_mdp_p());
        P.set_mdp_p(res);
        P.set_mail_p(email);
        bool test=P.modifiermdp_p(P.get_id_p());
        QMessageBox msgBox;
        msgBox.setStyleSheet("QMessageBox {background:#f8f5f1;border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
        msgBox.setFixedSize(600,600);
        msgBox.setWindowOpacity(0.8);
        QFont bellMTFont("Bell MT");
        msgBox.setFont(bellMTFont);
        msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
        msgBox.setWindowTitle("Ahminy");
        if(test)
        {
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setText("Modification Mot De Passe éffectué."); msgBox.exec();close();}
        else {        msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText("Modification Mot De Passe non éffectué."); msgBox.exec();}
    }

}
void modifmdp::setPasswordStrength(QString password, QLabel *strengthLabel, QProgressBar *strengthBar)
{
    int strength = 0;
    // Evaluate password complexity
    ui->strengthmdp->setHidden(0);
    if (password.length() < 6) {
        strength = 0;
        strengthLabel->setText("Faible");
        strengthLabel->setStyleSheet("color: #e62020;");
    } else if (password.length() < 8) {
        bool hasLower = false, hasUpper = false, hasDigit = false;
        for (QChar c : password) {
            if (c.isLower()) {
                hasLower = true;
            } else if (c.isUpper()) {
                hasUpper = true;
            } else if (c.isDigit()) {
                hasDigit = true;
            }
        }
        if (hasLower && hasUpper && hasDigit) {
            strength = 50;
            strengthLabel->setText("Moyen");
            strengthLabel->setStyleSheet("color: #ffae42;");
        } else {
            strength = 25;
            strengthLabel->setText("Faible");
            strengthLabel->setStyleSheet("color: #e62020;");
        }
    } else {
        bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
        for (QChar c : password) {
            if (c.isLower()) {
                hasLower = true;
            } else if (c.isUpper()) {
                hasUpper = true;
            } else if (c.isDigit()) {
                hasDigit = true;
            } else {
                hasSpecial = true;
            }
        }
        if (hasLower && hasUpper && hasDigit && hasSpecial) {
            strength = 100;
            strengthLabel->setText("Fort");
            strengthLabel->setStyleSheet("color: #87a96b;");
        } else {
            strength = 75;
            strengthLabel->setText("Moyen");
            strengthLabel->setStyleSheet("color: #ffae42;");
        }
    }
    strengthBar->setValue(strength);
}

void modifmdp::on_nouveaumdp_textEdited(const QString &arg1)
{
    setPasswordStrength(arg1,ui->strengthmdpL,ui->strengthmdp);
}


