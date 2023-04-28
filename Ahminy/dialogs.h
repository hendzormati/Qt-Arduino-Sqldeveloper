#ifndef DIALOGS_H
#define DIALOGS_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>
#include "sdf.h"

namespace Ui {
class Dialogs;
}

class Dialogs : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogs(QWidget *parent = nullptr);
    ~Dialogs();

    void afficherunsdf(Sdf &S);

private:
    Ui::Dialogs *ui;
};

#endif // DIALOGS_H
