import QtQuick
import QtQuick.Controls

Rectangle {
    SplitView.preferredWidth: 50
    SplitView.minimumWidth: 40
    SplitView.maximumWidth: 60
    color: "#333333"
    
    Text {
        anchors.centerIn: parent
        text: "Tools"
        color: "#cccccc"
        rotation: 90
    }
}
