import QtQuick
import QtQuick.Window

Item {
    id: root
    // We expect this to be anchored to fill the window
    
    // The window instance to control
    property var targetWindow: Window.window

    // Left
    MouseArea {
        width: 5
        anchors { left: parent.left; top: parent.top; bottom: parent.bottom }
        anchors.topMargin: 5; anchors.bottomMargin: 5
        cursorShape: Qt.SizeHorCursor
        onPressed: root.targetWindow.startSystemResize(Qt.LeftEdge)
    }
    // Right
    MouseArea {
        width: 5
        anchors { right: parent.right; top: parent.top; bottom: parent.bottom }
        anchors.topMargin: 5; anchors.bottomMargin: 5
        cursorShape: Qt.SizeHorCursor
        onPressed: root.targetWindow.startSystemResize(Qt.RightEdge)
    }
    // Top
    MouseArea {
        height: 5
        anchors { top: parent.top; left: parent.left; right: parent.right }
        anchors.leftMargin: 5; anchors.rightMargin: 5
        cursorShape: Qt.SizeVerCursor
        onPressed: root.targetWindow.startSystemResize(Qt.TopEdge)
    }
    // Bottom
    MouseArea {
        height: 5
        anchors { bottom: parent.bottom; left: parent.left; right: parent.right }
        anchors.leftMargin: 5; anchors.rightMargin: 5
        cursorShape: Qt.SizeVerCursor
        onPressed: root.targetWindow.startSystemResize(Qt.BottomEdge)
    }
    // Top-Left Corner
    MouseArea {
        width: 5; height: 5
        anchors { top: parent.top; left: parent.left }
        cursorShape: Qt.SizeFDiagCursor
        onPressed: root.targetWindow.startSystemResize(Qt.TopEdge | Qt.LeftEdge)
    }
    // Top-Right Corner
    MouseArea {
        width: 5; height: 5
        anchors { top: parent.top; right: parent.right }
        cursorShape: Qt.SizeBDiagCursor
        onPressed: root.targetWindow.startSystemResize(Qt.TopEdge | Qt.RightEdge)
    }
    // Bottom-Left Corner
    MouseArea {
        width: 5; height: 5
        anchors { bottom: parent.bottom; left: parent.left }
        cursorShape: Qt.SizeBDiagCursor
        onPressed: root.targetWindow.startSystemResize(Qt.BottomEdge | Qt.LeftEdge)
    }
    // Bottom-Right Corner
    MouseArea {
        width: 5; height: 5
        anchors { bottom: parent.bottom; right: parent.right }
        cursorShape: Qt.SizeFDiagCursor
        onPressed: root.targetWindow.startSystemResize(Qt.BottomEdge | Qt.RightEdge)
    }
}
