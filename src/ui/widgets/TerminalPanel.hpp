#pragma once
#include <QWidget>
#include <QVBoxLayout>

class QTermWidget;

namespace Luna::UI {

class TerminalPanel : public QWidget {
    Q_OBJECT
public:
    explicit TerminalPanel(QWidget *parent = nullptr);

    void sendText(const QString &text);

public slots:
    void copyClipboard();
    void pasteClipboard();

private:
    void setupUi();
    QTermWidget *m_termWidget{nullptr};
};

}
