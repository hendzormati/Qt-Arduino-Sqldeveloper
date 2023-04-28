/********************************************************************************
** Form generated from reading UI file 'modifmdp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFMDP_H
#define UI_MODIFMDP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_modifmdp
{
public:
    QLabel *titrep;
    QLineEdit *verifemailp;
    QLineEdit *confirmercodep;
    QLabel *strengthmdpL;
    QLineEdit *nouveaumdp;
    QProgressBar *strengthmdp;
    QLabel *nbtentativeL;
    QLabel *nbtentative;
    QPushButton *quittermodifmdp;
    QPushButton *quittermdp;
    QPushButton *renvoyer;
    QPushButton *showpswd;

    void setupUi(QDialog *modifmdp)
    {
        if (modifmdp->objectName().isEmpty())
            modifmdp->setObjectName(QStringLiteral("modifmdp"));
        modifmdp->resize(580, 225);
        modifmdp->setStyleSheet(QLatin1String("#modifmdp{ background: #fbf9f9;;border:8px double #e6e4ea;}\n"
"#titrep{color:#968c9b;}\n"
"#nbtentative{color:#aca0b2;} \n"
"#strengthmdpL{color:#aca0b2;} \n"
"#nbtentativeL{color:#aca0b2;} \n"
"#verifemailp{ \n"
"color: #968c9b;\n"
"font-weight: bold;\n"
"font-size: 15px;\n"
"border: 2px outset #dcd0c9;\n"
"border-radius: 7px;\n"
"background-color: #fefefb;\n"
"selection-background-color: #968c9b;\n"
"selection-color: #33457d;\n"
"}\n"
"#verifemailp:hover{\n"
"border: 2px inset #dcd0c9;\n"
"background:#f3f2f7;\n"
"}\n"
"#confirmercodep{ \n"
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
"#confirmercodep:hover{\n"
"border: 2px inset #dcd0c9;\n"
"background:#f3f2f7;\n"
"}\n"
"#nouveaumdp{ \n"
"color: #968c9b;\n"
"font-weight: bold;\n"
"font-size: 15px;\n"
"border: 2px outset #dcd0c9;\n"
"border-radius: 7px;\n"
"background-color"
                        ": #fefefb;\n"
"selection-background-color: #968c9b;\n"
"selection-color: #33457d;\n"
"\n"
"}\n"
"#nouveaumdp:hover{\n"
"border: 2px inset #dcd0c9;\n"
"background:#f3f2f7;\n"
"}\n"
"#showpswd{border-image:url(:/images/hideM.png) ;}\n"
"#showpswd:pressed{border-image:url(:/images/showM.png) ;}"));
        titrep = new QLabel(modifmdp);
        titrep->setObjectName(QStringLiteral("titrep"));
        titrep->setGeometry(QRect(50, 25, 501, 31));
        QFont font;
        font.setFamily(QStringLiteral("Bell MT"));
        font.setPointSize(17);
        font.setBold(true);
        font.setWeight(75);
        titrep->setFont(font);
        verifemailp = new QLineEdit(modifmdp);
        verifemailp->setObjectName(QStringLiteral("verifemailp"));
        verifemailp->setGeometry(QRect(80, 90, 391, 41));
        confirmercodep = new QLineEdit(modifmdp);
        confirmercodep->setObjectName(QStringLiteral("confirmercodep"));
        confirmercodep->setGeometry(QRect(80, 90, 391, 41));
        strengthmdpL = new QLabel(modifmdp);
        strengthmdpL->setObjectName(QStringLiteral("strengthmdpL"));
        strengthmdpL->setGeometry(QRect(80, 154, 131, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Bell MT"));
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        strengthmdpL->setFont(font1);
        strengthmdpL->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);
        nouveaumdp = new QLineEdit(modifmdp);
        nouveaumdp->setObjectName(QStringLiteral("nouveaumdp"));
        nouveaumdp->setGeometry(QRect(80, 90, 391, 41));
        nouveaumdp->setEchoMode(QLineEdit::Password);
        strengthmdp = new QProgressBar(modifmdp);
        strengthmdp->setObjectName(QStringLiteral("strengthmdp"));
        strengthmdp->setGeometry(QRect(270, 160, 191, 23));
        QFont font2;
        font2.setFamily(QStringLiteral("Bell MT"));
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setWeight(50);
        strengthmdp->setFont(font2);
        strengthmdp->setStyleSheet(QLatin1String("QProgressBar {\n"
"border: 1px solid black;\n"
"text-align: top;\n"
"padding: 1px;\n"
"border-bottom-right-radius: 7px;\n"
"border-bottom-left-radius: 7px;\n"
"background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,\n"
"stop: 0 #fff,\n"
"stop: 0.4999 #eee,\n"
"stop: 0.5 #ddd,\n"
"stop: 1 #eee );\n"
"width: 15px;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,\n"
"stop: 0 #78d,\n"
"stop: 0.4999 #46a,\n"
"stop: 0.5 #45a,\n"
"stop: 1 #238 );\n"
"border-bottom-right-radius: 7px;\n"
"border-bottom-left-radius: 7px;\n"
"border: 1px solid black;\n"
"}"));
        strengthmdp->setValue(0);
        nbtentativeL = new QLabel(modifmdp);
        nbtentativeL->setObjectName(QStringLiteral("nbtentativeL"));
        nbtentativeL->setGeometry(QRect(100, 60, 301, 21));
        QFont font3;
        font3.setFamily(QStringLiteral("Bell MT"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        nbtentativeL->setFont(font3);
        nbtentative = new QLabel(modifmdp);
        nbtentative->setObjectName(QStringLiteral("nbtentative"));
        nbtentative->setGeometry(QRect(410, 60, 21, 21));
        QFont font4;
        font4.setFamily(QStringLiteral("Bahnschrift SemiBold"));
        font4.setPointSize(14);
        font4.setBold(false);
        font4.setWeight(50);
        nbtentative->setFont(font4);
        quittermodifmdp = new QPushButton(modifmdp);
        quittermodifmdp->setObjectName(QStringLiteral("quittermodifmdp"));
        quittermodifmdp->setGeometry(QRect(630, 180, 33, 33));
        quittermodifmdp->setStyleSheet(QLatin1String("/*#quittermodifmdp{\n"
"border-image: url(:/images/closeafficherperso1.png);\n"
"}\n"
"#quittermodifmdp:hover{\n"
"border-image: url(:/images/closeafficherperso2.png);\n"
"}\n"
"#quittermodifmdp:pressed{\n"
"border-image: url(:/images/closeafficherperso3.png);\n"
"}*/"));
        quittermdp = new QPushButton(modifmdp);
        quittermdp->setObjectName(QStringLiteral("quittermdp"));
        quittermdp->setEnabled(false);
        quittermdp->setGeometry(QRect(530, 12, 40, 40));
        quittermdp->setStyleSheet(QLatin1String("#quittermdp{\n"
"border-image: url(:/images/closep1.png);\n"
"}\n"
"#quittermdp:hover{\n"
"border-image: url(:/images/closep2.png);\n"
"}\n"
"#quittermdp:pressed{\n"
"border-image: url(:/images/closep2.png);\n"
"}"));
        renvoyer = new QPushButton(modifmdp);
        renvoyer->setObjectName(QStringLiteral("renvoyer"));
        renvoyer->setGeometry(QRect(200, 150, 131, 40));
        QFont font5;
        font5.setFamily(QStringLiteral("Bell MT"));
        font5.setPointSize(16);
        font5.setBold(true);
        font5.setWeight(75);
        renvoyer->setFont(font5);
        renvoyer->setStyleSheet(QLatin1String("#renvoyer{\n"
"color:#968c9b;\n"
"border: 4px inset #dcd0c9;\n"
"border-radius: 15px;\n"
"background: #f3f2f7;\n"
"}\n"
"#renvoyer:hover{\n"
"border: 4px outset #dcd0c9;\n"
"background: #e0dfe5;\n"
"}\n"
"#renvoyer:pressed{\n"
"border: 4px inset #dcd0c9;\n"
"background: #f6f1f7;\n"
"}"));
        showpswd = new QPushButton(modifmdp);
        showpswd->setObjectName(QStringLiteral("showpswd"));
        showpswd->setGeometry(QRect(434, 95, 30, 30));
        showpswd->setStyleSheet(QStringLiteral(""));
        nouveaumdp->raise();
        confirmercodep->raise();
        titrep->raise();
        strengthmdpL->raise();
        strengthmdp->raise();
        nbtentativeL->raise();
        nbtentative->raise();
        verifemailp->raise();
        quittermodifmdp->raise();
        quittermdp->raise();
        renvoyer->raise();
        showpswd->raise();

        retranslateUi(modifmdp);

        QMetaObject::connectSlotsByName(modifmdp);
    } // setupUi

    void retranslateUi(QDialog *modifmdp)
    {
        modifmdp->setWindowTitle(QApplication::translate("modifmdp", "Ahminy", Q_NULLPTR));
        titrep->setText(QApplication::translate("modifmdp", "Veuillez Confirmer Votre Email", Q_NULLPTR));
        strengthmdpL->setText(QApplication::translate("modifmdp", "\303\251tat du mdp", Q_NULLPTR));
        nbtentativeL->setText(QApplication::translate("modifmdp", "Nombre De Tentatives Possibles :", Q_NULLPTR));
        nbtentative->setText(QApplication::translate("modifmdp", "2", Q_NULLPTR));
        quittermodifmdp->setText(QApplication::translate("modifmdp", "wtf", Q_NULLPTR));
        quittermdp->setText(QString());
        renvoyer->setText(QApplication::translate("modifmdp", "renvoyer", Q_NULLPTR));
        showpswd->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class modifmdp: public Ui_modifmdp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFMDP_H
