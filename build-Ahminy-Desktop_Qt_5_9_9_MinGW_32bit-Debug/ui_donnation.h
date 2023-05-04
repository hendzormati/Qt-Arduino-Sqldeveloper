/********************************************************************************
** Form generated from reading UI file 'donnation.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DONNATION_H
#define UI_DONNATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_donnation
{
public:
    QFrame *donnationmontant;
    QPushButton *ajouter;
    QPushButton *annuler;
    QLineEdit *nbfois;
    QLineEdit *montant;
    QLabel *NbfoisL;
    QLabel *montantL;

    void setupUi(QDialog *donnation)
    {
        if (donnation->objectName().isEmpty())
            donnation->setObjectName(QStringLiteral("donnation"));
        donnation->resize(528, 290);
        donnationmontant = new QFrame(donnation);
        donnationmontant->setObjectName(QStringLiteral("donnationmontant"));
        donnationmontant->setGeometry(QRect(0, 0, 531, 288));
        donnationmontant->setStyleSheet(QLatin1String("#donnationmontant{background:#f8f5f1;border:8px double #eff5d6;  border-top-right-radius: 10px;   border-bottom-left-radius: 10px;}\n"
"#titremodifdon{color:#52794a;}\n"
"\n"
"#NbfoisL{color:#62865C;}\n"
"\n"
"#montantL{color:#62865C;}\n"
"\n"
"#nbfois{ selection-color:#56695b;\n"
"color: #52794a;\n"
"font-weight: bold;\n"
"font-size: 15px;\n"
"border: 2px outset #dcd0c9;\n"
"border-radius: 7px;\n"
"background-color: #fefefb;\n"
"  selection-background-color: #e3dac9;\n"
"}\n"
"#nbfois:hover{\n"
"border: 2px inset #dcd0c9;\n"
"background: #fafaeb;\n"
"}\n"
"\n"
"#montant{ selection-color:#56695b;\n"
"color: #52794a;\n"
"font-weight: bold;\n"
"font-size: 15px;\n"
"border: 2px outset #dcd0c9;\n"
"border-radius: 7px;\n"
"background-color: #fefefb;\n"
"  selection-background-color: #e3dac9;\n"
"}\n"
"#montant:hover{\n"
"border: 2px inset #dcd0c9;\n"
"background: #fafaeb;\n"
"}\n"
"\n"
"#ajouter{\n"
"color:#52794a;\n"
"border: 4px inset #dcd0c9;\n"
"border-radius: 15px;\n"
"background: #f3f2f7;\n"
"}\n"
"#ajouter:h"
                        "over{\n"
"border: 4px outset #dcd0c9;\n"
"background: #eff5d6;\n"
"}\n"
"#ajouter:pressed{\n"
"border: 4px inset #dcd0c9;\n"
"background: #f6f1f7;\n"
"}\n"
"\n"
"#annuler{\n"
"color:#52794a;\n"
"border: 4px inset #dcd0c9;\n"
"border-radius: 15px;\n"
"background: #f3f2f7;\n"
"}\n"
"#annuler:hover{\n"
"border: 4px outset #dcd0c9;\n"
"background: #eff5d6;\n"
"}\n"
"#annuler:pressed{\n"
"border: 4px inset #dcd0c9;\n"
"background: #f6f1f7;\n"
"}\n"
"\n"
""));
        donnationmontant->setFrameShape(QFrame::StyledPanel);
        donnationmontant->setFrameShadow(QFrame::Raised);
        ajouter = new QPushButton(donnationmontant);
        ajouter->setObjectName(QStringLiteral("ajouter"));
        ajouter->setGeometry(QRect(300, 210, 131, 41));
        QFont font;
        font.setFamily(QStringLiteral("Bell MT"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        font.setKerning(true);
        ajouter->setFont(font);
        annuler = new QPushButton(donnationmontant);
        annuler->setObjectName(QStringLiteral("annuler"));
        annuler->setGeometry(QRect(90, 210, 131, 41));
        annuler->setFont(font);
        nbfois = new QLineEdit(donnationmontant);
        nbfois->setObjectName(QStringLiteral("nbfois"));
        nbfois->setEnabled(false);
        nbfois->setGeometry(QRect(340, 50, 121, 41));
        montant = new QLineEdit(donnationmontant);
        montant->setObjectName(QStringLiteral("montant"));
        montant->setEnabled(true);
        montant->setGeometry(QRect(210, 110, 251, 41));
        NbfoisL = new QLabel(donnationmontant);
        NbfoisL->setObjectName(QStringLiteral("NbfoisL"));
        NbfoisL->setGeometry(QRect(40, 50, 291, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Bell MT"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        NbfoisL->setFont(font1);
        montantL = new QLabel(donnationmontant);
        montantL->setObjectName(QStringLiteral("montantL"));
        montantL->setGeometry(QRect(40, 120, 121, 31));
        montantL->setFont(font1);

        retranslateUi(donnation);

        QMetaObject::connectSlotsByName(donnation);
    } // setupUi

    void retranslateUi(QDialog *donnation)
    {
        donnation->setWindowTitle(QApplication::translate("donnation", "Dialog", Q_NULLPTR));
        ajouter->setText(QApplication::translate("donnation", "Ajouter", Q_NULLPTR));
        annuler->setText(QApplication::translate("donnation", "Annuler", Q_NULLPTR));
        NbfoisL->setText(QApplication::translate("donnation", "Nombre de donnation", Q_NULLPTR));
        montantL->setText(QApplication::translate("donnation", "Montant", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class donnation: public Ui_donnation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DONNATION_H
