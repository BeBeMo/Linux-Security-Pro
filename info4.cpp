#include "info4.h"

//此模块显示内存信息
INFO4::INFO4(QWidget *parent) :
    QWidget(parent)
{
    label1 = new QLabel;
    label2 = new QLabel;
    label3 = new QLabel;
    label1->setText("内存信息:");

    label1->setStyleSheet("font-size:20px;margin-bottom:;margin-left:20px;font-weight:bold;color:blue;");
    label1->setFixedSize(150,50);
    label2->setStyleSheet("margin-left:50px;margin-bottom:60px");
    QPixmap pixmap(":/mem1");
    label3->setPixmap(pixmap);
    label3->setFixedSize(pixmap.size());

    vlayout = new QVBoxLayout;
    vlayout->addWidget(label1);
    vlayout->addWidget(label2);
    vlayout->setSpacing(10);

    hlayout = new QHBoxLayout;
    hlayout->addLayout(vlayout);
    hlayout->addWidget(label3);

    this->setLayout(hlayout);
}

void INFO4::info_show4(QString a)
{
    label2->setText(a);//设置内存信息
}
