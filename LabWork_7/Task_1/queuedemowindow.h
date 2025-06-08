#ifndef QUEUEDEMOWINDOW_H
#define QUEUEDEMOWINDOW_H

#include <QWidget>
#include "doublylinkedqueue.h"

class QListWidget;
class QPushButton;

class QueueDemoWindow : public QWidget {
    Q_OBJECT

public:
    explicit QueueDemoWindow(QWidget* parent = nullptr);

private:
    DoublyLinkedQueue queue;
    QListWidget* queueView;
    QListWidget* ring1View;
    QListWidget* ring2View;

    void updateQueueView();
    void updateRingViews(DoublyLinkedQueue* ring1, DoublyLinkedQueue* ring2);

private slots:
    void onEnqueue();
    void onDequeue();
    void onClear();
    void onGenerateRandom();
    void onProcessVariant();
};

#endif // QUEUEDEMOWINDOW_H
