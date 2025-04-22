#include "serialreader.h"
#include <QSerialPort>
#include <QDebug>

SerialReader::SerialReader(QObject *parent)
    : QObject(parent)
{
}

void SerialReader::startReading(const QString &portName)
{
    serial.setPortName(portName);
    serial.setBaudRate(QSerialPort::Baud115200);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    if (serial.open(QIODevice::ReadOnly)) {
        qDebug() << "Serial port opened.";
    } else {
        qDebug() << "Failed to open port:" << serial.errorString();
    }

    connect(&serial, &QSerialPort::readyRead, this, &SerialReader::onReadyRead);  // اتصال سیگنال برای خواندن داده‌ها
}

void SerialReader::onReadyRead()
{
    static QString buffer;
    buffer += QString::fromUtf8(serial.readAll());

    if (buffer.count('\n') >= 3) {
        emit newDataReceived(buffer.trimmed());
        buffer.clear();
    }
}