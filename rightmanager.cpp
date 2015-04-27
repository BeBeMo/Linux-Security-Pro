#include "rightmanager.h"
#include <QApplication>
#include<QDesktopWidget>

rightmanager::rightmanager(QWidget *parent) :
    QWidget(parent)
{
    clsBtn = new QPushButton;
    QPixmap mypixmap;
    mypixmap.load(":/CLSBTN");
    clsBtn->setIconSize(QSize(mypixmap.width(),mypixmap.height()));
    clsBtn->setIcon(mypixmap);
    clsBtn->setStyleSheet("border:0px;background-color:rgb(41, 48, 62)");
    connect(clsBtn,SIGNAL(clicked()),this,SLOT(clickclsBtn()));

    minBtn = new QPushButton;
    QPixmap mypixmap2;
    mypixmap2.load(":/MINBTN");
    minBtn->setIcon(mypixmap2);
    minBtn->setIconSize(QSize(mypixmap2.width(),mypixmap2.height()));
    minBtn->setStyleSheet("border:0px;background-color:rgb(41, 48, 62)");
    connect(minBtn,SIGNAL(clicked()),this,SLOT(clickminBtn()));

    QLabel *rightlabel = new QLabel;
    rightlabel->setFixedSize(50,250);
    rightlabel->setStyleSheet("background-color:#29303e");

    tipBtn = new QPushButton;
    QPixmap mypixmap4;
    mypixmap4.load(":/tipico");
    tipBtn->setIcon(mypixmap4);
    tipBtn->setIconSize(QSize(50,50));
    tipBtn->setStyleSheet("border-style:hidden;");
    connect(tipBtn,SIGNAL(clicked()),this,SLOT(clicktipBtn()));


    QLabel *firelabel = new QLabel;
    firelabel->setPixmap(QPixmap(":/fireico"));
   // firelabel->setStyleSheet("");

    fireBtn = new QPushButton;
    fireBtn->setText("开启");
    QPalette fireBtnPal;
    fireBtnPal.setColor(QPalette::ButtonText,QColor(255,255,255));
    fireBtn->setPalette(fireBtnPal);
    /*
    mypixmap4.load("./FIREBTN");
    fireBtn->setIcon(mypixmap4);
    fireBtn->setIconSize(QSize(50,50));*/
    fireBtn->setStyleSheet("border:0px;background-color:#29303e;");
    connect(fireBtn,SIGNAL(clicked()),this,SLOT(clickfireBtn()));

    flowBtn = new QPushButton;
    QPixmap mypixmap3;
    mypixmap3.load(":/FLOWBTN");
    flowBtn->setIcon(mypixmap3);
    flowBtn->setIconSize(QSize(50,50));
    flowBtn->setStyleSheet("border-style:hidden;");
    connect(flowBtn,SIGNAL(clicked()),this,SLOT(clickflowBtn()));


    QLabel *rightlabel2 = new QLabel;
    rightlabel2->setFixedSize(50,20);
    rightlabel2->setStyleSheet("background-color:#29303e");

    QLabel *rightlabel3 = new QLabel;
    rightlabel3->setFixedSize(50,30);
    rightlabel3->setStyleSheet("background-color:#29303e");

    vlayout = new QVBoxLayout(this);
    vlayout->addWidget(clsBtn);
    vlayout->addWidget(minBtn);
    //vlayout->addStretch(0);
    vlayout->addWidget(rightlabel);
    vlayout->addWidget(tipBtn);
    vlayout->addWidget(flowBtn);
    vlayout->addWidget(firelabel);
    vlayout->addWidget(fireBtn);
    //vlayout->addStretch(0);
    vlayout->addWidget(rightlabel2);
    vlayout->addWidget(rightlabel3);
    vlayout->setContentsMargins(0,0,0,0);
    vlayout->setSpacing(0);

    this->setLayout(vlayout);
    this->setFixedSize(50,550);
}

rightmanager::~rightmanager()
{
}

void rightmanager::clickclsBtn()
{
    emit rightclsBtn();
}

void rightmanager::clickminBtn()
{
    emit rightminBtn();
}

void rightmanager::clickflowBtn()
{
    emit rightflowBtn();
}

void rightmanager::clicktipBtn()
{
    emit righttipBtn();
}

void rightmanager::clickfireBtn()
{
    if(fireBtn->text()=="开启")
    {
        fireBtn->setText("关闭");

        QFile pwdfile("/tmp/pwd");
        pwdfile.open(QFile::ReadOnly);
        QTextStream in1(&pwdfile);
        QString pwdstr=in1.readLine();

        QString program = "bash fire_open.sh "+ pwdstr;//执行shell脚本
        QProcess *myprocess = new QProcess;
         myprocess->start(program);
         if(!myprocess->waitForStarted())
         {
            qDebug()<<"failed started!";
         }
    }
    else
    {
        fireBtn->setText("开启");

        QFile pwdfile1("/tmp/pwd");
        pwdfile1.open(QFile::ReadOnly);
        QTextStream in2(&pwdfile1);
        QString pwdstr1=in2.readLine();

        QString program1 = "bash fire_close.sh "+ pwdstr1;//执行shell脚本
        QProcess *myprocess1 = new QProcess;
         myprocess1->start(program1);
         if(!myprocess1->waitForStarted())
         {
            qDebug()<<"failed started!";
         }
    }
}
