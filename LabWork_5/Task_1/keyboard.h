#ifndef KEYBOARDWIDGET_H
#define KEYBOARDWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QTimer>

class KeyboardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KeyboardWidget(QWidget *parent = nullptr);
    void setKeyboardLayout(const QString &layout);
    QList<QPushButton*> buttons();
    void highlightKey(QChar key, bool isCorrect);

private:
    QGridLayout *m_layout;
    QList<QPushButton*> m_buttons;
    void clearButtons();
};

#endif // KEYBOARDWIDGET_H
