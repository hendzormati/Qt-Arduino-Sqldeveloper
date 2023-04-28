/********************************************************************************
** Form generated from reading UI file 'historique.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORIQUE_H
#define UI_HISTORIQUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Historique
{
public:
    QTextBrowser *Historiquetext;

    void setupUi(QDialog *Historique)
    {
        if (Historique->objectName().isEmpty())
            Historique->setObjectName(QStringLiteral("Historique"));
        Historique->resize(471, 584);
        Historique->setStyleSheet(QLatin1String("#Historiquetext{\n"
"color: #696969;\n"
"background:#fbf9f9;\n"
"border:8px double #f0e4e0;\n"
"font-family: Arial;\n"
"font-size: 12pt;\n"
"font-weight: bold;\n"
"\n"
"}\n"
"\n"
""));
        Historiquetext = new QTextBrowser(Historique);
        Historiquetext->setObjectName(QStringLiteral("Historiquetext"));
        Historiquetext->setGeometry(QRect(0, 0, 471, 581));

        retranslateUi(Historique);

        QMetaObject::connectSlotsByName(Historique);
    } // setupUi

    void retranslateUi(QDialog *Historique)
    {
        Historique->setWindowTitle(QApplication::translate("Historique", "Dialog", Q_NULLPTR));
        Historiquetext->setHtml(QApplication::translate("Historique", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:12pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400;\"><br /></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Historique: public Ui_Historique {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORIQUE_H
