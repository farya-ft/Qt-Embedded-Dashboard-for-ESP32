import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 600
    title: "Sensor Dashboard"

    ListModel {
        id: sensorModel
        ListElement { name: "Temperature"; value: "Waiting..."; status: "UNKNOWN" }
        ListElement { name: "Humidity"; value: "Waiting..."; status: "UNKNOWN" }
        ListElement { name: "Pressure"; value: "Waiting..."; status: "UNKNOWN" }
    }

    ListView {
        anchors.fill: parent
        anchors.margins: 20
        model: sensorModel
        spacing: 12
        delegate: Rectangle {
            width: parent.width
            height: 100 // تنظیم ارتفاع برای هر عنصر
            radius: 16
            color: status === "OK" ? "#e8f5e9" :
                   status === "WARNING" ? "#fff8e1" :
                   "#ffebee"
            border.color: "#cfd8dc"
            border.width: 1

            Row {
                anchors.centerIn: parent
                spacing: 20

                Column {
                    spacing: 4
                    Text {
                        text: name
                        font.bold: true
                        font.pointSize: 14
                        color: "#37474f"
                    }
                    Text {
                        text: value + (name === "Humidity" ? "%" : " °C")
                        font.pointSize: 12
                        color: "#455a64"
                    }
                    Text {
                        text: "Status: " + status
                        font.pointSize: 11
                        color: "#78909c"
                    }
                }
            }
        }
    }

   Connections {
    target: serialReader
    function onNewDataReceived(data) {
        const lines = data.split('\n');
        for (var i = 0; i < lines.length; i++) {
            var line = lines[i].trim();
            if (line.startsWith("Temperature:")) {
                var value = line.split(":")[1].trim();
                sensorModel.setProperty(0, "value", value + " °C");
                sensorModel.setProperty(0, "status", "OK");
            } else if (line.startsWith("Humidity:")) {
                var value = line.split(":")[1].trim();
                sensorModel.setProperty(1, "value", value + " %");
                sensorModel.setProperty(1, "status", "OK");
            } else if (line.startsWith("Pressure:")) {
                var value = line.split(":")[1].trim();
                sensorModel.setProperty(2, "value", value + " hPa");
                sensorModel.setProperty(2, "status", "OK");
            }
        }
    }
}
}