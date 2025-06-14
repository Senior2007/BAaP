#include "mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QAction>
#include <QFrame>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
    m_canvas(new Canvas(this)),
    m_btnMenu(new QToolButton(this)),
    m_shapeMenu(new QMenu(this)),
    m_btnClear(new QPushButton("Очистить", this))
{
    setWindowTitle("Paint");
    resize(800, 600);

    m_btnMenu->setText("Меню");
    m_btnMenu->setFixedSize(100, 30);
    m_btnMenu->setPopupMode(QToolButton::InstantPopup);

    QAction* actionCircle = new QAction("Круг", this);
    QAction* actionEllipse = new QAction("Эллипс", this);
    QAction* actionSquare = new QAction("Квадрат", this);
    QAction* actionRectangle = new QAction("Прямоугольник", this);
    QAction* actionTriangle = new QAction("Треугольник", this);
    QAction* actionRhomb = new QAction("Ромб", this);
    QAction* actionHexagon = new QAction("Шестиугольник", this);
    QAction* actionStar5 = new QAction("Пятиконечная звезда", this);
    QAction* actionStar6 = new QAction("Шестиконечная звезда", this);
    QAction* actionStar8 = new QAction("Восьмиконечная звезда", this);
    QAction* actionMoving = new QAction("Перемещение", this);
    m_shapeMenu->addAction(actionCircle);
    m_shapeMenu->addAction(actionEllipse);
    m_shapeMenu->addAction(actionSquare);
    m_shapeMenu->addAction(actionRectangle);
    m_shapeMenu->addAction(actionTriangle);
    m_shapeMenu->addAction(actionRhomb);
    m_shapeMenu->addAction(actionHexagon);
    m_shapeMenu->addAction(actionStar5);
    m_shapeMenu->addAction(actionStar6);
    m_shapeMenu->addAction(actionStar8);
    m_shapeMenu->addAction(actionMoving);
    m_btnMenu->setMenu(m_shapeMenu);

    m_btnClear->setFixedSize(100, 35);

    QWidget* topPanel = new QWidget(this);
    QHBoxLayout* topLayout = new QHBoxLayout(topPanel);
    topLayout->setContentsMargins(0, 10, 10, 0);
    topLayout->addStretch();
    topLayout->addWidget(m_btnClear);
    topLayout->addWidget(m_btnMenu);

    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    mainLayout->addWidget(topPanel);
    mainLayout->addWidget(m_canvas, 1); // stretch factor = 1s

    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    connect(actionCircle, &QAction::triggered, this, &MainWindow::selectCircle);
    connect(actionEllipse, &QAction::triggered, this, &MainWindow::selectEllipse);
    connect(actionSquare, &QAction::triggered, this, &MainWindow::selectSquare);
    connect(actionRectangle, &QAction::triggered, this, &MainWindow::selectRectangle);
    connect(actionTriangle, &QAction::triggered, this, &MainWindow::selectTriangle);
    connect(actionRhomb, &QAction::triggered, this, &MainWindow::selectRhomb);
    connect(actionHexagon, &QAction::triggered, this, &MainWindow::selectHexagon);
    connect(actionStar5, &QAction::triggered, this, &MainWindow::selectStar5);
    connect(actionStar6, &QAction::triggered, this, &MainWindow::selectStar6);
    connect(actionStar8, &QAction::triggered, this, &MainWindow::selectStar8);
    connect(actionMoving, &QAction::triggered, this, &MainWindow::selectMoving);
    connect(m_btnClear, &QPushButton::clicked, this, &MainWindow::clearShapes);
}

void MainWindow::selectCircle() {
    m_canvas->setShapeType(Canvas::CircleType);
    m_btnMenu->setText("Круг");
}

void MainWindow::selectEllipse() {
    m_canvas->setShapeType(Canvas::EllipseType);
    m_btnMenu->setText("Эллипс");
}

void MainWindow::selectSquare() {
    m_canvas->setShapeType(Canvas::SquareType);
    m_btnMenu->setText("Квадрат");
}

void MainWindow::selectRectangle() {
    m_canvas->setShapeType(Canvas::RectangleType);
    m_btnMenu->setText("Прямоугольник");
}

void MainWindow::selectTriangle() {
    m_canvas->setShapeType(Canvas::TriangleType);
    m_btnMenu->setText("Треугольник");
}

void MainWindow::selectRhomb() {
    m_canvas->setShapeType(Canvas::RhombType);
    m_btnMenu->setText("Ромб");
}

void MainWindow::selectHexagon() {
    m_canvas->setShapeType(Canvas::HexagonType);
    m_btnMenu->setText("Шестиугольник");
}

void MainWindow::selectStar5() {
    m_canvas->setShapeType(Canvas::Star5Type);
    m_btnMenu->setText("Пятиконечная звезда");
}

void MainWindow::selectStar6() {
    m_canvas->setShapeType(Canvas::Star6Type);
    m_btnMenu->setText("Шестиконечная звезда");
}

void MainWindow::selectStar8() {
    m_canvas->setShapeType(Canvas::Star8Type);
    m_btnMenu->setText("Восьмиконечная звезда");
}

void MainWindow::selectMoving() {
    m_canvas->setShapeType(Canvas::MovingType);
    m_btnMenu->setText("Перемещение");
}

void MainWindow::clearShapes() {
    m_canvas->clear_shapes();
}
