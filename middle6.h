#ifndef MIDDLE6_H
#define MIDDLE6_H
#include <QMainWindow>
//#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QDialog>
#include <QPushButton>
#include <QListWidget>
#include <QHBoxLayout>
#include <QStackedLayout>
#include <QTimer>
#include <QString>
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QProcess>
class middle6 : public QDialog
{
	Q_OBJECT

	public:
		middle6(QWidget *parent = 0);
		~middle6();
	public:
		QTabWidget *tabWidget;
		QListWidget *listWidget;
		QPushButton *pushButton_processfresh;
		QPushButton *pushButton_processkill;
		QPushButton *pushButton_processkill2;
		QListWidgetItem *item1;
		QListWidgetItem *item2 ;
		QListWidgetItem *item3;
		QListWidgetItem *item4;
		QListWidgetItem *item5;
		QListWidgetItem *item6;
		QListWidgetItem *item7;
		QListWidgetItem *item8;
		QListWidgetItem *item9;
		QTabWidget *tabWidget2;
		QListWidget *listWidget2;
	public:
		QProcess *thread1 ;
		QProcess *thread2 ;
		QProcess *thread3 ;
		QProcess *thread4 ;
		QProcess *thread5 ;
		QProcess *thread6 ;
		QProcess *thread7 ;
		QProcess *thread8 ;
		QProcess *thread9;
		int flag1,flag2,flag3,flag4,flag5,flag6,flag7,flag8,flag9;
	private:
		QTimer *timer; //计时器
		public slots:
			void on_pushButton_pkill_clicked();
		void on_pushButton_prefresh_clicked();
		void on_pushButton_pkill_clicked2();
		void on_tabWidget_INFO_currentChanged(int index);
		//显示tab中的内容
		void show_tabWidgetInfo(int index);
		void timer_update_currentTabInfo();

};

#endif // MAINWINDOW_H
