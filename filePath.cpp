#include "filePath.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QInputDialog>
#include <QMessageBox>
#include <QWidget>
#include <QSplitter>
#include <QTextCodec>
#include <QWidget>
#include <QDebug>

filePath::filePath(QWidget *parent)
    : QMainWindow(parent)
{
    QSplitter *splitter = new QSplitter(Qt::Vertical);
      tree = new QTreeView(splitter);
     QDirModel *model = new QDirModel;
    //从缺省目录创建数据

    tree->setModel(model);
    tree->setRootIndex(model->index("/home"));
    QTextCodec *codec = QTextCodec::codecForLocale();
    QString a = codec->toUnicode("目录");
    splitter->setWindowTitle(a);
    splitter->resize(QSize(480,650));
    splitter->show();

}




filePath::~filePath()
{

}
