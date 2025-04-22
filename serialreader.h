#ifndef SERIALREADER_H
#define SERIALREADER_H

#include <QObject>
#include <QSerialPort>

class SerialReader : public QObject
{
    Q_OBJECT

public:
    explicit SerialReader(QObject *parent = nullptr);
    void startReading(const QString &portName);

signals:
    void newDataReceived(const QString &data);  // سیگنالی که برای داده‌های جدید فرستاده می‌شود

private slots:
    void onReadyRead();  // این متد داده‌های ورودی از پورت سریال را می‌خواند

private:
    QSerialPort serial;
};

#endif // SERIALREADER_H