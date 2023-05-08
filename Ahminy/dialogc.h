#ifndef DIALOGC_H
#define DIALOGC_H

#include <QDialog>
#include <qmessagebox.h>
#include "consultation.h"
#include "consultation.h"
#include "sdf.h"

namespace Ui {
class dialogc;
}

class dialogc : public QDialog
{
    Q_OBJECT

public:
    explicit dialogc(QWidget *parent = nullptr);
    ~dialogc();

    void setidcons(int id){ID=id;}
    void setetat(int et){etat=et;}
    void setcin_b(QString c){CIN=c;}
    void setIDP(QString p){IDP=p;}
    void setant(QString a){ant=a;}

    void affichercons(consultation &c);

private slots:
    void on_confirmerAjouterconst_clicked();

    void on_closeajoutercons_clicked();

    void on_tension_editingFinished();

    void on_temperature_editingFinished();

private:
    Ui::dialogc *ui;
    int etat;
    int ID;
    QString CIN;
    QString IDP;
    int malade=0;
    QString ant;

};
#endif // DIALOGC_H
