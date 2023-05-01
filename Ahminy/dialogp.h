#ifndef DIALOGP_H
#define DIALOGP_H
#include "personnel.h"
#include <QDialog>

namespace Ui {
class DialogP;
}

class DialogP : public QDialog
{
    Q_OBJECT

public:
    explicit DialogP(QWidget *parent = nullptr);
    ~DialogP();
    void afficher_P(Personnel &p);
private slots:
    void on_closeafficherperso_clicked();

private:
    Ui::DialogP *ui;
};

#endif // DIALOGP_H
