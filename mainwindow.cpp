#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QList>	// For appending QTableView model


View::View(QWidget *parent) : QMainWindow(parent), ui(new Ui::View)
{
    ui->setupUi(this);

	// Format input for textedit widgets
    ui->ePageCount->setValidator( new QIntValidator(1, 9999999, this) );
    ui->eProcCount->setValidator( new QIntValidator(1, 10, this) );

	// Initial view page state
	ui->bPause->setEnabled(false);
	ui->bStop->setEnabled(false);
	ui->progressBar->setValue(0);
	
	// Default values for input widgets
	ui->eURL->setText("http://developex.com.ua/");
	ui->eText->setText("succesful");
	ui->eProcCount->setText("5"); ui->ePageCount->setText("50");

	table_model = new QStandardItemModel();
}

View::~View()
{
	delete ui; delete table_model;
}

void View::on_bStart_clicked()
{
	// If first launch then set up table
	if (controller->state == Controller::STOP) init_table();

	QString proc_count = ui->eProcCount->text();
	QString max_pages = ui->ePageCount->text();
	QString url = ui->eURL->toPlainText();
	QString text = ui->eText->toPlainText();

	if (proc_count == "" || max_pages == "" || text == "" || url == "") return;

	// Starting calculations
	controller->start(url.toStdString(), text.toStdString(), 
		proc_count.toInt(), max_pages.toInt());

	// Launch update-view timer
	timer_id = startTimer(10);

	// Prevent from wrong user's actions
	ui->bStart->setEnabled(false);
	ui->bStop->setEnabled(true);
	ui->bPause->setEnabled(true);
}

void View::on_bPause_clicked()
{
	killTimer(timer_id);
    controller->pause();

	ui->bPause->setEnabled(false);
	ui->bStart->setEnabled(true);
}

void View::on_bStop_clicked()
{
	killTimer(timer_id);
    controller->stop();

	ui->bPause->setEnabled(false);
	ui->bStop->setEnabled(false);
	ui->bStart->setEnabled(true);

	table_model->clear();
}

void View::timerEvent(QTimerEvent *) {
	if (controller->get_model() == 0) return;
	
	// Update progress bar
	const auto & stat = controller->get_model()->get_statistics();

	const int pages_checked = stat->pages_checked;
	const int max_pages = stat->max_pages;
	const double percent = 100. * pages_checked / max_pages;

	ui->progressBar->setValue(percent);

	// Update table
	append_table();
}

void View::append_table() {
	const auto & pages = controller->get_model()->get_statistics()->pages;

	// Count how many new urls need to be appended to table
	int urls_all = pages.size();
	int urls_new = urls_all - table_model->rowCount();

	while (urls_new > 0) {
		int index = urls_all - urls_new;	// new url index in table
		QString qurl = QString(pages.at(index).getURL().c_str());
		QString qstate = QString(pages.at(index).text_is_found() ? "found" : "");
		QString qerror = QString(pages.at(index).error_is_found() ? "bad url" : "");

		// Append data to table model
		QList<QStandardItem *> items;
		items.append(new QStandardItem(qurl));
		items.append(new QStandardItem(qstate));
		items.append(new QStandardItem(qerror));
		table_model->appendRow(items);

		urls_new--;
	}
}

void View::init_table() {
	// Insert table header
	table_model->setHorizontalHeaderItem(0, new QStandardItem(QString("URL reference")));
	table_model->setHorizontalHeaderItem(1, new QStandardItem(QString("Text")));
	table_model->setHorizontalHeaderItem(2, new QStandardItem(QString("Error")));

	// Setting up table view
	ui->tFoundURLs->setModel(table_model);
	ui->tFoundURLs->setColumnWidth(0, 320);
	ui->tFoundURLs->setColumnWidth(1, 85);
	ui->tFoundURLs->setColumnWidth(2, 85);
}