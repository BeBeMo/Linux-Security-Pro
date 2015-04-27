#ifndef MIDDLE5_H
#define MIDDLE5_H

#include <QWidget>
#include<QLabel>
#include<QString>
#include<QFile>
#include<QListWidget>
#include<QListWidgetItem>
#include<QProcess>
#include<QPushButton>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QTextStream>
#include<QDebug>

class middle5 : public QWidget
{
    Q_OBJECT

public:
    explicit middle5(QWidget *parent = 0);
    ~middle5();
    QHBoxLayout *leftup;
    QHBoxLayout *leftdown;
    QHBoxLayout *rightup;
    QHBoxLayout *rightdown;
    QHBoxLayout *mainlayout;
    QVBoxLayout *leftlayout;
    QVBoxLayout *rightlayout;
    QListWidget *leftlist;
    QListWidget *rightlist;
    QListWidgetItem *item;
    QLabel *leftlabel1;
    QLabel *leftlabel2;
    QLabel *rightlabel1;
    QLabel *rightlabel2;
    QPushButton *cliBtn1;
    QPushButton *showBtn1;
    QPushButton *cliBtn2;
    QPushButton *showBtn2;
    QString curstart;
    QString pwd;
    QProcess *thread1_1;
    QProcess *thread1_2;
    QProcess *thread1_3;
    QProcess *thread2_1;
    QProcess *thread2_2;
    QProcess *thread2_3;

private slots:
    void showbootstart();
    void showbootclose();
    void closebootstart();
    void openbootstart();
};

#endif // MIDDLE5_H
