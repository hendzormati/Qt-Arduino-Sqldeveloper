#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "personnel.h"
#include "rfidpers.h"
#include "personnel.h"
#include "dialogp.h"
#include "modifmdp.h"
#include "mailingp.h"

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
    void on_closenotifsdf_clicked();
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

    //mayssa donation

    void on_ajouterdon_clicked();

    void on_closeajouterdon_clicked();

    void on_confirmerAjouterdon_clicked();

    void on_cindon_returnPressed();

    void on_nomdon_returnPressed();

    void on_prenomdon_returnPressed();

    void on_telephonedon_returnPressed();

    //loujain consultation

    void on_ajoutermed_clicked();

    void on_confirmerAjoutermed_clicked();

    void on_closeajoutermed_clicked();

    void on_cinpatient_activated();




















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

    //void on_closevendre_inv_clicked();

    //void on_vendreinv_clicked();

    void on_recherchedon_clicked();

    void on_homedon_clicked();

    void on_supprimer_d_clicked();

    void on_tableView_d_clicked(const QModelIndex &index);

    void on_lineEdit_recherche_returnPressed();

    void on_modifier_d_clicked();

    void on_closemodifdon_clicked();

    void on_confirmermodifdon_clicked();

private:
    Ui::MainWindow *ui;
    Personnel P;
    int currentRole;
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
};
#endif // MAINWINDOW_H