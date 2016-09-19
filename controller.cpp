#include "Controller.h"

using namespace std;


void Controller::start(string url, string text, int proc_count, int max_pages)
{
	if (state == Controller::PAUSE)
		resume();
	else if (state == Controller::STOP) {
		delete model;
		model = new Model(url, text, proc_count, max_pages);
		
		model->calculate();
	}

	state = ON;
}

void Controller::pause() {
	model->set_running_state(false); 
	
	// Wait until all processes complete
	for (auto & t : model->get_threads())
		if (t.joinable())
			t.join();

	state = PAUSE; 
}

void Controller::resume() {
	model->calculate();

	state = ON;
}

void Controller::stop() {
	pause();

	state = STOP;
}