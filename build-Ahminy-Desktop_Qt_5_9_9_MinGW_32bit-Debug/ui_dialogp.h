/********************************************************************************
** Form generated from reading UI file 'dialogp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGP_H
#define UI_DIALOGP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogP
{
public:
    QLabel *cinpersoL;
    QLabel *dobpersoL;
    QDateEdit *dobperso;
    QLabel *mailpersoL;
    QLineEdit *idperso;
    QRadioButton *hommeperso;
    QLabel *titreafficherp;
    QLabel *sexepersoL;
    QLineEdit *cinperso;
    QLabel *idpersoL;
    QRadioButton *femmeperso;
    QLabel *salairepersoL;
    QLabel *metierpersoL;
    QLineEdit *salaireperso;
    QLabel *telpersoL;
    QLineEdit *adresseperso;
    QLineEdit *numtelperso;
    QLabel *adressepersoL;
    QComboBox *metierperso;
    QTextEdit *mailperso;
    QPushButton *closeafficherperso;

    void setupUi(QDialog *DialogP)
    {
        if (DialogP->objectName().isEmpty())
            DialogP->setObjectName(QStringLiteral("DialogP"));
        DialogP->resize(507, 626);
        DialogP->setStyleSheet(QLatin1String("#DialogP{ background: #fbf9f9;;border:8px double #e6e4ea;}\n"
"#titreafficherp{color:#968c9b;}\n"
"#telpersoL{color:#aca0b2;} \n"
"#adressepersoL{color:#aca0b2;} \n"
"#metierpersoL{color:#aca0b2;} \n"
"#salairepersoL{color:#aca0b2;} \n"
"#cinpersoL{color:#aca0b2;} \n"
"#idpersoL{color:#aca0b2;} \n"
"#mailpersoL{color:#aca0b2;} \n"
"#sexepersoL{color:#aca0b2;} \n"
"#dobpersoL{color:#aca0b2;} \n"
"#cinperso{ \n"
"color: #968c9b;\n"
"font-weight: bold;\n"
"font-size: 15px;\n"
"border: 2px outset #dcd0c9;\n"
"border-radius: 7px;\n"
"background-color: #fefefb;\n"
"  selection-background-color: #968c9b;\n"
"selection-color: #33457d;\n"
"\n"
"}\n"
"#cinperso:hover{\n"
"border: 2px inset #dcd0c9;\n"
"background:#f3f2f7;\n"
"}\n"
"#mailperso{ \n"
"color: #968c9b;\n"
"font-weight: bold;\n"
"font-size: 15px;\n"
"border: 2px outset #dcd0c9;\n"
"border-radius: 7px;\n"
"background-color: #fefefb;\n"
"  selection-background-color: #968c9b;\n"
"selection-color: #33457d;\n"
"\n"
"}\n"
"#mailperso:hover{\n"
"border: 2px inset #"
                        "dcd0c9;\n"
"background:#f3f2f7;\n"
"}\n"
"#idperso{ selection-color: #33457d;\n"
"color: #968c9b;\n"
"font-weight: bold;\n"
"font-size: 15px;\n"
"border: 2px outset #dcd0c9;\n"
"border-radius: 7px;\n"
"background-color: #fefefb;\n"
"  selection-background-color: #968c9b;\n"
"}\n"
"#idperso:hover{\n"
"border: 2px inset #dcd0c9;\n"
"background:#f3f2f7;\n"
"}\n"
"#mdpperso{ selection-color: #33457d;\n"
"color: #968c9b;\n"
"font-weight: bold;\n"
"font-size: 15px;\n"
"border: 2px outset #dcd0c9;\n"
"border-radius: 7px;\n"
"background-color: #fefefb;\n"
"  selection-background-color: #968c9b;\n"
"}\n"
"#mdpperso:hover{\n"
"border: 2px inset #dcd0c9;\n"
"background:#f3f2f7;\n"
"}\n"
"#femmeperso{ color:#968c9b;\n"
"font-weight: bold;\n"
"font-size: 15px;}\n"
"#hommeperso{color:#968c9b;\n"
"font-weight: bold;\n"
"font-size: 15px;}\n"
"#femmeperso::indicator::checked{border-image: url(:/images/femme.png);}\n"
"\n"
"#hommeperso::indicator::checked{border-image: url(:/images/homme.png);}\n"
"#dobperso{color:#968c9b;\n"
""
                        " selection-color:#56695b;\n"
"border: 2px outset #dcd0c9;\n"
"border-radius: 7px;\n"
"background: #fefefb;\n"
"selection-background-color: #968c9b;}\n"
"#numtelperso{ \n"
"color: #968c9b;\n"
"font-weight: bold;\n"
"font-size: 15px;\n"
"border: 2px outset #dcd0c9;\n"
"border-radius: 7px;\n"
"background-color: #fefefb;\n"
"selection-background-color: #968c9b;\n"
"selection-color: #33457d;\n"
"\n"
"}\n"
"#numtelperso:hover{\n"
"border: 2px inset #dcd0c9;\n"
"background:#f3f2f7;\n"
"}\n"
"#adresseperso{ selection-color: #33457d;\n"
"color:#968c9b;\n"
"font-weight: bold;\n"
"font-size: 15px;\n"
"border: 2px outset #dcd0c9;\n"
"border-radius: 7px;\n"
"background-color: #fefefb;\n"
"  selection-background-color: #968c9b;\n"
"}\n"
"#adresseperso:hover{\n"
"border: 2px inset #dcd0c9;\n"
"background:#f3f2f7;\n"
"}\n"
"#metierperso{ \n"
"border: 2px solid #e0dfe5;\n"
"border-radius: 7px;\n"
"color:#968c9b;\n"
"font-weight: bold;\n"
"font-size: 15px;\n"
"}\n"
"#metierperso QAbstractItemView{ \n"
"color: #968c9b;\n"
"font-"
                        "weight: bold;\n"
"font-size: 15px;\n"
"selection-background-color: #968c9b;\n"
"selection-color:#425180;\n"
"}\n"
"#salaireperso{ selection-color: #33457d;\n"
"color:#968c9b;\n"
"font-weight: bold;\n"
"font-size: 15px;\n"
"border: 2px outset #dcd0c9;\n"
"border-radius: 7px;\n"
"background-color: #fefefb;\n"
"  selection-background-color:#968c9b;\n"
"}\n"
"#salaireperso:hover{\n"
"border: 2px inset #dcd0c9;\n"
"background:#f3f2f7;\n"
"}\n"
"\n"
""));
        cinpersoL = new QLabel(DialogP);
        cinpersoL->setObjectName(QStringLiteral("cinpersoL"));
        cinpersoL->setGeometry(QRect(16, 230, 81, 31));
        QFont font;
        font.setFamily(QStringLiteral("Bell MT"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        cinpersoL->setFont(font);
        dobpersoL = new QLabel(DialogP);
        dobpersoL->setObjectName(QStringLiteral("dobpersoL"));
        dobpersoL->setGeometry(QRect(16, 330, 221, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Bell MT"));
        font1.setPointSize(17);
        font1.setBold(true);
        font1.setWeight(75);
        dobpersoL->setFont(font1);
        dobperso = new QDateEdit(DialogP);
        dobperso->setObjectName(QStringLiteral("dobperso"));
        dobperso->setGeometry(QRect(271, 330, 141, 31));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        font2.setKerning(true);
        dobperso->setFont(font2);
        mailpersoL = new QLabel(DialogP);
        mailpersoL->setObjectName(QStringLiteral("mailpersoL"));
        mailpersoL->setGeometry(QRect(16, 160, 191, 31));
        mailpersoL->setFont(font);
        idperso = new QLineEdit(DialogP);
        idperso->setObjectName(QStringLiteral("idperso"));
        idperso->setGeometry(QRect(240, 80, 201, 41));
        idperso->setReadOnly(true);
        hommeperso = new QRadioButton(DialogP);
        hommeperso->setObjectName(QStringLiteral("hommeperso"));
        hommeperso->setEnabled(false);
        hommeperso->setGeometry(QRect(364, 290, 97, 20));
        hommeperso->setCheckable(true);
        titreafficherp = new QLabel(DialogP);
        titreafficherp->setObjectName(QStringLiteral("titreafficherp"));
        titreafficherp->setGeometry(QRect(150, 20, 261, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Bell MT"));
        font3.setPointSize(17);
        font3.setBold(true);
        font3.setUnderline(false);
        font3.setWeight(75);
        titreafficherp->setFont(font3);
        sexepersoL = new QLabel(DialogP);
        sexepersoL->setObjectName(QStringLiteral("sexepersoL"));
        sexepersoL->setGeometry(QRect(16, 290, 81, 31));
        sexepersoL->setFont(font);
        cinperso = new QLineEdit(DialogP);
        cinperso->setObjectName(QStringLiteral("cinperso"));
        cinperso->setEnabled(true);
        cinperso->setGeometry(QRect(240, 230, 201, 41));
        cinperso->setReadOnly(true);
        idpersoL = new QLabel(DialogP);
        idpersoL->setObjectName(QStringLiteral("idpersoL"));
        idpersoL->setGeometry(QRect(16, 83, 151, 31));
        idpersoL->setFont(font);
        femmeperso = new QRadioButton(DialogP);
        femmeperso->setObjectName(QStringLiteral("femmeperso"));
        femmeperso->setEnabled(false);
        femmeperso->setGeometry(QRect(240, 290, 81, 21));
        femmeperso->setIconSize(QSize(20, 20));
        femmeperso->setCheckable(true);
        salairepersoL = new QLabel(DialogP);
        salairepersoL->setObjectName(QStringLiteral("salairepersoL"));
        salairepersoL->setGeometry(QRect(16, 560, 131, 31));
        salairepersoL->setFont(font);
        metierpersoL = new QLabel(DialogP);
        metierpersoL->setObjectName(QStringLiteral("metierpersoL"));
        metierpersoL->setGeometry(QRect(16, 503, 131, 31));
        metierpersoL->setFont(font);
        salaireperso = new QLineEdit(DialogP);
        salaireperso->setObjectName(QStringLiteral("salaireperso"));
        salaireperso->setEnabled(false);
        salaireperso->setGeometry(QRect(240, 555, 201, 41));
        salaireperso->setReadOnly(true);
        telpersoL = new QLabel(DialogP);
        telpersoL->setObjectName(QStringLiteral("telpersoL"));
        telpersoL->setGeometry(QRect(16, 382, 151, 31));
        telpersoL->setFont(font);
        adresseperso = new QLineEdit(DialogP);
        adresseperso->setObjectName(QStringLiteral("adresseperso"));
        adresseperso->setGeometry(QRect(240, 440, 201, 41));
        adresseperso->setReadOnly(true);
        numtelperso = new QLineEdit(DialogP);
        numtelperso->setObjectName(QStringLiteral("numtelperso"));
        numtelperso->setGeometry(QRect(240, 380, 201, 41));
        numtelperso->setReadOnly(true);
        adressepersoL = new QLabel(DialogP);
        adressepersoL->setObjectName(QStringLiteral("adressepersoL"));
        adressepersoL->setGeometry(QRect(16, 443, 121, 31));
        adressepersoL->setFont(font);
        metierperso = new QComboBox(DialogP);
        metierperso->setObjectName(QStringLiteral("metierperso"));
        metierperso->setEnabled(false);
        metierperso->setGeometry(QRect(240, 497, 201, 41));
        mailperso = new QTextEdit(DialogP);
        mailperso->setObjectName(QStringLiteral("mailperso"));
        mailperso->setEnabled(true);
        mailperso->setGeometry(QRect(240, 144, 201, 61));
        mailperso->setReadOnly(true);
        closeafficherperso = new QPushButton(DialogP);
        closeafficherperso->setObjectName(QStringLiteral("closeafficherperso"));
        closeafficherperso->setGeometry(QRect(450, 16, 40, 40));
        closeafficherperso->setStyleSheet(QLatin1String("#closeafficherperso{\n"
"border-image: url(:/images/closep1.png);\n"
"}\n"
"#closeafficherperso:hover{\n"
"border-image: url(:/images/closep2.png);\n"
"}\n"
"#closeafficherperso:pressed{\n"
"border-image: url(:/images/closep2.png);\n"
"}"));

        retranslateUi(DialogP);

        QMetaObject::connectSlotsByName(DialogP);
    } // setupUi

    void retranslateUi(QDialog *DialogP)
    {
        DialogP->setWindowTitle(QApplication::translate("DialogP", "Ahminy", Q_NULLPTR));
        cinpersoL->setText(QApplication::translate("DialogP", "Cin", Q_NULLPTR));
        dobpersoL->setText(QApplication::translate("DialogP", "Date de naissance", Q_NULLPTR));
        mailpersoL->setText(QApplication::translate("DialogP", "Adresse Mail", Q_NULLPTR));
        hommeperso->setText(QApplication::translate("DialogP", "Homme", Q_NULLPTR));
        titreafficherp->setText(QApplication::translate("DialogP", "Nom + Prenom :", Q_NULLPTR));
        sexepersoL->setText(QApplication::translate("DialogP", "Sexe", Q_NULLPTR));
        idpersoL->setText(QApplication::translate("DialogP", "Matricule", Q_NULLPTR));
        femmeperso->setText(QApplication::translate("DialogP", "Femme", Q_NULLPTR));
        salairepersoL->setText(QApplication::translate("DialogP", "Salaire", Q_NULLPTR));
        metierpersoL->setText(QApplication::translate("DialogP", "M\303\251tier", Q_NULLPTR));
        telpersoL->setText(QApplication::translate("DialogP", "T\303\251l\303\251phone", Q_NULLPTR));
        adressepersoL->setText(QApplication::translate("DialogP", "Adresse", Q_NULLPTR));
        metierperso->clear();
        metierperso->insertItems(0, QStringList()
         << QApplication::translate("DialogP", "Responsable RH", Q_NULLPTR)
         << QApplication::translate("DialogP", "Receptionniste", Q_NULLPTR)
         << QApplication::translate("DialogP", "Medecin", Q_NULLPTR)
         << QApplication::translate("DialogP", "Tresorier", Q_NULLPTR)
         << QApplication::translate("DialogP", "Gestionnaire De Stock", Q_NULLPTR)
        );
        closeafficherperso->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogP: public Ui_DialogP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGP_H
