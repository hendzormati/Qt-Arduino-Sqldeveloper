#ifndef DONNATION_H
#define DONNATION_H

#include <QDialog>
#include <string>
#include "don.h"

namespace Ui {
class donnation;
}

class donnation : public QDialog
{
    Q_OBJECT

public:
    explicit donnation(QWidget *parent = nullptr);
    ~donnation();

    void setmontant(QString cin_d);

private slots:
    void on_annuler_clicked();

    void on_ajouter_clicked();

private:
    Ui::donnation *ui;
    QString CIN;
    don D;
};

#endif // DONNATION_H
