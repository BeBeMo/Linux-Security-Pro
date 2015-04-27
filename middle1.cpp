#include "middle1.h"
#include <QDebug>
#include <QTextStream>

//构造函数
middle1::middle1(QWidget *parent) :
	QWidget(parent)
{
	//总主体水平布局
	mainlayout = new QHBoxLayout;
	//左边栏垂直布局
	vlayout = new QVBoxLayout;

	//放置图片
	mylabel = new QLabel;
	QImage img;
	img.load(":images/e1.png");
	QImage* imgScaled = new QImage;
	//设置图片边距
    mylabel->setStyleSheet("QLabel{margin-left:40px;margin-right:90px;}");
	//设置图片大小
	*imgScaled=img.scaled(250,250,Qt::KeepAspectRatio);
	mylabel->setPixmap(QPixmap::fromImage(*imgScaled));

	//绘制按钮
	mybtn = new QPushButton("一键体检");
	//设置按钮样式
    mybtn->setStyleSheet("QPushButton{font-size:17px;color:green;border: 1px solid green;border-radius:15px;height:30px;margin-left:40px;margin-right:90px;margin-bottom:100px;}");
	//设置按钮大小
	mybtn->resize(80,30);

	//图片加入左边栏
	vlayout->addWidget(mylabel);
	//按钮加入左边栏
	vlayout->addWidget(mybtn);

	//右边栏分6个水平布局
	QVBoxLayout *vlayout1 = new QVBoxLayout;
	QHBoxLayout *hlayout1 = new QHBoxLayout;
	QHBoxLayout *hlayout2 = new QHBoxLayout;
	QHBoxLayout *hlayout3 = new QHBoxLayout;
	QHBoxLayout *hlayout4 = new QHBoxLayout;
	QHBoxLayout *hlayout5 = new QHBoxLayout;
	QHBoxLayout *hlayout6 = new QHBoxLayout;

	//需要放置6张图片
	mylabel1 = new QLabel;
	mylabel2 = new QLabel;
	mylabel3 = new QLabel;
	mylabel4 = new QLabel;
	mylabel5 = new QLabel;
	mylabel6 = new QLabel;

	//绘制文本框1并设置样式,与第1张图一起加入第1个水平布局
	lineedit1 = new QLineEdit;
	lineedit1->setReadOnly(true);
	lineedit1->setStyleSheet("QLineEdit{font-size : 20px;color:blue;background-color:rgb(255,0,0,0);margin-top:60px;}");
	lineedit1->setFrame(false);
	hlayout1->addWidget(mylabel1);
	hlayout1->addWidget(lineedit1);

	//绘制文本框2并设置样式,与第2张图一起加入第2个水平布局
	lineedit2 = new QLineEdit;
	lineedit2->setReadOnly(true);
	lineedit2->setStyleSheet("QLineEdit{font-size : 20px;color:blue;background-color:rgb(255,0,0,0);}");
	lineedit2->setFrame(false);
	hlayout2->addWidget(mylabel2);
	hlayout2->addWidget(lineedit2);

	//绘制文本框3并设置样式,与第3张图一起加入第3个水平布局
	lineedit3 = new QLineEdit;
	lineedit3->setReadOnly(true);
	lineedit3->setStyleSheet("QLineEdit{font-size : 20px;color:blue;background-color:rgb(255,0,0,0);}");
	lineedit3->setFrame(false);
	hlayout3->addWidget(mylabel3);
	hlayout3->addWidget(lineedit3);

	//绘制文本框4并设置样式,与第4张图一起加入第4个水平布局
	lineedit4 = new QLineEdit;
	lineedit4->setReadOnly(true);
	lineedit4->setStyleSheet("QLineEdit{font-size : 20px;color:blue;background-color:rgb(255,0,0,0);}");
	lineedit4->setFrame(false);
	hlayout4->addWidget(mylabel4);
	hlayout4->addWidget(lineedit4);

	//绘制文本框5并设置样式,与第5张图一起加入第5个水平布局
	lineedit5 = new QLineEdit;
	lineedit5->setReadOnly(true);
	lineedit5->setStyleSheet("QLineEdit{font-size : 20px;color:blue;background-color:rgb(255,0,0,0);}");
	lineedit5->setFrame(false);
	hlayout5->addWidget(mylabel5);
	hlayout5->addWidget(lineedit5);

	//绘制文本框6并设置样式,与第6张图一起加入第6个水平布局
	lineedit6 = new QLineEdit;
	lineedit6->setReadOnly(true);
	lineedit6->setStyleSheet("QLineEdit{font-size : 20px;color:blue;background-color:rgb(255,0,0,0);}");
	lineedit6->setFrame(false);
	hlayout6->addWidget(mylabel6);
	hlayout6->addWidget(lineedit6);

	//绘制文本框显示体检结果并设置样式格式
	ret_rabish1 = new QLineEdit;
	ret_rabish1->setReadOnly(true);
	ret_rabish1->setStyleSheet("QLineEdit{font-size : 15px;color:black;background-color:rgb(255,0,0,0);margin-left:20;}");
	ret_rabish1->setFrame(false);

	//绘制文本框显示体检结果并设置样式格式
	ret_rabish2 = new QLineEdit;
	ret_rabish2->setReadOnly(true);
	ret_rabish2->setStyleSheet("QLineEdit{font-size : 15px;color:black;background-color:rgb(255,0,0,0);margin-left:20;}");
	ret_rabish2->setFrame(false);

	//绘制文本框显示体检结果并设置样式格式
	ret_rabish3 = new QLineEdit;
	ret_rabish3->setReadOnly(true);
	ret_rabish3->setStyleSheet("QLineEdit{font-size : 15px;color:black;background-color:rgb(255,0,0,0);margin-left:20;}");
	ret_rabish3->setFrame(false);

	//绘制文本框显示体检结果并设置样式格式
	ret_rabish4 = new QLineEdit;
	ret_rabish4->setReadOnly(true);
	ret_rabish4->setStyleSheet("QLineEdit{font-size : 15px;color:black;background-color:rgb(255,0,0,0);margin-left:20;}");
	ret_rabish4->setFrame(false);

	//绘制文本框显示体检结果并设置样式格式
	ret_rabish5 = new QLineEdit;
	ret_rabish5->setReadOnly(true);
	ret_rabish5->setStyleSheet("QLineEdit{font-size : 15px;color:black;background-color:rgb(255,0,0,0);margin-left:20;}");
	ret_rabish5->setFrame(false);

	//绘制文本框显示体检结果并设置样式格式
	ret_rabish6 = new QLineEdit;
	ret_rabish6->setReadOnly(true);
	ret_rabish6->setStyleSheet("QLineEdit{font-size : 15px;color:black;background-color:rgb(255,0,0,0);margin-left:20;margin-bottom:50px;}");
	ret_rabish6->setFrame(false);

	//绘制右边第1张图片并设置样式
	QImage img1;
	img1.load(":images/time.png");
	QImage* imgScaled1 = new QImage;
	*imgScaled1=img1.scaled(30, 30,Qt::KeepAspectRatio);
	mylabel1->setStyleSheet("QLabel{margin-top:60px;}");
	mylabel1->setPixmap(QPixmap::fromImage(*imgScaled1));

	//绘制右边第2张图片并设置样式
	QImage img2;
	img2.load(":images/cpu.png");
	QImage* imgScaled2 = new QImage;
	*imgScaled2=img2.scaled(30, 30,Qt::KeepAspectRatio);
	mylabel2->setPixmap(QPixmap::fromImage(*imgScaled2));

	//绘制右边第3张图片并设置样式
	QImage img3;
	img3.load(":images/speed.png");
	QImage* imgScaled3 = new QImage;
	*imgScaled3=img3.scaled(30, 30,Qt::KeepAspectRatio);
	mylabel3->setPixmap(QPixmap::fromImage(*imgScaled3));

	//绘制右边第4张图片并设置样式
	QImage img4;
	img4.load(":images/cache.png");
	QImage* imgScaled4 = new QImage;
	*imgScaled4=img4.scaled(30, 30,Qt::KeepAspectRatio);
	mylabel4->setPixmap(QPixmap::fromImage(*imgScaled4));

	//绘制右边第5张图片并设置样式
	QImage img5;
	img5.load(":images/ufw.png");
	QImage* imgScaled5 = new QImage;
	*imgScaled5=img5.scaled(30, 30,Qt::KeepAspectRatio);
	mylabel5->setPixmap(QPixmap::fromImage(*imgScaled5));

	//绘制右边第6张图片并设置样式
	QImage img6;
	img6.load(":images/zomble.png");
	QImage* imgScaled6 = new QImage;
	*imgScaled6=img6.scaled(30, 30,Qt::KeepAspectRatio);
	mylabel6->setPixmap(QPixmap::fromImage(*imgScaled6));

	//为文本框填充内容
	lineedit1->setText("电脑运行时间");
	lineedit2->setText("cpu使用情况");
	lineedit3->setText("网速测试");
	lineedit4->setText("内存/缓存使用情况");
	lineedit5->setText("防火墙状态") ;
	lineedit6->setText("僵尸进程");

	//上一步的水平布局与结果文本框一起加入右边栏垂直布局
	vlayout1->addLayout(hlayout1);
	vlayout1->addWidget(ret_rabish1);
	vlayout1->addLayout(hlayout2);
	vlayout1->addWidget(ret_rabish2);
	vlayout1->addLayout(hlayout3);
	vlayout1->addWidget(ret_rabish3);
	vlayout1->addLayout(hlayout4);
	vlayout1->addWidget(ret_rabish4);
	vlayout1->addLayout(hlayout5);
	vlayout1->addWidget(ret_rabish5);
	vlayout1->addLayout(hlayout6);
	vlayout1->addWidget(ret_rabish6);

	//指定按钮的槽函数
	connect(mybtn, SIGNAL(clicked()), this, SLOT(show()));

	//左右垂直布局加入总水平布局
	mainlayout->addLayout(vlayout);
	mainlayout->addLayout(vlayout1);
	this->setLayout(mainlayout);
}

//点击按钮的槽函数
void middle1::show()
{
	

	//新建线程执行电脑运行时间脚本
	QProcess *thread1 = new QProcess;
    thread1->start("bash time.sh");
	if(!thread1->waitForStarted())
	{
		qDebug()<<"failed start!";
	}

	while(true == thread1->waitForFinished());
	{
		QString ver = thread1->readAllStandardOutput();
		ret_rabish1->setText(ver);
	}

	//新建线程执行CPU利用率脚本
	QProcess *thread2 = new QProcess;
    thread2->start("bash cpu.sh");
	if(!thread2->waitForStarted())
	{
		qDebug()<<"failed start!";
	}

	while(true == thread2->waitForFinished());
	{
		QString ver = thread2->readAllStandardOutput();
		ret_rabish2->setText(ver);
	}

	//新建线程执行网速测试脚本
	QProcess *thread3 = new QProcess;
    thread3->start("bash speed.sh");
	if(!thread3->waitForStarted())
	{
		qDebug()<<"failed start!";
	}

	thread3->waitForFinished(5000);
	//while(true == thread3->waitForFinished());
	//{
	QString ver = thread3->readAllStandardOutput();
	ret_rabish3->setText(ver);
	//}

	//判断按钮文字,执行不同脚本
	if(mybtn->text() == "一键体检")
	{
		//改变按钮文字
		mybtn->setText("一键修复");
		//重新绘制图片并设置样式
		QImage img;
		img.load(":images/e3.png");
		QImage* imgScaled = new QImage;
		*imgScaled=img.scaled(230, 230,Qt::KeepAspectRatio);
        mylabel->setStyleSheet("QLabel{margin-left:40px;margin-right:105px;}");
		mylabel->setPixmap(QPixmap::fromImage(*imgScaled));

		//新建线程执行查看内存缓存脚本
		QProcess *thread4 = new QProcess;
        thread4->start("bash meca.sh");
		if(!thread4->waitForStarted())
		{
			qDebug()<<"failed start!";
		}

		while(true == thread4->waitForFinished());
		{
			QString ver = thread4->readAllStandardOutput();
			ret_rabish4->setText(ver);
		}

		//新建线程执行查看ufw防火墙状态脚本
		QProcess *thread5 = new QProcess;
		//打开存放密码文件
        QFile mypwdfile("/tmp/pwd");
		mypwdfile.open(QFile::ReadOnly);
		QTextStream myin(&mypwdfile);
		//读取密码
		QString pwd = myin.readLine();
        QString mystring = "bash ufw.sh ";
		//密码作为脚本参数
		mystring += pwd;
		thread5->start(mystring);
		if(!thread5->waitForStarted())
		{
			qDebug()<<"failed start!";
		}

		while(true == thread5->waitForFinished());
		{
			QString ver = thread5->readAllStandardOutput();
			ret_rabish5->setText(ver);
		}


		//新建线程执行查看僵尸进程脚本
		QProcess *thread6 = new QProcess;
        thread6->start("bash zomble_count.sh");
		if(!thread6->waitForStarted())
		{
			qDebug()<<"failed start!";
		}

		while(true == thread6->waitForFinished());
		{
			QString ver = thread6->readAllStandardOutput();
			ret_rabish6->setText(ver);
		}
	}
	else{
		//改变按钮文字
		mybtn->setText("一键体检");
		//重新绘制图片
		QImage img;
		img.load(":images/e1.png");
		QImage* imgScaled = new QImage;
		*imgScaled=img.scaled(250, 250,Qt::KeepAspectRatio);
        mylabel->setStyleSheet("QLabel{margin-left:40px;margin-right:90px;}");
		mylabel->setPixmap(QPixmap::fromImage(*imgScaled));

		//新建线程执行释放内存缓存脚本
		QProcess *thread4 = new QProcess;
        thread4->start("bash clean_cache.sh");
		if(!thread4->waitForStarted())
		{
			qDebug()<<"failed start!";
		}

		while(true == thread4->waitForFinished());
		{
			QString ver = thread4->readAllStandardOutput();
			ret_rabish4->setText(ver);
		}


		//新建线程执行打开ufw防火墙脚本
		QProcess *thread5 = new QProcess;
		//打开密码文件
        QFile mypwdfile("/tmp/pwd");
		mypwdfile.open(QFile::ReadOnly);
		QTextStream myin(&mypwdfile);
		//读取密码
		QString pwd = myin.readLine();
        QString mystring = "bash open_ufw.sh ";
		//密码作为脚本参数
		mystring += pwd;
		thread5->start(mystring);
		if(!thread5->waitForStarted())
		{
			qDebug()<<"failed start!";
		}

		while(true == thread5->waitForFinished());
		{
			QString ver = thread5->readAllStandardOutput();
			ret_rabish5->setText(ver);
		}


		//新建线程执行杀死僵尸进程脚本
		QProcess *thread6 = new QProcess;
        thread6->start("bash zomble_kill.sh");
		if(!thread6->waitForStarted())
		{
			qDebug()<<"failed start!";
		}

		while(true == thread6->waitForFinished());
		{
			QString ver = thread6->readAllStandardOutput();
			ret_rabish6->setText(ver);
		}
	}
}

//析构函数
middle1::~middle1()
{
}
