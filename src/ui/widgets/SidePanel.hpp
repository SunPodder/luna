#pragma once
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QMap>

namespace Luna::UI {

class SidePanel : public QWidget {
    Q_OBJECT
public:
    explicit SidePanel(QWidget *parent = nullptr);
    void setContent(const QString& toolName);

private:
    void setupUi();
    void setupPages();
    QWidget* createFilesWidget();
    QWidget* createPlaceholderWidget(const QString& name);

    QStackedWidget* m_stack;
    QMap<QString, QWidget*> m_pages;
};

}
