#include <QLabel>
#include <QTimer>

class TextDisplayWidget : public QLabel
{
    Q_OBJECT
public:
    explicit TextDisplayWidget(QWidget *parent = nullptr);
    void setTargetText(const QString &text);
    bool handleKeyPress(QChar key);
    int getWPM();
    int getAccuracy();
    int getTime();
    bool IsEnd();
private:
    QString m_targetText;
    QString m_formattedText;
    int m_currentPosition = 0;
    int m_formattedCurrentPosition = 0;
    int len = 0;
    int correctLen = 0;
    QTimer* m_timer;
    int m_elapsedSeconds = 0;
signals:
    void timerUpdated(int seconds);
};
