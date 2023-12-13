#include "serialthread.h"

/* El constructor de SerialReaderThread inicializa la instancia de la clase.
   Recibe el nombre del puerto serie al que se conectará y crea una instancia
   de QSerialPort configurada con la velocidad de baudios y otros parámetros.*/

uint16_t adc_value[8];
uint16_t dac_value[2];
uint16_t n = 0;

serialThread::serialThread(const QString& portName, QObject* parent) :
    QThread(parent), serialPort(new QSerialPort(portName))
{
    //Configuracion del puerto serie
    serialPort->setBaudRate(QSerialPort::Baud115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    // Registrar el tipo de metadatos charFrame_t para su manejo en QT
    qRegisterMetaType<charFrame_t>("charFrame_t");
}

/* El destructor de SerialReaderThread se encarga de cerrar el puerto serie si está abierto
   y eliminar la instancia de QSerialPort cuando el objeto se destruye.*/
serialThread::~serialThread(){
    if (serialPort->isOpen()) {
        serialPort->close();
    }
    delete serialPort;
}

/* Este método es el punto de entrada del hilo SerialReaderThread. Aquí se configura el puerto
   serie y se inicia la lectura de datos desde el puerto serie. Cuando se reciben datos, se
   emite la señal dataReceived para que otros objetos puedan procesarlos.*/
void serialThread::run() {
    if (!serialPort->open(QIODevice::ReadWrite)) {   // Si no se puede abrir el puerto serie
        qDebug() << "No se pudo abrir el puerto serie" << serialPort->portName()
                 << ":" << serialPort->errorString();
        return;
    }
    qDebug() << "Conectado al puerto serie" << serialPort->portName();

    while (!isInterruptionRequested()) {
        readDataFromSerial();
    }
}

void serialThread::readDataFromSerial() {
    charFrame_t charData;

    // Wait for data with a timeout of 10 milliseconds
    if (serialPort->waitForReadyRead(10)) {
        // Check the number of bytes available to read
        if (serialPort->bytesAvailable() >= sizeof(frame_entrada)) {
            data.resize(sizeof(frame_entrada));
            int bytesRead = serialPort->read(data.data(), sizeof(frame_entrada)); // Read the frame

            if (bytesRead == sizeof(frame_entrada) && valid_crc() && static_cast<unsigned char>(data.at(0)) == 0x1b) {
                setAdc_Dac_Values(); // Convert the adc and dac values to 12 bits
                memcpy(charData.tramaEntradaChar, data.constData(), sizeof(frame_entrada));

                //printDataInHex();
            }else
                clearBuffer();
        }else
            clearBuffer();
    }else
        clearBuffer();

    usleep(1);
}

void serialThread::sendDataOverSerial(){
    static uint8_t counter = 0x00;

    tramaSalida.clear();
    tramaSalida = QByteArray(); // Reset the QByteArray
    tramaSalida.reserve(7);     // Definimos la trama de 7 bytes

    // Header
    tramaSalida.append(header);

    // Counter
    tramaSalida.append(counter);

    // ValorBoton
    tramaSalida.append(valorSalidasDigitales);

    // DAC
    for(int i = 0; i < num_dac_frames; i++){
        tramaSalida.append(DAC[i]);
    }

    // CRC
    tramaSalida.append(0x01);

    // Send tramaSalida over serial
    if(serialPort->isOpen()) {
        serialPort->write(tramaSalida);
        counter++;

        printTramaSalidaInHex();
    }

    if ( counter >= 255 )
        counter = 0;
}

// Convierte los valores del adc y dac a 12 bits
void serialThread::setAdc_Dac_Values(){
    // Define la posicion del adc en la cadena
    uint8_t position_adc_frame = 2;
    // Define la posicion del dac en la cadena
    uint8_t position_dac_frame = 16;


    for(uint8_t i = 0; i < num_adc; i++)
    {
        if(i % 2 == 0){
            adc_value[i] = (static_cast<uint16_t>(data.at(position_adc_frame)) << 4) | (((static_cast<uint16_t>(data.at(position_adc_frame+1))) >> 4) & 0x0F);
            adc_value[i] = adc_value[i] & 0x0FFF;
        }
        else{
            adc_value[i] = ((static_cast<uint16_t>(data.at(position_adc_frame)) & 0x0F) << 8) | (static_cast<uint16_t>(data.at(position_adc_frame+1) & 0xFF));
            adc_value[i] = adc_value[i] & 0x0FFF;
            position_adc_frame += 1;
        }

        position_adc_frame += 1;
    }

    for(uint8_t i = 0; i < num_dac; i++)
    {
        if(i % 2 == 0){
            dac_value[i] = (static_cast<uint16_t>(data.at(position_dac_frame)) << 4) | (((static_cast<uint16_t>(data.at(position_dac_frame+1))) >> 4) & 0x0F);
            dac_value[i] = dac_value[i] & 0x0FFF;
        }
        else{
            dac_value[i] = ((static_cast<uint16_t>(data.at(position_dac_frame)) & 0x0F) << 8) | (static_cast<uint16_t>(data.at(position_dac_frame+1) & 0xFF));
            dac_value[i] = dac_value[i] & 0x0FFF;
            position_dac_frame += 1;
        }

        position_dac_frame += 1;
    }
}

void serialThread::readButtonValue(uint8_t* arrayBotones){
    valorSalidasDigitales = 0;

    for (int i = 0; i < numSalidasDigitales; i++ ) {
        uint8_t invertedValue = ~arrayBotones[i];

        // Use the inverted value to set the bits in valorSalidasDigitales
        valorSalidasDigitales |= (invertedValue & 0x01) << i;
    }

    sendDataOverSerial();
}

void serialThread::readDialDAC(int value, int numDAC){
    if(numDAC == 0){
        DAC[0] = static_cast<uint8_t>(((value) >> 4) & 0xFF);
        DAC[1] = (static_cast<uint8_t>((value) & 0x0F) << 4) | (DAC[1] & 0x0F);
    }else if(numDAC == 1){
        DAC[1] = (DAC[1] & 0xF0) | static_cast<uint8_t>(((value) >> 8) & 0x0F);
        DAC[2] = static_cast<uint8_t>((value) & 0xFF);
    }else{
        qDebug() << "ERROR.";
    }

    sendDataOverSerial();
}

uint8_t serialThread::valid_crc(){
    // Polinomio generador CRC-8 (0x07)
    const uint8_t polinomio_generador = 0x07;
    // definimos la posicion del crc en la cadena
    const uint8_t position_crc = 19;

    // Inicializa el registro CRC en cero
    uint8_t registro_crc = 0;

    if(data.size() == sizeof(frame_entrada)){
        for (uint8_t i = 0; i < sizeof(frame_entrada) - 1; i++){
            registro_crc ^= static_cast<uint8_t>(data.at(i));

            for (uint8_t j = 0; j < 8; j++) {
                if (registro_crc & 0x80) {
                    registro_crc = (registro_crc << 1) ^ polinomio_generador;
                } else {
                    registro_crc <<= 1;
                }
            }
        }

        if(registro_crc == static_cast<uint8_t>(data.at(position_crc))){
            return 1;
        }else{
            return 0;
        }
    }

    return 1;
}

void serialThread::printDataInHex(){
    // Print the received data in hexadecimal
    QString hexData = "Received data in hex: ";

    for (uint16_t i = 0; i < sizeof(frame_entrada); i++) {
        hexData += QString::number(static_cast<unsigned char>(data.at(i)), 16).rightJustified(2, '0').toUpper() + " ";
    }

    qDebug().noquote() << hexData;
}

void serialThread::printTramaSalidaInHex(){
    // Print tramaSalida in hexadecimal
    QString hexData = "Sent data in hex: ";
    for (int i = 0; i < tramaSalida.size(); i++) {
        hexData += QString::number(static_cast<unsigned char>(tramaSalida.at(i)), 16).rightJustified(2, '0').toUpper() + " ";
    }
    qDebug().noquote() << hexData;
}

bool* serialThread::printDigitalIn() {
    uint8_t positionDigitalIn = 14;
    uint8_t value = static_cast<uint8_t>(data.at(positionDigitalIn));

    // Create an array to store individual bits
    static bool bits[8];

    for (int i = 0; i < 8; ++i) {
        bits[i] = (value >> i) & 1;
    }

    return bits;
}

void serialThread::clearBuffer() {
    if (serialPort->isOpen()) {
        serialPort->clear();
    }
}

