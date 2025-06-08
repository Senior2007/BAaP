#ifndef LANGUAGEMANAGER_H
#define LANGUAGEMANAGER_H

#include <QObject>
#include <QHash>
#include <QString>

class LanguageManager : public QObject
{
    Q_OBJECT
public:
    explicit LanguageManager(QObject *parent = nullptr);

    QString getKeyboardLayout(const QString &language) const;
    QStringList availableLanguages() const;
    QString generateText(const QString &language) const;

private:
    void initializeLayouts();
    QHash<QString, QString> m_keyboardLayouts;
};

#endif // LANGUAGEMANAGER_H
