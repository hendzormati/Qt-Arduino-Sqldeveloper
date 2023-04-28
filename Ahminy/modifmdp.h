#ifndef MODIFMDP_H
#define MODIFMDP_H
#include <QString>
#include <QDialog>
#include "../SMTPClient/email.h"
#include "../SMTPClient/smtpclient.h"
#include "../SMTPClient/emailaddress.h"
#include "mainwindow.h"
#include "personnel.h"
namespace Ui {
class modifmdp;
}

class modifmdp : public QDialog
{
    Q_OBJECT

public:
    explicit modifmdp(QWidget *parent = nullptr);
    void affichermail_P(Personnel &p);
    ~modifmdp();
private slots:
    //void sendEmail();
    void sendcodemail();
    //void clearFields();

    void onStatus(Status::e status, QString errorMessage);

    void on_verifemailp_returnPressed();

    void on_confirmercodep_returnPressed();

    void on_nouveaumdp_returnPressed();

    void setPasswordStrength(QString password, QLabel *strengthLabel, QProgressBar *strengthBar);

    void on_nouveaumdp_textEdited(const QString &arg1);

    void on_quittermdp_clicked();

    void on_renvoyer_clicked();

    void on_showpswd_pressed();

    void on_showpswd_released();

    void on_quittermodifmdp_clicked();
private:
    //Email createEmail();
    Email createcodemail();
private:
    Ui::modifmdp *ui;
    SMTPClient *client_;
    Personnel P;
    QString code;
    QString email;
    int nbtentative;
    int nbmail;
};

#endif // MODIFMDP_H
