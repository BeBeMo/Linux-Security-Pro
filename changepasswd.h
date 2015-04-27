#ifndef CHANGEPASSWD_H
#define CHANGEPASSWD_H
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QObject>
#include <QProcess>
#include <QFile>
class changePasswd:public QWidget
{
    Q_OBJECT
public:
    changePasswd(QWidget *parent = 0);
public slots:
void close_window();
void add_user();
public:
QWidget *widget;
QPushButton *close_pushbutton;
QPushButton *add_pushbutton;
QLineEdit *myEdt2;
QLineEdit *myEdt4;
QLineEdit *myEdt6;
};

#endif // CHANGEPASSWD_H
