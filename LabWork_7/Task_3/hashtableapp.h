#ifndef HASHTABLEAPP_H
#define HASHTABLEAPP_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QScrollArea>
#include <QGridLayout>
#include <QInputDialog>
#include <QMessageBox>
#include "extendedhashtable.h"

class HashTableApp : public QWidget {
    Q_OBJECT

public:
    HashTableApp(QWidget* parent = nullptr);

private:
    ExtendedHashTable hashTable;
    QTextEdit* output;

    void setupUI();
    void updateOutput();

private slots:
    void createNewTable();
    void addRandomKey();
    void findStackWithMinKey();
    void clearTable();
    void removeKey();
    void checkContainsKey();
};

#endif // HASHTABLEAPP_H
