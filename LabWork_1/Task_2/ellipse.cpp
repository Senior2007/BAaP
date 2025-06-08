#include "ellipse.h"
#include <QPainter>

Ellipse::Ellipse(const QPoint& center, int radiusX, int radiusY): m_center(center), m_radiusX(radiusX), m_radiusY(radiusY) {
    S = M_PI * radiusX * radiusY;
    P = M_PI * (3 * (radiusX + radiusY) - sqrt((3 * radiusX + radiusY) * (radiusX + 3 * radiusY)));
}

void Ellipse::scale(double factor) {
    if(SF * factor > 10) SF = 10;
    else if(SF * factor < 0.1) SF = 0.1;
    else SF *= factor;

    S = M_PI * m_radiusX * m_radiusY * SF * SF;
    P = M_PI * (3 * (m_radiusX * SF + m_radiusY * SF) - sqrt((3 * m_radiusX * SF + m_radiusY * SF) * (m_radiusX * SF + 3 * m_radiusY * SF)));
}

void Ellipse::draw(QPainter& painter, const Shape* selectedShape) const {
    painter.save();
    painter.translate(m_center); // Перемещаем начало координат в центр фигуры
    painter.rotate(rotation);
    painter.translate(-m_center);

    bool pr = false;

    if (selectedShape == this) {
        painter.setPen(Qt::green);
        pr = true;
    } else {
        painter.setPen(Qt::black);
    }

    painter.setBrush(Qt::lightGray);
    painter.drawEllipse(m_center.x() - m_radiusX * SF, m_center.y() - m_radiusY * SF, 2 * m_radiusX * SF, 2 * m_radiusY * SF);

    if (pr) {
        painter.setBrush(Qt::black);
        painter.drawEllipse(m_center, 3, 3);
    }

    painter.restore();
}

bool Ellipse::contains(const QPoint& point) const {
    QPainterPath path;
    double R1 = m_radiusX, R2 = m_radiusY;
    path.addEllipse(-R1, -R2, R1 * 2, R2 * 2);

    QTransform transform;
    transform.translate(m_center.x(), m_center.y());
    transform.scale(SF, SF);
    transform.rotate(rotation);

    // Применяем трансформацию к пути
    QPainterPath transformedPath = transform.map(path);

    return transformedPath.contains(point);
}

void Ellipse::updatePos(QPoint diff) {
    m_center += diff;
}

void Ellipse::showInformation(QPainter& painter, int height) {

    painter.setPen(Qt::white);
    QRect rect(20, height - 43, 100, 20);
    painter.drawText(rect, Qt::AlignLeft, QString("P: ") + QString::number(P, 'f', 2));

    QRect rect2(20, height - 22, 100, 20);
    painter.drawText(rect2, Qt::AlignLeft, QString("S: ") + QString::number(S, 'f', 2));

    QRect rect3(142, height - 22, 100, 20);
    painter.drawText(rect3, Qt::AlignLeft, QString("Угол: ") + QString::number(-this->rotation, 'f', 2));

    QRect rect4(118, height - 43, 100, 20);
    painter.drawText(rect4, Qt::AlignLeft, QString("Маcштаб: ") + QString::number(SF, 'f', 2));


    QRect rect5(250, height - 22, 100, 20);
    painter.drawText(rect5, Qt::AlignLeft, QString("ЦМ X: ") + QString::number(m_center.x(), 'f', 2));

    QRect rect6(250, height - 43, 100, 20);
    painter.drawText(rect6, Qt::AlignLeft, QString("ЦМ Y: ") + QString::number(m_center.y(), 'f', 2));
}

void Ellipse::rotate(double angle){
    rotation += angle;
    //if (rotation >= 360) rotation -= 360;
    //if (rotation < 0) rotation += 360;
}
