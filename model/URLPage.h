#include <string>
#include <list>

using namespace std;


#pragma once
class URLPage
{
	string url, content;
	const string *text;
	bool text_found;

public:
	URLPage(string _url, const string * _text) : url(_url), text(_text) {};
	~URLPage() {};

	void download();
	void find_text();	
	list<string> * get_references();	// Find all references on url page
	
	// Getters
	const string & getURL() const;
	const bool text_is_found() const { return text_found; };
	const bool error_is_found() const { return content.size() == 0; }

private:
	// Delete last delimiter in url format
	static void clear_reference(string & ref);

	// For page download
	static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
};

