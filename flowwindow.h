#ifndef FLOWWINDOW_H
#define FLOWWINDOW_H
#include<QDialog>
#include <QWidget>
#include <QPoint>
#include <QPixmap>
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QThread>
#include <QTimer>
#include <QWidget>
#include <QString>
#include <QObject>
#include <QBitmap>
#include <QtGui>
#include <QProcess>
#include <QString>
#include <QThread>
#include <QFile>
#include <QMessageBox>

class MyThread : public  QThread
{
    Q_OBJECT
 public:
    MyThread(QObject *parent = 0);
protected:
    void run();
signals:
    void sendint(QString a);
    void sendint1(QString b);
};

class flowwindow : public QDialog
{
    Q_OBJECT

public:
    explicit flowwindow(QWidget *parent = 0);
    ~flowwindow();
    QHBoxLayout *hlayout;
    QVBoxLayout *vlayout;
    QPoint m_CurrentPos;
    QPixmap m_Pixmap;
    QWidget m_widget;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QThread *myprocess;
//    QTimer *timer1; //计时器
    QString  test;
    MyThread *thread;

public slots:
   // void showfunction();
    void showint(QString a);
    void showint1(QString b);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
};

#endif // FLOWWINDOW_H
