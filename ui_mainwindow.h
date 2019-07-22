/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *labelImage;
    QLabel *label;
    QLabel *label_FrameNum;
    QLabel *label_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *pushButton_Disconnect;
    QPushButton *pushButton_CameraConnect;
    QWidget *tab_2;
    QPushButton *pushButton_SoftwareTrigger;
    QPushButton *pushButton_Inverter;
    QPushButton *pushButton_Strobe;
    QPushButton *pushButton_Gain;
    QLineEdit *lineEdit_Gain;
    QLineEdit *lineEdit_exp;
    QPushButton *pushButton_Exposure;
    QComboBox *comboBox_strobe_inverter;
    QComboBox *comboBox_strobe;
    QComboBox *comboBox_Acquisition_Mode;
    QPushButton *pushButton_Strobe_2;
    QPushButton *pushButton_Inverter_2;
    QComboBox *comboBox_trigger_mode;
    QComboBox *comboBox_trigger_source;
    QPushButton *pushButton_Inverter_3;
    QComboBox *comboBox_trigger_activation;
    QPushButton *pushButton_Inverter_4;
    QPushButton *pushButton_SendValues;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1031, 740);
        MainWindow->setStyleSheet(QLatin1String("\n"
"background-color: rgb(168, 168, 168);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        labelImage = new QLabel(centralWidget);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        labelImage->setGeometry(QRect(280, 19, 740, 640));
        labelImage->setStyleSheet(QLatin1String("background-color: rgb(216, 216, 216);\n"
"border-radius: 5px;"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(430, 680, 461, 41));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setStyleSheet(QLatin1String("background-color: rgb(180, 180, 180);\n"
"border-radius: 15px;"));
        label->setAlignment(Qt::AlignCenter);
        label_FrameNum = new QLabel(centralWidget);
        label_FrameNum->setObjectName(QStringLiteral("label_FrameNum"));
        label_FrameNum->setGeometry(QRect(170, 680, 101, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Sans Serif"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_FrameNum->setFont(font1);
        label_FrameNum->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"Sans Serif\";\n"
"border-radius: 5px;"));
        label_FrameNum->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 680, 151, 41));
        label_3->setStyleSheet(QLatin1String("\n"
"font: 14pt \"Sans Serif\";"));
        label_3->setAlignment(Qt::AlignCenter);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(5, 0, 271, 661));
        tabWidget->setStyleSheet(QStringLiteral("background-color: rgb(129, 129, 129);"));
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        pushButton_Disconnect = new QPushButton(tab);
        pushButton_Disconnect->setObjectName(QStringLiteral("pushButton_Disconnect"));
        pushButton_Disconnect->setGeometry(QRect(10, 120, 241, 41));
        pushButton_Disconnect->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"background-color: rgb(181, 181, 181);\n"
"font: 12pt \"Sans Serif\";"));
        pushButton_CameraConnect = new QPushButton(tab);
        pushButton_CameraConnect->setObjectName(QStringLiteral("pushButton_CameraConnect"));
        pushButton_CameraConnect->setGeometry(QRect(10, 40, 241, 41));
        pushButton_CameraConnect->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"font: 14pt \"Sans Serif\";\n"
"background-color: rgb(181, 181, 181);"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        pushButton_SoftwareTrigger = new QPushButton(tab_2);
        pushButton_SoftwareTrigger->setObjectName(QStringLiteral("pushButton_SoftwareTrigger"));
        pushButton_SoftwareTrigger->setGeometry(QRect(70, 350, 121, 41));
        pushButton_SoftwareTrigger->setStyleSheet(QLatin1String("\n"
"background-color: rgb(181, 181, 181);"));
        pushButton_Inverter = new QPushButton(tab_2);
        pushButton_Inverter->setObjectName(QStringLiteral("pushButton_Inverter"));
        pushButton_Inverter->setGeometry(QRect(10, 140, 121, 31));
        pushButton_Inverter->setStyleSheet(QLatin1String("\n"
"background-color: rgb(181, 181, 181);"));
        pushButton_Inverter->setCheckable(true);
        pushButton_Strobe = new QPushButton(tab_2);
        pushButton_Strobe->setObjectName(QStringLiteral("pushButton_Strobe"));
        pushButton_Strobe->setGeometry(QRect(10, 91, 121, 31));
        pushButton_Strobe->setStyleSheet(QLatin1String("\n"
"background-color: rgb(181, 181, 181);"));
        pushButton_Strobe->setCheckable(true);
        pushButton_Gain = new QPushButton(tab_2);
        pushButton_Gain->setObjectName(QStringLiteral("pushButton_Gain"));
        pushButton_Gain->setGeometry(QRect(10, 510, 121, 31));
        pushButton_Gain->setStyleSheet(QLatin1String("\n"
"background-color: rgb(181, 181, 181);"));
        lineEdit_Gain = new QLineEdit(tab_2);
        lineEdit_Gain->setObjectName(QStringLiteral("lineEdit_Gain"));
        lineEdit_Gain->setGeometry(QRect(140, 510, 111, 31));
        QFont font2;
        font2.setPointSize(16);
        lineEdit_Gain->setFont(font2);
        lineEdit_Gain->setStyleSheet(QLatin1String("background-color: rgb(244, 255, 170);\n"
"border-radius: 10px;"));
        lineEdit_exp = new QLineEdit(tab_2);
        lineEdit_exp->setObjectName(QStringLiteral("lineEdit_exp"));
        lineEdit_exp->setGeometry(QRect(140, 460, 111, 31));
        lineEdit_exp->setFont(font2);
        lineEdit_exp->setStyleSheet(QLatin1String("background-color: rgb(244, 255, 170);\n"
"border-radius: 10px;"));
        pushButton_Exposure = new QPushButton(tab_2);
        pushButton_Exposure->setObjectName(QStringLiteral("pushButton_Exposure"));
        pushButton_Exposure->setGeometry(QRect(10, 460, 121, 31));
        pushButton_Exposure->setStyleSheet(QLatin1String("\n"
"background-color: rgb(181, 181, 181);"));
        comboBox_strobe_inverter = new QComboBox(tab_2);
        comboBox_strobe_inverter->setObjectName(QStringLiteral("comboBox_strobe_inverter"));
        comboBox_strobe_inverter->setGeometry(QRect(140, 140, 111, 31));
        QFont font3;
        font3.setPointSize(9);
        comboBox_strobe_inverter->setFont(font3);
        comboBox_strobe_inverter->setLayoutDirection(Qt::LeftToRight);
        comboBox_strobe_inverter->setStyleSheet(QStringLiteral("border-radius: 10px;background-color: rgb(244, 255, 170);"));
        comboBox_strobe = new QComboBox(tab_2);
        comboBox_strobe->setObjectName(QStringLiteral("comboBox_strobe"));
        comboBox_strobe->setGeometry(QRect(140, 90, 111, 31));
        comboBox_strobe->setFont(font3);
        comboBox_strobe->setLayoutDirection(Qt::LeftToRight);
        comboBox_strobe->setStyleSheet(QStringLiteral("border-radius: 10px;background-color: rgb(244, 255, 170);"));
        comboBox_Acquisition_Mode = new QComboBox(tab_2);
        comboBox_Acquisition_Mode->setObjectName(QStringLiteral("comboBox_Acquisition_Mode"));
        comboBox_Acquisition_Mode->setGeometry(QRect(140, 40, 111, 31));
        comboBox_Acquisition_Mode->setFont(font3);
        comboBox_Acquisition_Mode->setLayoutDirection(Qt::LeftToRight);
        comboBox_Acquisition_Mode->setStyleSheet(QStringLiteral("border-radius: 10px;background-color: rgb(244, 255, 170);"));
        pushButton_Strobe_2 = new QPushButton(tab_2);
        pushButton_Strobe_2->setObjectName(QStringLiteral("pushButton_Strobe_2"));
        pushButton_Strobe_2->setGeometry(QRect(10, 41, 121, 31));
        pushButton_Strobe_2->setStyleSheet(QLatin1String("\n"
"background-color: rgb(181, 181, 181);"));
        pushButton_Strobe_2->setCheckable(true);
        pushButton_Inverter_2 = new QPushButton(tab_2);
        pushButton_Inverter_2->setObjectName(QStringLiteral("pushButton_Inverter_2"));
        pushButton_Inverter_2->setGeometry(QRect(10, 190, 121, 31));
        pushButton_Inverter_2->setStyleSheet(QLatin1String("\n"
"background-color: rgb(181, 181, 181);"));
        pushButton_Inverter_2->setCheckable(true);
        comboBox_trigger_mode = new QComboBox(tab_2);
        comboBox_trigger_mode->setObjectName(QStringLiteral("comboBox_trigger_mode"));
        comboBox_trigger_mode->setGeometry(QRect(140, 190, 111, 31));
        comboBox_trigger_mode->setFont(font3);
        comboBox_trigger_mode->setLayoutDirection(Qt::LeftToRight);
        comboBox_trigger_mode->setStyleSheet(QLatin1String("background-color: rgb(244, 255, 170);\n"
"border-radius: 10px;"));
        comboBox_trigger_source = new QComboBox(tab_2);
        comboBox_trigger_source->setObjectName(QStringLiteral("comboBox_trigger_source"));
        comboBox_trigger_source->setGeometry(QRect(140, 240, 111, 31));
        comboBox_trigger_source->setFont(font3);
        comboBox_trigger_source->setLayoutDirection(Qt::LeftToRight);
        comboBox_trigger_source->setStyleSheet(QLatin1String("background-color: rgb(244, 255, 170);\n"
"border-radius: 10px;"));
        pushButton_Inverter_3 = new QPushButton(tab_2);
        pushButton_Inverter_3->setObjectName(QStringLiteral("pushButton_Inverter_3"));
        pushButton_Inverter_3->setGeometry(QRect(10, 240, 121, 31));
        pushButton_Inverter_3->setStyleSheet(QLatin1String("\n"
"background-color: rgb(181, 181, 181);"));
        pushButton_Inverter_3->setCheckable(true);
        comboBox_trigger_activation = new QComboBox(tab_2);
        comboBox_trigger_activation->setObjectName(QStringLiteral("comboBox_trigger_activation"));
        comboBox_trigger_activation->setGeometry(QRect(140, 290, 111, 31));
        comboBox_trigger_activation->setFont(font3);
        comboBox_trigger_activation->setLayoutDirection(Qt::LeftToRight);
        comboBox_trigger_activation->setStyleSheet(QLatin1String("background-color: rgb(244, 255, 170);\n"
"border-radius: 10px;"));
        pushButton_Inverter_4 = new QPushButton(tab_2);
        pushButton_Inverter_4->setObjectName(QStringLiteral("pushButton_Inverter_4"));
        pushButton_Inverter_4->setGeometry(QRect(10, 290, 121, 31));
        pushButton_Inverter_4->setStyleSheet(QLatin1String("\n"
"background-color: rgb(181, 181, 181);"));
        pushButton_Inverter_4->setCheckable(true);
        pushButton_SendValues = new QPushButton(tab_2);
        pushButton_SendValues->setObjectName(QStringLiteral("pushButton_SendValues"));
        pushButton_SendValues->setGeometry(QRect(2, 590, 261, 41));
        pushButton_SendValues->setStyleSheet(QLatin1String("\n"
"background-color: rgb(181, 181, 181);"));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MVS", 0));
        labelImage->setText(QString());
        label->setText(QString());
        label_FrameNum->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Frame Number", 0));
        pushButton_Disconnect->setText(QApplication::translate("MainWindow", "DisConnect", 0));
        pushButton_CameraConnect->setText(QApplication::translate("MainWindow", "Connect", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Connect", 0));
        pushButton_SoftwareTrigger->setText(QApplication::translate("MainWindow", "Soft Trigger", 0));
        pushButton_Inverter->setText(QApplication::translate("MainWindow", "Strobe Inverter", 0));
        pushButton_Strobe->setText(QApplication::translate("MainWindow", "Strobe", 0));
        pushButton_Gain->setText(QApplication::translate("MainWindow", "Gain", 0));
        pushButton_Exposure->setText(QApplication::translate("MainWindow", "Exposure", 0));
        comboBox_strobe_inverter->clear();
        comboBox_strobe_inverter->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "False", 0)
         << QApplication::translate("MainWindow", "True", 0)
        );
        comboBox_strobe->clear();
        comboBox_strobe->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "True", 0)
         << QApplication::translate("MainWindow", "False", 0)
        );
        comboBox_Acquisition_Mode->clear();
        comboBox_Acquisition_Mode->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "SingleFrame", 0)
         << QApplication::translate("MainWindow", "MultiFrame", 0)
         << QApplication::translate("MainWindow", "Continuous", 0)
        );
        pushButton_Strobe_2->setText(QApplication::translate("MainWindow", "Acquisition Mode", 0));
        pushButton_Inverter_2->setText(QApplication::translate("MainWindow", "Trigger Mode", 0));
        comboBox_trigger_mode->clear();
        comboBox_trigger_mode->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "On", 0)
         << QApplication::translate("MainWindow", "Off", 0)
        );
        comboBox_trigger_source->clear();
        comboBox_trigger_source->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Line 0", 0)
         << QApplication::translate("MainWindow", "Line 1", 0)
         << QApplication::translate("MainWindow", "Line 2", 0)
         << QApplication::translate("MainWindow", "Line 3", 0)
         << QApplication::translate("MainWindow", "Counter 0", 0)
         << QApplication::translate("MainWindow", "Software", 0)
         << QApplication::translate("MainWindow", "FrequencyConverter", 0)
        );
        pushButton_Inverter_3->setText(QApplication::translate("MainWindow", "Trigger Source", 0));
        comboBox_trigger_activation->clear();
        comboBox_trigger_activation->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "RisingEdge", 0)
         << QApplication::translate("MainWindow", "FallingEdge", 0)
         << QApplication::translate("MainWindow", "LevelHigh", 0)
         << QApplication::translate("MainWindow", "LevelLow", 0)
        );
        pushButton_Inverter_4->setText(QApplication::translate("MainWindow", "Trigger Activation", 0));
        pushButton_SendValues->setText(QApplication::translate("MainWindow", "Send", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Parameters", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
