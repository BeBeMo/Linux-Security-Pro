#include "info2.h"

//此模块输出cpu信息
INFO2::INFO2(QWidget *parent) :
    QWidget(parent)
{
    label1 = new QLabel;
    label2 = new QLabel;
    label3 = new QLabel;
    label1->setText("CPU信息:");

    label1->setStyleSheet("font-size:20px;margin-bottom:;margin-left:20px;font-weight:bold;color:blue;");
    label1->setFixedSize(150,50);
    label2->setStyleSheet("margin-left:20px;margin-bottom:60px");
  
    QPixmap pixmap(":/cpu1");
    label3->setPixmap(pixmap);

    label3->setFixedSize(pixmap.size());//加载图片
    label3->setStyleSheet("margin-right:0px;margin-bottom:50px");

    vlayout = new QVBoxLayout;//纵向布局
    vlayout->addWidget(label1);
    vlayout->addWidget(label2);
    vlayout->setSpacing(10);

    hlayout = new QHBoxLayout;//横向布局
    hlayout->addLayout(vlayout);
    hlayout->addWidget(label3);
    hlayout->setMargin(0);

    this->setLayout(hlayout);
}

void INFO2::info_show2(QString a)
{
    label2->setText(a);//label2显示cpu信息
}
