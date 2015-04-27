#ifndef INFO1_H
#define INFO1_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QString>
#include <QHBoxLayout>
#include <QProcess>
#include <QFile>
#include <QTextStream>
#include <QtDebug>
#include <QPixmap>

class INFO1 : public QWidget
{
    Q_OBJECT
public:
    explicit INFO1(QWidget *parent = 0);
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QVBoxLayout *vlayout;
    QHBoxLayout *hlayout;
    void info_show1(QString a);

    public slots:

};

#endif // INFO1_H
