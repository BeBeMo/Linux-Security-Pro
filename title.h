#ifndef TITLE_H
#define TITLE_H

#include <QWidget>
#include <QToolButton>
#include <QHBoxLayout>


class TITLE : public QWidget
{
    Q_OBJECT
public:
    explicit TITLE(QWidget *parent = 0);
    QToolButton *button1;
    QToolButton *button2;
    QToolButton *button3;
    QToolButton *button4;
    QHBoxLayout *hlayout;

signals:

public slots:


};

#endif // TITLE_H
