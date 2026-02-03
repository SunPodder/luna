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

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        // Topbar
        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 35
            Layout.minimumHeight: 35
            Layout.maximumHeight: 35
            color: "#3c3c3c"
            
            Text {
                anchors.centerIn: parent
                text: "Luna Editor - Topbar"
                color: "#cccccc"
                font.pointSize: 10
            }
        }

        // Main Content Area
        SplitView {
            Layout.fillWidth: true
            Layout.fillHeight: true
            orientation: Qt.Horizontal
            
            handle: Rectangle {
                implicitWidth: 2
                color: SplitHandle.pressed ? "#007fd4" : (SplitHandle.hovered ? "#505050" : "#1e1e1e")
            }

            // AI Panel (Left)
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

            // Center Area: Editor + Terminal
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
                    // border.top: 1 Removed invalid property
                    
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

            // Sidepanel (Right)
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

            // Tools (Far Right)
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
        }

        // Bottom status bar
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
    }
}
