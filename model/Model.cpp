#include "Model.h"

using namespace std;


Model::Model(string _url, string _text, const int proc_count, int max_pages)
	: text(_text), PROC_COUNT(proc_count), stat(Statistics(max_pages))
{
	refs.push_back(_url);
}


void Model::process()
{
	URLPage * urlpage = 0;

	while (running && stat.pages_checked < stat.max_pages) {
		// Take url from queue
		m.lock();
		if (refs.size()) {
			urlpage = new URLPage(refs.front(), &text);
			refs.pop_front();
		}
		m.unlock();

		if (urlpage == 0) continue;		// Didn't own the mutex

		// Search new references on current page and add to queue
		urlpage->download();
		list<string> * new_refs = urlpage->get_references();
		if (new_refs && refs.size() <= stat.max_pages) {
			m.lock();
			refs.splice(refs.end(), *new_refs);
			m.unlock();
		}
		delete new_refs;

		urlpage->find_text();
		
		if (stat.max_pages > stat.pages_checked)
			stat.pages.push_back(urlpage);	// WEB-page is processed
		
		stat.pages_checked++;
	}
}


void Model::calculate()
{
	running = true;

	// Start threads
	threads.clear();
	for (int i = 0; i < PROC_COUNT; i++)
		threads.push_back(thread([=] {process(); }));
}

