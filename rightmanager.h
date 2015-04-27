#ifndef RIGHTMANAGER_H
#define RIGHTMANAGER_H

#include"tipdialog.h"
#include"flowwindow.h"
#include <QWidget>
#include<QPushButton>
#include<QVBoxLayout>
#include<QLabel>
#include<QFile>
#include<qstring.h>
#include<QTextStream>

class rightmanager : public QWidget
{
    Q_OBJECT

public:
    explicit rightmanager(QWidget *parent = 0);
    ~rightmanager();
    QPushButton *clsBtn;
    QPushButton *minBtn;
    QPushButton *tipBtn;
    QPushButton *flowBtn;
    QPushButton *fireBtn;
    QVBoxLayout *vlayout;
  //  flowwindow fw;
    QPixmap mypixmap4;

private:

signals:
    void rightclsBtn();
    void rightminBtn();
    void rightflowBtn();
    void righttipBtn();

public slots:
   void clickclsBtn();
   void clickminBtn();
   void clickflowBtn();
   void clickfireBtn();
   void clicktipBtn();
};

#endif // RIGHTMANAGER_H
