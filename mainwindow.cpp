#include "mainwindow.h"

mainwindow::mainwindow(QWidget *parent) :
    QWidget(parent)
{
  // CreatTrayIcon();

    myleft = new leftmanager(this); //左边页面
    myright = new rightmanager(this);
    connect(myright,SIGNAL(rightclsBtn()),SLOT(rightclsBtnSlot()));
    connect(myright,SIGNAL(rightminBtn()),SLOT(rightminBtnSlot()));
    connect(myright,SIGNAL(rightflowBtn()),SLOT(rightflowBtnSlot()));
    connect(myright,SIGNAL(righttipBtn()),SLOT(righttipBtnSlot()));

    showWidget = new QStackedWidget;    //中间页面
    m1 = new middle1;
    m2  =new middle2;
    m3 = new middle3;
    m4  =new middle4;
    m5 = new middle5;
    m6  =new middle6;
    m7 = new middle7;
    showWidget->addWidget(m1);
    showWidget->addWidget(m2);
    showWidget->addWidget(m3);
    showWidget->addWidget(m4);
    showWidget->addWidget(m5);
    showWidget->addWidget(m6);
    showWidget->addWidget(m7);
    connect(myleft,SIGNAL(leftlistchanged(int)),this,SLOT(leftlistchangedSlot(int)));

    QHBoxLayout *mainlayout = new QHBoxLayout;
    myleft->setStyleSheet("background-color:white;width:90px;");

    mainlayout->addWidget(myleft);
    mainlayout->addWidget(showWidget);
    mainlayout->addWidget(myright);
    mainlayout->setContentsMargins(0,0,0,0);
    mainlayout->setSpacing(0);

    //窗口在屏幕上居中显示
    QDesktopWidget *desktop = QApplication::desktop();
    move((desktop->width()-this->width())/2,(desktop->height()-this->height())/2);

    //this->resize(900,550);
    this->setFixedSize(900,550);
    this->setLayout(mainlayout);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowIcon(QIcon(":/logo"));
}

mainwindow::~mainwindow()
{
}

//void mainwindow::CreatTrayMenu()
//{
//    miniSizeAction = new QAction("最小化",this);
//    restoreWinAction = new QAction("还原",this);
//    quitAction = new QAction("退出",this);

//    connect(miniSizeAction,SIGNAL(triggered()),this,SLOT(hide()));
//    connect(restoreWinAction,SIGNAL(triggered()),this,SLOT(showNormal()));
//    connect(quitAction,SIGNAL(triggered()),qApp,SLOT(quit()));

//    trayiconMenu = new QMenu((QWidget *)QApplication::desktop());
//    trayiconMenu->addAction(miniSizeAction);
//    trayiconMenu->addAction(restoreWinAction);
//    trayiconMenu->addSeparator();   //加入一个分隔符
//    trayiconMenu->addAction(quitAction);
//}

//void mainwindow::CreatTrayIcon()
//{
//    if(!QSystemTrayIcon::isSystemTrayAvailable())   //判断系统是否支持系统托盘图标
//    {
//        return;
//    }
//    trayicon = new QSystemTrayIcon(this);
//    trayicon->setIcon(QIcon(":/mytrayico"));    //设置图标图片
//   // setWindowIcon(QIcon(":/mytrayico"));    //把图片设置到窗口上
//    trayicon->setContextMenu(trayiconMenu); //设置托盘上下文菜单
//    trayicon->show();
//    connect(trayicon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
//            this,SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
//    CreatTrayMenu();
//}

//void mainwindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
//{
//    switch (reason) {
//    case QSystemTrayIcon::Trigger:

//    case QSystemTrayIcon::DoubleClick:
//        showNormal();
//        break;

//    default:
//        break;
//    }
//}

//void mainwindow::closeEvent(QCloseEvent *event)
//{
//    if(trayicon->isVisible())
//    {
//        hide();
//        event->ignore();
//    }
//    else
//        event->accept();
//}

//void mainwindow::addMD5()
//{
//    QFile file("./pwd");    //打开文件，读取密码
//    file.open(QIODevice::ReadOnly);
//    QTextStream myin(&file);
//    QString pwdstr = myin.readLine();
//    file.close();

//    QString pwdstrafter;    //对密码进行MD5加密
//    QByteArray ba,bb;
//    QCryptographicHash md(QCryptographicHash::Md5);
//    ba.append(pwdstr);
//    md.addData(ba);
//    bb = md.result();
//    pwdstrafter.append(bb.toHex());
//    QFile afterfile("./pwd");
//    afterfile.resize(0);    //文件内容被清空
//    afterfile.open(QFile::WriteOnly);//以只写的方式打开
//    afterfile.write(pwdstrafter.toUtf8());  //将加密后的密码写入文件
//    afterfile.close();
//    system("rm -f afterfile");
//}

//右边自定义的关闭按钮的触发事件
void mainwindow::rightclsBtnSlot()
{
//    if(trayicon->isVisible()) //托盘
//    {
//        //hide();
//        event->ignore();
//    }
//    else
//        event->accept();
 //   addMD5();
    fw.close();

    close();
    system("killall LinuxManger");
}

//右边自定义的最小化按钮的触发事件
void mainwindow::rightminBtnSlot()
{
   // hide();
    showMinimized();
    //CreatTrayIcon();
}

void mainwindow::rightflowBtnSlot()
{
    fw.show();
    fw.move((QApplication::desktop()->width() - fw.width())-30,(QApplication::desktop()->height() - fw.height())-30);
}

void mainwindow::righttipBtnSlot()
{
    tipDia.show();
}

//左边列表中的item选项改变时，触发的槽
void mainwindow::leftlistchangedSlot(int index)
{
    showWidget->setCurrentIndex(index);
}

//去除掉标题栏后，整个窗口能够移动
void mainwindow::mousePressEvent(QMouseEvent *e)
{
    windowpos = e->globalPos();
}

void mainwindow::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX()-windowpos.x();
    int dy = e->globalY()-windowpos.y();
    windowpos = e->globalPos();
    move(x()+dx,y()+dy);
}

void mainwindow::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX()-windowpos.x();
    int dy = e->globalY()-windowpos.y();
    move(x()+dx,y()+dy);
}
