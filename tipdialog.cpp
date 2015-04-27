#include "tipdialog.h"

tipDialog::tipDialog(QWidget *parent) :
    QDialog(parent)
{
  //  this->setWindowFlags(Qt::WindowStaysOnTopHint);
    this->setWindowTitle("电脑启动项小贴士");
    this->setStyleSheet("background:#f0f9fd;");
    label1 = new QLabel;
    label2 = new QLabel;
    label3 = new QLabel;
    label4 =new QLabel;
    label5 = new QLabel;
    label6 = new QLabel;
    label7 = new QLabel;
    label8 = new QLabel;
    //label9 = new QLabel;
    label1->setText("auditd　安全审核服务，它将审核日志写到硬盘");
    label2->setText("dns-clean　使用拨号连接时，清除dns信息");
    label3->setText("hostapd　实现WIFI热点(AP)");
    label4->setText("kerneloops　为Linux用户与开发员搭建桥梁，显示系统崩溃报告签名");
    label5->setText("nfs-kernel-server　分布式文件系统");
    label6->setText("selinux　强制访问控制系统");
    label7->setText("sysstat　检测系统性能及效率的一组工具");
    label8->setText("rsync　数据镜像备份工具，用于在计算机之间同步文件的服务");

    vlayout = new QVBoxLayout;
    vlayout->addWidget(label1);
    vlayout->addWidget(label2);
    vlayout->addWidget(label3);
    vlayout->addWidget(label4);
    vlayout->addWidget(label5);
    vlayout->addWidget(label6);
    vlayout->addWidget(label7);
    vlayout->addWidget(label8);

    this->setLayout(vlayout);
}

tipDialog::~tipDialog()
{
}
