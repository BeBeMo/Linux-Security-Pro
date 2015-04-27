#include "middle3.h"
#include <QDebug>
#include <QProcess>
#include "filePath.h"
#include <QFile>

middle3::middle3(QWidget *parent) :
	QWidget(parent)
{
	return_num = '0';
	tabWidget = new QTabWidget();
	tabWidget->setIconSize(QSize(220,220));
	tabWidget->setStyleSheet("QTabBar::tab {height: 40px; width:220px;color: black;font-size:20px;padding: 5px;margin-left:40px;}"
				"QTabBar::tab:selected { background: lightgray; } ");

	//新建第一个页面的部件,全盘查杀
	widget1 = new QWidget();
	QVBoxLayout *mainLayout = new QVBoxLayout(widget1);
	QHBoxLayout *hLayout4 = new QHBoxLayout(widget1);
	QLineEdit *tip1 = new QLineEdit("上次查杀时间：");
	tip1->setFixedSize(220,60);
	tip1->setStyleSheet("QLineEdit{font-size : 20px;color:blue;background-color:rgb(255,0,0,0);margin-top:20;margin-left:60;}");
	tip1->setFrame(false);
	tip1->setReadOnly(true);
	time = new QLineEdit(widget1);
	time->setStyleSheet("QLineEdit{font-size : 40px;color:black;background-color:rgb(255,0,0,0);background-position:center;background-attachment:fixed;background-image:url(:images/dariay.png);margin-top:20;margin-right:10;}");
	time->setFixedSize(240,100);
	time->setAlignment(Qt::AlignCenter);
	time->setFrame(false);
	time->setReadOnly(true);
	hLayout4->addWidget(tip1);
	hLayout4->addWidget(time);

	QHBoxLayout *hLayout = new QHBoxLayout(widget1);
	QLineEdit *tip = new QLineEdit("全盘查杀比较慢，请耐心等候");
	tip->setFixedSize(300,50);
	tip->setStyleSheet("QLineEdit{font-size : 20px;color:gray;background-color:rgb(255,0,0,0);margin-top:20;margin-right:20;margin-left:20;}");
	tip->setFrame(false);
	tip->setReadOnly(true);
	QPushButton *kill_pushbutton = new QPushButton("开始查杀");
	QPushButton *stop_pushbutton = new QPushButton("停止查杀");
	kill_pushbutton->setStyleSheet("QPushButton{color:green;margin-top:20;border: 1px solid green;border-radius:15px;height:30px;margin-left:30px}");
	stop_pushbutton->setStyleSheet("QPushButton{color:blue;margin-top:20;border: 1px solid blue;border-radius:15px;height:30px;margin-right:30px}");
	hLayout->addWidget(tip);
	hLayout->addWidget(kill_pushbutton);
	hLayout->addWidget(stop_pushbutton);

	QHBoxLayout *hLayout0 = new QHBoxLayout(widget1);
	QLabel *label3 = new QLabel(widget1);
	QImage img;
	img.load(":images/safefile.png");
	QImage* imgScaled = new QImage;
	*imgScaled=img.scaled(100,100,Qt::KeepAspectRatio);
	label3->setPixmap(QPixmap::fromImage(*imgScaled));
	label3->setStyleSheet("QLabel{margin-left:100;}");

	safnum = new QLineEdit(widget1);
	safnum->setStyleSheet("QLineEdit{font-size : 40px;color:black;background-color:rgb(255,0,0,0);margin-left:20;}");
	safnum->setFrame(false);
	safnum->setFixedSize(200,60);
	safnum->setAlignment(Qt::AlignCenter);
	safnum->setText("0");

	QLineEdit *saffile = new QLineEdit("安全文件 !");
	saffile->setStyleSheet("QLineEdit{font-size : 25px;color:blue;background-color:rgb(255,0,0,0);margin-left:20;}");
	saffile->setFrame(false);
	saffile->setReadOnly(true);
	hLayout0->addWidget(label3);
	hLayout0->addWidget(safnum);
	hLayout0->addWidget(saffile);

	QHBoxLayout *hLayout1 = new QHBoxLayout(widget1);
	QLabel *label4 = new QLabel(widget1);
	QImage img2;
	img2.load(":images/virusfile.png");
	QImage* imgScaled2 = new QImage;
	*imgScaled2=img2.scaled(100, 100,Qt::KeepAspectRatio);
	label4->setPixmap(QPixmap::fromImage(*imgScaled2));
	label4->setStyleSheet("QLabel{margin-left:100;}");
	virnum = new QLineEdit(widget1);
	virnum->setStyleSheet("QLineEdit{font-size : 40px;color:red;background-color:rgb(255,0,0,0);margin-left:20;}");
	virnum->setFrame(false);
	virnum->setFixedSize(200,60);
	virnum->setAlignment(Qt::AlignCenter);
	virnum->setText("0");

	QLineEdit *virfile = new QLineEdit("危险文件 !");
	virfile->setReadOnly(true);
	virfile->setStyleSheet("QLineEdit{font-size : 25px;color:red;background-color:rgb(255,0,0,0);margin-left:20;}");
	virfile->setFrame(false);
	hLayout1->addWidget(label4);
	hLayout1->addWidget(virnum);
	hLayout1->addWidget(virfile);

	result_label1 = new QTextEdit(widget1);
	QPalette pl1 = result_label1->palette();
	pl1.setBrush(QPalette::Base,QBrush(QColor(255,0,0,0)));
	result_label1->setPalette(pl1);
	result_label1->setAlignment(Qt::AlignTop);
	result_label1->setReadOnly(true);

	mainLayout->setSpacing(10);
	mainLayout->addLayout(hLayout4);
	mainLayout->addLayout(hLayout);
	mainLayout->addLayout(hLayout0);
	mainLayout->addLayout(hLayout1);
	mainLayout->addWidget(result_label1);
	widget1->setLayout(mainLayout);
	connect(kill_pushbutton, SIGNAL(clicked()), this, SLOT(all_file()));

	//新建第二个页面的部件，选择查杀
	widget2 = new QWidget();
	QHBoxLayout *mainLayout2 = new QHBoxLayout(widget2);
	mainLayout2->setSpacing(30);
	QVBoxLayout *vLayout1 = new QVBoxLayout(widget2);
	vLayout1->setMargin(0);
	vLayout1->setSpacing(0);
	QLabel *label = new QLabel(widget2);
	QPixmap map(":images/file.png");
	label->setPixmap(map);

	vLayout1->addWidget(label);
	QLabel *label2 = new QLabel(widget2);
	label2->setText("请输入需要查杀的目录:");
	label2->setFixedHeight(25);
	label2->setAlignment(Qt::AlignCenter);
	fileline = new QLineEdit(widget2);
	fileline->setText("/home");
	fileline->setStyleSheet("QLineEdit{color:gray;background-color:rgb(255,0,0,0)}");
	fileline->setFrame(false);
	fileline->setFixedSize(150,60);
	fileline->setTextMargins(20,0,0,0);
	scan_pushbutton = new QPushButton("浏览...");
	scan_pushbutton->setStyleSheet("QPushButton{color:blue;border: 1px solid blue;border-radius:15px;height:30px;margin-left:10px}");
	execute_pushbutton = new QPushButton("开始查杀");
	execute_pushbutton->setStyleSheet("QPushButton{color:green;border: 1px solid green;border-radius:15px;height:30px;margin-left:10px}");
	QFont tip_font2 = label2->font();

	tip_font2.setPointSize(14);
	tip_font2.setItalic(true);
	tip_font2.setBold(true);
	label2->setFont(tip_font2);

	vLayout1->addWidget(label2);
	QHBoxLayout *hLayout3 = new QHBoxLayout(widget2);
	hLayout3->addWidget(scan_pushbutton);
	hLayout3->addWidget(execute_pushbutton);
	hLayout3->setMargin(30);
	vLayout1->addWidget(fileline);
	vLayout1->addLayout(hLayout3);

	QVBoxLayout *vLayout2 = new QVBoxLayout(widget2);
	QHBoxLayout *hLayout2 = new QHBoxLayout(widget2);
	QLabel *label1= new QLabel(widget2);
	label1->setText("运行结果：");
	label1->setAlignment(Qt::AlignLeft);
	label1->setFixedHeight(25);
	QFont tip_font = label1->font();
	tip_font.setPointSize(14);
	tip_font.setBold(true);
	label1->setFont(tip_font);
	hLayout2->addWidget(label1);
	hLayout2->setSpacing(0);
	hLayout2->setMargin(30);
	result_label = new QTextEdit(widget2);
	QPalette pl = result_label->palette();
	pl.setBrush(QPalette::Base,QBrush(QColor(255,0,0,0)));
	result_label->setPalette(pl);
	result_label->setAlignment(Qt::AlignTop);
	result_label->setReadOnly(true);
	vLayout2->setMargin(0);
	vLayout2->setSpacing(0);
	vLayout2->addLayout(hLayout2);
	vLayout2->addWidget(result_label);
	mainLayout2->addLayout(vLayout1);
	mainLayout2->addLayout(vLayout2);
	widget2->setLayout(mainLayout2);

	QIcon icon1(":images/full_scan.png");
	tabWidget->addTab(widget1,icon1,"");
	QIcon icon2(":images/custom_scan.png");
	tabWidget->addTab(widget2, icon2,"");

	QVBoxLayout *layout = new QVBoxLayout();
	layout->addWidget(tabWidget);
	this->setLayout(layout);
	connect(scan_pushbutton, SIGNAL(clicked()), this, SLOT(show_file()));
	connect(execute_pushbutton, SIGNAL(clicked()), this, SLOT(scan_file()));
	connect(stop_pushbutton, SIGNAL(clicked()), this, SLOT(kill_process()));
	connect(fileline, SIGNAL(textChanged(QString)), this, SLOT(get_file()));
	temp = 0;
	flag = 0;
	myThread = new QProcess;
	myThread1 = new QProcess;
	//定时器，实时刷新
	timer = new QTimer(this);
	QWidget::connect( timer, SIGNAL( timeout() ), this, SLOT( timer_update_currentTabInfo() ) );
	timer->start(0075);

}
//刷新页面槽函数
void middle3::timer_update_currentTabInfo()
{

    myThread1->start("bash modify.sh");
	if(!myThread1->waitForStarted())
	{
		qDebug()<<"failed start!";
	}
	while(true == myThread1->waitForFinished());
	{
		QString ver1 = myThread1->readAllStandardOutput();
		time->setText(ver1);
	}

    myThread->start("bash ps-file.sh");
	if(!myThread->waitForStarted())
	{
		qDebug()<<"failed start!";
	}
	while(true == myThread->waitForFinished());
	{
		bool ok2;
		QString ver = myThread->readAllStandardOutput();
		int dec = ver.toInt(&ok2,10);

		if(dec >=1)
		{
            QFile fromFile1("/tmp/filenum.sh");
			fromFile1.open(QIODevice::ReadOnly);
			QTextStream in1(&fromFile1);
			while(!in1.atEnd())
			{
				line = in1.readLine();
			}
		}
	}
	if((line.toInt() == 0 || line.toInt() > temp) && flag == 1)
	{
		result_label1->setText("查杀中，请稍后。。。");
		temp++;
		char str[10];
		QString str1;
		sprintf(str,"%d",temp);
		str1 = str;
		safnum->setText(str1);
	}
	if(line.toInt() == temp && temp != 0)
	{
		result_label1->setText("无病毒文件，亲可以放心啦～");
	}


}

void middle3:: scan_file()
{
	//     int totalline = 0;
	QString ver = "查杀中，请稍后。。。";
	result_label->setText(ver);
	QProcess *thread = new QProcess;
    thread->start("bash select-virus.sh "+gettext);
	if(!thread->waitForStarted())
	{
		qDebug()<<"failed start!";
	}

	while(true == thread->waitForFinished());
	{
		ver = thread->readAllStandardOutput();
		if(ver == "")
		{
			ver = "没有需要查杀的文件。。。";
            result_label->setText(ver);
		}
		else
		  result_label->setText(ver);

	}
}


void middle3::show_file()
{
	filepath = new filePath;
	fileline->setText("/home");
	result_label->clear();
}


void middle3::get_file()
{
	gettext = fileline->text();

}

void middle3::all_file()
{
	flag = 1;
	temp = 0;
	line = '0';
    QFile fromFile("/tmp/filenum.sh");
	fromFile.open(QIODevice::WriteOnly);
	fromFile.write("0",1);
	fromFile.close();
	result_label1->setText("查杀中，请稍后。。。");
	QProcess *thread1 = new QProcess;
	thread1->start("bash all-virus.sh");
	if(!thread1->waitForStarted())
	{
		qDebug()<<"failed start!";
	}

	while(true == thread1->waitForFinished());
	{
		return_num = thread1->readAllStandardOutput();

	}
}

void middle3::kill_process()
{
	QProcess *thread = new QProcess;
	thread->start("killall all-file");
	if(!thread->waitForStarted())
	{
		qDebug()<<"failed start!";
	}

	while(true == thread->waitForFinished());
	{
		//        ver = thread->readAllStandardOutput();
		safnum->setText("0");
		flag = 0;
		temp = 0;
		line = "0";
		result_label1->setText("点击按钮查杀!");

	}
}

middle3::~middle3()
{

}
