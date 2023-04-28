#ifndef INCONDIESDF_H
#define INCONDIESDF_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>


class Incondiesdf
{
public:
    Incondiesdf();
    int connect_incondie();
    int close_incondie();
    int write_to_incondie( QByteArray ); // envoyer des données vers arduino
    QByteArray read_from_incondie();  //recevoir des données de la carte Arduino
    QSerialPort* getserialsdf();   // accesseur
    QString getincondie_port_name();
private:
    QSerialPort * serial; //Cet objet rassemble des informations (vitesse, bits de données, etc.)
    //et des fonctions (envoi, lecture de réception,…) sur ce qu’est une voie série pour Arduino.
    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_producy_id=67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data;
};

#endif // INCONDIESDF_H
