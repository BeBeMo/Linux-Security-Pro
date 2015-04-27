#ifndef MIDDLE1_H
#define MIDDLE1_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPixmap>
#include <QPushButton>
#include <QHBoxLayout>
#include <QProcess>
#include <QFile>

class middle1 : public QWidget
{
	Q_OBJECT

	public:
		explicit middle1(QWidget *parent = 0);
		~middle1();

		//新建总水平布局
		QHBoxLayout *mainlayout;
		//新建右边栏子水平布局
		QHBoxLayout *hlayout1;
		QHBoxLayout *hlayout2;
		QHBoxLayout *hlayout3;
		QHBoxLayout *hlayout4;
		QHBoxLayout *hlayout5;
		QHBoxLayout *hlayout6;

		//新建左右边栏垂直布局
		QVBoxLayout *vlayout;
		//新建按钮
		QPushButton *mybtn;
		//新建6个提示信息文本框
		QLineEdit *lineedit1;
		QLineEdit *lineedit2;
		QLineEdit *lineedit3;
		QLineEdit *lineedit4;
		QLineEdit *lineedit5;
		QLineEdit *lineedit6;
		//新建6个体检结果文本框
		QLineEdit *ret_rabish1;
		QLineEdit *ret_rabish2;
		QLineEdit *ret_rabish3;
		QLineEdit *ret_rabish4;
		QLineEdit *ret_rabish5;
		QLineEdit *ret_rabish6;

		//新建放置图片的6个label
		QLabel *mylabel;
		QLabel *mylabel1;
		QLabel *mylabel2;
		QLabel *mylabel3;
		QLabel *mylabel4;
		QLabel *mylabel5;
		QLabel *mylabel6;

		//   QFile *mypwdfile();
		//定义槽函数   
		public slots:
			void show();

	private:
};

#endif // MIDDLE1_H
