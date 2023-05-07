#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "personnel.h"
#include "rfidpers.h"
#include "personnel.h"
#include "dialogp.h"
#include "modifmdp.h"
#include "mailingp.h"
#include "../SMTPClient/email.h"
#include "../SMTPClient/smtpclient.h"
#include "../SMTPClient/emailaddress.h"

#include "sdf.h"
#include "incondiesdf.h"
#include "dialogs.h"
#include "historique.h"
#include "alerteincondie.h"

#include "stock.h"
#include "Stock_stat.h"
#include "excel.h"
#include "arduino.h"
#include "vente.h"

#include "don.h"
#include "qrcode.h"
#include "donnation.h"

#include "fiche.h"
#include "consultation.h"
#include "dialogc.h"

#include <QMessageBox>
#include <QDebug>
#include <QList>
#include <regex>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
#include <QSystemTrayIcon>
#include <QApplication>
#include <QMainWindow>

#include <QPdfWriter>
#include <QPainter>
#include <QPrinter>
#include <QTextDocument>
#include <QtSql>
#include <QFile>
#include <QTextStream>
#include <QDate>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QChartView>
#include <QBarSeries>
#include <QBarSet>
#include <QCategoryAxis>
#include <QValueAxis>
#include <map>
using namespace QtCharts;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString get_email(){return P.get_mail_p();}
    void meileurD();
private slots:
    //LOGIN + ACCESS

    void on_showpswd_pressed();

    void on_showpswd_released();

    void on_quitlogin_clicked();

    void on_username_returnPressed();

    void on_password_returnPressed();

    void on_confirm_clicked();

    void getacces(int i);

    void on_exigo_currentChanged(int index);

    void on_tabpersonnel_currentChanged(int index);

    //hend personnel

    void on_ajouterperso_clicked();

    void on_closeajouterperso_clicked();

    void on_cinperso_returnPressed();

    void on_nomperso_returnPressed();

    void on_prenomperso_returnPressed();

    void on_femmeperso_clicked();

    void on_hommeperso_clicked();

    void on_confirmersuivantperso_clicked();


    void on_confirmerAjouterperso_clicked();

    void on_closeajouterperso2_clicked();

    void on_numtelperso_returnPressed();

    void on_mailperso_returnPressed();

    void setsalaire(int i);

    void on_metierperso_activated(int index);

    void on_precedentajouterperso2_clicked();

    void on_supprimerp_clicked();

    void clearajoutperso();

    void on_modifierp_clicked();

    void on_closemodifierperso_clicked();

    void on_confirmerModifierperso_clicked();

    bool verif_ajoutperso();

    bool verif_modifierperso();

    void on_rechercheperso_clicked();

    void on_trierp_clicked();

    void on_typetrip_activated(int index);

    void on_afficherp_clicked();

    void on_pdfp_clicked();

    void on_statp_clicked();

    void on_tableViewP_clicked(const QModelIndex &index);

    void on_rechercherper_returnPressed();

    void on_rechercherper_textEdited(const QString &arg1);

    void on_barpersonnel_activated(int index);

    void on_closestatperso_clicked();

    void on_home_p_clicked();

    void on_mailp_clicked();

    void on_ajoutrfidp_clicked();

    void on_closerfid_clicked();

    void on_lancerlescan_clicked();

    void on_cartelogin_clicked();

    void on_retour_clicked();

    void on_lancerlescanlogin_clicked();

    void on_coderfid_returnPressed();

    void sendcodemail(QString mail ,QString code,QString nomprenom );

    void onStatus(Status::e status, QString errorMessage);

    //nour acceuil

    void clear_sdf();
    void on_tableViewsdf_clicked(const QModelIndex &index);
    void on_cinsdf_returnPressed();
    void on_nomsdf_returnPressed();
    void on_prenomsdf_returnPressed();
    void on_femmesdf_clicked();
    void on_hommesdf_clicked();

    ///Metiers:
    void on_recherchesdf_clicked();
    void on_recherchersdf_returnPressed();
    void on_recherchersdf_textEdited(const QString &arg1);
    void on_homesdf_clicked();
    void on_selectrisdf_activated(int index);
    void on_triersdf_clicked();
    void on_affsdf_clicked();
    void on_statsdfsexe_clicked();
    void on_closestatsdf_clicked();
    void on_sdfnotif_clicked();
    void on_pdfsdf_clicked();
    void on_textsdf_clicked();
    void on_fichierhistorique_clicked();

    ///CRUD:
    void on_ajoutersdf_clicked();
    void on_confirmerAjoutersdf_clicked();
    void on_closeajoutersdf_clicked();
    void on_supprimersdf_clicked();
    void on_modsdf_clicked();
    void on_num_lit_currentTextChanged(const QString &arg1);
    void on_confirmerModifiersdf_clicked();
    void on_closeModifiersdf_clicked();

    void Incondie();
    void on_dialogClosed();
    //yassmine inventaire
    void on_ajouterinventaire_clicked();

    void on_closeajouterinv_clicked();

    void on_annuler_imageinv_clicked();

    void on_confirmerAjouterinv_clicked();

    void on_imageinv_2_clicked();

    void on_homeinv_clicked();

    void on_categorieinv_activated(int index);

    void on_rechercherinv_2_clicked();

    void on_suppmodifinv_textEdited(const QString &arg1);

    void on_suppmodifinv_returnPressed();

    void on_tableView_inv_clicked(const QModelIndex &index);

    void on_statinv_clicked();

    void on_closestatinv_clicked();

    void on_bilaninv_clicked();

    void on_triinv_clicked();

    void on_triinv_combo_activated(int index);

    void on_supprimerinv_clicked();

    void on_affichplus_clicked();

    void on_closeaffiche_image_inv_clicked();

    void on_modifierinv_2_clicked();

    void on_closeajouterinv_2_clicked();

    void on_categorieinv_2_activated(int index);

    void on_imageinv_3_clicked();

    void on_annuler_imageinv_2_clicked();

    void on_modifierinv_page2_clicked();

    void on_pdfinv_clicked();

    void on_vendre_inv_clicked();

    //mayssa donation

    void on_ajouterdon_clicked();

    void on_closeajouterdon_clicked();

    void on_confirmerAjouterdon_clicked();

    void on_cindon_returnPressed();

    void on_nomdon_returnPressed();

    void on_prenomdon_returnPressed();

    void on_telephonedon_returnPressed();

    void on_recherchedon_clicked();

    void on_homedon_clicked();

    void on_supprimer_d_clicked();

    void on_tableView_d_clicked(const QModelIndex &index);

    void on_lineEdit_recherche_returnPressed();

    void on_modifier_d_clicked();

    void on_closemodifdon_clicked();

    void on_confirmermodifdon_clicked();

    void on_lineEdit_recherche_textEdited(const QString &arg1);

    void on_comboBox_triDon_activated(int index);

    void on_tri_d_clicked();

    void on_stat_d_clicked();

    void on_closeqrcodedon_clicked();

    void on_qr_code_2_clicked();

    void on_don_d_clicked();

    void on_montantdon_returnPressed();

    void on_execldon_clicked();

    void on_pdf_d_clicked();

   void on_closestatdon_clicked();
    //loujain consultation

   void on_home_f_clicked();

   void on_trierf_clicked();

   void on_recherchefiche_clicked();

   void on_typetrif_activated(int index);

   void on_rechercherfiche_returnPressed();

   void on_rechercherfiche_textEdited(const QString &arg1);

   void on_ajouterfichee_clicked();

   void on_confirmerAjoutfich_clicked();

   void on_closeajoutfich_clicked();

   void clear_fiche();
   void on_closemodifich_clicked();

   void on_modiffiche_clicked();

   void on_tableViewF_clicked(const QModelIndex &index);

   void on_supprimerf_clicked();

   void on_confirmerModifich_clicked();

   void on_cinpatientfich_currentTextChanged(const QString &arg1);
   void on_consultation_clicked();

   void on_retourfiche_clicked();

   void on_home_f_2_clicked();

   void on_trierf_2_clicked();

   void on_recherchefiche_2_clicked();

   void on_typetrif_2_activated(int index);

   void on_rechercherfiche_2_returnPressed();

   void on_rechercherfiche_2_textEdited(const QString &arg1);

   void on_tableViewF_2_clicked(const QModelIndex &index);

   void on_supprimerf_2_clicked();
   void on_ajouterc_clicked();

   void on_modiffiche_2_clicked();

private:
    Ui::MainWindow *ui;
    Personnel P;
    int currentRole;
    Email createcodemail(QString,QString,QString);
    SMTPClient *client_;
    // arduino personnel
    QByteArray datapers;
    rfidpers A_per;
    bool connectardper;
    QString rfid;
    // arduino sdf
    Sdf Stmp;
    QByteArray data_sdf;
    Incondiesdf A_sdf;
    // arduino inv
    stock S1;
    QByteArray data;
    Arduino A;
    // arduino mayssa
    don D;
    excel *excelObj;
    // loujain
    fiche F;
    consultation C;
};
#endif // MAINWINDOW_H
