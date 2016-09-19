#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "model/URLPage.h"
#include "model/Statistics.h"
#include "controller.h"

#include <QMainWindow>
#include <QStandardItemModel>	// For table model


namespace Ui { class View; }


class View : public QMainWindow
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = 0);
    ~View();
	
private slots:
	// Event click slots
	void on_bStart_clicked();
    void on_bPause_clicked();
    void on_bStop_clicked();

private:
    Ui::View *ui;
	Controller * controller;
	
	int timer_id;	// For timer updating function
	QStandardItemModel* table_model; 

	// Member functions for table implementation
	void append_table();
	void init_table();

protected:
	void timerEvent(QTimerEvent *); // For view updating

public:
	void set_controller(Controller * _controller) { controller = _controller; };
};

#endif // MAINWINDOW_H
