#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "serialreader.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    SerialReader reader;
    engine.rootContext()->setContextProperty("serialReader", &reader);  // ارسال SerialReader به QML

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    reader.startReading("/dev/cu.usbserial-210");  // استفاده از پورت صحیح سریال

    return app.exec();
}