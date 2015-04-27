#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include"mainwindow.h"
#include <QDialog>
#include<QLineEdit>
#include<QPushButton>
#include<QToolButton>
#include<QProcess>
#include<QString>
#include<QDebug>
#include<QMessageBox>
#include<QFile>
#include<QPalette>
#include<QDesktopWidget>
#include<QRadioButton>

class loginwindow : public QDialog
{
    Q_OBJECT

public:
    explicit loginwindow(QWidget *parent = 0);
    ~loginwindow();
    mainwindow mw;
    QHBoxLayout *usrhlayout;
    QHBoxLayout *pwdhlayout;
    QHBoxLayout *bearpwdhlayout;
    QLabel *usrLabel;
    QLabel *pwdLabel;
    QLineEdit *pwdLineEdit;
    QLineEdit *usrLineEdit;
    QRadioButton *pwdRadioBtn;
    QPushButton *loginBtn;
    QLabel *showpwdLabel;
    QLabel *bearpwdLabel;

    QString usrinputstr;
    QString usroutputstr;
    QString pwdinputstr;
    QString pwdoutputstr;
    QString pwdprogram;

    QProcess *usrProcess;
    QProcess *pwdProcess;

    void showmainwindow();
    void checkusr();
    void checkpwd();
    void createpwdFile();
private:
    QPoint windowpos;

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    bool eventFilter(QObject *, QEvent *);

private slots:
    void click_loginBtn();
  //  void bearpwdslot(bool);
};

#endif // LOGINWINDOW_H
