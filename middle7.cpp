#include "middle7.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
middle7::middle7(QWidget *parent) :
	QWidget(parent)
{
//窗口界面布局
	QWidget *widget = new QWidget(this);
	QHBoxLayout *mainlayout= new QHBoxLayout;

	QVBoxLayout *vlayout1 = new QVBoxLayout;
	QHBoxLayout *hlayout = new QHBoxLayout;
	QLabel *label = new QLabel(widget);
	QImage img;
	img.load(":images/users.png");
	QImage* imgScaled = new QImage;
	*imgScaled=img.scaled(140,140,Qt::KeepAspectRatio);
	label->setPixmap(QPixmap::fromImage(*imgScaled));
	label->setStyleSheet("QLabel{margin-left:0;margin-top:20px}");

	QLineEdit *tip = new QLineEdit("电脑用户：");
	tip->setFixedSize(300,80);
	tip->setStyleSheet("QLineEdit{font-size : 20px;color:gray;background-color:rgb(255,0,0,0);margin-top:20px;margin-right:140px}");
	tip->setFrame(false);
	tip->setReadOnly(true);

	hlayout->addWidget(label);
	hlayout->addWidget(tip);
//listwidget存放用户
	list = new QListWidget(widget);
	list->setFixedSize(360,360);
	list->setIconSize(QSize(48,48));
    list->setStyleSheet("background-color:rgb(255,0,0,0);border:0px;margin-left:120px;maigin-bottom:40px;");

	vlayout1->addLayout(hlayout);
	vlayout1->addWidget(list);
	vlayout1->addStretch(0);

//定义button
	QVBoxLayout *vlayout = new QVBoxLayout;

	QPushButton *user_pushbutton = new QPushButton("刷新/显示");
	user_pushbutton->setFixedSize(168,30);
	user_pushbutton->setStyleSheet("QPushButton{color:green;border: 1px solid green;border-radius:15px;margin-right:40px;}");

	QPushButton *add_pushbutton = new QPushButton("添加用户...");
	add_pushbutton->setFixedSize(168,30);
	add_pushbutton->setStyleSheet("QPushButton{color:blue;border: 1px solid blue;border-radius:15px;margin-right:40px;}");

	del_pushbutton = new QPushButton("删除用户");
	del_pushbutton->setStyleSheet("QPushButton{color:gray;border: 1px solid gray;border-radius:15px;margin-right:40px;}");
	del_pushbutton->setFixedSize(168,30);
	del_pushbutton->setEnabled(false);

	QPushButton *passwd_pushbutton = new QPushButton("修改密码...");
	passwd_pushbutton->setStyleSheet("QPushButton{color:blue;border: 1px solid blue;border-radius:15px;margin-right:40px;}");
	passwd_pushbutton->setFixedSize(168,30);

	black_pushbutton = new QPushButton("加入黑名单");
	black_pushbutton->setFixedSize(168,30);
	black_pushbutton->setStyleSheet("QPushButton{color:gray;border: 1px solid gray;border-radius:15px;margin-right:40px;}");
	black_pushbutton->setEnabled(false);

	delb_pushbutton = new QPushButton("移出黑名单");
	delb_pushbutton->setFixedSize(168,30);
	delb_pushbutton->setEnabled(false);
	delb_pushbutton->setStyleSheet("QPushButton{color:gray;border: 1px solid gray;border-radius:15px;margin-right:40px;}");

	vlayout->addWidget(user_pushbutton);
	vlayout->addWidget(add_pushbutton);
	vlayout->addWidget(del_pushbutton);
	vlayout->addWidget(passwd_pushbutton);
	vlayout->addWidget(black_pushbutton);
	vlayout->addWidget(delb_pushbutton);
	vlayout->setContentsMargins(0,123,80,50);

	mainlayout->addLayout(vlayout1);
	mainlayout->addLayout(vlayout);
	this->setLayout(mainlayout);

	flag = 0;
	//添加槽函数，按钮点击触发事件
	connect(list,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(blackFunc()));
	connect(user_pushbutton, SIGNAL(clicked()), this, SLOT(show_user()));
	connect(add_pushbutton, SIGNAL(clicked()), this, SLOT(add_user()));
	connect(del_pushbutton, SIGNAL(clicked()), this, SLOT(del_user()));
	connect(passwd_pushbutton, SIGNAL(clicked()), this, SLOT(passwd_change()));
	connect(black_pushbutton, SIGNAL(clicked()), this, SLOT(add_black()));
	connect(delb_pushbutton, SIGNAL(clicked()), this, SLOT(del_black()));
//定时器刷新界面
	timer = new QTimer(this);
	QWidget::connect( timer, SIGNAL( timeout() ), this, SLOT( timer_update_currentTabInfo() ) );
	timer->start(1000);

}
//定时器刷新界面槽函数
void middle7::timer_update_currentTabInfo()
{
	QProcess *thread1 = new QProcess;
    thread1->start("bash currentUser.sh");
	if(!thread1->waitForStarted())
	{
		qDebug()<<"failed start!";
	}

	while(true == thread1->waitForFinished());
	{
		currentUser = thread1->readAllStandardOutput();
	}

	QProcess *thread = new QProcess;
    thread->start("bash showuser.sh");
	if(!thread->waitForStarted())
	{
		qDebug()<<"failed start!";
	}
	while(true == thread->waitForFinished());
	{
        QFile fromFile("/tmp/user");
		fromFile.open(QIODevice::ReadOnly);
		QTextStream in(&fromFile);
		while(!in.atEnd())
		{
			QString line = in.readLine();
			QString temp;
			temp = line +  '\n';
			if(temp == currentUser)
			{
				line  += "    (当前用户)";
			}
			item = new QListWidgetItem(list);
			int islock=0;
			for(int i=0;i<flag;i++)
			{
				if(line == user_temp[i])
				{
					item->setIcon(QIcon(":images/userlock.png"));
					islock = 1;
					break;
				}

			}
			if(islock == 0)
			{
				item->setIcon(QIcon(":images/user.png"));
			}
			item->setText(line);
			list->addItem(item);
		}
		fromFile.close();
	}
	delete timer;
}
//点击listwidgetitem更改按钮属性
void middle7::blackFunc()
{
	del_pushbutton->setEnabled(true);
	del_pushbutton->setStyleSheet("QPushButton{color:green;border: 1px solid green;border-radius:15px;margin-right:40px;}");
	black_pushbutton->setEnabled(true);
	black_pushbutton->setStyleSheet("QPushButton{color:green;border: 1px solid green;border-radius:15px;margin-right:40px;}");
	delb_pushbutton->setEnabled(true);
	delb_pushbutton->setStyleSheet("QPushButton{color:green;border: 1px solid green;border-radius:15px;margin-right:40px;}");

}

//刷新按钮点击事件
void middle7::show_user()
{

	list->clear();
	QProcess *thread1 = new QProcess;
    thread1->start("bash currentUser.sh");
	if(!thread1->waitForStarted())
	{
		qDebug()<<"failed start!";
	}

	while(true == thread1->waitForFinished());
	{
		currentUser = thread1->readAllStandardOutput();
	}

	//执行shell脚本，获取当前电脑的用户
	QProcess *thread = new QProcess;
    thread->start("bash showuser.sh");
	if(!thread->waitForStarted())
	{
		qDebug()<<"failed start!";
	}
	while(true == thread->waitForFinished());
	{
        QFile fromFile("/tmp/user");
		fromFile.open(QIODevice::ReadOnly);
		QTextStream in(&fromFile);
		while(!in.atEnd())
		{
			QString line = in.readLine();
			QString temp;
			temp = line +  '\n';
			if(temp == currentUser)
			{
				line  += "    (当前用户)";//显示当前用户，避免误操作
			}
			item = new QListWidgetItem(list);//将当前用户显示到页面
			int islock=0;
			for(int i=0;i<flag;i++)
			{
				if(line == user_temp[i])
				{
					item->setIcon(QIcon(":images/userlock.png"));
					islock = 1;
					break;
				}

			}
			if(islock == 0)
			{
				item->setIcon(QIcon(":images/user.png"));
			}
			item->setText(line);
			list->addItem(item);
		}
		fromFile.close();
	}
}

//添加用户按钮点击事件
void middle7::add_user()
{
	myuser = new adduser;//显示添加界面

}

//删除按钮触发事件
void middle7::del_user()
{
	QListWidgetItem *item = list->currentItem();
	QString user = item->text();
    QFile mypwdfile("/tmp/pwd");
	mypwdfile.open(QFile::ReadOnly);
	QTextStream myin(&mypwdfile);
	QString pwd = myin.readLine();
	mypwdfile.close();
	QProcess *thread1 = new QProcess;
    thread1->start("bash del_user.sh "+pwd+" "+user);
	if(!thread1->waitForStarted())
	{
		qDebug()<<"failed start!";
	}

	while(true == thread1->waitForFinished());
	{
        qDebug()<<"hello";
		middle7::show_user();
	}
}

//更改密码触发事件
void middle7::passwd_change()
{
	changePasswd *ps = new changePasswd;//显示更改密码页面
}

//加入黑名单按钮触发事件
void middle7::add_black()
{
	QListWidgetItem *item = list->currentItem();
	QString temp = item->text();
	user_temp[flag] = temp;
	flag++;
	QListWidgetItem *item1 = new QListWidgetItem;
	list->removeItemWidget(item);
	delete item;
	item1->setIcon(QIcon(":images/userlock.png"));
	item1->setText(temp);
	list->addItem(item1);

    QFile mypwdfile("/tmp/pwd");
	mypwdfile.open(QFile::ReadOnly);
	QTextStream myin(&mypwdfile);
	QString pwd = myin.readLine();
	mypwdfile.close();

    system("bash add-black.sh "+pwd.toLatin1() +" "+ temp.toLatin1());

}

//移出黑名单按钮触发事件
void middle7::del_black()
{
	QListWidgetItem *item = list->currentItem();//获取按钮点击的item
	QString temp = item->text();//保存item的值
//在数组中删除该用户
	for(int i=0;i<flag;i++)
	{
		if(user_temp[i] == temp)
		{
			for(int j=i;j<flag;j++)
			  user_temp[j] = user_temp[j+1];
		}
	}
	QListWidgetItem *item1 = new QListWidgetItem;//新建一个item
	list->removeItemWidget(item);//删除原item
	delete item;
	item1->setIcon(QIcon(":images/user.png"));
	item1->setText(temp);
	list->addItem(item1);

    QFile mypwdfile("/tmp/pwd");
	mypwdfile.open(QFile::ReadOnly);
	QTextStream myin(&mypwdfile);
	QString pwd = myin.readLine();
	mypwdfile.close();

    system("bash del-black.sh "+pwd.toLatin1() +" "+ temp.toLatin1());

}
