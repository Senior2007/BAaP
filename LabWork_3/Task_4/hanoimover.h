#ifndef HANOIMOVER_H
#define HANOIMOVER_H

#include <QWidget>
#include <QVector>
#include <QTimer>
#include <QPainter>

class HanoiMover : public QWidget
{
    Q_OBJECT

public:
    explicit HanoiMover(QWidget *parent = nullptr);
    void draw(int n, const QVector<std::pair<int, int>>& moves);

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void nextMove();

private:
    int numRings;
    QVector<std::pair<int, int>> moveList;
    int currentMoveIndex;
    QVector<QVector<int>> towers;
    QTimer timer;

    void initializeTowers(int n);
    void moveRing(int from, int to);
    void drawTowers(QPainter &painter);
};

#endif // HANOIMOVER_H
