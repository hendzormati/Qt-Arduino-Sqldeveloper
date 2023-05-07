/********************************************************************************
** Form generated from reading UI file 'dialogc.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGC_H
#define UI_DIALOGC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dialogc
{
public:
    QFrame *ajouterconst;
    QPushButton *confirmerAjouterconst;
    QLabel *ajoutcons;
    QPushButton *closeajoutercons;
    QLabel *resultatL;
    QPlainTextEdit *resultat;
    QLineEdit *taille;
    QLabel *tailleL;
    QLabel *poidsL;
    QLabel *temperatureL;
    QLabel *tensionL;
    QLineEdit *poids;
    QLineEdit *tension;
    QLineEdit *temperature;
    QLabel *cm;
    QLabel *kg;
    QLabel *c;
    QLabel *hg;

    void setupUi(QDialog *dialogc)
    {
        if (dialogc->objectName().isEmpty())
            dialogc->setObjectName(QStringLiteral("dialogc"));
        dialogc->resize(483, 542);
        ajouterconst = new QFrame(dialogc);
        ajouterconst->setObjectName(QStringLiteral("ajouterconst"));
        ajouterconst->setGeometry(QRect(0, 0, 481, 541));
        ajouterconst->setStyleSheet(QLatin1String("#ajouterconst{background:#f8f5f1;border:8px double #e0dfe5;  border-top-right-radius:5px;   border-bottom-left-radius: 5px;}\n"
"\n"
"#ajoutcons{color:#425180;}\n"
"#cm{color:#425180;}\n"
"#kg{color:#425180;}\n"
"#hg{color:#425180;}\n"
"#c{color:#425180;}\n"
"\n"
"#nomprenom{color:#4f619a;}\n"
"#tailleL{color:#4f619a;}\n"
"#poidsL{color:#4f619a;}\n"
"#tensionL{color:#4f619a;}\n"
"#temperatureL{color:#4f619a;}\n"
"#resultatL{color:#4f619a;}\n"
"\n"
"#resultat{ \n"
"color: #425180;\n"
"font-weight: bold;\n"
"font-size: 15px;\n"
"border: 2px outset #e0dfe5;\n"
"border-radius: 7px;\n"
"background-color: #fefefb;\n"
"selection-background-color: #d3d3d3;\n"
"selection-color: #33457d;\n"
"\n"
"}\n"
"#resultat:hover{\n"
"border: 2px inset #dcd0c9;\n"
"background: #f3f2f7;\n"
"}\n"
"\n"
"#taille{ \n"
"color: #425180;\n"
"font-weight: bold;\n"
"font-size: 15px;\n"
"border: 2px outset #e0dfe5;\n"
"border-radius: 7px;\n"
"background-color: #fefefb;\n"
"selection-background-color: #d3d3d3;\n"
"selection-color: #33457d;\n"
""
                        "\n"
"}\n"
"#taille:hover{\n"
"border: 2px inset #dcd0c9;\n"
"background: #f3f2f7;\n"
"}\n"
"\n"
"#poids{ \n"
"color: #425180;\n"
"font-weight: bold;\n"
"font-size: 15px;\n"
"border: 2px outset #e0dfe5;\n"
"border-radius: 7px;\n"
"background-color: #fefefb;\n"
"selection-background-color: #d3d3d3;\n"
"selection-color: #33457d;\n"
"\n"
"}\n"
"#poids:hover{\n"
"border: 2px inset #dcd0c9;\n"
"background: #f3f2f7;\n"
"}\n"
"\n"
"#tension{ \n"
"color: #425180;\n"
"font-weight: bold;\n"
"font-size: 15px;\n"
"border: 2px outset #e0dfe5;\n"
"border-radius: 7px;\n"
"background-color: #fefefb;\n"
"selection-background-color: #d3d3d3;\n"
"selection-color: #33457d;\n"
"\n"
"}\n"
"#tension:hover{\n"
"border: 2px inset #dcd0c9;\n"
"background: #f3f2f7;\n"
"}\n"
"\n"
"#temperature{ \n"
"color: #425180;\n"
"font-weight: bold;\n"
"font-size: 15px;\n"
"border: 2px outset #e0dfe5;\n"
"border-radius: 7px;\n"
"background-color: #fefefb;\n"
"selection-background-color: #d3d3d3;\n"
"selection-color: #33457d;\n"
"\n"
"}\n"
"#temperatu"
                        "re:hover{\n"
"border: 2px inset #dcd0c9;\n"
"background: #f3f2f7;\n"
"}\n"
"\n"
"#confirmerAjouterconst{\n"
"color:#425180;\n"
"border: 4px inset #dcd0c9;\n"
"border-radius: 15px;\n"
"background: #f3f2f7;\n"
"}\n"
"#confirmerAjouterconst:hover{\n"
"border: 4px outset #dcd0c9;\n"
"background: #e0dfe5;\n"
"}\n"
"#confirmerAjouterconst:pressed{\n"
"border: 4px inset #dcd0c9;\n"
"background: #f6f1f7;\n"
"}\n"
"#closeajoutercons{\n"
"color:#425180;\n"
"border: 4px inset #dcd0c9;\n"
"border-radius: 15px;\n"
"background: #f3f2f7;\n"
"}\n"
"#closeajoutercons:hover{\n"
"border: 4px outset #dcd0c9;\n"
"background: #f0e4e0;\n"
"}\n"
"#closeajoutercons:pressed{\n"
"border: 4px inset #dcd0c9;\n"
"background: #f6f1f7;\n"
"}\n"
""));
        ajouterconst->setFrameShape(QFrame::StyledPanel);
        ajouterconst->setFrameShadow(QFrame::Raised);
        confirmerAjouterconst = new QPushButton(ajouterconst);
        confirmerAjouterconst->setObjectName(QStringLiteral("confirmerAjouterconst"));
        confirmerAjouterconst->setGeometry(QRect(150, 470, 181, 50));
        QFont font;
        font.setFamily(QStringLiteral("Bell MT"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        font.setKerning(true);
        confirmerAjouterconst->setFont(font);
        ajoutcons = new QLabel(ajouterconst);
        ajoutcons->setObjectName(QStringLiteral("ajoutcons"));
        ajoutcons->setGeometry(QRect(60, 30, 381, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Bell MT"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        ajoutcons->setFont(font1);
        closeajoutercons = new QPushButton(ajouterconst);
        closeajoutercons->setObjectName(QStringLiteral("closeajoutercons"));
        closeajoutercons->setGeometry(QRect(12, 11, 28, 28));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        closeajoutercons->setFont(font2);
        resultatL = new QLabel(ajouterconst);
        resultatL->setObjectName(QStringLiteral("resultatL"));
        resultatL->setGeometry(QRect(20, 355, 231, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Bell MT"));
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setWeight(75);
        resultatL->setFont(font3);
        resultat = new QPlainTextEdit(ajouterconst);
        resultat->setObjectName(QStringLiteral("resultat"));
        resultat->setGeometry(QRect(260, 345, 201, 91));
        taille = new QLineEdit(ajouterconst);
        taille->setObjectName(QStringLiteral("taille"));
        taille->setGeometry(QRect(260, 105, 201, 41));
        tailleL = new QLabel(ajouterconst);
        tailleL->setObjectName(QStringLiteral("tailleL"));
        tailleL->setGeometry(QRect(20, 110, 241, 31));
        tailleL->setFont(font3);
        poidsL = new QLabel(ajouterconst);
        poidsL->setObjectName(QStringLiteral("poidsL"));
        poidsL->setGeometry(QRect(20, 170, 241, 31));
        poidsL->setFont(font3);
        temperatureL = new QLabel(ajouterconst);
        temperatureL->setObjectName(QStringLiteral("temperatureL"));
        temperatureL->setGeometry(QRect(20, 290, 241, 31));
        temperatureL->setFont(font3);
        tensionL = new QLabel(ajouterconst);
        tensionL->setObjectName(QStringLiteral("tensionL"));
        tensionL->setGeometry(QRect(20, 230, 241, 31));
        tensionL->setFont(font3);
        poids = new QLineEdit(ajouterconst);
        poids->setObjectName(QStringLiteral("poids"));
        poids->setGeometry(QRect(260, 165, 201, 41));
        tension = new QLineEdit(ajouterconst);
        tension->setObjectName(QStringLiteral("tension"));
        tension->setGeometry(QRect(260, 225, 201, 41));
        temperature = new QLineEdit(ajouterconst);
        temperature->setObjectName(QStringLiteral("temperature"));
        temperature->setGeometry(QRect(260, 285, 201, 41));
        cm = new QLabel(ajouterconst);
        cm->setObjectName(QStringLiteral("cm"));
        cm->setGeometry(QRect(418, 110, 41, 31));
        cm->setFont(font3);
        kg = new QLabel(ajouterconst);
        kg->setObjectName(QStringLiteral("kg"));
        kg->setGeometry(QRect(420, 170, 41, 31));
        kg->setFont(font3);
        c = new QLabel(ajouterconst);
        c->setObjectName(QStringLiteral("c"));
        c->setGeometry(QRect(420, 290, 41, 31));
        c->setFont(font3);
        hg = new QLabel(ajouterconst);
        hg->setObjectName(QStringLiteral("hg"));
        hg->setGeometry(QRect(378, 225, 81, 31));
        hg->setFont(font3);

        retranslateUi(dialogc);

        QMetaObject::connectSlotsByName(dialogc);
    } // setupUi

    void retranslateUi(QDialog *dialogc)
    {
        dialogc->setWindowTitle(QApplication::translate("dialogc", "Dialog", Q_NULLPTR));
        confirmerAjouterconst->setText(QApplication::translate("dialogc", "Confirmer", Q_NULLPTR));
        ajoutcons->setText(QApplication::translate("dialogc", "Ajouter Une Consultation", Q_NULLPTR));
        closeajoutercons->setText(QApplication::translate("dialogc", "X", Q_NULLPTR));
        resultatL->setText(QApplication::translate("dialogc", "R\303\251sultat", Q_NULLPTR));
        tailleL->setText(QApplication::translate("dialogc", "Taille de Patient", Q_NULLPTR));
        poidsL->setText(QApplication::translate("dialogc", "Poids de Patient", Q_NULLPTR));
        temperatureL->setText(QApplication::translate("dialogc", "Temp\303\251rature", Q_NULLPTR));
        tensionL->setText(QApplication::translate("dialogc", "Tension Art\303\251rielle", Q_NULLPTR));
        cm->setText(QApplication::translate("dialogc", "Cm", Q_NULLPTR));
        kg->setText(QApplication::translate("dialogc", "Kg", Q_NULLPTR));
        c->setText(QApplication::translate("dialogc", "\302\260C", Q_NULLPTR));
        hg->setText(QApplication::translate("dialogc", "mmHg", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class dialogc: public Ui_dialogc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGC_H
