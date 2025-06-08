#include "hanoimover.h"
#include <QPainter>
#include <QTimer>

HanoiMover::HanoiMover(QWidget *parent) : QWidget(parent), currentMoveIndex(0) {
    timer.setInterval(1000);
    connect(&timer, &QTimer::timeout, this, &HanoiMover::nextMove);
}

void HanoiMover::draw(int n, const QVector<std::pair<int, int>>& moves) {
    numRings = n;
    moveList = moves;
    currentMoveIndex = 0;
    initializeTowers(n);
    timer.start();
}

void HanoiMover::initializeTowers(int n) {
    towers.clear();
    towers.resize(3);
    towers[0].clear();
    for (int i = n; i >= 1; --i) {
        towers[0].push_back(i);
    }
    towers[1].clear();
    towers[2].clear();
}

void HanoiMover::moveRing(int from, int to) {
    if (towers[from - 1].isEmpty()) return;
    int ring = towers[from - 1].back();
    towers[from - 1].pop_back();
    towers[to - 1].push_back(ring);
    update();
}

void HanoiMover::nextMove() {
    if (currentMoveIndex >= moveList.size()) {
        timer.stop();
        return;
    }
    auto move = moveList[currentMoveIndex++];
    moveRing(move.first, move.second);
}

void HanoiMover::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    drawTowers(painter);
}

void HanoiMover::drawTowers(QPainter &painter) {
    int towerWidth = width() / 4;
    int ringHeight = 20;
    int baseY = height() - 100;

    for (int i = 0; i < 3; ++i) {
        int towerX = (i + 1) * towerWidth;
        painter.drawLine(towerX, baseY, towerX, baseY - numRings * ringHeight);
    }

    for (int i = 0; i < 3; ++i) {
        int towerX = (i + 1) * towerWidth;
        for (int j = 0; j < towers[i].size(); ++j) {
            int ringSize = towers[i][j] * 10;
            int ringY = baseY - (j + 1) * ringHeight;
            painter.setBrush(Qt::blue);
            painter.drawRect(towerX - ringSize / 2, ringY, ringSize, ringHeight);
        }
    }
}
