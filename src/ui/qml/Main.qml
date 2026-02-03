import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window

ApplicationWindow {
    id: window
    visible: true
    width: 1280
    height: 800
    title: "Luna Editor"
    color: "#1e1e1e"
    
    // Frameless window flags
    flags: Qt.Window | Qt.FramelessWindowHint

    // Fullscreen toggle
    Shortcut {
        sequence: "F11"
        onActivated: window.visibility === Window.FullScreen ? window.showNormal() : window.showFullScreen()
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        Topbar {
            targetWindow: window
        }

        // Main Content Area (Original content preserved)
        SplitView {
            Layout.fillWidth: true
            Layout.fillHeight: true
            orientation: Qt.Horizontal
            
            handle: Rectangle {
                implicitWidth: 2
                color: SplitHandle.pressed ? "#007fd4" : (SplitHandle.hovered ? "#505050" : "#1e1e1e")
            }

            AiPanel {}

            CenterArea {}

            SidePanel {}

            ToolsPanel {}
        }

        StatusBar {}
    }

    ResizeHandles {
        anchors.fill: parent
        z: 1000
        targetWindow: window
    }
}
