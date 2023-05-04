#ifndef DONNATION_H
#define DONNATION_H

#include <QDialog>
#include <string>
#include <QDate>
#include "don.h"
#include "personnel.h"
namespace Ui {
class donnation;
}

class donnation : public QDialog
{
    Q_OBJECT

public:
    explicit donnation(QWidget *parent = nullptr);
    ~donnation();

    void setmontant(QString cin_d,Personnel &p);

private slots:
    void on_annuler_clicked();

    void on_ajouter_clicked();

private:
    Ui::donnation *ui;
    QString CIN;
    don D;
    Personnel P;
};

#endif // DONNATION_H
