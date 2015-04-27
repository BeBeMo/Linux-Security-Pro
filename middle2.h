#ifndef MIDDLE2_H
#define MIDDLE2_H

#include <QWidget>
#include <QStackedWidget>
#include <QVBoxLayout>
#include "title.h"
#include "info1.h"
#include "info2.h"
#include "info3.h"
#include "info4.h"
#include <QFile>
#include <QProcess>
#include <QTextStream>
#include <QDebug>

class middle2 : public QWidget
{
    Q_OBJECT

public:
    explicit middle2(QWidget *parent = 0);
    ~middle2();
signals:
    void send1(QString a);

private slots:
       void turnPage1();
       void turnPage2();
       void turnPage3();
       void turnPage4();

  public slots:

private:
    QStackedWidget *stacked;
     INFO1 *info1;
     INFO2 *info2;
     INFO3 *info3;
     INFO4 *info4;
     TITLE *title1;
};

#endif // MIDDLE2_H
