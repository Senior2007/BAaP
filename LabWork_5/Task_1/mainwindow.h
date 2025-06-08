#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <languagemanager.h>
#include <keyboard.h>
#include <textdisplay.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onLanguageChanged(int index);
    void onOpenFileClicked();

private:
    LanguageManager *m_languageManager;

    QComboBox *languageComboBox;
    QPushButton *openFileButton;
    KeyboardWidget *m_keyboardWidget;
    TextDisplayWidget *m_textDisplayWidget;
    QLabel *stats;

    void setupUI();
    void setupLanguageMenu();
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // MAINWINDOW_H
