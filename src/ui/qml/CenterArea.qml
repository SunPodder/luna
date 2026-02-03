import QtQuick
import QtQuick.Controls

SplitView {
    SplitView.fillWidth: true
    orientation: Qt.Vertical
    
    handle: Rectangle {
        implicitHeight: 2
        color: SplitHandle.pressed ? "#007fd4" : (SplitHandle.hovered ? "#505050" : "#1e1e1e")
    }

    // Main Editor Area
    Rectangle {
        SplitView.fillHeight: true
        color: "#1e1e1e"
        
        Text {
            anchors.centerIn: parent
            text: "Main Editor Area"
            color: "#808080"
            font.pixelSize: 20
        }
    }

    // Terminal
    Rectangle {
        SplitView.preferredHeight: 200
        SplitView.minimumHeight: 50
        color: "#1e1e1e"
        
        Rectangle { 
            // Top border simulation
            width: parent.width
            height: 1
            color: "#333333"
            anchors.top: parent.top
        }

        Text {
            anchors.centerIn: parent
            text: "Terminal"
            color: "#cccccc"
        }
    }
}
