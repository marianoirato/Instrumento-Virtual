#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "serialthread.h"
#include <QDateTime>

/*El constructor de MainWindow inicializa la ventana principal y crea la interfaz gráfica.*/
mainWidget::mainWidget(QWidget *parent) : QWidget(parent) , ui(new Ui::mainWidget),
    mSerialThread(nullptr)
{
    ui->setupUi(this);

    inicializarUI();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &mainWidget::callAppendDataToListWidget);
    timer->start(250); // Delay para refrescar el display
}

/* El destructor de MainWindow se encarga de detener el hilo SerialReaderThread y liberar
   recursos al cerrar la aplicación.*/
mainWidget::~mainWidget(){
    if(mSerialThread){
        mSerialThread->requestInterruption();
        mSerialThread->wait();
        delete mSerialThread;
    }
    delete ui;
}

void mainWidget::inicializarUI(){
    // Configurar y crear el hilo del lector serie con el puerto serie seleccionado
    QList<QSerialPortInfo> portList = QSerialPortInfo::availablePorts();  // Se lista los puertos disponibles
    for(int i = 0; i < portList.size(); ++i){
        const QSerialPortInfo &port = portList.at(i);
        ui->comPort->addItem(port.portName());
    }

    // Inicialización de los displays de los ADC
    adcDisplays[0] = ui->ADC_0;
    adcDisplays[1] = ui->ADC_1;
    adcDisplays[2] = ui->ADC_2;
    adcDisplays[3] = ui->ADC_3;
    adcDisplays[4] = ui->ADC_4;
    adcDisplays[5] = ui->ADC_5;
    adcDisplays[6] = ui->ADC_6;
    adcDisplays[7] = ui->ADC_7;

    // Inicialización de los displays de los DAC
    dacDisplays[0] = ui->DAC_0;
    dacDisplays[1] = ui->DAC_1;

    // Inicialización de los display para los valores de entrada digital
    digitalInputDisplay[0] = ui->inputD0;
    digitalInputDisplay[1] = ui->inputD1;
    digitalInputDisplay[2] = ui->inputD2;
    digitalInputDisplay[3] = ui->inputD3;
    digitalInputDisplay[4] = ui->inputD4;
    digitalInputDisplay[5] = ui->inputD5;
    digitalInputDisplay[6] = ui->inputD6;
    digitalInputDisplay[7] = ui->inputD7;


    // Botones para las salidas digitales
    for(int i = 0; i < 8; i++){
        QPushButton *button = findChild<QPushButton*>("D" + QString::number(i));

        buttons.append(button);

        QStateMachine *machine = new QStateMachine(this);

        QState *off = new QState();
        off->assignProperty(button, "text", "0");
        off->setObjectName("0");

        QState *on = new QState();
        on->setObjectName("1");
        on->assignProperty(button, "text", "1");

        off->addTransition(button, &QPushButton::clicked, on);
        on->addTransition(button, &QPushButton::clicked, off);

        machine->addState(off);
        machine->addState(on);

        machine->setInitialState(off);
        machine->start();

        machines.append(machine);
    }

    // Setea el valor minimo de 0 a 4095, 12 bits
    ui->dialDAC0->setMinimum(0); // Set the minimum value
    ui->dialDAC0->setMaximum(4095); // Set the maximum value
    ui->dialDAC1->setMinimum(0); // Set the minimum value
    ui->dialDAC1->setMaximum(4095); // Set the maximum value
}

// Con el boton de inicio (conectar) se incializa el hilo lector y se lista los puertos y se toma el que esta abierto
void mainWidget::on_Iniciar_clicked(){
    if(!mSerialThread){
        QString selectedPort = ui->comPort->currentText();
        mSerialThread = new serialThread(selectedPort, this);

        mSerialThread->start();
    }else
        qDebug() << "No se pudo conectar con el puerto.";
}


/* Con el boton de finalizar (desconectar) se cierra el puerto y limpia el plainText.*/
void mainWidget::on_Finalizar_clicked(){
    if(mSerialThread){
        mSerialThread->requestInterruption();
        mSerialThread->wait();
        delete mSerialThread;
        mSerialThread = nullptr;
    }
}

void mainWidget::callAppendDataToListWidget(){
    static QDateTime lastDateTime = QDateTime::currentDateTime();

    if(mSerialThread){
        QDateTime currentDateTime = QDateTime::currentDateTime();

        if(lastDateTime.msecsTo(currentDateTime) >= 250){
            lastDateTime = currentDateTime;

            displayADCAndDACValues();
            displayDigitalInValues();
            sendData();
        }
    }
}

void mainWidget::displayADCAndDACValues(){
    for(int i = 0; i < 8; i++)
        adcDisplays[i]->display(adc_value[i]);

    for(int i = 0; i < 2; i++)
        dacDisplays[i]->display(dac_value[i]);
}

void mainWidget::displayDigitalInValues(){
    bool* value = mSerialThread->printDigitalIn();  // Se obtienen los valores de las entradas digitales

    for(int i = 0; i < 8; i ++)
        digitalInputDisplay[i] -> display(*(value+i)); // Se muestran los valores en los displays
}

void mainWidget::sendData(){
    readyToSendData = false;

    uint8_t* buttonValues = readButtons();

    if(readyToSendData && mSerialThread){
        mSerialThread->readButtonValue(buttonValues);
    }

    uint16_t valueDAC0 = setValueDAC(0);

    if(readyToSendData && mSerialThread){
        mSerialThread->readDialDAC(valueDAC0, 0);
    }

    uint16_t valueDAC1 = setValueDAC(1);

    if(readyToSendData && mSerialThread){
        mSerialThread->readDialDAC(valueDAC1, 1);
    }
}

uint8_t* mainWidget::readButtons() {
    static uint8_t buttonValues[8] = {0};
    static uint8_t previousButtonValues[8] = {0};
    bool buttonValuesChanged = false;

    for (int i = 0; i < 8; i++) {
        bool isOn = buttons[i]->property("text").toString() == "1";
        buttonValues[i] = isOn ? 1 : 0;
    }

    for (int i = 0; i < 8; i++) {
        if (buttonValues[i] != previousButtonValues[i]) {
            buttonValuesChanged = true;
            break;
        }
    }

    // Update the previous button values
    for (int i = 0; i < 8; i++) {
        previousButtonValues[i] = buttonValues[i];
    }

    if (buttonValuesChanged && mSerialThread) {
        readyToSendData = true;
        return buttonValues;
    }else{
        readyToSendData = false;
        return previousButtonValues;
    }

    return 0;
}

uint16_t mainWidget::setValueDAC(uint8_t num_dac){
    uint16_t valueD0 = ui->dialDAC0->value();
    uint16_t valueD1 = ui->dialDAC1->value();
    static uint16_t previousValueD0 = 0;
    static uint16_t previousValueD1 = 0;

    if( num_dac == 0 ){
        if(valueD0 != previousValueD0){ // Si el valor del DAC cambio, entonces se envía la trama por serial
            readyToSendData = true;
            previousValueD0 = valueD0;
            return valueD0;
        }else{
            readyToSendData = false;    // Si no cambio el valor, entonces no se envía nada
            return previousValueD0;
        }
    } else {
        if(valueD1 != previousValueD1){
            readyToSendData = true;
            previousValueD1 = valueD1;
            return valueD1;
        }else{
            readyToSendData = false;
            return previousValueD1;
        }
    }

    return 0;
}

