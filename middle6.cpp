#include "middle6.h"
#include <QDebug>

middle6::middle6(QWidget *parent)
    : QDialog(parent)
{
     tabWidget = new QTabWidget();
     tabWidget->setStyleSheet("QTabBar::tab {height: 50px; width:220px;background-image:url(:/3);color: black;font-size:25px;font-family:宋体;padding: 0px;margin-left:40px;}"
                                  "QTabBar::tab:selected { background: lightgray; } ");
      //新建第一个页面的部件
      QWidget *widget = new QWidget();
      QVBoxLayout *mainLayout = new QVBoxLayout();
      QHBoxLayout *hLayout = new QHBoxLayout();
      listWidget = new QListWidget();
      listWidget->setStyleSheet("border:0px;");
      pushButton_processfresh = new QPushButton("刷新");
      pushButton_processfresh->setStyleSheet("QPushButton{color:blue;border: 1px solid blue;border-radius:15px;height:30px;margin-left:10px;margin-top:10px;}");
      pushButton_processkill = new QPushButton("关闭");
      pushButton_processkill->setStyleSheet("QPushButton{color:green;border: 1px solid green;border-radius:15px;height:30px;margin-left:10px;margin-top:10px;}");
      mainLayout->addWidget(listWidget);

      hLayout->addWidget(pushButton_processfresh);
      hLayout->addWidget(pushButton_processkill);
      mainLayout->addLayout(hLayout);
      widget->setLayout(mainLayout);

      //新建第二个页面的部件
       QWidget *widget2 = new QWidget();
       QVBoxLayout *mainLayout2 = new QVBoxLayout(widget2);

 //     QLabel *label = new QLabel("");
      QHBoxLayout *hLayout2 = new QHBoxLayout(widget2);
      QPushButton *pushButton_task = new QPushButton("进程信息");
      pushButton_task->setStyleSheet("QPushButton{color:blue;border: 1px solid blue;border-radius:5px;height:20px;}");
      QPushButton  *pushButton_state= new QPushButton("运行状态");
      pushButton_state->setStyleSheet("QPushButton{color:blue;border: 1px solid blue;border-radius:5px;height:20px;}");
      hLayout2->addWidget(pushButton_task);
      hLayout2->addWidget(pushButton_state);

       listWidget2 = new QListWidget(widget2);
       listWidget2->setSpacing(5);
       listWidget2->setStyleSheet("QListWidget{background-color:#FFF0F5;border:0px;}");
      //  listWidget2->addItem(topItem);
       listWidget2->setStyleSheet("border:0px;");
       listWidget2->setIconSize(QSize(48,48));
       pushButton_processkill2 = new QPushButton("关闭");
       pushButton_processkill2->setStyleSheet("QPushButton{color:green;border: 1px solid green;border-radius:15px;height:30px;margin-left:10px;margin-top:10px;}");
     mainLayout2->addLayout(hLayout2);
     mainLayout2->addWidget(listWidget2);
     mainLayout2->addWidget(pushButton_processkill2);
     widget2->setLayout(mainLayout2);

      //向QTabWidget中添加第一个页面
      QIcon icon1(":/new/icon/images/1.ico");
      tabWidget->addTab(widget2, icon1, "应用进程");

      //向QTabWidget中添加第二个页面
      QIcon icon2(":/new/icon/images/2.ico");
      tabWidget->addTab(widget, icon2, "所有进程");

      QHBoxLayout *layout = new QHBoxLayout();
      layout->addWidget(tabWidget);
      this->setLayout(layout);
//创建进程执行shell脚本
       thread1 = new QProcess;
       thread2 = new QProcess;
       thread3 = new QProcess;
       thread4 = new QProcess;
       thread5 = new QProcess;
       thread6 = new QProcess;
       thread7 = new QProcess;
       thread8 = new QProcess;
	   thread9 = new QProcess;
       flag1 = flag2 = flag3 = flag4 = flag5 = flag6 = flag7 = flag8 = flag9 = 0;
      timer = new QTimer(this);
      QWidget::connect( timer, SIGNAL( timeout() ), this, SLOT( timer_update_currentTabInfo() ) );
      QWidget::connect( tabWidget, SIGNAL( currentChanged(int)), this, SLOT( on_tabWidget_INFO_currentChanged(int)) );
       timer->start(1000);

}

void middle6::timer_update_currentTabInfo()
{
    int index = tabWidget->currentIndex();
    //定时器只刷新内存tab页面
    if (index == 0)
    {
        show_tabWidgetInfo(index);
    }
}

void middle6::show_tabWidgetInfo(int index)
{
    if(index == 0)
{
        connect(pushButton_processkill2, SIGNAL(clicked()), this, SLOT(on_pushButton_pkill_clicked2()));
        thread1->start("bash ps-amaz.sh");
        thread2->start("bash ps-firfo.sh");
        thread3->start("bash ps-gogl.sh");
        thread4->start("bash ps-qc.sh");
        thread5->start("bash ps-ql.sh");
        thread6->start("bash ps-soft-cent.sh");
        thread7->start("bash ps-term.sh");
        thread8->start("bash ps-wp.sh");
        thread9->start("bash ps-evi.sh");
        if(!thread1->waitForStarted())
        {
            qDebug()<<"failed start!";
        }
        if(!thread2->waitForStarted())
        {
            qDebug()<<"failed start!";
        }
        if(!thread3->waitForStarted())
        {
            qDebug()<<"failed start!";
        }
        if(!thread4->waitForStarted())
        {
            qDebug()<<"failed start!";
        }
        if(!thread5->waitForStarted())
        {
            qDebug()<<"failed start!";
        }
        if(!thread6->waitForStarted())
        {
            qDebug()<<"failed start!";
        }
        if(!thread7->waitForStarted())
        {
            qDebug()<<"failed start!";
        }
        if(!thread8->waitForStarted())
        {
            qDebug()<<"failed start!";
        }
        if(!thread9->waitForStarted())
        {
            qDebug()<<"failed start!";
        }
        while(true == thread1->waitForFinished());
        {
            bool ok1;
            QString ver1 = thread1->readAllStandardOutput();
            int dec1 = ver1.toInt(&ok1,10);
            if(dec1 > 1 && flag1 == 0)
            {
               item1 = new QListWidgetItem(listWidget2);
                flag1 = 1;
                item1->setIcon(QIcon(":images/amazon.png"));
                item1->setText("亚马逊                                                                          正在运行中...");
                listWidget2->addItem(item1);

            }
             if(dec1 < 2 && flag1 == 1)
            {
               listWidget2->removeItemWidget(item1);
               delete item1;
                flag1 = 0;
                dec1 = 0;
            }
         }
        while(true == thread2->waitForFinished());
        {
            bool ok2;
            QString ver2 = thread2->readAllStandardOutput();
            int dec2 = ver2.toInt(&ok2,10);
            if(dec2 >1 && flag2 == 0)
            {
                item2 = new QListWidgetItem;
                flag2 = 1;
                item2->setIcon(QIcon(":images/firefox.png"));
                item2->setText("火狐浏览器                                                                  正在运行中...");
                 listWidget2->addItem(item2);
            }
            if(dec2 < 2 && flag2 == 1)
            {
                listWidget2->removeItemWidget(item2);
                delete item2;
                flag2 = 0;
            }
         }
        while(true == thread3->waitForFinished());
        {
            bool ok3;
            QString ver3= thread3->readAllStandardOutput();
            int dec3 = ver3.toInt(&ok3,10);
            if(dec3 > 2 && flag3 == 0)
            {
                item3 = new QListWidgetItem;
                flag3 = 1;
                item3->setIcon(QIcon(":images/google.png"));
                item3->setText("谷歌浏览器                                                                  正在运行中...");
                 listWidget2->addItem(item3);
            }
            if(dec3 < 3 && flag3 == 1)
            {
                listWidget2->removeItemWidget(item3);
                delete item3;
                dec3 = 0;
                flag3 = 0;
            }
         }
        while(true == thread4->waitForFinished());
        {
            bool ok4;
            QString ver4 = thread4->readAllStandardOutput();
            int dec4 = ver4.toInt(&ok4,10);
            if(dec4 > 2 && flag4 == 0)
            {
                item4 = new QListWidgetItem;
                flag4 = 1;
                item4->setIcon(QIcon(":/images/qt.png"));
                item4->setText("Qt Creater                                                                   正在运行中...");
                listWidget2->addItem(item4);

            }
            if(dec4 < 2 && flag4 == 1)
            {
                listWidget2->removeItemWidget(item4);
                delete item4;
                dec4 = 0;
                flag4 = 0;
            }
         }
        while(true == thread5->waitForFinished());
        {
            bool ok5;
            QString ver5 = thread5->readAllStandardOutput();
            int dec5 = ver5.toInt(&ok5,10);
         //   qDebug()<< dec5;
            if(dec5> 2 && flag5 == 0)
            {
                item5 = new QListWidgetItem;
                flag5 = 1;
                item5->setIcon(QIcon(":/images/qq.png"));
                item5->setText("qq                                                                                   正在运行中...");
                 listWidget2->addItem(item5);
            }
            if(dec5 < 3 && flag5 == 1)
            {
                listWidget2->removeItemWidget(item5);
                delete item5;
                flag5 = 0;
            }
         }
        while(true == thread6->waitForFinished());
        {
            bool ok6;
            QString ver6 = thread6->readAllStandardOutput();
            int dec6 = ver6.toInt(&ok6,10);
            if(dec6> 1 && flag6 == 0)
            {
                item6 = new QListWidgetItem;
                flag6 = 1;
                item6->setIcon(QIcon(":/images/software-center.png"));
                item6->setText("ubuntu软件中心                                                        正在运行中...");
                listWidget2->addItem(item6);
            }
            if(dec6 < 2 && flag6 == 1)
            {
                listWidget2->removeItemWidget(item6);
                delete item6;
                flag6 = 0;
            }
         }
        while(true == thread7->waitForFinished());
        {
            bool ok7;
            QString ver7 = thread7->readAllStandardOutput();
            int dec7 = ver7.toInt(&ok7,10);
            if(dec7> 1 && flag7 == 0)
            {
                item7 = new QListWidgetItem;
                flag7 = 1;
                item7->setIcon(QIcon(":/images/terminal.png"));
                item7->setText("终端                                                                               正在运行中...");
                 listWidget2->addItem(item7);
            }
            if(dec7 < 2 && flag7 == 1)
            {
                listWidget2->removeItemWidget(item7);
                delete item7;
                flag7 = 0;
            }
         }
        while(true == thread8->waitForFinished());
        {
            bool ok8;
            QString ver8 = thread8->readAllStandardOutput();
            int dec8 = ver8.toInt(&ok8,10);
            if(dec8> 1 && flag8 == 0)
            {
                item8 = new QListWidgetItem;
                flag8 = 1;
                item8->setIcon(QIcon(":/images/wps.png"));
                item8->setText("wps文本编辑器                                                          正在运行中...");
                 listWidget2->addItem(item8);
            }
            if(dec8 < 2 && flag8 == 1)
            {
                listWidget2->removeItemWidget(item8);
                delete item8;
                flag8 = 0;
            }
         }
        while(true == thread9->waitForFinished());
        {
            bool ok9;
            QString ver9 = thread9->readAllStandardOutput();
            int dec9 = ver9.toInt(&ok9,10);
            if(dec9> 1 && flag9 == 0)
            {
                item9 = new QListWidgetItem;
                flag9 = 1;
                item9->setIcon(QIcon(":/images/evnice.png"));
                item9->setText("pdf文本编辑器                                                            正在运行中...");
                 listWidget2->addItem(item9);
            }
            if(dec9 < 2 && flag9 == 1)
            {
                listWidget2->removeItemWidget(item9);
                delete item9;
                flag9 = 0;
            }
         }
    }
    if(index == 1)
    {
    QString tempStr; //读取文件信息字符串
    QFile tempFile; //用于打开系统文件
   //  int pos; //读取文件的位置
     this->listWidget->clear();
            connect(this->pushButton_processfresh, SIGNAL(clicked()), this, SLOT(on_pushButton_prefresh_clicked()));
            connect(this->pushButton_processkill, SIGNAL(clicked()), this, SLOT(on_pushButton_pkill_clicked()));
            QDir qd("/proc");
            QStringList qsList = qd.entryList();
            QString qs = qsList.join("\n");
            QString id_of_pro;
            bool ok;
            int find_start = 3;
            int a, b;
            int nProPid; //进程PID
            int totalProNum = 0; //进程总数
            QString proName; //进程名
            QString proState; //进程状态
            QString proPri; //进程优先级
            QString proMem; //进程占用内存
            QListWidgetItem *title = new QListWidgetItem("PID\t" + QString::fromUtf8("名称") + "\t\t" +
                                                         QString::fromUtf8("状态") + "\t" +
                                                         QString::fromUtf8("优先级") + "\t" +
                                                         QString::fromUtf8("占用内存"), this->listWidget);
            //循环读取进程
            while (1)
            {
                //获取进程PID
                a = qs.indexOf("\n", find_start);
                b = qs.indexOf("\n", a+1);
                find_start = b;
                id_of_pro = qs.mid(a+1, b-a-1);
                totalProNum++;
                nProPid = id_of_pro.toInt(&ok, 10);
                if(!ok)
                {
                    break;
                }

                //打开PID所对应的进程状态文件
                tempFile.setFileName("/proc/" + id_of_pro + "/stat");
                if ( !tempFile.open(QIODevice::ReadOnly) )
                {
//                    QMessageBox::warning(this, tr("warning"), tr("The pid stat file can not open!"), QMessageBox::Yes);
                    return;
                }
                tempStr = tempFile.readLine();
                if (tempStr.length() == 0)
                {
                    break;
                }
                a = tempStr.indexOf("(");
                b = tempStr.indexOf(")");
                proName = tempStr.mid(a+1, b-a-1);
                proName.trimmed(); //删除两端的空格
                proState = tempStr.section(" ", 2, 2);
                proPri = tempStr.section(" ", 17, 17);
                proMem = tempStr.section(" ", 22, 22);

                if (proName.length() >= 12)
                {
                    QListWidgetItem *item = new QListWidgetItem(id_of_pro + "\t" +
                                                                proName + "\t" +
                                                                proState + "\t" +
                                                                proPri + "\t" +
                                                                proMem, this->listWidget);
                }
                else
                {
                    QListWidgetItem *item = new QListWidgetItem(id_of_pro + "\t" +
                                                                proName + "\t\t" +
                                                                proState + "\t" +
                                                                proPri + "\t" +
                                                                proMem, this->listWidget);
                }
            }
            tempFile.close(); //关闭该PID进程的状态文件
}
}


void middle6::on_tabWidget_INFO_currentChanged(int index)
{
   // index = tabWidget->currentIndex();
    if(index == 1)
         show_tabWidgetInfo(index); //显示tab中的内容
    return ;
}

void middle6::on_pushButton_pkill_clicked()
{
    //获得进程号
    QListWidgetItem *item = this->listWidget->currentItem();
    QString pro = item->text();
    pro = pro.section("\t", 0, 0);

    system("kill " + pro.toLatin1());
    QMessageBox::warning(this, tr("kill"), QString::fromUtf8("该进程已被杀死!"), QMessageBox::Yes);
    //回到进程信息tab表
    show_tabWidgetInfo(1);
}

//触发list删除某进程
void middle6::on_pushButton_pkill_clicked2()
{

    //获得进程号
    QListWidgetItem *item = this->listWidget2->currentItem();
    if(item == item1)
    {
        system("ps aux | grep amazon | grep -v grep | awk '{print $2}' | xargs -i kill {} ");
    }
    if(item == item2)
    {
        system("ps aux | grep firefox | grep -v grep | awk '{print $2}' | xargs -i kill {} ");
    }

    if(item == item3)
    {
        system("ps aux | grep google | grep -v grep | awk '{print $2}' | xargs -i kill {} ");
    }
    if(item == item4)
    {
        system("ps aux | grep qt | grep -v grep | awk '{print $2}' | xargs -i kill {} ");
    }
    if(item == item5)
    {
        system("ps aux | grep qq | grep -v grep | awk '{print $2}' | xargs -i kill {} ");
    }
    if(item == item6)
    {
        system("ps aux | grep software-center | grep -v grep | awk '{print $2}' | xargs -i kill {} ");
    }
    if(item == item7)
    {
        system("ps aux | grep terminal | grep -v grep | awk '{print $2}' | xargs -i kill {} ");
    }
    if(item == item8)
    {
        system("ps aux | grep wps | grep -v grep | awk '{print $2}' | xargs -i kill {} ");
    }
    if(item == item9)
    {
        system("ps aux | grep evince | grep -v grep | awk '{print $2}' | xargs -i kill {} ");
    }
}
void middle6::on_pushButton_prefresh_clicked()
{
    show_tabWidgetInfo(1);
}


middle6::~middle6()
{
        delete timer;
}
