#include "mailingp.h"
#include "ui_mailingp.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
using namespace QSql;
mailingp::mailingp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mailingp)
{
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width() - this->width()+100) / 2;
    int y = (screenGeometry.height() - this->height()-150) / 2;
    this->move(x, y);
    ui->setupUi(this);

}

mailingp::~mailingp()
{
    delete ui;
}
void mailingp::affichermail_P(Personnel &p)
{
    P=p;
    ui->mailE->setText(P.get_mail_p());
}
void mailingp::affichermailDest()
{
    QStringList mailDs= P.listemail();
    foreach (const QString& email, mailDs) {
        ui->mailD->addItem(email);
    }
}
void mailingp::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}
void mailingp::sendemail()
{
    Smtp* smtp = new Smtp(ui->mailE->text(), ui->paswd->text(),"smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail(ui->mailE->text(), ui->mailD->currentText() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail(ui->mailE->text(), ui->mailD->currentText() , ui->subject->text(),ui->msg->toPlainText());
}

void mailingp::mailSent(QString status)
{
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1; border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setWindowOpacity(0.8);
    msgBox.setFixedSize(600,600);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Ahminy");
    if(status == "Message sent")
    {
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText("Mail envoyé !\n\n");msgBox.exec();}
}
void mailingp::clearFields()
{
    ui->mailE->clear();
    ui->paswd->clear();
    ui->mailD->setCurrentIndex(0);
    ui->subject->clear();
    ui->msg->clear();
    ui->file->clear();
    ui->mailE->setText(P.get_mail_p());
}
void mailingp::on_closeafficherperso_clicked()
{ qDebug() << "tenzel aleya bel enter";

}

void mailingp::on_envoyer_clicked()
{
    sendemail();
}

void mailingp::on_clear_clicked()
{
    clearFields();
}

void mailingp::on_mailE_returnPressed()
{
    ui->paswd->setFocus();
}

void mailingp::on_browseBtn_clicked()
{
    browse();
}

void mailingp::on_closemailing_clicked()
{
    close();
}

void mailingp::on_paswd_returnPressed()
{
    ui->mailD->setFocus();
}

void mailingp::on_showpswd_pressed()
{
    ui->paswd->setEchoMode(QLineEdit::Normal);
}

void mailingp::on_showpswd_released()
{
    ui->paswd->setEchoMode(QLineEdit::Password);
}
