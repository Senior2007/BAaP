#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>

class QTreeWidget;
class QLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void browseFolder();
    void openFile(QTreeWidgetItem *item, int column);

private:
    void buildTree(QTreeWidgetItem *parent, const QString &path, int &fileCount, int &folderCount);
    QTreeWidget *treeWidget;
    QLabel *statusLabel;
};

#endif // MAINWINDOW_H
