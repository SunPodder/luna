import QtQuick
import QtQuick.Controls

Rectangle {
    SplitView.preferredWidth: 250
    SplitView.minimumWidth: 50
    color: "#252526"
    
    Text {
        anchors.centerIn: parent
        text: "Sidepanel"
        color: "#cccccc"
    }
}
