import QtQuick
import QtQuick.Layouts
import QtQuick.Window

Rectangle {
    id: root
    Layout.fillWidth: true
    Layout.preferredHeight: 35
    Layout.minimumHeight: 35
    Layout.maximumHeight: 35
    color: "#3c3c3c"
    
    property var targetWindow: Window.window
    
    // Drag Area (Title Bar)
    MouseArea {
        anchors.fill: parent
        // Allow clicking through to buttons which are on top in z-order
        onPressed: root.targetWindow.startSystemMove()
        onDoubleClicked: {
            if (root.targetWindow.visibility === Window.Maximized)
                root.targetWindow.showNormal()
            else
                root.targetWindow.showMaximized()
        }
    }
    
    Text {
        anchors.centerIn: parent
        text: "Luna Editor - Topbar"
        color: "#cccccc"
        font.pointSize: 10
    }

    // Window Controls
    Row {
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: 135 // 3 buttons * 45px

        // Minimize
        Rectangle {
            width: 45
            height: parent.height
            color: maMin.containsMouse ? "#505050" : "transparent"
            Text { 
                text: "─"
                anchors.centerIn: parent
                color: "white"
                font.pixelSize: 12
            }
            MouseArea {
                id: maMin
                anchors.fill: parent
                hoverEnabled: true
                onClicked: root.targetWindow.showMinimized()
            }
        }

        // Maximize/Restore
        Rectangle {
            width: 45
            height: parent.height
            color: maMax.containsMouse ? "#505050" : "transparent"
            Text { 
                text: root.targetWindow.visibility === Window.Maximized ? "❐" : "☐" 
                anchors.centerIn: parent
                color: "white" 
                font.pixelSize: 12
            }
            MouseArea {
                id: maMax
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    if (root.targetWindow.visibility === Window.Maximized)
                        root.targetWindow.showNormal()
                    else
                        root.targetWindow.showMaximized()
                }
            }
        }

        // Close
        Rectangle {
            width: 45
            height: parent.height
            color: maClose.containsMouse ? "#e81123" : "transparent"
            Text { 
                text: "✕"
                anchors.centerIn: parent
                color: "white" 
                font.pixelSize: 12
            }
            MouseArea {
                id: maClose
                anchors.fill: parent
                hoverEnabled: true
                onClicked: root.targetWindow.close()
            }
        }
    }
}
