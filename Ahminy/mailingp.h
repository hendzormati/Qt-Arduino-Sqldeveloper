#ifndef MAILINGP_H
#define MAILINGP_H
#include <QString>
#include <QDialog>
#include "../SMTPClient/email.h"
#include "../SMTPClient/smtpclient.h"
#include "../SMTPClient/emailaddress.h"
#include "mainwindow.h"
#include "personnel.h"

#include "../SMTPClient/smtp.h"
#include <QtWidgets/QMessageBox>
#include <QFileDialog>

namespace Ui {
class mailingp;
}

class mailingp : public QDialog
{
    Q_OBJECT

public:
    explicit mailingp(QWidget *parent = nullptr);
    void affichermail_P(Personnel &p);
    void affichermailDest();
    ~mailingp();

private slots:
    void on_closeafficherperso_clicked();
    void sendemail();
    void mailSent(QString);
    void clearFields();

    void browse();
    void on_envoyer_clicked();

    void on_clear_clicked();

    void on_mailE_returnPressed();

    void on_browseBtn_clicked();

    void on_closemailing_clicked();

    void on_paswd_returnPressed();

    void on_showpswd_pressed();

    void on_showpswd_released();

private:
    Ui::mailingp *ui;
    Personnel P;
    QStringList files;
};

#endif // MAILINGP_H
