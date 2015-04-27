#include "info3.h"

//此模块显示主板信息
INFO3::INFO3(QWidget *parent) :
    QWidget(parent)
{
    label1 = new QLabel;
    label2 = new QLabel;
    label3 = new QLabel;
    label4 = new QLabel;
    label1->setText("主板信息:");
    label1->setStyleSheet("font-size:20px;margin-bottom:;margin-left:20px;font-weight:bold;color:blue;font-family:华文彩云");
    label1->setFixedSize(150,50);
    label2->setStyleSheet("margin-left:30px;margin-bottom:60px");
    QPixmap pixmap(":/board1");//加载图片
    label3->setPixmap(pixmap);
    label3->setFixedSize(pixmap.size());

    vlayout = new QVBoxLayout;//垂直布局
    vlayout->addWidget(label1);
    vlayout->addWidget(label2);
    vlayout->setSpacing(10);

     hlayout = new QHBoxLayout;//横向布局
     hlayout->addLayout(vlayout);
     hlayout->addWidget(label3);

     this->setLayout(hlayout);
}

void INFO3::info_show3(QString a)
{
    label2->setText(a);
}
