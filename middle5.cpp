#include "middle5.h"

middle5::middle5(QWidget *parent) :
    QWidget(parent)
{
    leftlayout = new QVBoxLayout;
    rightlayout = new QVBoxLayout;
    leftup = new QHBoxLayout;
    leftdown = new QHBoxLayout;
    rightup = new QHBoxLayout;
    rightdown = new QHBoxLayout;
    mainlayout = new QHBoxLayout;

    //左边的布局
    QSize size(80,80);
    leftlabel1 = new QLabel;
    QPixmap pixmap(":/bootstart");
    QPixmap pixmap1(pixmap.scaled(size));
    leftlabel1->setPixmap(pixmap1);
   // leftlabel1->setGeometry(QRect(0,0,50,50));
    leftlabel2 = new QLabel;
    leftlabel2->setText("开机自启动项");
    leftlabel2->setStyleSheet("font-size:20px;color:blue;margin-right:80px;");

    leftlist = new QListWidget;

    showBtn1 = new QPushButton;
    showBtn1->setText("显示启动项");
    connect(showBtn1,SIGNAL(clicked()),this,SLOT(showbootstart()));
    cliBtn1 = new QPushButton;
    cliBtn1->setText("关闭自启动项");
    connect(cliBtn1,SIGNAL(clicked()),this,SLOT(closebootstart()));

    leftup->addWidget(leftlabel1);
    leftup->addWidget(leftlabel2);
    leftdown->addWidget(showBtn1);
    leftdown->addWidget(cliBtn1);

    leftlayout->addLayout(leftup);
    leftlayout->addWidget(leftlist);
    leftlayout->addLayout(leftdown);

    //右边的布局
    rightlabel1 = new QLabel;
    QPixmap pixmap2(":/bootclose");
    QPixmap pixmap3(pixmap2.scaled(size));
    rightlabel1->setPixmap(pixmap3);
    rightlabel1->setGeometry(QRect(330,0,50,50));
    rightlabel2 = new QLabel;
    rightlabel2->setText("非开机自启动项");
    rightlabel2->setStyleSheet("font-size:20px;color:blue;margin-right:60px");

    rightlist = new QListWidget;

    showBtn2 = new QPushButton;
    showBtn2->setText("显示非启动项");
    connect(showBtn2,SIGNAL(clicked()),this,SLOT(showbootclose()));
    cliBtn2 = new QPushButton;
    cliBtn2->setText("打开非启动项");
    connect(cliBtn2,SIGNAL(clicked()),this,SLOT(openbootstart()));

    rightup->addWidget(rightlabel1);
    rightup->addWidget(rightlabel2);
    rightdown->addWidget(showBtn2);
    rightdown->addWidget(cliBtn2);
    rightlayout->addLayout(rightup);
    rightlayout->addWidget(rightlist);
    rightlayout->addLayout(rightdown);

    //主布局
    mainlayout->addLayout(leftlayout);
    mainlayout->addLayout(rightlayout);

    this->setLayout(mainlayout);
}

middle5::~middle5()
{
}

//显示开机自启动项
void middle5::showbootstart()
{
    leftlist->clear();
    thread1_1 = new QProcess;
    thread1_1->start("bash 1showname.sh");
    thread1_1->waitForFinished(1000);
    QFile resultFile("/tmp/result1");
    resultFile.open(QIODevice::ReadOnly);
    QTextStream in(&resultFile);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        item = new QListWidgetItem;
        item->setText(line);
        QFont item_font1 = item->font();
        item_font1.setPointSize(13);
        item->setFont(item_font1);
        leftlist->addItem(item);
    }
    resultFile.close();
}

//关闭自启动项
void middle5::closebootstart()
{
    QFile pwdfile("/tmp/pwd");
    pwdfile.open(QFile::ReadOnly);
    QTextStream pwdin(&pwdfile);
    pwd = pwdin.readLine();
    pwdfile.close();

    thread1_2 = new QProcess;
    thread1_2->start("bash 2pathfile.sh "+pwd);
    thread1_2->waitForFinished(1000);

    item = leftlist->currentItem();
    curstart = item->text();
    thread1_3 = new QProcess;
    thread1_3->start("bash 3delbootstart.sh "+pwd+" "+curstart);
    thread1_3->waitForFinished(1000);
    showbootstart();
    showbootclose();
}

//显示非开机自启动项
void middle5::showbootclose()
{
    rightlist->clear();
    thread2_1 = new QProcess;
    thread2_1->start("bash 1_2showname.sh");
    thread2_1->waitForFinished(1000);
    QFile resultFile("/tmp/result2");
    resultFile.open(QIODevice::ReadOnly);
    QTextStream in(&resultFile);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        item = new QListWidgetItem;
        item->setText(line);
        QFont item_font = item->font();
        item_font.setPointSize(13);
        item->setFont(item_font);
        rightlist->addItem(item);
    }
    resultFile.close();
}

//打开非自启动项
void middle5::openbootstart()
{
    QFile pwdfile("/tmp/pwd");
    pwdfile.open(QFile::ReadOnly);
    QTextStream pwdin(&pwdfile);
    pwd = pwdin.readLine();
    pwdfile.close();

    thread2_2 = new QProcess;
    thread2_2->start("bash 2_2pathfile.sh "+pwd);
    thread2_2->waitForFinished(1000);

    item = rightlist->currentItem();
    curstart = item->text();
    thread2_3 = new QProcess;
    thread2_3->start("bash 3_2delbootclose.sh "+pwd+" "+curstart);
    thread2_3->waitForFinished(1000);
    showbootclose();
    showbootstart();
}





