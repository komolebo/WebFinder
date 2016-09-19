#include "model/Model.h"

using namespace std;


#pragma once
class Controller
{
	Model * model = 0;

public:
	Controller() : state(STOP) {};
	~Controller() { delete model; };

	void start(string, string, int, int);
	void pause();
	void resume();
	void stop();

	const Model * get_model() const { return model; }

	enum State { ON, PAUSE, STOP } state;
};

