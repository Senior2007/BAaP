#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>
#include <QPoint>
#include <QPainterPath>

class Shape {
public:
    Shape() noexcept = default;
    virtual ~Shape() = default;
    virtual void draw(QPainter& painter, const Shape* selectedShape) const = 0;
    virtual bool contains(const QPoint& point) const = 0;
    virtual void updatePos(QPoint diff) = 0;
    virtual void scale(double scalefactor) = 0;
    virtual void rotate(double angle) = 0;
    virtual void showInformation(QPainter& painter, int height) = 0;

protected:
    double S;
    double P;
    double SF = 1.0;
    double rotation = 0;
};

#endif // SHAPE_H
