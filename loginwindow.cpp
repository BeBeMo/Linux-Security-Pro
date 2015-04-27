#include "loginwindow.h"

loginwindow::loginwindow(QWidget *parent) :
    QDialog(parent)
{
    resize(330,350);    //重设登陆窗口的大小
    QDesktopWidget *desktop = QApplication::desktop();  //将窗口设置为居中
    move((desktop->width()-this->width())/2,(desktop->height()-this->height())/2);

    QLabel *logolabel = new QLabel(this);   //设置logo的位置和图片
    logolabel->setPixmap(QPixmap(":/logoico"));
    logolabel->setGeometry(50,20,250,80);

    usrhlayout = new QHBoxLayout();
    pwdhlayout = new QHBoxLayout();
    bearpwdhlayout = new QHBoxLayout();

    usrLabel = new QLabel(this);    //存放用户名图片和输入用户名的输入框
    usrLabel->setGeometry(30,120,41,41);
    usrLabel->setPixmap(QPixmap(":/usrico"));
    usrLabel->setStyleSheet("background-color:white");

    pwdLabel = new QLabel(this);    //存放密码图片和输入密码的输入框
    pwdLabel->setGeometry(30,180,41,41);
    pwdLabel->setPixmap(QPixmap(":/lockico"));
    pwdLabel->setStyleSheet("background-color:white");

    usrLineEdit = new QLineEdit(this);  //输入用户名
    usrLineEdit->setGeometry(71,120,231,41);
    usrLineEdit->setMaxLength(12);
    usrLineEdit->setPlaceholderText(tr("Username"));
    usrLineEdit->setStyleSheet("background-color:white;border:0px");

     pwdLineEdit = new QLineEdit(this); //输入密码
     pwdLineEdit->setGeometry(71,180,231,41);
     pwdLineEdit->setMaxLength(12);
     pwdLineEdit->setPlaceholderText(tr("Password"));
     pwdLineEdit->setEchoMode(QLineEdit::Password);
     pwdLineEdit->setStyleSheet("background-color:white;border:0px");

     showpwdLabel = new QLabel(this);   //小眼睛,按住显示密码
     showpwdLabel->setText("123");
     showpwdLabel->setGeometry(261,180,41,41);
     showpwdLabel->setPixmap(QPixmap(":/showpwdico"));
     showpwdLabel->installEventFilter(this);

//    pwdRadioBtn = new QRadioButton(this);   //单选框之记住密码
//    pwdRadioBtn->setGeometry(QRect(220,222,18,18));

//    QFile mypwdfile("./bearpwd");    //首先确定文件中的值,判断单选框是否被选中
//    mypwdfile.open(QFile::ReadOnly);
//    QTextStream myin(&mypwdfile);
//    QString bearpwdstr = myin.readLine();
//    if("true"==bearpwdstr)  //如果文件中有内容,则将单选框选中,并判断用户名是否输入的正确
//    {
//        pwdRadioBtn->setChecked(true);
//        checkusr();
//    }
//    else
//    {
//        bool radio_sel = pwdRadioBtn->isChecked();  //先核实状态
//        if(true==radio_sel) //如果状态为真,则将其写入文件
//        {
//            QFile file("./bearpwd");
//            file.open(QIODevice::ReadWrite|QIODevice::Text);
//            //file.write(radio_sel.toUtf8());
//            file.close();
//        }
//    }

//    bearpwdLabel = new QLabel(this);
//    bearpwdLabel->setText("记住密码");
//    bearpwdLabel->setGeometry(QRect(240,220,70,20));
//    connect(pwdRadioBtn,SIGNAL(clicked()),this,SLOT(bearpwdslot(radio_sel)));

     loginBtn = new QPushButton(this);  //设置登陆按钮的属性
     loginBtn->setText("LOGIN");
     QPalette loginBtnPal;
     loginBtnPal.setColor(QPalette::ButtonText,QColor(255,255,255));
     loginBtn->setPalette(loginBtnPal);
     loginBtn->setGeometry(30,240,271,51);
     loginBtn->setStyleSheet("border:0px;font-family:方正黑体_GBK;font-size:20px;background-color:#1085fd");
     connect(loginBtn,SIGNAL(clicked()),this,SLOT(click_loginBtn()));

     usrhlayout->addWidget(usrLabel);   //将用户名和密码栏的控件加入到相应的布局中
     usrhlayout->addWidget(usrLineEdit);
     pwdhlayout->addWidget(pwdLabel);
     pwdhlayout->addWidget(pwdLineEdit);
     pwdhlayout->addWidget(showpwdLabel);

     QVBoxLayout *vlayout =new QVBoxLayout; //加入整体的布局
     vlayout->addWidget(logolabel);
     vlayout->addLayout(usrhlayout);
     vlayout->addLayout(pwdhlayout);

     QToolButton *clsBtn = new QToolButton(this);   //关闭按钮
     QPixmap clsPix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);
     clsBtn->setIcon(clsPix);
     clsBtn->setGeometry(316,0,15,15);
     connect(clsBtn,SIGNAL(clicked()),this,SLOT(close()));

     this->setWindowFlags(Qt::FramelessWindowHint);
     this->setWindowIcon(QIcon(":/logo"));
}

loginwindow::~loginwindow()
{
}

//移动窗体事件
void loginwindow::mousePressEvent(QMouseEvent *e)
{
    windowpos = e->globalPos();
}

void loginwindow::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX()-windowpos.x();
    int dy = e->globalY()-windowpos.y();
    windowpos = e->globalPos();
    move(x()+dx,y()+dy);
}

void loginwindow::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX()-windowpos.x();
    int dy = e->globalY()-windowpos.y();
    move(x()+dx,y()+dy);
}

//显示主窗口
void loginwindow::showmainwindow()
{
    QApplication::setQuitOnLastWindowClosed(false);
    mw.show();
}

//创建存放密码的文件
void loginwindow::createpwdFile()
{
    QFile file("/tmp/pwd");
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    file.write(pwdinputstr.toUtf8());
    file.close();
}

//核实密码正确性
void loginwindow::checkpwd()
{
    pwdinputstr = pwdLineEdit->text();
    pwdprogram = "bash getpwd.sh "+pwdinputstr;
    pwdProcess = new QProcess;
    pwdProcess->start(pwdprogram);
 //   pwdProcess->start("bash getpwd.sh"+pwdinputstr);
    pwdProcess->waitForFinished(1000);
    pwdoutputstr =  (QString)pwdProcess->readAllStandardOutput();
   // if(pwdoutputstr.endsWith("1\n",Qt::CaseInsensitive))
    if(pwdoutputstr.contains("1"))
    {
        createpwdFile();
        close();
        showmainwindow();
    }
    else
    {
        QMessageBox::warning(this,"提示","密码错误！");
    }
}

//核实用户名正确性
void loginwindow::checkusr()
{
    //判断用户名是否正确
    usrProcess = new QProcess;
    usrProcess->start("bash getusrname.sh");
    usrProcess->waitForFinished(100);
    usrinputstr = usrLineEdit->text();
    usroutputstr = usrProcess->readAllStandardOutput();
    usroutputstr = usroutputstr.trimmed();
    if(usrinputstr==usroutputstr)
    {
        checkpwd();
    }
    else
    {
        QMessageBox::warning(this,"提示","用户名错误");
    }
}

//点击登陆按钮的触发事件
void loginwindow::click_loginBtn()
{
    checkusr();
}

//密码小眼睛的触发事件
bool loginwindow::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == showpwdLabel)
    {
        if(event->type()==QEvent::MouseButtonPress) //点击小眼睛
        {
            pwdLineEdit->setEchoMode(QLineEdit::Normal);    // 将密码设置为可见
            return true;
        }
        else if(event->type()==QEvent::MouseButtonRelease)  //松开小眼睛
        {
            pwdLineEdit->setEchoMode(QLineEdit::Password);  //将密码设置为隐藏
            return true;
        }
    }
    else
    {
        return QDialog::eventFilter(obj,event);
    }
    return false;
}

////点击记住密码的触发事件
//void loginwindow::bearpwdslot(bool radio_situation)
//{
//    if(true==radio_situation)
//    {
//        QFile mypwdfile("./pwd");
//        mypwdfile.open(QFile::ReadOnly);
//        QTextStream myin(&mypwdfile);
//        pwdLineEdit->setText(myin.readLine());
//    }
//}
