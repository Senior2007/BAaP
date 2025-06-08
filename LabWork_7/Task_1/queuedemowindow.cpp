#include "queuedemowindow.h"
#include "doublylinkedqueue.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QInputDialog>
#include <QTime>
#include <QRandomGenerator>

QueueDemoWindow::QueueDemoWindow(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QLabel* queueLabel = new QLabel("Очередь:");
    queueView = new QListWidget();
    mainLayout->addWidget(queueLabel);
    mainLayout->addWidget(queueView);

    QHBoxLayout* buttonLayout = new QHBoxLayout();

    QPushButton* enqueueBtn = new QPushButton("Добавить (enqueue)");
    QPushButton* dequeueBtn = new QPushButton("Удалить (dequeue)");
    QPushButton* clearBtn = new QPushButton("Очистить");
    QPushButton* randomBtn = new QPushButton("Случайные числа");
    QPushButton* variantBtn = new QPushButton("Выполнить вариант");

    buttonLayout->addWidget(enqueueBtn);
    buttonLayout->addWidget(dequeueBtn);
    buttonLayout->addWidget(clearBtn);
    buttonLayout->addWidget(randomBtn);
    buttonLayout->addWidget(variantBtn);

    mainLayout->addLayout(buttonLayout);

    QLabel* ring1Label = new QLabel("Первое кольцо (между min и max):");
    ring1View = new QListWidget();

    QLabel* ring2Label = new QLabel("Второе кольцо (остальные элементы):");
    ring2View = new QListWidget();

    mainLayout->addWidget(ring1Label);
    mainLayout->addWidget(ring1View);
    mainLayout->addWidget(ring2Label);
    mainLayout->addWidget(ring2View);

    connect(enqueueBtn, &QPushButton::clicked, this, &QueueDemoWindow::onEnqueue);
    connect(dequeueBtn, &QPushButton::clicked, this, &QueueDemoWindow::onDequeue);
    connect(clearBtn, &QPushButton::clicked, this, &QueueDemoWindow::onClear);
    connect(randomBtn, &QPushButton::clicked, this, &QueueDemoWindow::onGenerateRandom);
    connect(variantBtn, &QPushButton::clicked, this, &QueueDemoWindow::onProcessVariant);

    setWindowTitle("Демонстрация двусвязной очереди");
    resize(600, 500);
}

void QueueDemoWindow::updateQueueView() {
    queueView->clear();
    QVector<int> items = queue.toVector();
    for (int value : items) {
        queueView->addItem(QString::number(value));
    }
}

void QueueDemoWindow::updateRingViews(DoublyLinkedQueue* ring1, DoublyLinkedQueue* ring2) {
    ring1View->clear();
    ring2View->clear();

    QVector<int> ring1Items = ring1->toVector();
    QVector<int> ring2Items = ring2->toVector();

    for (int value : ring1Items) {
        ring1View->addItem(QString::number(value));
    }
    for (int value : ring2Items) {
        ring2View->addItem(QString::number(value));
    }
}

void QueueDemoWindow::onEnqueue() {
    bool ok;
    int value = QInputDialog::getInt(this, "Добавить элемент", "Введите целое число:",
                                     0, -2147483647, 2147483647, 1, &ok);
    if (ok) {
        queue.enqueue(value);
        updateQueueView();
    }
}

void QueueDemoWindow::onDequeue() {
    try {
        int value = queue.dequeue();
        QMessageBox::information(this, "Удален элемент",
                                 QString("Удален элемент: %1").arg(value));
        updateQueueView();
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Ошибка", e.what());
    }
}

void QueueDemoWindow::onClear() {
    queue.clear();
    updateQueueView();
    ring1View->clear();
    ring2View->clear();
}

void QueueDemoWindow::onGenerateRandom() {
    int count = QInputDialog::getInt(this, "Сгенерировать случайные числа",
                                     "Количество элементов:", 10, 1, 1000, 1);

    srand(QTime::currentTime().msec());
    queue.clear();
    for (int i = 0; i < count; ++i) {
        queue.enqueue(rand() % 1000 - 500);
    }
    updateQueueView();
}

void QueueDemoWindow::onProcessVariant() {
    if (queue.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Очередь пуста!");
        return;
    }

    Node* maxNode = queue.findMax();
    Node* minNode = queue.findMin();

    if (maxNode == minNode) {
        QMessageBox::warning(this, "Ошибка", "Все элементы в очереди одинаковые!");
        return;
    }

    DoublyLinkedQueue* ring1 = queue.getElementsBetween(minNode, maxNode);
    ring1->makeCircular();
    DoublyLinkedQueue* ring2 = queue.getElementsOutside(minNode, maxNode);
    ring2->makeCircular();

    updateRingViews(ring1, ring2);
    delete ring1;
    delete ring2;

    QMessageBox::information(this, "Успех", "Кольца успешно созданы!");
}
