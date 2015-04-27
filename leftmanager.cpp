#include "leftmanager.h"

leftmanager::leftmanager(QWidget *parent) :
    QWidget(parent)
{
    //list的定义与初始化
    list = new QListWidget();
    list->setStyleSheet("border:0px;");
    list->setIconSize(QSize(180,58));
    list->setStyleSheet("background-color:#29303E;border:0px;");

    //上面的label的定义与初始化
    QLabel *uplabel = new QLabel;
    uplabel->setPixmap(QPixmap(":/leftico"));
    uplabel->setStyleSheet("background-color: rgb(16, 134, 255);padding-left:50px;padding-top:13px;");
   // uplabel->setParent(list);


    //QListWidgetItem的定义与初始化
    QListWidgetItem *item1 = new QListWidgetItem;
    item1->setIcon(QIcon(":/2-1"));
    QListWidgetItem *item2 = new QListWidgetItem;
    item2->setIcon(QIcon(":/2-2"));
    QListWidgetItem *item3 = new QListWidgetItem;
    item3->setIcon(QIcon(":/2-3"));
    QListWidgetItem *item4 = new QListWidgetItem;
    item4->setIcon(QIcon(":/2-4"));
    QListWidgetItem *item5 = new QListWidgetItem;
    item5->setIcon(QIcon(":/2-5"));
    QListWidgetItem *item6 = new QListWidgetItem;
    item6->setIcon(QIcon(":/2-6"));
    QListWidgetItem *item7 = new QListWidgetItem;
    item7->setIcon(QIcon(":/2-7"));

    //将item添加到list中
    list->addItem(item1);
    list->addItem(item2);
    list->addItem(item3);
    list->addItem(item4);
    list->addItem(item5);
    list->addItem(item6);
    list->addItem(item7);

    connect(list,SIGNAL(currentRowChanged(int)),SLOT(pagechanged(int)));

    //最下面的label的定义与初始化
    QLabel *downlabel = new QLabel;
    downlabel->setText("     版本号:  1.0.2  Beta");
    QPalette downlabelPal;
    downlabelPal.setColor(QPalette::Text,QColor(255,255,255));
    downlabel->setPalette(downlabelPal);
    downlabel->setStyleSheet("background-color:#29303E;padding-bottom:15px;height:25px;border-top-color:gray");

    //将各个控件加入到布局中
    QVBoxLayout *vlayout = new QVBoxLayout(this);
    vlayout->addWidget(uplabel);
    vlayout->addWidget(list);
    vlayout->addWidget(downlabel);
    vlayout->setSpacing(0);
    vlayout->setContentsMargins(0,0,0,0);

    this->setLayout(vlayout);
    this->setFixedSize(180,550);
}

leftmanager::~leftmanager()
{
}

//listitem改变时，页面也改变
void leftmanager::pagechanged(int index)
{
    emit leftlistchanged(index);
}
