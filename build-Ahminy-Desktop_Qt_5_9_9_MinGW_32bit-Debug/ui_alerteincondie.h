/********************************************************************************
** Form generated from reading UI file 'alerteincondie.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALERTEINCONDIE_H
#define UI_ALERTEINCONDIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_AlerteIncondie
{
public:
    QTextBrowser *texteincondie;
    QLabel *titrealerte;
    QLabel *timerlabel;
    QPushButton *fermerincondie;

    void setupUi(QDialog *AlerteIncondie)
    {
        if (AlerteIncondie->objectName().isEmpty())
            AlerteIncondie->setObjectName(QStringLiteral("AlerteIncondie"));
        AlerteIncondie->resize(853, 450);
        AlerteIncondie->setStyleSheet(QLatin1String("/*#AlerteIncondie{background:#fbf9f9;border:8px double #f0e4e0;}*/\n"
"\n"
"#texteincondie{background:#fbf9f9;border:8px double #f0e4e0;}\n"
"\n"
"#timerlabel{color:#56695b;}\n"
"\n"
"#titrealerte{color:#56695b;}\n"
"\n"
"#fermerincondie{\n"
"color:#56695b;\n"
"border: 4px inset #dcd0c9;\n"
"border-radius: 15px;\n"
"background: #f3f2f7;\n"
"}\n"
"#fermerincondie:hover{\n"
"border: 4px outset #dcd0c9;\n"
"background: #f0e4e0;\n"
"}\n"
"#fermerincondie:pressed{\n"
"border: 4px inset #dcd0c9;\n"
"background: #f6f1f7;\n"
"}"));
        texteincondie = new QTextBrowser(AlerteIncondie);
        texteincondie->setObjectName(QStringLiteral("texteincondie"));
        texteincondie->setGeometry(QRect(0, 0, 851, 451));
        titrealerte = new QLabel(AlerteIncondie);
        titrealerte->setObjectName(QStringLiteral("titrealerte"));
        titrealerte->setGeometry(QRect(200, 0, 481, 121));
        QFont font;
        font.setFamily(QStringLiteral("Bell MT"));
        font.setPointSize(36);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        titrealerte->setFont(font);
        timerlabel = new QLabel(AlerteIncondie);
        timerlabel->setObjectName(QStringLiteral("timerlabel"));
        timerlabel->setGeometry(QRect(370, 390, 151, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial Rounded MT Bold"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        timerlabel->setFont(font1);
        fermerincondie = new QPushButton(AlerteIncondie);
        fermerincondie->setObjectName(QStringLiteral("fermerincondie"));
        fermerincondie->setGeometry(QRect(280, 350, 271, 50));
        QFont font2;
        font2.setFamily(QStringLiteral("Bell MT"));
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setWeight(75);
        font2.setKerning(true);
        fermerincondie->setFont(font2);

        retranslateUi(AlerteIncondie);

        QMetaObject::connectSlotsByName(AlerteIncondie);
    } // setupUi

    void retranslateUi(QDialog *AlerteIncondie)
    {
        AlerteIncondie->setWindowTitle(QApplication::translate("AlerteIncondie", "Dialog", Q_NULLPTR));
        texteincondie->setHtml(QApplication::translate("AlerteIncondie", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:11pt; color:#5f5f5f;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:11pt; color:#5f5f5f;\"><br /></p>\n"
""
                        "<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:11pt; color:#5f5f5f;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:11pt; color:#5f5f5f;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:11pt; color:#5f5f5f;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:11pt; color:#5f5f5f;\">\303\200 tous les membres du personnel, </span></p>\n"
"<p align=\"center\" style=\" margin-"
                        "top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:11pt; color:#5f5f5f;\"> Un incendie s'est d\303\251clar\303\251 dans la chambre affich\303\251e </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:11pt; color:#5f5f5f;\">et il est important que les occupants sortent rapidement et en toute s\303\251curit\303\251.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:11pt; color:#5f5f5f;\"> Aidez-les \303\240 \303\251vacuer le b\303\242timent en suivant les proc\303\251dures d'\303\251vacuation pr\303\251vues. </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0"
                        "px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:11pt; color:#5f5f5f;\">Veuillez \303\251galement appeler les services d'urgence et les informer de la situation. </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:11pt; color:#5f5f5f;\">Nous comptons sur votre coop\303\251ration</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:11pt; color:#5f5f5f;\"> pour garantir la s\303\251curit\303\251 de tous les occupants du centre.</span></p></body></html>", Q_NULLPTR));
        titrealerte->setText(QApplication::translate("AlerteIncondie", "Alerte Incendie !", Q_NULLPTR));
        timerlabel->setText(QString());
        fermerincondie->setText(QApplication::translate("AlerteIncondie", "Mission accomplie", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AlerteIncondie: public Ui_AlerteIncondie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALERTEINCONDIE_H
