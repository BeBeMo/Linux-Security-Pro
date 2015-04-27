#ifndef MIDDLE7_H
#define MIDDLE7_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QProcess>
#include <QString>
#include<QTimer>
#include <QMap>
#include <QMapIterator>
#include "adduser.h"
#include "changepasswd.h"
#include <QTimer>

class middle7 : public QWidget
{
    Q_OBJECT
public:
    explicit middle7(QWidget *parent = 0);

public:
    QListWidget *list;
    QString currentUser;
    QListWidgetItem *item;
    QPushButton *del_pushbutton;
    QPushButton *black_pushbutton;
    QPushButton *delb_pushbutton;
private:
    QTimer *timer;
public slots:
    void show_user();
    void add_user();
    void del_user();
    void passwd_change();
    void add_black();
    void blackFunc();
    void del_black();
    void timer_update_currentTabInfo() ;
public:
     class adduser *myuser;
     QString  user_temp[10];
     int flag;

};

#endif // MIDDLE7_H
