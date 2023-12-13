/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWidget
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Iniciar;
    QPushButton *Finalizar;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QComboBox *comPort;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_2;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_12;
    QLabel *label_15;
    QLabel *label_14;
    QLabel *label_17;
    QLabel *label_16;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *D0;
    QPushButton *D1;
    QPushButton *D2;
    QPushButton *D3;
    QPushButton *D4;
    QPushButton *D5;
    QPushButton *D6;
    QPushButton *D7;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout;
    QLCDNumber *ADC_2;
    QLCDNumber *ADC_1;
    QLCDNumber *ADC_7;
    QLabel *label_6;
    QLCDNumber *ADC_5;
    QLabel *label;
    QLCDNumber *ADC_0;
    QLCDNumber *ADC_3;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_7;
    QLCDNumber *ADC_4;
    QLabel *label_2;
    QLCDNumber *ADC_6;
    QLabel *label_5;
    QWidget *layoutWidget4;
    QGridLayout *gridLayout_3;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QDial *dialDAC0;
    QDial *dialDAC1;
    QLCDNumber *DAC_0;
    QLCDNumber *DAC_1;
    QLabel *label_30;
    QWidget *widget;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *label_37;
    QLabel *label_38;
    QHBoxLayout *horizontalLayout_4;
    QLCDNumber *inputD0;
    QLCDNumber *inputD1;
    QLCDNumber *inputD2;
    QLCDNumber *inputD3;
    QLCDNumber *inputD4;
    QLCDNumber *inputD5;
    QLCDNumber *inputD6;
    QLCDNumber *inputD7;

    void setupUi(QWidget *mainWidget)
    {
        if (mainWidget->objectName().isEmpty())
            mainWidget->setObjectName(QString::fromUtf8("mainWidget"));
        mainWidget->resize(1008, 318);
        layoutWidget = new QWidget(mainWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 270, 681, 23));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Iniciar = new QPushButton(layoutWidget);
        Iniciar->setObjectName(QString::fromUtf8("Iniciar"));

        horizontalLayout->addWidget(Iniciar);

        Finalizar = new QPushButton(layoutWidget);
        Finalizar->setObjectName(QString::fromUtf8("Finalizar"));

        horizontalLayout->addWidget(Finalizar);

        layoutWidget1 = new QWidget(mainWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 0, 133, 24));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_3->addWidget(label_9);

        comPort = new QComboBox(layoutWidget1);
        comPort->setObjectName(QString::fromUtf8("comPort"));

        horizontalLayout_3->addWidget(comPort);

        layoutWidget2 = new QWidget(mainWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 30, 686, 51));
        gridLayout_2 = new QGridLayout(layoutWidget2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 0, 0, 1, 1);

        label_11 = new QLabel(layoutWidget2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 0, 1, 1, 1);

        label_13 = new QLabel(layoutWidget2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 0, 2, 1, 1);

        label_12 = new QLabel(layoutWidget2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 0, 3, 1, 1);

        label_15 = new QLabel(layoutWidget2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_2->addWidget(label_15, 0, 4, 1, 1);

        label_14 = new QLabel(layoutWidget2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_2->addWidget(label_14, 0, 5, 1, 1);

        label_17 = new QLabel(layoutWidget2);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_2->addWidget(label_17, 0, 6, 1, 1);

        label_16 = new QLabel(layoutWidget2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_2->addWidget(label_16, 0, 7, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        D0 = new QPushButton(layoutWidget2);
        D0->setObjectName(QString::fromUtf8("D0"));

        horizontalLayout_2->addWidget(D0);

        D1 = new QPushButton(layoutWidget2);
        D1->setObjectName(QString::fromUtf8("D1"));

        horizontalLayout_2->addWidget(D1);

        D2 = new QPushButton(layoutWidget2);
        D2->setObjectName(QString::fromUtf8("D2"));

        horizontalLayout_2->addWidget(D2);

        D3 = new QPushButton(layoutWidget2);
        D3->setObjectName(QString::fromUtf8("D3"));

        horizontalLayout_2->addWidget(D3);

        D4 = new QPushButton(layoutWidget2);
        D4->setObjectName(QString::fromUtf8("D4"));

        horizontalLayout_2->addWidget(D4);

        D5 = new QPushButton(layoutWidget2);
        D5->setObjectName(QString::fromUtf8("D5"));

        horizontalLayout_2->addWidget(D5);

        D6 = new QPushButton(layoutWidget2);
        D6->setObjectName(QString::fromUtf8("D6"));

        horizontalLayout_2->addWidget(D6);

        D7 = new QPushButton(layoutWidget2);
        D7->setObjectName(QString::fromUtf8("D7"));

        horizontalLayout_2->addWidget(D7);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 0, 1, 8);

        layoutWidget3 = new QWidget(mainWidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 80, 681, 81));
        gridLayout = new QGridLayout(layoutWidget3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        ADC_2 = new QLCDNumber(layoutWidget3);
        ADC_2->setObjectName(QString::fromUtf8("ADC_2"));

        gridLayout->addWidget(ADC_2, 1, 1, 1, 1);

        ADC_1 = new QLCDNumber(layoutWidget3);
        ADC_1->setObjectName(QString::fromUtf8("ADC_1"));

        gridLayout->addWidget(ADC_1, 1, 3, 1, 1);

        ADC_7 = new QLCDNumber(layoutWidget3);
        ADC_7->setObjectName(QString::fromUtf8("ADC_7"));

        gridLayout->addWidget(ADC_7, 1, 7, 1, 1);

        label_6 = new QLabel(layoutWidget3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 5, 1, 1);

        ADC_5 = new QLCDNumber(layoutWidget3);
        ADC_5->setObjectName(QString::fromUtf8("ADC_5"));

        gridLayout->addWidget(ADC_5, 1, 5, 1, 1);

        label = new QLabel(layoutWidget3);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        ADC_0 = new QLCDNumber(layoutWidget3);
        ADC_0->setObjectName(QString::fromUtf8("ADC_0"));

        gridLayout->addWidget(ADC_0, 1, 2, 1, 1);

        ADC_3 = new QLCDNumber(layoutWidget3);
        ADC_3->setObjectName(QString::fromUtf8("ADC_3"));

        gridLayout->addWidget(ADC_3, 1, 4, 1, 1);

        label_3 = new QLabel(layoutWidget3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 3, 1, 1);

        label_8 = new QLabel(layoutWidget3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 0, 7, 1, 1);

        label_7 = new QLabel(layoutWidget3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 6, 1, 1);

        ADC_4 = new QLCDNumber(layoutWidget3);
        ADC_4->setObjectName(QString::fromUtf8("ADC_4"));

        gridLayout->addWidget(ADC_4, 1, 6, 1, 1);

        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        ADC_6 = new QLCDNumber(layoutWidget3);
        ADC_6->setObjectName(QString::fromUtf8("ADC_6"));

        gridLayout->addWidget(ADC_6, 1, 0, 1, 1);

        label_5 = new QLabel(layoutWidget3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 4, 1, 1);

        layoutWidget4 = new QWidget(mainWidget);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(780, 20, 221, 201));
        gridLayout_3 = new QGridLayout(layoutWidget4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_18 = new QLabel(layoutWidget4);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_3->addWidget(label_18, 0, 0, 1, 1);

        label_19 = new QLabel(layoutWidget4);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_3->addWidget(label_19, 0, 1, 1, 1);

        label_20 = new QLabel(layoutWidget4);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_3->addWidget(label_20, 1, 0, 1, 1);

        label_21 = new QLabel(layoutWidget4);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_3->addWidget(label_21, 1, 1, 1, 1);

        dialDAC0 = new QDial(layoutWidget4);
        dialDAC0->setObjectName(QString::fromUtf8("dialDAC0"));

        gridLayout_3->addWidget(dialDAC0, 2, 0, 1, 1);

        dialDAC1 = new QDial(layoutWidget4);
        dialDAC1->setObjectName(QString::fromUtf8("dialDAC1"));

        gridLayout_3->addWidget(dialDAC1, 2, 1, 1, 1);

        DAC_0 = new QLCDNumber(layoutWidget4);
        DAC_0->setObjectName(QString::fromUtf8("DAC_0"));

        gridLayout_3->addWidget(DAC_0, 3, 0, 1, 1);

        DAC_1 = new QLCDNumber(layoutWidget4);
        DAC_1->setObjectName(QString::fromUtf8("DAC_1"));

        gridLayout_3->addWidget(DAC_1, 3, 1, 1, 1);

        label_30 = new QLabel(mainWidget);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(310, 170, 381, 16));
        widget = new QWidget(mainWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 190, 671, 71));
        gridLayout_5 = new QGridLayout(widget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_31 = new QLabel(widget);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        horizontalLayout_6->addWidget(label_31);

        label_32 = new QLabel(widget);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        horizontalLayout_6->addWidget(label_32);

        label_33 = new QLabel(widget);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        horizontalLayout_6->addWidget(label_33);

        label_34 = new QLabel(widget);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        horizontalLayout_6->addWidget(label_34);

        label_35 = new QLabel(widget);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        horizontalLayout_6->addWidget(label_35);

        label_36 = new QLabel(widget);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        horizontalLayout_6->addWidget(label_36);

        label_37 = new QLabel(widget);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        horizontalLayout_6->addWidget(label_37);

        label_38 = new QLabel(widget);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        horizontalLayout_6->addWidget(label_38);


        gridLayout_5->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        inputD0 = new QLCDNumber(widget);
        inputD0->setObjectName(QString::fromUtf8("inputD0"));

        horizontalLayout_4->addWidget(inputD0);

        inputD1 = new QLCDNumber(widget);
        inputD1->setObjectName(QString::fromUtf8("inputD1"));

        horizontalLayout_4->addWidget(inputD1);

        inputD2 = new QLCDNumber(widget);
        inputD2->setObjectName(QString::fromUtf8("inputD2"));

        horizontalLayout_4->addWidget(inputD2);

        inputD3 = new QLCDNumber(widget);
        inputD3->setObjectName(QString::fromUtf8("inputD3"));

        horizontalLayout_4->addWidget(inputD3);

        inputD4 = new QLCDNumber(widget);
        inputD4->setObjectName(QString::fromUtf8("inputD4"));

        horizontalLayout_4->addWidget(inputD4);

        inputD5 = new QLCDNumber(widget);
        inputD5->setObjectName(QString::fromUtf8("inputD5"));

        horizontalLayout_4->addWidget(inputD5);

        inputD6 = new QLCDNumber(widget);
        inputD6->setObjectName(QString::fromUtf8("inputD6"));

        horizontalLayout_4->addWidget(inputD6);

        inputD7 = new QLCDNumber(widget);
        inputD7->setObjectName(QString::fromUtf8("inputD7"));

        horizontalLayout_4->addWidget(inputD7);


        gridLayout_5->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        QWidget::setTabOrder(Iniciar, Finalizar);

        retranslateUi(mainWidget);
        QObject::connect(dialDAC0, SIGNAL(valueChanged(int)), label_20, SLOT(setNum(int)));
        QObject::connect(dialDAC1, SIGNAL(valueChanged(int)), label_21, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(mainWidget);
    } // setupUi

    void retranslateUi(QWidget *mainWidget)
    {
        mainWidget->setWindowTitle(QApplication::translate("mainWidget", "mainWidget", nullptr));
        Iniciar->setText(QApplication::translate("mainWidget", "CONECTAR", nullptr));
        Finalizar->setText(QApplication::translate("mainWidget", "DESCONECTAR", nullptr));
        label_9->setText(QApplication::translate("mainWidget", "Serial port:", nullptr));
        label_10->setText(QApplication::translate("mainWidget", "D0", nullptr));
        label_11->setText(QApplication::translate("mainWidget", "D1", nullptr));
        label_13->setText(QApplication::translate("mainWidget", "D2", nullptr));
        label_12->setText(QApplication::translate("mainWidget", "D3", nullptr));
        label_15->setText(QApplication::translate("mainWidget", "D4", nullptr));
        label_14->setText(QApplication::translate("mainWidget", "D5", nullptr));
        label_17->setText(QApplication::translate("mainWidget", "D6", nullptr));
        label_16->setText(QApplication::translate("mainWidget", "D7", nullptr));
        D0->setText(QApplication::translate("mainWidget", "off", nullptr));
        D1->setText(QApplication::translate("mainWidget", "off", nullptr));
        D2->setText(QApplication::translate("mainWidget", "off", nullptr));
        D3->setText(QApplication::translate("mainWidget", "off", nullptr));
        D4->setText(QApplication::translate("mainWidget", "off", nullptr));
        D5->setText(QApplication::translate("mainWidget", "off", nullptr));
        D6->setText(QApplication::translate("mainWidget", "off", nullptr));
        D7->setText(QApplication::translate("mainWidget", "off", nullptr));
        label_6->setText(QApplication::translate("mainWidget", "ADC5", nullptr));
        label->setText(QApplication::translate("mainWidget", "ADC0", nullptr));
        label_3->setText(QApplication::translate("mainWidget", "ADC2", nullptr));
        label_4->setText(QApplication::translate("mainWidget", "ADC3", nullptr));
        label_8->setText(QApplication::translate("mainWidget", "ADC7", nullptr));
        label_7->setText(QApplication::translate("mainWidget", "ADC6", nullptr));
        label_2->setText(QApplication::translate("mainWidget", "ADC1", nullptr));
        label_5->setText(QApplication::translate("mainWidget", "ADC4", nullptr));
        label_18->setText(QApplication::translate("mainWidget", "DAC0", nullptr));
        label_19->setText(QApplication::translate("mainWidget", "DAC1", nullptr));
        label_20->setText(QApplication::translate("mainWidget", "TextLabel", nullptr));
        label_21->setText(QApplication::translate("mainWidget", "TextLabel", nullptr));
        label_30->setText(QApplication::translate("mainWidget", "Digital Input", nullptr));
        label_31->setText(QApplication::translate("mainWidget", "D0", nullptr));
        label_32->setText(QApplication::translate("mainWidget", "D1", nullptr));
        label_33->setText(QApplication::translate("mainWidget", "D2", nullptr));
        label_34->setText(QApplication::translate("mainWidget", "D3", nullptr));
        label_35->setText(QApplication::translate("mainWidget", "D4", nullptr));
        label_36->setText(QApplication::translate("mainWidget", "D5", nullptr));
        label_37->setText(QApplication::translate("mainWidget", "D6", nullptr));
        label_38->setText(QApplication::translate("mainWidget", "D7", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainWidget: public Ui_mainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
