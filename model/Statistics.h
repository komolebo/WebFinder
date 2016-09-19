#include "URLPage.h"
#include <boost/ptr_container/ptr_vector.hpp>	// For automatic calling destructors


#pragma once
struct Statistics
{
	// Pages counters
	const unsigned max_pages;
	unsigned pages_checked;

	boost::ptr_vector<URLPage> pages;

	Statistics(unsigned _max_pages) : pages_checked(0), max_pages(_max_pages) {};
	~Statistics() {};
};

