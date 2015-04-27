#ifndef MIDDLE3_H
#define MIDDLE3_H

#include <QWidget>
#include<QLabel>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QListWidget>
#include<QWidget>
#include<QTableWidget>
#include <QPixmap>
#include <QFont>
#include <QPushButton>
#include <QDebug>
#include <QObject>
#include <QTextEdit>
#include <QLineEdit>
#include <QString>
#include <QTimer>
#include <QFile>
#include <QProcess>

class filePath;
class middle3 : public QWidget
{
	Q_OBJECT

	public:
		explicit middle3(QWidget *parent = 0);
		~middle3();
		filePath *filepath;
		QTabWidget *tabWidget;
		QWidget  *widget1;
		QWidget  *widget2;
		QLineEdit *fileline;
		QLineEdit *safnum;
		QLineEdit *virnum;
		QPushButton *scan_pushbutton;
		QPushButton *execute_pushbutton;
		QTextEdit *result_label;
		QTextEdit *result_label1;
		QString return_num;
		QString gettext;
		QLineEdit *time;
		int temp;
	private:
		QTimer *timer; //计时器
		public slots:
			void scan_file();
		void show_file();
		void get_file();
		void all_file();
		void timer_update_currentTabInfo();
		void kill_process();
	public :
		int flag;
		QString line;//存放文件读取内容
		QProcess *myThread;
		QProcess *myThread1;
};

#endif // MIDDLE1_H
