#include "middle4.h"
#include <QDebug>

//构造函数
middle4::middle4(QWidget *parent) :
	QWidget(parent)
{
	//总主体水平布局
	mainlayout = new QHBoxLayout;
	//左边栏垂直布局
	vlayout = new QVBoxLayout;

	//放置图片
	mylabel = new QLabel;
	QImage img;
	img.load(":images/fullbin.png");
	QImage* imgScaled = new QImage;
	//设置图片边距
	mylabel->setStyleSheet("QLabel{margin-left:35px;margin-right:85px;}");
	//设置图片大小
	*imgScaled=img.scaled(250,250,Qt::KeepAspectRatio);
	mylabel->setPixmap(QPixmap::fromImage(*imgScaled));

	//绘制按钮
	mybtn = new QPushButton("查看垃圾");
	//设置按钮样式
	mybtn->setStyleSheet("QPushButton{font-size:17px;color:green;border: 1px solid green;border-radius:15px;height:30px;margin-left:35px;margin-right:85px;margin-bottom:100px;}");
	//设置按钮大小
	mybtn->resize(80,30);

	//图片加入左边栏
	vlayout->addWidget(mylabel);
	//按钮加入左边栏
	vlayout->addWidget(mybtn);

	//右边栏分5个水平布局
	QVBoxLayout *vlayout1 = new QVBoxLayout;
	QHBoxLayout *hlayout1 = new QHBoxLayout;
	QHBoxLayout *hlayout2 = new QHBoxLayout;
	QHBoxLayout *hlayout3 = new QHBoxLayout;
	QHBoxLayout *hlayout4= new QHBoxLayout;
	QHBoxLayout *hlayout5 = new QHBoxLayout;

	//需要放置5张图片
	mylabel1 = new QLabel;
	mylabel2 = new QLabel;
	mylabel3 = new QLabel;
	mylabel4 = new QLabel;
	mylabel5 = new QLabel;

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

	//绘制文本框显示垃圾大小并设置样式格式
	ret_rabish1 = new QLineEdit;
	ret_rabish1->setReadOnly(true);
	ret_rabish1->setStyleSheet("QLineEdit{font-size : 15px;color:black;background-color:rgb(255,0,0,0);margin-left:20;}");
	ret_rabish1->setFrame(false);

	//绘制文本框显示垃圾大小并设置样式格式
	ret_rabish2 = new QLineEdit;
	ret_rabish2->setReadOnly(true);
	ret_rabish2->setStyleSheet("QLineEdit{font-size : 15px;color:black;background-color:rgb(255,0,0,0);margin-left:20;}");
	ret_rabish2->setFrame(false);

	//绘制文本框显示垃圾大小并设置样式格式
	ret_rabish3 = new QLineEdit;
	ret_rabish3->setReadOnly(true);
	ret_rabish3->setStyleSheet("QLineEdit{font-size : 15px;color:black;background-color:rgb(255,0,0,0);margin-left:20;}");
	ret_rabish3->setFrame(false);

	//绘制文本框显示垃圾大小并设置样式格式
	ret_rabish4 = new QLineEdit;
	ret_rabish4->setReadOnly(true);
	ret_rabish4->setStyleSheet("QLineEdit{font-size : 15px;color:black;background-color:rgb(255,0,0,0);margin-left:20;}");
	ret_rabish4->setFrame(false);

	//绘制文本框显示垃圾大小并设置样式格式
	ret_rabish5 = new QLineEdit;
	ret_rabish5->setReadOnly(true);
	ret_rabish5->setStyleSheet("QLineEdit{font-size : 15px;color:black;background-color:rgb(255,0,0,0);margin-left:20;margin-bottom:50px}");
	ret_rabish5->setFrame(false);

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

	//指定按钮的槽函数
	connect(mybtn, SIGNAL(clicked()), this, SLOT(show()));

	//为文本框填充内容
	lineedit1->setText("回收站(bytes)");
	lineedit2->setText("包临时文件(bytes)");
	lineedit3->setText("缩略图(bytes)");
	lineedit4->setText("最近使用文档记录(bytes)");
	lineedit5->setText("垃圾总量(kb)");

	//绘制右边第1张图片并设置样式
	QImage img1;
	img1.load(":images/t1.png");
	QImage* imgScaled1 = new QImage;
	*imgScaled1=img1.scaled(40, 40,Qt::KeepAspectRatio);
	mylabel1->setStyleSheet("QLabel{margin-top:60px;}");
	mylabel1->setPixmap(QPixmap::fromImage(*imgScaled1));

	//绘制右边第2张图片并设置样式
	QImage img2;
	img2.load(":images/t2.png");
	QImage* imgScaled2 = new QImage;
	*imgScaled2=img2.scaled(40, 40,Qt::KeepAspectRatio);
	mylabel2->setPixmap(QPixmap::fromImage(*imgScaled2));

	//绘制右边第3张图片并设置样式
	QImage img3;
	img3.load(":images/t3.png");
	QImage* imgScaled3 = new QImage;
	*imgScaled3=img3.scaled(40, 40,Qt::KeepAspectRatio);
	mylabel3->setPixmap(QPixmap::fromImage(*imgScaled3));

	//绘制右边第4张图片并设置样式
	QImage img4;
	img4.load(":images/t4.png");
	QImage* imgScaled4 = new QImage;
	*imgScaled4=img4.scaled(40, 40,Qt::KeepAspectRatio);
	mylabel4->setPixmap(QPixmap::fromImage(*imgScaled4));

	//绘制右边第5张图片并设置样式
	QImage img5;
	img5.load(":images/t10.png");
	QImage* imgScaled5 = new QImage;
	*imgScaled5=img5.scaled(40, 40,Qt::KeepAspectRatio);
	mylabel5->setPixmap(QPixmap::fromImage(*imgScaled5));

	//左右垂直布局加入总水平布局
	mainlayout->addLayout(vlayout);
	mainlayout->addLayout(vlayout1);
	this->setLayout(mainlayout);
}

//点击按钮的槽函数
void middle4::show()
{
	//判断按钮文字,执行不同脚本
	if(mybtn->text() == "查看垃圾")
	{
		//改变按钮文字
		mybtn->setText("清理垃圾");
		//为文本框填充内容
		lineedit1->setText("回收站(bytes)");
		lineedit2->setText("包临时文件(bytes)");
		lineedit3->setText("缩略图(bytes)");
		lineedit4->setText("最近使用文档记录(bytes)");
		lineedit5->setText("垃圾总量(kb)");

		//新建线程执行垃圾总量脚本
		QProcess *thread5 = new QProcess;
        thread5->start("bash 9.sh");
		if(!thread5->waitForStarted())
		{
			qDebug()<<"failed start!";
		}

		while(true == thread5->waitForFinished());
		{
			QString ver = thread5->readAllStandardOutput();
			ret_rabish5->setText(ver);
		}

		//重新绘制图片
		QImage img;
		img.load(":images/fullbin.png");
		QImage* imgScaled = new QImage;
		*imgScaled=img.scaled(250, 250,Qt::KeepAspectRatio);
		mylabel->setStyleSheet("QLabel{margin-left:35px;margin-right:85px;}");
		mylabel->setPixmap(QPixmap::fromImage(*imgScaled));

		//重新绘制图片
		QImage img1;
		img1.load(":images/t1.png");
		QImage* imgScaled1 = new QImage;
		*imgScaled1=img1.scaled(40, 40,Qt::KeepAspectRatio);
		mylabel1->setStyleSheet("QLabel{margin-top:60px;}");
		mylabel1->setPixmap(QPixmap::fromImage(*imgScaled1));

		//重新绘制图片
		QImage img2;
		img2.load(":images/t2.png");
		QImage* imgScaled2 = new QImage;
		*imgScaled2=img2.scaled(40, 40,Qt::KeepAspectRatio);
		mylabel2->setPixmap(QPixmap::fromImage(*imgScaled2));

		//重新绘制图片
		QImage img3;
		img3.load(":images/t3.png");
		QImage* imgScaled3 = new QImage;
		*imgScaled3=img3.scaled(40, 40,Qt::KeepAspectRatio);
		mylabel3->setPixmap(QPixmap::fromImage(*imgScaled3));

		//重新绘制图片
		QImage img4;
		img4.load(":images/t4.png");
		QImage* imgScaled4 = new QImage;
		*imgScaled4=img4.scaled(40, 40,Qt::KeepAspectRatio);
		mylabel4->setPixmap(QPixmap::fromImage(*imgScaled4));

		//重新绘制图片
		QImage img5;
		img5.load(":images/t10.png");
		QImage* imgScaled5 = new QImage;
		*imgScaled5=img5.scaled(40, 40,Qt::KeepAspectRatio);
		mylabel5->setPixmap(QPixmap::fromImage(*imgScaled5));

		//新建线程执行回收站脚本
		QProcess *thread1 = new QProcess;
        thread1->start("bash 1.sh");
		if(!thread1->waitForStarted())
		{
			qDebug()<<"failed start!";
		}

		while(true == thread1->waitForFinished());
		{
			QString ver = thread1->readAllStandardOutput();
			ret_rabish1->setText(ver);
		}

		//新建线程执行包临时文件脚本
		QProcess *thread2 = new QProcess;
        thread2->start("bash 2.sh");
		if(!thread2->waitForStarted())
		{
			qDebug()<<"failed start!";
		}

		while(true == thread2->waitForFinished());
		{
			QString ver = thread2->readAllStandardOutput();
			ret_rabish2->setText(ver);
		}

		//新建线程执行缩略图脚本
		QProcess *thread3 = new QProcess;
        thread3->start("bash 3.sh");
		if(!thread3->waitForStarted())
		{
			qDebug()<<"failed start!";
		}

		while(true == thread3->waitForFinished());
		{
			QString ver = thread3->readAllStandardOutput();
			ret_rabish3->setText(ver);
		}


		//新建线程执行最近使用文档记录脚本
		QProcess *thread4 = new QProcess;
        thread4->start("bash 4.sh");
		if(!thread4->waitForStarted())
		{
			qDebug()<<"failed start!";
		}

		while(true == thread4->waitForFinished());
		{
			QString ver = thread4->readAllStandardOutput();
			ret_rabish4->setText(ver);
		}
	}
	else{
		//改变按钮文字
		mybtn->setText("查看垃圾");

		//为文本框填充内容
		lineedit1->setText("清理回收站(bytes)");
		lineedit2->setText("清理包临时文件(bytes)");
		lineedit3->setText("清理缩略图(bytes)");
		lineedit4->setText("清理最近使用文档记录(bytes)");
		lineedit5->setText("清理总量(kb)");

		//重新绘制图片并设置样式
		QImage img;
		img.load(":images/emptybin.png");
		QImage* imgScaled = new QImage;
		*imgScaled=img.scaled(250, 250,Qt::KeepAspectRatio);
		mylabel->setStyleSheet("QLabel{margin-left:35px;margin-right:85px;}");
		mylabel->setPixmap(QPixmap::fromImage(*imgScaled));

		//重新绘制图片并设置样式
		QImage img1;
		img1.load(":images/t5.png");
		QImage* imgScaled1 = new QImage;
		*imgScaled1=img1.scaled(40, 40,Qt::KeepAspectRatio);
		mylabel1->setStyleSheet("QLabel{margin-top:60px;}");
		mylabel1->setPixmap(QPixmap::fromImage(*imgScaled1));

		//重新绘制图片并设置样式
		QImage img2;
		img2.load(":images/t6.png");
		QImage* imgScaled2 = new QImage;
		*imgScaled2=img2.scaled(40, 40,Qt::KeepAspectRatio);
		mylabel2->setPixmap(QPixmap::fromImage(*imgScaled2));

		//重新绘制图片并设置样式
		QImage img3;
		img3.load(":images/t7.png");
		QImage* imgScaled3 = new QImage;
		*imgScaled3=img3.scaled(40, 40,Qt::KeepAspectRatio);
		mylabel3->setPixmap(QPixmap::fromImage(*imgScaled3));

		//重新绘制图片并设置样式
		QImage img4;
		img4.load(":images/t8.png");
		QImage* imgScaled4 = new QImage;
		*imgScaled4=img4.scaled(40, 40,Qt::KeepAspectRatio);
		mylabel4->setPixmap(QPixmap::fromImage(*imgScaled4));

		//重新绘制图片并设置样式
		QImage img5;
		img5.load(":images/t9.png");
		QImage* imgScaled5 = new QImage;
		*imgScaled5=img5.scaled(40, 40,Qt::KeepAspectRatio);
		mylabel5->setPixmap(QPixmap::fromImage(*imgScaled5));

		//新建线程执行清空回收站脚本
		QProcess *thread1 = new QProcess;
        thread1->start("bash 5.sh");
		if(!thread1->waitForStarted())
		{
			qDebug()<<"failed start!";
		}

		while(true == thread1->waitForFinished());
		{
			QString ver = thread1->readAllStandardOutput();
			ret_rabish1->setText(ver);
		}

		//新建线程执行清空包临时文件脚本
		QProcess *thread2 = new QProcess;
        thread2->start("bash 6.sh");
		if(!thread2->waitForStarted())
		{
			qDebug()<<"failed start!";
		}

		while(true == thread2->waitForFinished());
		{
			QString ver = thread2->readAllStandardOutput();
			ret_rabish2->setText(ver);
		}

		//新建线程执行清空缩略图脚本
		QProcess *thread3 = new QProcess;
        thread3->start("bash 7.sh");
		if(!thread3->waitForStarted())
		{
			qDebug()<<"failed start!";
		}

		while(true == thread3->waitForFinished());
		{
			QString ver = thread3->readAllStandardOutput();
			ret_rabish3->setText(ver);
		}


		//新建线程执行清空最近使用文档记录脚本
		QProcess *thread4 = new QProcess;
        thread4->start("bash 8.sh");
		if(!thread4->waitForStarted())
		{
			qDebug()<<"failed start!";
		}

		while(true == thread4->waitForFinished());
		{
			QString ver = thread4->readAllStandardOutput();
			ret_rabish4->setText(ver);
		}

	}
}

//析构函数
middle4::~middle4()
{
}
