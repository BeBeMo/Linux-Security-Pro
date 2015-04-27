#include "changepasswd.h"
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>
changePasswd::changePasswd(QWidget *parent)
                           :QWidget(parent)
{
    widget = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout(widget);
    QHBoxLayout *hLayout1 = new QHBoxLayout(widget);
    QLineEdit *myEdt1 = new QLineEdit(widget);
    myEdt1->setText("用户名：");
    myEdt1->setStyleSheet("QLineEdit{background-color:rgb(255,0,0,0)}");
    myEdt1->setFrame(false);
    myEdt1->setReadOnly(true);
    myEdt1->setAlignment(Qt::AlignCenter);
    myEdt2= new QLineEdit(widget);
    hLayout1->addWidget(myEdt1);
    hLayout1->addWidget(myEdt2);

    QHBoxLayout *hLayout2 = new QHBoxLayout(widget);
    QLineEdit *myEdt3 = new QLineEdit(widget);
    myEdt3->setText("新密码：");
    myEdt3->setStyleSheet("QLineEdit{background-color:rgb(255,0,0,0)}");
    myEdt3->setFrame(false);
    myEdt3->setReadOnly(true);
    myEdt3->setAlignment(Qt::AlignCenter);
    myEdt4= new QLineEdit(widget);
    myEdt4->setEchoMode(QLineEdit::Password);
    hLayout2->addWidget(myEdt3);
    hLayout2->addWidget(myEdt4);

    QHBoxLayout *hLayout3 = new QHBoxLayout(widget);
    QLineEdit *myEdt5 = new QLineEdit(widget);
    myEdt5->setText("确认密码：");
    myEdt5->setStyleSheet("QLineEdit{background-color:rgb(255,0,0,0)}");
    myEdt5->setFrame(false);
    myEdt5->setReadOnly(true);
    myEdt5->setAlignment(Qt::AlignCenter);
    myEdt6= new QLineEdit(widget);
    myEdt6->setEchoMode(QLineEdit::Password);
    hLayout3->addWidget(myEdt5);
    hLayout3->addWidget(myEdt6);

   QHBoxLayout *hLayout4 = new QHBoxLayout(widget);
    close_pushbutton = new QPushButton("关闭");
    add_pushbutton = new QPushButton("确认");
    hLayout4->addWidget(close_pushbutton);
    hLayout4->addWidget(add_pushbutton);

    mainLayout->addLayout(hLayout1);
    mainLayout->addLayout(hLayout2);
    mainLayout->addLayout(hLayout3);
    mainLayout->addLayout(hLayout4);

    widget->setWindowTitle("修改密码");
    widget->setLayout(mainLayout);
    widget->show();

    connect(close_pushbutton, SIGNAL(clicked()), this, SLOT(close_window()));
    connect(add_pushbutton, SIGNAL(clicked()), this, SLOT(add_user()));
}
void changePasswd::close_window()
{
    widget->close();
}

void changePasswd::add_user()
{
    QString name = myEdt2->text();
    if(name == "")
    {
            QMessageBox::warning(this,"提示","用户名不能为空！");
    }
    else
    {
        QString passwd = myEdt4->text();
        QString passwd1 = myEdt6->text();
        if(passwd == "" |passwd == "")
        {
                QMessageBox::warning(this,"提示","密码不能为空！");
        }
         if(passwd != passwd1)
         {
              QMessageBox::warning(this,"提示","两次密码不一致！");
         }
         else
         {
              QFile mypwdfile("/tmp/pwd");
              mypwdfile.open(QFile::ReadOnly);
              QTextStream myin(&mypwdfile);
              QString pwd = myin.readLine();
              mypwdfile.close();
                QString  add_passwd = name+":"+passwd;
                QByteArray ba = add_passwd.toLatin1();
                   char *mm = ba.data();
                QFile fromFile("/tmp/passwd1.txt");
                fromFile.open(QIODevice::WriteOnly);
                fromFile.write(mm);
                fromFile.close();
                 QProcess *thread = new QProcess;
                 thread->start("bash flush_passwd.sh "+ pwd + " "+name);
                 if(!thread->waitForStarted())
                 {
                     qDebug()<<"failed start!";
                 }

                 while(true == thread->waitForFinished());
                 {
                     QMessageBox::warning(this,"提示","密码修改成功！");
                     widget->close();
                 }
         }
    }
}


