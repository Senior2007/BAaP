#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "polygon.h"
#include <QPoint>

class Rectangle : public Polygon {
public:
    Rectangle(const QPoint& start, const QPoint& end);
    void draw(QPainter& painter, const Shape* selectedShape) const override;
    void updatePos(QPoint diff) override;
    void scale(double scalefactor) override;
    void showInformation(QPainter& painter, int height) override;

private:
    QPoint m_end;
};

#endif // RECTANGLE_H
