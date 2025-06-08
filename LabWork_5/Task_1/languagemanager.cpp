#include "languagemanager.h"

LanguageManager::LanguageManager(QObject *parent) : QObject(parent)
{
    initializeLayouts();
}

QString LanguageManager::getKeyboardLayout(const QString &language) const
{
    return m_keyboardLayouts.value(language, "");
}

QStringList LanguageManager::availableLanguages() const
{
    return m_keyboardLayouts.keys();
}

void LanguageManager::initializeLayouts()
{
    m_keyboardLayouts["English"] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    m_keyboardLayouts["Deutsch"] = "^1234567890ß´qwertzuiopü+asdfghjklöä#<yxcvbnm,.-";
    m_keyboardLayouts["Français"] = "²&é\"'(-è_çà)azertyuiop^$qsdfghjklmù*wxcvbn,;:!";
    m_keyboardLayouts["العربية"] = "ذ1234567890-=ضصثقفغعهخحجد\\شسيبلاتنمكطئءؤرىةوزظ";
    m_keyboardLayouts["中文"] = "1234567890-=的一是在不了有和人这中大为上个国我以要他会来分生";
    m_keyboardLayouts["Беларуская"] = "'1234567890-=йцукенгшўзх\\фывапролджэячсмітьбю";
    m_keyboardLayouts["עברית"] = ";1234567890-=/'קראטוןםפ][\\שדגכעיחלךף,זסבהנמצתץ.";
}

QString LanguageManager::generateText(const QString &language) const {
    QString answer = "";
    int len = arc4random() % 20 + 1;
    for (int i = 0; i < len; i++) {
        int curLen = arc4random() % 8 + 1;
        while(curLen--) {
            int pos = arc4random() % m_keyboardLayouts[language].size();
            QChar c = m_keyboardLayouts[language][pos];
            if ((c >= '0' && c <= '9') || c == '/' || c == '[' || c == ']' || c == '<' || c == '>' || c == '='
              || c == '\\' || c == '`' || c == '\'' || c == '#' || c == '-' || c == '+' || c == ';' || c == '^') {
                curLen++;
                continue;
            }
            answer += c;
        }
        if (i != len - 1)
            answer += ' ';
    }

    return answer;
}
