#ifndef ALERTEINCONDIE_H
#define ALERTEINCONDIE_H

#include <QDialog>
#include <QTimer>
#include <QDateTime>
#include <QTime>



namespace Ui {
class AlerteIncondie;
}

class AlerteIncondie : public QDialog
{
    Q_OBJECT

public:
    explicit AlerteIncondie(QWidget *parent = nullptr);
    ~AlerteIncondie();
    void closeEvent(QCloseEvent *event);
    QTime startTime;

public slots:
    void showtime();

signals:
    void dialogClosed();


private slots:
    void on_fermerincondie_clicked();

private:
    Ui::AlerteIncondie *ui;
};

#endif // ALERTEINCONDIE_H
