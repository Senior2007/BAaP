#include "textdisplay.h"

TextDisplayWidget::TextDisplayWidget(QWidget *parent)
    : QLabel(parent), m_currentPosition(0)
{
    setAlignment(Qt::AlignLeft | Qt::AlignTop);
    setWordWrap(true);
    QFont font;
    font.setFamily("Arial");
    font.setPointSize(20);
    setFont(font);

    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, [this]() {
        m_elapsedSeconds++;
        emit timerUpdated(m_elapsedSeconds);
    });
}

void TextDisplayWidget::setTargetText(const QString &text)
{
    m_targetText = text;
    m_currentPosition = m_formattedCurrentPosition = 0;
    setText(m_targetText);
    m_formattedText = m_targetText;
    len = correctLen = 0;
    m_elapsedSeconds = 0;
}

bool TextDisplayWidget::handleKeyPress(QChar key)
{
    if (m_currentPosition == 0) {
        m_elapsedSeconds = 0;
        m_timer->start(1000);
        emit timerUpdated(0);
    }
    if (m_currentPosition >= m_targetText.length()) {
        m_timer->stop();
        return 1;
    }
    bool isCorrect = (key == m_targetText.at(m_currentPosition));
    if (isCorrect && m_targetText.at(m_currentPosition) != ' ') {
        correctLen++;
    }
    if (m_targetText.at(m_currentPosition) != ' ') {
        len++;
    }

    m_formattedText.insert(m_formattedCurrentPosition + 1 , "</span>");
    m_formattedText.insert(m_formattedCurrentPosition, isCorrect ? "<span style='color:green;'>" : "<span style='color:red;'>");

    setText(m_formattedText);
    m_currentPosition++;
    while(m_formattedText[m_formattedCurrentPosition] != '/') {
        m_formattedCurrentPosition++;
    }
    while(m_formattedText[m_formattedCurrentPosition] != '>') {
        m_formattedCurrentPosition++;
    }
    m_formattedCurrentPosition++;

    return isCorrect;
}


int TextDisplayWidget::getTime() {
    return this->m_elapsedSeconds;
}

bool TextDisplayWidget::IsEnd() {
    return m_currentPosition >= m_targetText.length();
}

int TextDisplayWidget::getAccuracy() {
    return correctLen * 100 / len;
}

int TextDisplayWidget::getWPM() {
    return 60 * len / m_elapsedSeconds;
}
