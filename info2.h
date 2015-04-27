#ifndef INFO2_H
#define INFO2_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QString>
#include <QHBoxLayout>

class INFO2 : public QWidget
{
    Q_OBJECT
public:
    explicit INFO2(QWidget *parent = 0);
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QVBoxLayout *vlayout;
    QHBoxLayout *hlayout;
    void info_show2(QString a);

public slots:

};

#endif // INFO2_H
