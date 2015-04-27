#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"leftmanager.h"
#include"rightmanager.h"
#include <QWidget>
#include<QMenu>
#include<QMouseEvent>
#include<QDesktopWidget>
#include<QApplication>
#include<QSystemTrayIcon>
#include<QMenu>
#include<QAction>
#include<QCryptographicHash>
#include<QFile>
#include<QIODevice>

class mainwindow : public QWidget
{
    Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = 0);
     ~mainwindow();
    leftmanager *myleft;
    rightmanager *myright;
    middle1 *m1;
    middle2 *m2;
    middle3 *m3;
    middle4 *m4;
    middle5 *m5;
    middle6 *m6;
    middle7 *m7;
    QStackedWidget *showWidget;
    flowwindow fw;
    tipDialog tipDia;
//    QSystemTrayIcon *trayicon;
//    QMenu *trayiconMenu;
//    QAction *miniSizeAction;
//   // QAction *maxSizeAction;
//    QAction *restoreWinAction;
//    QAction *quitAction;

//    void CreatTrayMenu();
//    void CreatTrayIcon();
//    void addMD5();

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private:
    QPoint windowpos;

public slots:
    void rightclsBtnSlot();
    void rightflowBtnSlot();
    void rightminBtnSlot();
    void righttipBtnSlot();
//    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void leftlistchangedSlot(int);
};

#endif // MAINWINDOW_H
