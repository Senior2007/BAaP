#include "keyboard.h"
#include <QDebug>

KeyboardWidget::KeyboardWidget(QWidget *parent) : QWidget(parent), m_layout(new QGridLayout(this))
{
    setLayout(m_layout);
    m_layout->setSpacing(2);
}

QList<QPushButton*> KeyboardWidget::buttons() {
    return this->m_buttons;
}

void KeyboardWidget::clearButtons()
{
    for (auto button : m_buttons) {
        m_layout->removeWidget(button);
        delete button;
    }
    m_buttons.clear();
}

void KeyboardWidget::setKeyboardLayout(const QString &layout)
{
    clearButtons();

    if (layout.isEmpty()) {
        qDebug() << "Раскладка пуста!";
        return;
    }

    static const QHash<QString, QStringList> layoutTemplates = {
        {"English", {
                        "`1234567890-=",
                        " qwertyuiop[]\\",
                        " asdfghjkl;'",
                        " zxcvbnm,./"
                    }},

        {"Deutsch", {
                        "^1234567890ß´",
                        " qwertzuiopü+",
                        " asdfghjklöä#",
                        " yxcvbnm,.-"
                    }},

        {"Français", {
                          "²&é\"'(-è_çà)",
                          " azertyuiop^$",
                          " qsdfghjklmù",
                          " wxcvbn,;:!"
                      }},

        {"العربية", {
                               "ذ1234567890-=",
                               " ضصثقفغعهخحجد",
                               " شسيبلاتنمكط",
                               " ئءؤرىةوزظ"
                           }},

        {"中文", {
                       "·1234567890-=",
                       " 的一是在不了有和",
                       " 人这中大为上个国",
                       " 我以要他会来分生"
                   }},

        {"Беларуская", {
                                     "'1234567890-=",
                                     " йцукенгшўзх'\\",
                                     " фывапролджэ",
                                     " ячсмітьбю."
                                 }},

        {"עברית", {
                           ";1234567890-=",
                           " '/קראטוןםפ][",
                           " שדגכעיחלךף,",
                           " זסבהנמצתץ."
                       }}
    };


    QString layoutType = "English";
    if (layout.contains("ß")) layoutType = "Deutsch";
    else if (layout.contains("é")) layoutType = "Français";
    else if (layout.contains("ذ")) layoutType = "العربية";
    else if (layout.contains("的")) layoutType = "中文";
    else if (layout.contains("ў")) layoutType = "Беларуская";
    else if (layout.contains("ק")) layoutType = "עברית";

    QStringList rows = layoutTemplates.value(layoutType, layoutTemplates["English"]);

    for (int row = 0; row < rows.size(); ++row) {
        QString rowKeys = rows.at(row);
        for (int col = 0; col < rowKeys.length(); ++col) {
            QChar keyChar = rowKeys.at(col);
            if (keyChar == ' ') continue;

            QPushButton *button = new QPushButton(QString(keyChar), this);
            button->setFixedSize(40, 40);

            m_layout->addWidget(button, row, col);
            m_buttons.append(button);
        }
    }
}

void KeyboardWidget::highlightKey(QChar key, bool isCorrect)
{
    for (auto button : m_buttons) {
        if (button->text().compare(key, Qt::CaseInsensitive) == 0) {
            button->setStyleSheet(isCorrect ?
                                      "background-color: #4CAF50; color: white; border-color: #45a049;" :
                                      "background-color: #F44336; color: white; border-color: #d32f2f;");
            QTimer::singleShot(300, [button, this]() {
                button->setStyleSheet("");
            });
            break;
        }
    }
}
