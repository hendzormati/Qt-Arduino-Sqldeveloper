#ifndef VENTE_H
#define VENTE_H

#include <QDialog>
#include <QMessageBox>
#include "stock.h"
namespace Ui {
class vente;
}

class vente : public QDialog
{
    Q_OBJECT

public:
    explicit vente(QWidget *parent = nullptr);
    ~vente();


    void setidinv(int id){Id=id;}
    void max(int nb);

private slots:
    void on_closeinv_clicked();

    void on_vendinv_clicked();

private:
    Ui::vente *ui;
    int Id;
    stock s;
};

#endif // VENTE_H
