import QtQuick
import QtQuick.Layouts

Rectangle {
    Layout.fillWidth: true
    Layout.preferredHeight: 22
    Layout.minimumHeight: 22
    Layout.maximumHeight: 22
    color: "#007fd4"
    
    Text {
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.verticalCenter: parent.verticalCenter
        text: "Ready"
        color: "white"
        font.pointSize: 9
    }
}
