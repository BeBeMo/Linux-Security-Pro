#ifndef INFO3_H
#define INFO3_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QString>
#include <QHBoxLayout>

class INFO3 : public QWidget
{
    Q_OBJECT
public:
    explicit INFO3(QWidget *parent = 0);
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QVBoxLayout *vlayout;
    QHBoxLayout *hlayout;
    void info_show3(QString a);

signals:

public slots:

};

#endif // INFO3_H
