#include "alerteincondie.h"
#include "ui_alerteincondie.h"
#include "incondiesdf.h"
#include "sdf.h"



AlerteIncondie::AlerteIncondie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlerteIncondie)
{
    ui->setupUi(this);

    startTime = QTime::currentTime();

    QTimer *timer=new QTimer(this);
    showtime();
    connect(timer,SIGNAL(timeout()),this,SLOT(showtime()));
    timer->start(1000);
}

void AlerteIncondie::showtime()
{
    QTime endTime=QTime::currentTime();
    int elapsedTime = startTime.msecsTo(endTime);
    QString elapsedTimeString = QString::asprintf("%02d:%02d:%02d",
                                                       elapsedTime / 3600000,
                                                       (elapsedTime / 60000) % 60,
                                                       (elapsedTime / 1000) % 60);
    ui->timerlabel->setText(elapsedTimeString);
}


AlerteIncondie::~AlerteIncondie()
{
    delete ui;
}


void AlerteIncondie::on_fermerincondie_clicked()
{

    QSqlQuery query;
    Sdf s;

    query.prepare("SELECT num_l FROM Chambres WHERE incendie = 1");
    if (!query.exec())
    {
        qDebug() << "Erreur lors de l'exécution de la requête SQL :" ;
    }

    while (query.next())
    {
        s.Incondie_detecte(query.value("num_l").toInt(),0);
    }

    emit dialogClosed();
    close();
}

void AlerteIncondie::closeEvent(QCloseEvent *event)
{
    emit dialogClosed();
    QDialog::closeEvent(event);
}
