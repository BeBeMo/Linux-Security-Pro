#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QDirModel>
#include <QTreeView>
class filePath : public QMainWindow
{
    Q_OBJECT

public:
    filePath(QWidget *parent = 0);
    ~filePath();

private:
    QDirModel *model;
    QTreeView *tree;
};

#endif // MAINWINDOW_H
