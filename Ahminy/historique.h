#ifndef HISTORIQUE_H
#define HISTORIQUE_H

#include <QDialog>

namespace Ui {
class Historique;
}

class Historique : public QDialog
{
    Q_OBJECT

public:
    explicit Historique(QWidget *parent = nullptr);
    ~Historique();

    void afficherhistorique(QString q);

private:
    Ui::Historique *ui;
};

#endif // HISTORIQUE_H
