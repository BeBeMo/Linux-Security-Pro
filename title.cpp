#include "title.h"
#include <QPixmap>

//此模块为电脑概述，cpu信息，主板信息，内存信息的四个button
TITLE::TITLE(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(670,83);

    button1 =new QToolButton;//电脑概述按钮
    button1->setStyleSheet("background-image:url(:/com);border-color:blue;");
    button1->setFixedSize(170,45);

    button2 =new QToolButton;//cpu信息按钮
    button2->setStyleSheet("background-image:url(:/cpu2);");
    button2->setFixedSize(170,45);

    button3 =new QToolButton;//主板信息按钮
    button3->setStyleSheet("background-image:url(:/board);");
    button3->setFixedSize(170,45);

    button4 =new QToolButton;//内存信息按钮
    button4->setStyleSheet("background-image:url(:/mem);");
    button4->setFixedSize(170,45);


   hlayout = new QHBoxLayout;//横向布局
   hlayout->addWidget(button1);
   hlayout->addWidget(button2);
   hlayout->addWidget(button3);
   hlayout->addWidget(button4);
   hlayout->setContentsMargins(0,0,0,0);

   this->setLayout(hlayout);

}
