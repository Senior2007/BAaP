#include "mainwindow.h"
#include <QFileDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTreeWidget>
#include <QLabel>
#include <QDir>
#include <QFileInfo>
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QPushButton *browseButton = new QPushButton("Открыть папку", this);
    treeWidget = new QTreeWidget(this);
    treeWidget->setHeaderLabel("Структура папок");
    statusLabel = new QLabel("Файлов: 0, Папок: 0", this);

    layout->addWidget(browseButton);
    layout->addWidget(treeWidget);
    layout->addWidget(statusLabel);

    setCentralWidget(centralWidget);

    connect(browseButton, &QPushButton::clicked, this, &MainWindow::browseFolder);
    connect(treeWidget, &QTreeWidget::itemDoubleClicked, this, &MainWindow::openFile);
}

void MainWindow::browseFolder()
{
    QString folder = QFileDialog::getExistingDirectory(this, "Выберите папку");
    if (folder.isEmpty()) return;

    treeWidget->clear();
    QTreeWidgetItem *rootItem = new QTreeWidgetItem(treeWidget);
    rootItem->setText(0, QDir(folder).dirName());
    rootItem->setData(0, Qt::UserRole, folder);

    int fileCount = 0;
    int folderCount = 0;
    buildTree(rootItem, folder, fileCount, folderCount);
    rootItem->setExpanded(true);

    statusLabel->setText(QString("Файлов: %1, Папок: %2").arg(fileCount).arg(folderCount));
}

void MainWindow::buildTree(QTreeWidgetItem *parent, const QString &path, int &fileCount, int &folderCount)
{
    QDir dir(path);
    QFileInfoList entries = dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot | QDir::NoSymLinks);

    for (const QFileInfo &entry : entries) {
        if (entry.isDir()) {
            folderCount++;
            QTreeWidgetItem *item = new QTreeWidgetItem(parent);
            item->setText(0, entry.fileName());
            item->setData(0, Qt::UserRole, entry.absoluteFilePath());
            buildTree(item, entry.absoluteFilePath(), fileCount, folderCount);
        } else {
            fileCount++;
            QTreeWidgetItem *item = new QTreeWidgetItem(parent);
            item->setText(0, entry.fileName());
            item->setData(0, Qt::UserRole, entry.absoluteFilePath());
        }
    }
}

void MainWindow::openFile(QTreeWidgetItem *item, int column)
{
    Q_UNUSED(column);
    QString path = item->data(0, Qt::UserRole).toString();
    if (QFileInfo(path).isFile()) {
        QDesktopServices::openUrl(QUrl::fromLocalFile(path));
    }
}
