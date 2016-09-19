#include "mainwindow.h"
#include "controller.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	View * v = new View();
	Controller * c = new Controller();

	v->set_controller(c);
	v->show();
	
    return a.exec();
}
