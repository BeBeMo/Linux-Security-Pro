#include "flowwindow.h"

flowwindow::flowwindow(QWidget *parent) :
    QDialog(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);//使窗口隐藏边框，最前端显示，形成悬浮窗

    setWindowTitle("flow widget");
    m_Pixmap.load(":/4");
    resize( m_Pixmap.size() );//设置窗口形状为图片形状
    setMask( m_Pixmap.mask() );//实现不规则窗口的关键

    label1 = new QLabel;//流量监控
    label1->setStyleSheet("font-size:12px;margin-top:40px;margin-right:10px;");
    label2 = new QLabel;//cpu使用率
    label2->setStyleSheet("margin-top:40px;margin-left:40px");

     hlayout = new QHBoxLayout;
     hlayout->addWidget(label2);
     hlayout->addWidget(label1);

     this->setLayout(hlayout);

     //创建线程不停刷新悬浮窗口
     thread = new MyThread;
     connect(thread, SIGNAL(sendint(QString)), this, SLOT(showint(QString)));//流量信号槽
     connect(thread, SIGNAL(sendint1(QString)), this, SLOT(showint1(QString)));//cpu信号槽
     thread->start();
}

flowwindow::~flowwindow()
{
}

void flowwindow::mousePressEvent(QMouseEvent *event)
{
    //按住左键可以托动窗口，按下右键关闭程序

    if(event->button() == Qt::LeftButton)
    {
        m_CurrentPos = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
    else if(event->button() == Qt::RightButton)
    {
        thread->terminate();//关闭窗口时，终止线程
        close();
    }
}

void flowwindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() && Qt::LeftButton)
    {
        move(event->globalPos() - m_CurrentPos);
        event->accept();
    }
}

void flowwindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, m_Pixmap);
}

void flowwindow::leaveEvent(QEvent *event)
{
    //鼠标离开窗口时是普通的指针
    setCursor(Qt::ArrowCursor);
}

void flowwindow::enterEvent(QEvent *event)
{
    //鼠标留在窗口上时是一个手指
    setCursor(Qt::PointingHandCursor);
}

void flowwindow::showint(QString ver)//槽函数
{
    label1->setText(ver);//设置label1内容为后台流量脚本执行的输出结果
}


void flowwindow::showint1(QString ver1)//槽函数
{
    label2->setText(ver1);//设置label2内容为后台cpu脚本执行的输出结果
}

MyThread::MyThread(QObject *parent):
QThread(parent)
{

}

//
void MyThread::run()//线程启动的函数，不停调用后台shell脚本
{

    while(1)
    {
        QString program = "bash ll.sh";//调用流量监控脚本
        QProcess *myprocess = new QProcess;//创建进程
        myprocess->start(program);//执行shell脚本

        if(!myprocess->waitForStarted())
        {
            qDebug()<<"failed started flowwindow ll!";
        }

         while( true == myprocess->waitForFinished() );
          {
            QString ver= myprocess->readAllStandardOutput();
            emit sendint(ver);//发送流量信号
          }

        QString program1 = "bash cpu1.sh";//调用cpu脚本

         QProcess *myprocess1 = new QProcess;//创建进程
        myprocess1->start(program1);//执行shell脚本

        if(!myprocess1->waitForStarted())
        {
             qDebug()<<"failed started flowwindow cpu!";
        }

        while( true == myprocess1->waitForFinished() );
        {
            QString  ver1= myprocess1->readAllStandardOutput();
            emit sendint1(ver1);//发送cpu信号
        }
      }
}
