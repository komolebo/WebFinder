#include "URLPage.h"
#include "Statistics.h"
#include <string>	
#include <mutex>		// For synchronizing processes 
#include <list>			// For saving pages and holding threads
#include <thread>		// For multithreading

using namespace std;


#pragma once
class Model
{
	const int PROC_COUNT;	// Maximal number of processes
	
	const string text;		// Text to find
	list<string> refs;		// Queue of url pages
	Statistics stat;		// Holds received data
	
	// For multithreading
	mutex m;
	list<thread> threads;
	bool running = false;

	// Thread member function that processes urls
	void process();
public:
	Model(string _url, const string _text, int proc_count, int max_pages);
	~Model() {};

	// Processes initial url, downloads WEB-pages, searches text in these
	void calculate();

	list<thread> & get_threads() { return threads; };
	const Statistics * get_statistics() const { return &stat; }
	
	// User may stop the processes
	void set_running_state(bool running) { this->running = running; }
};

