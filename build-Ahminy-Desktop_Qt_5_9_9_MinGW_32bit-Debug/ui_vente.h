/********************************************************************************
** Form generated from reading UI file 'vente.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTE_H
#define UI_VENTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_vente
{
public:
    QFrame *vendreinvdialog;
    QLabel *titreveninv;
    QSpinBox *nbresinv;
    QPushButton *vendinv;
    QPushButton *closeinv;
    QRadioButton *vendre;
    QRadioButton *ajouter;

    void setupUi(QDialog *vente)
    {
        if (vente->objectName().isEmpty())
            vente->setObjectName(QStringLiteral("vente"));
        vente->resize(525, 250);
        vendreinvdialog = new QFrame(vente);
        vendreinvdialog->setObjectName(QStringLiteral("vendreinvdialog"));
        vendreinvdialog->setGeometry(QRect(0, 0, 525, 250));
        vendreinvdialog->setStyleSheet(QLatin1String("#vendreinvdialog{background:#f8f5f1;border:8px double #f0e4e0;  border-top-right-radius: 10px;   border-bottom-left-radius:10px;}\n"
"\n"
"#titreveninv{color:#d7837f;}\n"
"\n"
"#vendinv{\n"
"color:#d7837f;\n"
"border: 4px inset #dcd0c9;\n"
"border-radius: 15px;\n"
"background: #f3f2f7;\n"
"}\n"
"#vendinv:hover{\n"
"border: 4px outset #dcd0c9;\n"
"background: #f0e4e0;\n"
"}\n"
"#vendinv:pressed{\n"
"border: 4px inset #dcd0c9;\n"
"background: #f6f1f7;\n"
"}\n"
"\n"
"#closeinv{\n"
"color:#d7837f;\n"
"border: 4px inset #dcd0c9;\n"
"border-radius: 15px;\n"
"background: #f3f2f7;\n"
"}\n"
"#closeinv:hover{\n"
"border: 4px outset #dcd0c9;\n"
"background: #f0e4e0;\n"
"}\n"
"#closeinv:pressed{\n"
"border: 4px inset #dcd0c9;\n"
"background: #f6f1f7;\n"
"}\n"
"\n"
"#nbresinv{ \n"
"border: 2px solid #dcd0c9;\n"
"border-radius: 7px;\n"
"color: #858585;\n"
"font-weight: bold;\n"
"font-size: 15px;\n"
"}\n"
"#nbresinv QAbstractItemView{ \n"
"color: #858585;\n"
"font-weight: bold;\n"
"font-size: 15px;\n"
"selection-background-c"
                        "olor: #ffffff;\n"
"selection-color:#56695b;\n"
"}\n"
""));
        vendreinvdialog->setFrameShape(QFrame::StyledPanel);
        vendreinvdialog->setFrameShadow(QFrame::Raised);
        titreveninv = new QLabel(vendreinvdialog);
        titreveninv->setObjectName(QStringLiteral("titreveninv"));
        titreveninv->setGeometry(QRect(70, 20, 411, 41));
        QFont font;
        font.setFamily(QStringLiteral("Bell MT"));
        font.setPointSize(20);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        titreveninv->setFont(font);
        nbresinv = new QSpinBox(vendreinvdialog);
        nbresinv->setObjectName(QStringLiteral("nbresinv"));
        nbresinv->setGeometry(QRect(290, 110, 171, 31));
        nbresinv->setMinimum(1);
        vendinv = new QPushButton(vendreinvdialog);
        vendinv->setObjectName(QStringLiteral("vendinv"));
        vendinv->setGeometry(QRect(110, 160, 131, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Bell MT"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setKerning(true);
        vendinv->setFont(font1);
        closeinv = new QPushButton(vendreinvdialog);
        closeinv->setObjectName(QStringLiteral("closeinv"));
        closeinv->setGeometry(QRect(290, 160, 131, 41));
        closeinv->setFont(font1);
        vendre = new QRadioButton(vendreinvdialog);
        vendre->setObjectName(QStringLiteral("vendre"));
        vendre->setGeometry(QRect(150, 120, 97, 20));
        ajouter = new QRadioButton(vendreinvdialog);
        ajouter->setObjectName(QStringLiteral("ajouter"));
        ajouter->setGeometry(QRect(20, 120, 97, 20));

        retranslateUi(vente);

        QMetaObject::connectSlotsByName(vente);
    } // setupUi

    void retranslateUi(QDialog *vente)
    {
        vente->setWindowTitle(QApplication::translate("vente", "Dialog", Q_NULLPTR));
        titreveninv->setText(QApplication::translate("vente", "Nombre de pieces a vendre", Q_NULLPTR));
        vendinv->setText(QApplication::translate("vente", "Vendre", Q_NULLPTR));
        closeinv->setText(QApplication::translate("vente", "Annuler", Q_NULLPTR));
        vendre->setText(QApplication::translate("vente", "Vendre", Q_NULLPTR));
        ajouter->setText(QApplication::translate("vente", "Ajouter", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class vente: public Ui_vente {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTE_H
