#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QCryptographicHash>
#include <QDebug>

#include "personnel.h"
int main(int argc, char *argv[])
{   //int i;
    QApplication a(argc, argv);
    connection c;
    bool test=c.createconnect();
    MainWindow w;
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox {background:#f8f5f1;border:8px double #e0dfe5;  border-bottom-right-radius: 10px;   border-bottom-left-radius: 20px; text-align: center;font-size: 30px; padding: 10px; } QLabel{color:#425180; font-weight: bold;} QPushButton { font-weight: bold;font-size: 20px;padding: 5px; color:#425180;border: 4px inset #dcd0c9;border-radius: 15px;background: #f3f2f7;}QPushButton:hover{border: 4px outset #dcd0c9;background: #e0dfe5;}QPushButton:pressed{border: 4px inset #dcd0c9;background: #f6f1f7;}");
    msgBox.setFixedSize(600,600);
    msgBox.setWindowOpacity(0.8);
    QFont bellMTFont("Bell MT");
    msgBox.setFont(bellMTFont);
    msgBox.setWindowIcon(QIcon(":/images/ahminy.png"));
    msgBox.setWindowTitle("Base De Donnée Introuvable");
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setText("Connexion Impossible.");


    w.setWindowIcon(QIcon(":/images/ahminy.png"));


    if(test)
    {
        w.show();}
    else msgBox.exec();
    return a.exec();


}
