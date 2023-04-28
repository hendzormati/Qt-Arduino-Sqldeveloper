/********************************************************************************
** Form generated from reading UI file 'dialogs.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGS_H
#define UI_DIALOGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialogs
{
public:
    QLabel *dianumchsdfL;
    QLabel *dianbpassagesdfL;
    QSpinBox *dianumchsdf;
    QSpinBox *dianbpassagesdf;
    QLabel *diacinsdfL;
    QLabel *titresdf;
    QDateEdit *diadatesorsdf;
    QDateEdit *diadateentsdf;
    QLineEdit *diacinsdf;
    QLabel *diadatesorsdfL;
    QLabel *diadateentsdfL;
    QLabel *nondtsdf;

    void setupUi(QDialog *Dialogs)
    {
        if (Dialogs->objectName().isEmpty())
            Dialogs->setObjectName(QStringLiteral("Dialogs"));
        Dialogs->resize(383, 421);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        Dialogs->setFont(font);
        Dialogs->setStyleSheet(QLatin1String("#Dialogs{background:#fbf9f9;border:8px double #f0e4e0;}\n"
"\n"
"#titresdf{color:#56695b;}\n"
"/*#titresdf_2{color:#56695b;}*/\n"
"#nondtsdf{color:#56695b;}\n"
"\n"
"#diacinsdfL{color:#62865C;}\n"
"#dianbpassagesdfL{color:#62865C;}\n"
"#diadateentsdfL{color:#62865C;}\n"
"#diadatesorsdfL{color:#62865C;}\n"
"#dianumchsdfL{color:#62865C;}\n"
"\n"
"#diadateentsdf{color:#56695b;\n"
" selection-color:#56695b;\n"
"border: 2px outset #dcd0c9;\n"
"border-radius: 7px;\n"
"background: #fefefb;\n"
"selection-background-color: #e3dac9;}\n"
"#diadatesorsdf{color:#56695b;\n"
" selection-color:#56695b;\n"
"border: 2px outset #dcd0c9;\n"
"border-radius: 7px;\n"
"background: #fefefb;\n"
"selection-background-color: #e3dac9;}\n"
"#dianbpassagesdf{color:#56695b;\n"
" selection-color:#56695b;\n"
"border: 2px outset #dcd0c9;\n"
"border-radius: 7px;\n"
"background: #fefefb;\n"
"selection-background-color: #e3dac9;}\n"
"#dianumchsdf{color:#56695b;\n"
" selection-color:#56695b;\n"
"border: 2px outset #dcd0c9;\n"
"border-radius: 7px;\n"
""
                        "background: #fefefb;\n"
"selection-background-color: #e3dac9;}\n"
"#diacinsdf{ selection-color:#56695b;\n"
"color: #56695b;\n"
"font-weight: bold;\n"
"font-size: 15px;\n"
"border: 2px outset #dcd0c9;\n"
"border-radius: 7px;\n"
"background-color: #fefefb;\n"
"selection-background-color: #e3dac9;}\n"
""));
        dianumchsdfL = new QLabel(Dialogs);
        dianumchsdfL->setObjectName(QStringLiteral("dianumchsdfL"));
        dianumchsdfL->setGeometry(QRect(30, 340, 161, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Bell MT"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        dianumchsdfL->setFont(font1);
        dianbpassagesdfL = new QLabel(Dialogs);
        dianbpassagesdfL->setObjectName(QStringLiteral("dianbpassagesdfL"));
        dianbpassagesdfL->setGeometry(QRect(30, 190, 161, 31));
        dianbpassagesdfL->setFont(font1);
        dianumchsdf = new QSpinBox(Dialogs);
        dianumchsdf->setObjectName(QStringLiteral("dianumchsdf"));
        dianumchsdf->setEnabled(false);
        dianumchsdf->setGeometry(QRect(220, 338, 121, 31));
        dianbpassagesdf = new QSpinBox(Dialogs);
        dianbpassagesdf->setObjectName(QStringLiteral("dianbpassagesdf"));
        dianbpassagesdf->setEnabled(false);
        dianbpassagesdf->setGeometry(QRect(220, 189, 121, 31));
        diacinsdfL = new QLabel(Dialogs);
        diacinsdfL->setObjectName(QStringLiteral("diacinsdfL"));
        diacinsdfL->setGeometry(QRect(30, 140, 161, 31));
        diacinsdfL->setFont(font1);
        titresdf = new QLabel(Dialogs);
        titresdf->setObjectName(QStringLiteral("titresdf"));
        titresdf->setGeometry(QRect(30, 50, 341, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Bell MT"));
        font2.setPointSize(22);
        font2.setBold(true);
        font2.setUnderline(true);
        font2.setWeight(75);
        titresdf->setFont(font2);
        diadatesorsdf = new QDateEdit(Dialogs);
        diadatesorsdf->setObjectName(QStringLiteral("diadatesorsdf"));
        diadatesorsdf->setEnabled(false);
        diadatesorsdf->setGeometry(QRect(220, 289, 121, 31));
        QFont font3;
        font3.setPointSize(10);
        diadatesorsdf->setFont(font3);
        diadateentsdf = new QDateEdit(Dialogs);
        diadateentsdf->setObjectName(QStringLiteral("diadateentsdf"));
        diadateentsdf->setEnabled(false);
        diadateentsdf->setGeometry(QRect(220, 239, 121, 31));
        diadateentsdf->setFont(font3);
        diacinsdf = new QLineEdit(Dialogs);
        diacinsdf->setObjectName(QStringLiteral("diacinsdf"));
        diacinsdf->setEnabled(false);
        diacinsdf->setGeometry(QRect(220, 140, 121, 31));
        diadatesorsdfL = new QLabel(Dialogs);
        diadatesorsdfL->setObjectName(QStringLiteral("diadatesorsdfL"));
        diadatesorsdfL->setGeometry(QRect(30, 290, 161, 31));
        diadatesorsdfL->setFont(font1);
        diadateentsdfL = new QLabel(Dialogs);
        diadateentsdfL->setObjectName(QStringLiteral("diadateentsdfL"));
        diadateentsdfL->setGeometry(QRect(30, 240, 161, 31));
        diadateentsdfL->setFont(font1);
        nondtsdf = new QLabel(Dialogs);
        nondtsdf->setObjectName(QStringLiteral("nondtsdf"));
        nondtsdf->setGeometry(QRect(220, 293, 111, 21));
        QFont font4;
        font4.setFamily(QStringLiteral("Arial Black"));
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        nondtsdf->setFont(font4);

        retranslateUi(Dialogs);

        QMetaObject::connectSlotsByName(Dialogs);
    } // setupUi

    void retranslateUi(QDialog *Dialogs)
    {
        Dialogs->setWindowTitle(QApplication::translate("Dialogs", "Dialog", Q_NULLPTR));
        dianumchsdfL->setText(QApplication::translate("Dialogs", "N\302\260 Chambre", Q_NULLPTR));
        dianbpassagesdfL->setText(QApplication::translate("Dialogs", "Nb Passage", Q_NULLPTR));
        diacinsdfL->setText(QApplication::translate("Dialogs", "Cin", Q_NULLPTR));
        titresdf->setText(QApplication::translate("Dialogs", "NOM", Q_NULLPTR));
        diadatesorsdfL->setText(QApplication::translate("Dialogs", "Date Sortie", Q_NULLPTR));
        diadateentsdfL->setText(QApplication::translate("Dialogs", "Date Entree", Q_NULLPTR));
        nondtsdf->setText(QApplication::translate("Dialogs", "Pas Encore", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialogs: public Ui_Dialogs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGS_H
