import QtQuick
import QtQuick.Controls

Rectangle {
    SplitView.preferredWidth: 250
    SplitView.minimumWidth: 100
    color: "#252526"
    
    Text {
        anchors.centerIn: parent
        text: "AI PANEL"
        color: "#cccccc"
        font.bold: true
    }
}
