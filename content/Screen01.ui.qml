/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick 6.2
import QtQuick.Controls 6.2
import BookMed

Rectangle {
    id: rectangle
    width: Constants.width
    height: Constants.height

    color: Constants.backgroundColor

    ComboBox {
        id: comboBox1
        x: 571
        y: 248
        width: 290
        height: 68
        editable: false
        displayText: "Województwo"
    }

    TextEdit {
        id: textEdit
        x: 571
        y: 136
        width: 290
        height: 41
        text: qsTr("Nazwa Świadczenia")
        font.pixelSize: 12
    }

    Switch {
        id: switch1
        x: 571
        y: 336
        text: qsTr("Świadczenie dla dzieci")
    }

    Switch {
        id: switch2
        x: 571
        y: 395
        text: qsTr("Przypadeek pilny - CITO")
    }

    ListView {
        id: listView
        x: 967
        y: 136
        width: 389
        height: 384
        model: ListModel {
            ListElement {
                name: "Grey"
                colorCode: "grey"
            }

            ListElement {
                name: "Red"
                colorCode: "red"
            }

            ListElement {
                name: "Blue"
                colorCode: "blue"
            }

            ListElement {
                name: "Green"
                colorCode: "green"
            }
        }
        delegate: Item {
            x: 5
            width: 80
            height: 40
            Row {
                id: row1
                spacing: 10
                Rectangle {
                    width: 40
                    height: 40
                    color: colorCode
                }

                Text {
                    text: name
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: true
                }
            }
        }
    }

    Button {
        id: button
        x: 571
        y: 468
        width: 290
        height: 52
        text: qsTr("Sprawdź Termin")
    }

    TextEdit {
        id: textEdit1
        x: 571
        y: 183
        width: 290
        height: 23
        text: qsTr("Miejscowość")
        font.pixelSize: 12
    }
    states: [
        State {
            name: "clicked"
        }
    ]
}
