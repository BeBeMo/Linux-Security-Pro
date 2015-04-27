#ifndef MIDDLE4_H
#define MIDDLE4_H

#include <QWidget>
#include<QLabel>
#include<QVBoxLayout>
#include<QLineEdit>
#include<QPixmap>
#include<QPushButton>
#include<QHBoxLayout>
#include <QProcess>
#include <QFile>
class middle4 : public QWidget
{
	Q_OBJECT

	public:
		explicit middle4(QWidget *parent = 0);
		~middle4();
		//新建总水平布局
		QHBoxLayout *mainlayout;
		//新建右边栏子水平布局
		QHBoxLayout *hlayout1;
		QHBoxLayout *hlayout2;
		QHBoxLayout *hlayout3;
		QHBoxLayout *hlayout4;
		QHBoxLayout *hlayout5;

		//新建左右边栏垂直布局
		QVBoxLayout *vlayout;
		//新建按钮
		QPushButton *mybtn;
		//新建5个提示信息文本框
		QLineEdit *lineedit1;
		QLineEdit *lineedit2;
		QLineEdit *lineedit3;
		QLineEdit *lineedit4;
		QLineEdit *lineedit5;

		//新建5个清理结果文本框
		QLineEdit *ret_rabish1;
		QLineEdit *ret_rabish2;
		QLineEdit *ret_rabish3;
		QLineEdit *ret_rabish4;
		QLineEdit *ret_rabish5;

		//新建放置图片的5个label
		QLabel *mylabel;
		QLabel *mylabel1;
		QLabel *mylabel2;
		QLabel *mylabel3;
		QLabel *mylabel4;
		QLabel *mylabel5;

		//   QFile *mypwdfile();
		//定义槽函数
		public slots:
			void show();

	private:
};

#endif // MIDDLE4_H
