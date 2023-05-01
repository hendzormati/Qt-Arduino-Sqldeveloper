#ifndef RFIDPERS_H
#define RFIDPERS_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
class rfidpers
{
public:
    rfidpers();
    int connect_rfidpers(); // permet de connecter le PC à Arduino
    int close_rfidpers(); // permet de femer la connexion
    int write_to_rfidpers( QByteArray ); // envoyer des données vers arduino
    QByteArray read_from_rfidpers();  //recevoir des données de la carte Arduino
    QSerialPort* getserialpers();   // accesseur
    QString getarduino_port_namepers();
private:
    QSerialPort * serial; //Cet objet rassemble des informations (vitesse, bits de données, etc.)
    //et des fonctions (envoi, lecture de réception,…) sur ce qu’est une voie série pour Arduino.
    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_producy_id=67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data;
};

#endif // RFIDPERS_H
