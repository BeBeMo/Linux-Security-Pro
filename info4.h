#ifndef INFO4_H
#define INFO4_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QString>
#include <QHBoxLayout>

class INFO4 : public QWidget
{
    Q_OBJECT
public:
    explicit INFO4(QWidget *parent = 0);
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QVBoxLayout *vlayout;
    QHBoxLayout *hlayout;
    void info_show4(QString a);

signals:

public slots:

};

#endif // INFO4_H
