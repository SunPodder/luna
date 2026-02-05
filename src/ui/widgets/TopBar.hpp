#pragma once
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

namespace Luna::UI {

class TopBar : public QWidget {
    Q_OBJECT
public:
    explicit TopBar(QWidget *parent = nullptr);

signals:
    void minimizeClicked();
    void maximizeClicked();
    void closeClicked();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;

private:
    void setupUi();
    QPushButton* createBtn(const QString &text, const QString &id, const QString &hoverColor = "#505050", const QString &pressColor = "#505050");

    QLabel *m_titleLabel{nullptr};
    QPushButton *m_minimizeBtn{nullptr};
    QPushButton *m_maximizeBtn{nullptr};
    QPushButton *m_closeBtn{nullptr};
    
    QPoint m_dragPosition;
};

}
