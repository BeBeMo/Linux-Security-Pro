#include "middle2.h"
#include "title.h"

middle2::middle2(QWidget *parent) :
    QWidget(parent)
{

       stacked = new QStackedWidget;
	//按钮栏
       title1 = new TITLE;
	//四个对应跳转界面
       info1 = new INFO1;
       info2 = new INFO2;
       info3 = new INFO3;
       info4 = new INFO4;

       stacked->addWidget(info1);
       stacked->addWidget(info2);
       stacked->addWidget(info3);
       stacked->addWidget(info4);

       QVBoxLayout *main_layout = new QVBoxLayout;
       main_layout->addWidget(title1);
       main_layout->addWidget(stacked);
       main_layout->setSpacing(0);
       main_layout->setContentsMargins(0,0,0,0);
       this->setLayout(main_layout);

	//四个button对应界面跳转
        connect(title1->button1,SIGNAL(clicked()),this,SLOT(turnPage1()));
        connect(title1->button2,SIGNAL(clicked()),this,SLOT(turnPage2()));
        connect(title1->button3,SIGNAL(clicked()),this,SLOT(turnPage3()));
        connect(title1->button4,SIGNAL(clicked()),this,SLOT(turnPage4()));
}

//跳转不同界面，并调用info.sh脚本，执行脚本传入两个参数，$1为密码 ，$2输入参数不同输出信息不同
void middle2::turnPage1()//跳转电脑基本信息页面
{
      stacked->setCurrentWidget(info1);//设置界面为info1

      QFile pwdfile("/tmp/pwd");//从文件中读取密码,执行脚本需要root权限
      pwdfile.open(QFile::ReadOnly);
      QTextStream in1(&pwdfile);
      QString pwdstr=in1.readLine();

       QString program = "bash info.sh "+ pwdstr + " 1";//执行shell脚本，传入参数1输出电脑概述信息
       QProcess *myprocess = new QProcess;
         myprocess->start(program);
         if(!myprocess->waitForStarted())
        {
               qDebug()<<"failed started!";
       }
         while( true == myprocess->waitForFinished() );
       {
            QString ver= myprocess->readAllStandardOutput();
            info1->info_show1(ver);//调用INFO1类的函数,传入电脑基本信息
        }

}

void middle2::turnPage2()//跳转cpu信息页面
{
    stacked->setCurrentWidget(info2);

    QFile pwdfile("/tmp/pwd");
    pwdfile.open(QFile::ReadOnly);
    QTextStream in1(&pwdfile);
    QString  pwdstr=in1.readLine();

       QString program = "bash info.sh "+ pwdstr + " 2";//执行shell脚本，传入参数2输出cpu信息
       QProcess *myprocess = new QProcess;
       myprocess->start(program);
       if(!myprocess->waitForStarted())
        {
               qDebug()<<"failed started!";
       }
         while( true == myprocess->waitForFinished() );
       {
            QString ver= myprocess->readAllStandardOutput();
            info2->info_show2(ver);////调用INFO2类的函数,传入CPU信息
        }
}

void middle2::turnPage3()//跳转主板信息界面
{
    stacked->setCurrentWidget(info3);

    QFile pwdfile("/tmp/pwd");
    pwdfile.open(QFile::ReadOnly);
    QTextStream in1(&pwdfile);
    QString pwdstr=in1.readLine();

    QString program = "bash info.sh "+ pwdstr + " 3";//执行shell脚本，传入参数3输出主板信息
    QProcess *myprocess = new QProcess;
     myprocess->start(program);
     if(!myprocess->waitForStarted())
     {
        qDebug()<<"failed started!";
     }
     while( true == myprocess->waitForFinished() );
     {
        QString ver= myprocess->readAllStandardOutput();
        info3->info_show3(ver);//调用INFO3类的函数,传入主板信息
     }
}

void middle2::turnPage4()//跳转内存信息界面
{
    stacked->setCurrentWidget(info4);

    QFile pwdfile("/tmp/pwd");
    pwdfile.open(QFile::ReadOnly);
    QTextStream in1(&pwdfile);
    QString pwdstr=in1.readLine();

    QString program = "bash info.sh "+ pwdstr + " 4";//执行shell脚本，传入参数4输出内存信息
    QProcess *myprocess = new QProcess;
    myprocess->start(program);
    if(!myprocess->waitForStarted())
    {
        qDebug()<<"failed started!";
    }
   while( true == myprocess->waitForFinished() );
   {
        QString ver= myprocess->readAllStandardOutput();
        info4->info_show4(ver);//调用INFO4类的函数,传入内存信息
    }
}


middle2::~middle2()
{
}
