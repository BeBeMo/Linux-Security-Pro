#ifndef LEFTMANAGER_H
#define LEFTMANAGER_H

#include <QWidget>
#include"middle1.h"
#include"middle2.h"
#include"middle3.h"
#include"middle4.h"
#include"middle5.h"
#include"middle6.h"
#include"middle7.h"
#include<QLabel>
#include<QVBoxLayout>
#include<QListWidget>
#include<QListWidgetItem>
#include<QStackedWidget>
#include<QPalette>
#include<QBrush>

class leftmanager : public QWidget
{
    Q_OBJECT

public:
    explicit leftmanager(QWidget *parent = 0);
    ~leftmanager();
     QListWidget *list;

protected slots:
    void pagechanged(int);

private:

signals:
    void leftlistchanged(int);
};

#endif // LEFTMANAGER_H
