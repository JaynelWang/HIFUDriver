#include <QApplication>
#include <QQmlContext>
#include <QQuickItem>
#include <QQuickView>
#include "login.h"
#include "tablemodel.h"
#include "mainwindow.h"
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QQuickWindow>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QMetaObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login login;

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/LoginWindow.qml")));
    QQuickView main_viewer(QUrl(QStringLiteral("qrc:/MainWindow.qml")));
    QQuickView patient_viewer(QUrl(QStringLiteral("qrc:/PatientDetail.qml")));
    QQuickView newPatient_viewer(QUrl(QStringLiteral("qrc:/NewPatient.qml")));
    QQuickView doctor_viewer(QUrl(QStringLiteral("qrc:/DoctorDetail.qml")));
    QQuickView newDoctor_viewer(QUrl(QStringLiteral("qrc:/NewDoctor.qml")));
    main_viewer.rootContext()->setContextProperty("PatientModel",login.m_model_Pt);
    main_viewer.rootContext()->setContextProperty("DoctorModel",login.m_model_Dr);
    patient_viewer.rootContext()->setContextProperty("TPModel",login.m_model_TP);
    patient_viewer.rootContext()->setContextProperty("w",&login.w);

    QObject* rootObject_login = engine.rootObjects().value(0);
    QMetaObject::invokeMethod(rootObject_login,"generateColor");
    QQuickItem *rootObject_main = main_viewer.rootObject();
    QQuickItem *rootObject_patient = patient_viewer.rootObject();
    QQuickItem *rootObject_newPt = newPatient_viewer.rootObject();
    QQuickItem *rootObject_doctor = doctor_viewer.rootObject();
    QQuickItem *rootObject_newDr = newDoctor_viewer.rootObject();

    //login
    QObject::connect(rootObject_login,SIGNAL(btnLoginClicked(QString,QString)),&login,SLOT(checkInfo(QString,QString)));
    QObject::connect(&login,SIGNAL(showResult(QVariant,QVariant)),rootObject_login,SLOT(showResultMsg(QVariant,QVariant)));
    QObject::connect(rootObject_login,SIGNAL(shutLoginQml()),&main_viewer,SLOT(show()));
    QObject::connect(rootObject_login,SIGNAL(authorize()),rootObject_doctor,SLOT(authorizeResult()));
    //patient
    QObject::connect(rootObject_main,SIGNAL(getSearchTextChanged_Pt(int,QString)),&login,SLOT(updatePtSearchList(int,QString)));
    QObject::connect(rootObject_main,SIGNAL(getDelete_Pt(int)),&login,SLOT(deletePtRow(int)));
    QObject::connect(rootObject_main,SIGNAL(getAdd_Pt()),&newPatient_viewer,SLOT(show()));
    QObject::connect(rootObject_main,SIGNAL(showPatientDetailTab(int)),&patient_viewer,SLOT(show()));
    QObject::connect(rootObject_main,SIGNAL(showPatientDetailTab(int)),&login,SLOT(getPatientBasic(int)));
    QObject::connect(rootObject_main,SIGNAL(showPatientDetailTab(int)),&login,SLOT(getPatientTreatment(int)));
    QObject::connect(rootObject_newPt,SIGNAL(addNewPt(QString,QString,QString,QString,QString,QString,QString)),&login,SLOT(addPtRow(QString,QString,QString,QString,QString,QString,QString)));
    QObject::connect(&login,SIGNAL(closeNewPt()),&newPatient_viewer,SLOT(close()));
    QObject::connect(&login,SIGNAL(showPatientBasic(QVariant,QVariant,QVariant,QVariant,QVariant,QVariant,QVariant,QVariant)),rootObject_patient,SLOT(showBasicInfo(QVariant,QVariant,QVariant,QVariant,QVariant,QVariant,QVariant,QVariant)));
    QObject::connect(&login,SIGNAL(showPatientTS(QVariant,QVariant,QVariant,QVariant,QVariant,QVariant,QVariant,QVariant)),rootObject_patient,SLOT(showTreatmentSession(QVariant,QVariant,QVariant,QVariant,QVariant,QVariant,QVariant,QVariant)));
    QObject::connect(&login,SIGNAL(clearPatientTS()),rootObject_patient,SLOT(clearTreatmentSession()));
    QObject::connect(rootObject_patient,SIGNAL(changeCommit(QString,QString,QString,QString,QString,QString,QString,QString)),&login,SLOT(changePtRow(QString,QString,QString,QString,QString,QString,QString,QString)));
    //doctor
    QObject::connect(rootObject_main,SIGNAL(getSearchTextChanged_Dr(int,QString)),&login,SLOT(updateDrSearchList(int,QString)));
    QObject::connect(rootObject_main,SIGNAL(getDelete_Dr(int)),&login,SLOT(deleteDrRow(int)));
    QObject::connect(rootObject_main,SIGNAL(getAdd_Dr()),&newDoctor_viewer,SLOT(show()));
    QObject::connect(rootObject_main,SIGNAL(showDoctorDetailTab(int)),&doctor_viewer,SLOT(show()));
    QObject::connect(rootObject_main,SIGNAL(showDoctorDetailTab(int)),&login,SLOT(getDoctorBasic(int)));
    QObject::connect(rootObject_main,SIGNAL(showDoctorDetailTab(int)),&login,SLOT(getDoctorLogin(int)));
    QObject::connect(rootObject_newDr,SIGNAL(addNewDr(QString,QString,QString,QString,QString,QString,QString,QString)),&login,SLOT(addDrRow(QString,QString,QString,QString,QString,QString,QString,QString)));
    QObject::connect(&login,SIGNAL(closeNewDr()),&newDoctor_viewer,SLOT(close()));
    QObject::connect(&login,SIGNAL(showDoctorBasic(QVariant,QVariant,QVariant,QVariant,QVariant,QVariant,QVariant,QVariant)),rootObject_doctor,SLOT(showBasicInfo(QVariant,QVariant,QVariant,QVariant,QVariant,QVariant,QVariant,QVariant)));
    QObject::connect(&login,SIGNAL(showDoctorLogin(QVariant,QVariant,QVariant)),rootObject_doctor,SLOT(showLoginInfo(QVariant,QVariant,QVariant)));
    QObject::connect(rootObject_doctor,SIGNAL(basicChangeCommit(QString,QString,QString,QString,QString,QString,QString,QString,QString)),&login,SLOT(changeDrBasicRow(QString,QString,QString,QString,QString,QString,QString,QString,QString)));
    QObject::connect(rootObject_doctor,SIGNAL(loginChangeCommit(QString,QString,QString)),&login,SLOT(changeDrLoginRow(QString,QString,QString)));

    QObject::connect(&main_viewer,SIGNAL(closing(QQuickCloseEvent*)),&patient_viewer,SLOT(close()));
    QObject::connect(&main_viewer,SIGNAL(closing(QQuickCloseEvent*)),&doctor_viewer,SLOT(close()));
    QObject::connect(rootObject_patient,SIGNAL(startTreatment()),&patient_viewer,SLOT(close()));
    QObject::connect(rootObject_patient,SIGNAL(startTreatment()),&main_viewer,SLOT(close()));

//    login_viewer.show();
//    main_viewer.show();
    return a.exec();
}
