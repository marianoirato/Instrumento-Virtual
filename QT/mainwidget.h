/*#########################################################################################*/
/*##                                    Head principal                                   ##*/
/*##-------------------------------------------------------------------------------------##*/
/*## Es la cabecera principal del pgrogama y representa a la clase padre del sistema.    ##*/
/*## Dentro de la clase mainWidget se tiene declarado los botones de Inicio, Fin y una   ##*/
/*## Lista en donde se imprimirá lo recibido por el puerto serie, a su vez se almacenará ##*/
/*## lo recibidio para su posterior comparacion.                                         ##*/
/*#########################################################################################*/


#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QStateMachine>
#include <QState>
#include <QtWidgets>
#include "serialthread.h"

/* La clase MainWindow es una ventana de la interfaz gráfica principal de la aplicación.
   También hereda de QWidget. Contiene varios elementos de la interfaz de usuario,
   incluyendo botones y una lista para mostrar datos.*/

QT_BEGIN_NAMESPACE
namespace Ui { class mainWidget; }
QT_END_NAMESPACE


class mainWidget : public QWidget
{
    Q_OBJECT

public:
    mainWidget(QWidget *parent = nullptr);  // Constructor
    ~mainWidget();                          // Destructor

    // slot privados, propio de los widget
private slots:
    void inicializarUI();
    void on_Iniciar_clicked();
    void on_Finalizar_clicked();
    void displayADCAndDACValues();
    void sendData();
    void callAppendDataToListWidget();
    uint8_t* readButtons();
    uint16_t setValueDAC(uint8_t);
    void displayDigitalInValues();

    // variables propias de la clase
private:
    Ui::mainWidget *ui;             // Puntero tipo mainWidget
    serialThread *mSerialThread;    // Puntero de la clase serialThread
    QTimer *timer;
    QList<QPushButton*> buttons;
    QList<QStateMachine*> machines;
    QLCDNumber* adcDisplays[8];
    QLCDNumber* dacDisplays[2];
    QLCDNumber* digitalInputDisplay[8];
    bool readyToSendData;
};

#endif // MAINWIDGET_H
