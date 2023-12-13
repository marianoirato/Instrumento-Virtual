/*#########################################################################################*/
/*##                                    Head del hijo                                    ##*/
/*##-------------------------------------------------------------------------------------##*/
/*## Esta cabecera pertenece a la clase hija, la cual se encarga de gestionar un hilo de ##*/
/*## trabajo que recibe por puerto serie los datos que se le envia y luego pasarlos      ##*/
/*## al padre para poder imprimir en pantralla lo recibido y almacenarlo.                ##*/
/*## El manejo de hilos permite trabajar con datos en paralelo sin tener que detener     ##*/
/*## procesos principales del propio script como son en este caso los botones y pantalla ##*/
/*## los hilos procesan los datos y luego los libera para la rama principal.             ##*/
/*## esto se logra con el uso de la libreria <QThread> y su funcion void run() override  ##*/
/*## la cual dentro de la misma se coloca lo que se quiere ejecutar en el hilo.          ##*/
/*## se puede utilizar multiples hilos, y en ese caso se recomienda el uso de <QMutex>   ##*/
/*## para bloquear datos y evitar interferencia entre dos hilos que quieran usarlo       ##*/
/*#########################################################################################*/

#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

//Librerias del proyecto
#include <QObject>
#include <QApplication>
#include <QtSerialPort/QSerialPort> //Serial port
#include <QtSerialPort/QSerialPortInfo>
#include <QMutex>   // Bloqueo de datos
#include <QThread>  // Manejo de hilos
#include <QtDebug>  // Imprimir datos en consola
#include <QFile>    // Guardado de datos en archivos
#include <QTextStream> // manejo de datos en los archivos
#include <QString>
#include <QTimer>
#include <QDial>

void sleepForNanoseconds(long nanoseconds);

/*
 * Se definen una estructura frame_t para almacenar los datos de cada trama y
 * una unión charFrame_t que permite interpretar esos datos como un arreglo
 * de caracteres (char) para facilitar la lectura en archivos binarios. Esta
 * misma estructura se utiliza en el script de C utilizado para crear el archivo
 * a enviar por puerto serie.
*/
typedef struct
{
    // Byte de inicio.
    uint8_t header;
    // Contador.
    uint8_t counter;
    // 8 entradas analógicas (12 bits).
    uint8_t adc_frames[12];
    // 8 entradas digitales.
    uint8_t digital_in;
    // 8 salidas digitales.
    uint8_t digital_out;
    // 2 salidas analógicas.
    uint8_t dac_frames[3];
    // CRC
    uint8_t crc;
} frame_entrada;

// 8 entradas analógicas (12 bits).
extern uint16_t adc_value[8];
// 2 salidas analógicas.
extern uint16_t dac_value[2];
extern uint16_t n;

/* Esta es una unión llamada charFrame_t que se utiliza para interpretar los
   datos de la estructura datos_procesados tanto como una estructura completa (tramaEntrada)
   como una matriz de caracteres (tramaEntradaChar). Esta unión se utiliza para
   manipular los datos en diferentes formatos.
*/
typedef union
{
    frame_entrada tramaEntrada;
    char          tramaEntradaChar[20];
} charFrame_t;

/* Clase llamada SerialReaderThread, que hereda de QThread. Esta clase se utiliza para
   leer datos desde un puerto serie en un hilo separado. Se configura para que cuando
   se reciban datos, emita una señal dataReceived que enviará la estructura charFrame_t
   con los datos.
*/
class serialThread : public QThread //Clase serialThread para el puerto serie
{
    Q_OBJECT

public:
    serialThread(const QString& portName, QObject* parent = nullptr); // Constructor
    ~serialThread();                                                  // Destructor
    void run() override;
    void setAdc_Dac_Values();
    uint8_t valid_crc();
    void readButtonValue(uint8_t*);
    void readDialDAC(int, int);
    bool* printDigitalIn();

signals:
    /* Esta es una señal que se emite cuando se reciben datos en el hilo SerialReaderThread.
       La señal lleva como argumento la estructura charFrame_t que contiene los datos recibidos.*/
    void dataReceived(const charFrame_t &data);

private:
    QSerialPort *serialPort; // Puntero para serialPort
    QByteArray data;        // Para recibir por puerto serie
    QByteArray tramaSalida;
    QTimer *clearBufferTimer;

    const uint8_t num_adc = 8;
    const uint8_t num_dac = 2;
    const uint8_t num_dac_frames = 3;
    const uint16_t num_promedios = 50;
    const uint8_t numSalidasDigitales = 8;
    // Define la posicion del adc en la cadena
    uint8_t position_adc_frame = 2;
    // Define la posicion del dac en la cadena
    uint8_t position_dac_frame = 16;

    // Trama
    const uint8_t header = 0x1b;
    uint8_t counter = 0;
    uint8_t valorSalidasDigitales = 0;
    uint8_t DAC[3] = {0};

    void readDataFromSerial();
    void clearBuffer();
    void printDataInHex();
    void printTramaSalidaInHex();
    void sendDataOverSerial();
};

#endif // SERIALTHREAD_H


