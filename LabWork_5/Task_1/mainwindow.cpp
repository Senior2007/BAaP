#include "mainwindow.h"
#include <QVBoxLayout>
#include <QFileDialog>
#include <QDebug>
#include <QKeyEvent>
#include <QTimer>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    m_languageManager(new LanguageManager(this)),
    m_keyboardWidget(new KeyboardWidget(this)),
    m_textDisplayWidget(new TextDisplayWidget(this))
{
    setupUI();
    setupLanguageMenu();
    m_textDisplayWidget->setTargetText("The quick brown fox jumps over the lazy dog");
}

MainWindow::~MainWindow() {}

void MainWindow::setupUI()
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    languageComboBox = new QComboBox(this);
    layout->addWidget(languageComboBox);

    openFileButton = new QPushButton("Открыть файл", this);
    layout->addWidget(openFileButton);

    languageComboBox->setStyleSheet(
        "QComboBox {"
        "   color: white;"
        "   background-color: #222222;"
        "   font: bold 16px 'Arial';"
        "   border: 2px solid #444444;"
        "   border-radius: 5px;"
        "   padding: 5px 15px;"
        "   text-align: center;"
        "   min-width: 150px;"
        "}"
        "QComboBox::down-arrow {"
        "   color: white;"
        "   width: 12px;"
        "   height: 12px;"
        "}"
        "QComboBox QAbstractItemView {"
        "   color: white;"
        "   background-color: #333333;"
        "   selection-color: #222222;"
        "   selection-background-color: #AAAAAA;"
        "   border: 1px solid #444444;"
        "}"
    );


    languageComboBox->setEditable(true);
    languageComboBox->lineEdit()->setAlignment(Qt::AlignCenter);
    languageComboBox->lineEdit()->setReadOnly(true);
    languageComboBox->lineEdit()->setFrame(false);

    openFileButton->setStyleSheet(
        "QPushButton {"
        "   color: white;"
        "   background-color: #222222;"
        "   font: bold 16px 'Arial';"
        "   border: 2px solid #444444;"
        "   border-radius: 5px;"
        "   padding: 8px 16px;"
        "   min-width: 120px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #333333;"
        "   border-color: #AAAAAA;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #111111;"
        "   border-color: #888888;"
        "}"
        );


    layout->addWidget(m_textDisplayWidget);

    layout->addWidget(m_keyboardWidget);
    m_keyboardWidget->setStyleSheet(R"(
        QWidget {
            background-color: #2b2b2b;
            border-radius: 10px;
            padding: 10px;
        }

        QPushButton {
            background-color: #3c3c3c;
            color: #ffffff;
            border: 2px solid #4a4a4a;
            border-radius: 5px;
            min-width: 40px;
            min-height: 40px;
            font-size: 16px;
            font-weight: bold;
        }

        QPushButton:hover {
            background-color: #4d4d4d;
            border-color: #5a5a5a;
        }

        QPushButton:pressed {
            background-color: #2a2a2a;
            border-color: #3a3a3a;
        }
    )");

    stats = new QLabel("Здесь будет отображена статистика", this);
    stats->setStyleSheet(
        "QLabel {"
        "   color: #f8f8f8;"
        "   font: bold 18px 'Segoe UI';"
        "   background-color: rgba(70, 50, 120, 150);"
        "   border: 2px solid #a0a0ff;"
        "   border-radius: 10px;"
        "   padding: 8px 12px;"
        "   min-width: 300px;"
        "   qproperty-alignment: 'AlignCenter';"
        "}"
        "QLabel:hover {"
        "   background-color: rgba(80, 60, 130, 180);"
        "}"
        );
    layout->addWidget(stats);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(languageComboBox, &QComboBox::currentIndexChanged, this, &MainWindow::onLanguageChanged);
    connect(openFileButton, &QPushButton::clicked, this, &MainWindow::onOpenFileClicked);

    this->setStyleSheet(
        "MainWindow {"
        "   background-image: url(/Users/senior/Desktop/BSUIR/ОАиП/QT/LabWork_5/Task_1/cosmos.jpg);"
        "   background-position: center;"
        "   background-repeat: no-repeat;"
        "}"
        );
}

void MainWindow::setupLanguageMenu()
{
    languageComboBox->clear();
    languageComboBox->addItems(m_languageManager->availableLanguages());
    const QString defaultLanguage = "English";
    languageComboBox->setCurrentText(defaultLanguage);
}

void MainWindow::onLanguageChanged(int index)
{
    QString selectedLanguage = languageComboBox->itemText(index);
    QString layout = m_languageManager->getKeyboardLayout(selectedLanguage);
    //qDebug() << "Выбран язык:" << selectedLanguage << "Раскладка:" << layout;
    m_keyboardWidget->setKeyboardLayout(layout);
    m_textDisplayWidget->setTargetText(m_languageManager->generateText(selectedLanguage));
}

void MainWindow::onOpenFileClicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Выберите файл с текстом", "", "Текстовые файлы (*.txt)");
    if (!filePath.isEmpty()) {
        qDebug() << "Выбран файл:" << filePath;
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString fileContent = in.readAll();
            file.close();
            m_textDisplayWidget->setTargetText(fileContent);
            qDebug() << "Текст загружен. Символов:" << fileContent.length();
        } else {
            return;
        }
    }
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (m_textDisplayWidget->IsEnd()) {
        stats->setText("Здесь будет отображена статистика");
        QString curLanguage = languageComboBox->currentText();
        m_textDisplayWidget->setTargetText(m_languageManager->generateText(curLanguage));
        return;
    }

    QChar key = event->text().isEmpty() ? QChar() : event->text().at(0);
    if (!key.isNull()) {
        bool IsCorrect = m_textDisplayWidget->handleKeyPress(key);
        m_keyboardWidget->highlightKey(key, IsCorrect);
    }

    if (m_textDisplayWidget->IsEnd()) {
        QString str = "Затраченное время: ";
        str += QString::number(m_textDisplayWidget->getTime());
        str += " секунд\nСкорость: ";
        str += QString::number(m_textDisplayWidget->getWPM());
        str += " символов в минуту\nТочность: " + QString::number(m_textDisplayWidget->getAccuracy()) + "%";
        stats->setText(str);
        QEventLoop loop;
        QTimer::singleShot(2000, &loop, &QEventLoop::quit);
        loop.exec(QEventLoop::ExcludeUserInputEvents | QEventLoop::ExcludeSocketNotifiers);
    }
}
