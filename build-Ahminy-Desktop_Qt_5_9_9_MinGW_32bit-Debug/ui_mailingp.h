/********************************************************************************
** Form generated from reading UI file 'mailingp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAILINGP_H
#define UI_MAILINGP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mailingp
{
public:
    QPushButton *closeafficherperso;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *clear;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *envoyer;
    QWidget *layoutWidget_4;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLineEdit *mailE;
    QLabel *label_4;
    QLineEdit *paswd;
    QLabel *label_5;
    QComboBox *mailD;
    QLabel *label_6;
    QLineEdit *subject;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *file;
    QPushButton *browseBtn;
    QLabel *label_7;
    QPlainTextEdit *msg;
    QPushButton *closemailing;
    QPushButton *showpswd;
    QLabel *label;

    void setupUi(QDialog *mailingp)
    {
        if (mailingp->objectName().isEmpty())
            mailingp->setObjectName(QStringLiteral("mailingp"));
        mailingp->resize(530, 700);
        mailingp->setStyleSheet(QLatin1String("#mailingp{ background: #fbf9f9;;border:8px double #e6e4ea;}\n"
"QGroupBox::title { color: #968c9b; font-family: Bell MT;}\n"
"QLabel { color:#aca0b2; font-family: Bell MT; font-size: 22px;font-weight: bold;}\n"
"QLineEdit{ font-family: Bell MT;\n"
"color: #968c9b;\n"
"font-weight: bold;\n"
"font-size: 19px;\n"
"border: 3px inset #dcd0c9;\n"
"border-radius: 6px;\n"
"background-color: #fefefb;\n"
"selection-background-color: #f3f2f7;\n"
"selection-color: #968c9b;\n"
"\n"
"}\n"
"QLineEdit:hover{\n"
"border: 2px outset #dcd0c9;\n"
"background:#f3f2f7;\n"
"}\n"
"QPlainTextEdit{ font-family: Bell MT;\n"
"color: #968c9b;\n"
"font-weight: bold;\n"
"font-size: 19px;\n"
"border: 3px inset #dcd0c9;\n"
"border-radius: 6px;\n"
"background-color: #fefefb;\n"
"selection-background-color: #f3f2f7;\n"
"selection-color: #968c9b;\n"
"\n"
"}\n"
"QPlainTextEdit:hover{\n"
"border: 2px outset #dcd0c9;\n"
"background:#f3f2f7;\n"
"}\n"
"#envoyer{\n"
"color:#425180;\n"
"border: 3px inset #dcd0c9;\n"
"border-radius: 7px;\n"
"background:"
                        " #f3f2f7;\n"
"}\n"
"#envoyer:hover{\n"
"border: 3px outset #dcd0c9;\n"
"background: #e0dfe5;\n"
"}\n"
"#envoyer:pressed{\n"
"border: 3px inset #dcd0c9;\n"
"background: #f6f1f7;\n"
"}\n"
"#clear{\n"
"color:#425180;\n"
"border: 3px inset #dcd0c9;\n"
"border-radius: 7px;\n"
"background: #f3f2f7;\n"
"}\n"
"#clear:hover{\n"
"border: 3px outset #dcd0c9;\n"
"background: #e0dfe5;\n"
"}\n"
"#clear:pressed{\n"
"border: 3px inset #dcd0c9;\n"
"background: #f6f1f7;\n"
"}\n"
"#browseBtn{\n"
"color:#425180;\n"
"border: 3px inset #dcd0c9;\n"
"border-radius: 7px;\n"
"background: #f3f2f7;\n"
"}\n"
"#browseBtn:hover{\n"
"border: 3px outset #dcd0c9;\n"
"background: #e0dfe5;\n"
"}\n"
"#browseBtn:pressed{\n"
"border: 3px inset #dcd0c9;\n"
"background: #f6f1f7;\n"
"}\n"
"#mailD{ \n"
" font-family: Bell MT;\n"
"color: #968c9b;\n"
"font-weight: bold;\n"
"font-size: 20px;\n"
"border: 2px solid #dcd0c9;\n"
"border-radius: 7px;\n"
"}\n"
"#mailD QAbstractItemView{ \n"
" font-family: Bell MT;\n"
"color: #968c9b;\n"
"font-weight: bold;\n"
""
                        "font-size: 20px;\n"
"selection-background-color: #f3f2f7;\n"
"selection-color: #968c9b;\n"
"}\n"
"\n"
"\n"
""));
        closeafficherperso = new QPushButton(mailingp);
        closeafficherperso->setObjectName(QStringLiteral("closeafficherperso"));
        closeafficherperso->setGeometry(QRect(940, 10, 40, 40));
        closeafficherperso->setStyleSheet(QLatin1String("#closeafficherperso{\n"
"border-image: url(:/images/closep1.png);\n"
"}\n"
"#closeafficherperso:hover{\n"
"border-image: url(:/images/closep2.png);\n"
"}\n"
"#closeafficherperso:pressed{\n"
"border-image: url(:/images/closep2.png);\n"
"}"));
        layoutWidget_2 = new QWidget(mailingp);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(130, 590, 260, 54));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_6->setSpacing(9);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 10, 0, 10);
        clear = new QPushButton(layoutWidget_2);
        clear->setObjectName(QStringLiteral("clear"));
        clear->setMinimumSize(QSize(100, 34));
        clear->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_6->addWidget(clear);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        envoyer = new QPushButton(layoutWidget_2);
        envoyer->setObjectName(QStringLiteral("envoyer"));
        envoyer->setMinimumSize(QSize(100, 34));
        envoyer->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_6->addWidget(envoyer);

        layoutWidget_4 = new QWidget(mailingp);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(20, 100, 481, 451));
        formLayout = new QFormLayout(layoutWidget_4);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        formLayout->setRowWrapPolicy(QFormLayout::WrapLongRows);
        formLayout->setVerticalSpacing(9);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_4);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        mailE = new QLineEdit(layoutWidget_4);
        mailE->setObjectName(QStringLiteral("mailE"));
        mailE->setMinimumSize(QSize(0, 35));

        formLayout->setWidget(0, QFormLayout::FieldRole, mailE);

        label_4 = new QLabel(layoutWidget_4);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        paswd = new QLineEdit(layoutWidget_4);
        paswd->setObjectName(QStringLiteral("paswd"));
        paswd->setMinimumSize(QSize(0, 35));
        paswd->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, paswd);

        label_5 = new QLabel(layoutWidget_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font;
        font.setFamily(QStringLiteral("Bell MT"));
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        mailD = new QComboBox(layoutWidget_4);
        mailD->setObjectName(QStringLiteral("mailD"));
        mailD->setMinimumSize(QSize(330, 35));
        mailD->setFont(font);

        formLayout->setWidget(2, QFormLayout::FieldRole, mailD);

        label_6 = new QLabel(layoutWidget_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);

        subject = new QLineEdit(layoutWidget_4);
        subject->setObjectName(QStringLiteral("subject"));
        subject->setMinimumSize(QSize(0, 35));

        formLayout->setWidget(3, QFormLayout::FieldRole, subject);

        label_8 = new QLabel(layoutWidget_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_8);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        file = new QLineEdit(layoutWidget_4);
        file->setObjectName(QStringLiteral("file"));
        file->setEnabled(true);
        file->setMinimumSize(QSize(0, 30));
        file->setFont(font);
        file->setReadOnly(true);

        horizontalLayout_3->addWidget(file);

        browseBtn = new QPushButton(layoutWidget_4);
        browseBtn->setObjectName(QStringLiteral("browseBtn"));
        browseBtn->setMinimumSize(QSize(0, 25));

        horizontalLayout_3->addWidget(browseBtn);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout_3);

        label_7 = new QLabel(layoutWidget_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_7);

        msg = new QPlainTextEdit(layoutWidget_4);
        msg->setObjectName(QStringLiteral("msg"));
        msg->setMaximumSize(QSize(330, 200));

        formLayout->setWidget(5, QFormLayout::FieldRole, msg);

        closemailing = new QPushButton(mailingp);
        closemailing->setObjectName(QStringLiteral("closemailing"));
        closemailing->setGeometry(QRect(460, 20, 40, 40));
        closemailing->setStyleSheet(QLatin1String("#closemailing{\n"
"border-image: url(:/images/closep1.png);\n"
"}\n"
"#closemailing:hover{\n"
"border-image: url(:/images/closep2.png);\n"
"}\n"
"#closemailing:pressed{\n"
"border-image: url(:/images/closep2.png);\n"
"}"));
        showpswd = new QPushButton(mailingp);
        showpswd->setObjectName(QStringLiteral("showpswd"));
        showpswd->setGeometry(QRect(462, 148, 30, 30));
        showpswd->setStyleSheet(QLatin1String("#showpswd{border-image:url(:/images/hideM.png) ;}\n"
"#showpswd:pressed{border-image:url(:/images/showM.png) ;}"));
        label = new QLabel(mailingp);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(171, 31, 201, 31));
        label->setFont(font);

        retranslateUi(mailingp);

        QMetaObject::connectSlotsByName(mailingp);
    } // setupUi

    void retranslateUi(QDialog *mailingp)
    {
        mailingp->setWindowTitle(QApplication::translate("mailingp", "Ahminy", Q_NULLPTR));
        closeafficherperso->setText(QString());
        clear->setText(QApplication::translate("mailingp", "Rafra\303\256chir", Q_NULLPTR));
        envoyer->setText(QApplication::translate("mailingp", "Envoyer", Q_NULLPTR));
        label_3->setText(QApplication::translate("mailingp", "E-mail:", Q_NULLPTR));
        label_4->setText(QApplication::translate("mailingp", "Mot De Passe:", Q_NULLPTR));
        paswd->setInputMask(QString());
        label_5->setText(QApplication::translate("mailingp", "Destinataire:", Q_NULLPTR));
        label_6->setText(QApplication::translate("mailingp", "Objet:", Q_NULLPTR));
        label_8->setText(QApplication::translate("mailingp", "Attachement:", Q_NULLPTR));
        browseBtn->setText(QApplication::translate("mailingp", "Ajouter...", Q_NULLPTR));
        label_7->setText(QApplication::translate("mailingp", "Contenu:", Q_NULLPTR));
        closemailing->setText(QString());
        showpswd->setText(QString());
        label->setText(QApplication::translate("mailingp", "Nouveau Message", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mailingp: public Ui_mailingp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAILINGP_H
