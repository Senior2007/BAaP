#include "polygon.h"

Polygon::Polygon(QPoint center, QPoint start) : m_center(center), m_start(start) {

}

void Polygon::draw(QPainter& painter, const Shape* selectedShape) const {
}

bool Polygon::contains(const QPoint& point) const {

    QPoint pt = m_start;
    if (pt.x() == -1 && pt.y() == -1) {
        pt = m_center;
    }

    QPolygon polygon;
    for (const QPoint& vertice: vertices) {
        QPoint scaledVertice = (vertice - pt) * SF + pt;
        polygon << scaledVertice;
    }

    QTransform transform;
    transform.translate(pt.x(), pt.y());
    transform.rotate(rotation);
    transform.translate(-pt.x(), -pt.y());

    QPolygon transformedPolygon = transform.map(polygon);

    return transformedPolygon.containsPoint(point, Qt::OddEvenFill);
}

void Polygon::updatePos(QPoint diff) {

}

void Polygon::scale(double scalefactor) {

}

void Polygon::showInformation(QPainter& painter, int height) {

}

void Polygon::rotate(double angle){
    rotation += angle;
}
