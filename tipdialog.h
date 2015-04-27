#ifndef TIPDIALOG_H
#define TIPDIALOG_H

#include <QDialog>
#include<QLabel>
#include<QVBoxLayout>
#include<QWidget>

class tipDialog : public QDialog
{
    Q_OBJECT

public:
    explicit tipDialog(QWidget *parent = 0);
    ~tipDialog();
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLabel *label5;
    QLabel *label6;
    QLabel *label7;
    QLabel *label8;
    //QLabel *label9;
    QVBoxLayout *vlayout;
private:
};

#endif // TIPDIALOG_H
