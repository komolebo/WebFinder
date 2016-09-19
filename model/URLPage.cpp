#include "URLPage.h"
#include <curl/curl.h>		// For page downloading
#include <boost/regex.hpp>	// For searching text http://

using namespace std;


void URLPage::clear_reference(string & ref)
{
	switch (ref.back())
	{
	case ';':
	case ':':
	case '\"':
	case ' ':
		ref.pop_back();
	}
}

size_t URLPage::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
	((string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

void URLPage::download()
{
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &content);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
}

void URLPage::find_text()
{
	text_found = content.find(*text) != string::npos;
}

list<string> * URLPage::get_references()
{
	list<string> * refs = new list<string>();

	boost::regex e("https?:\/\/(.*?)( |\"|\:|\;)");

	boost::sregex_token_iterator iter(content.begin(), content.end(), e, 0), end;
	for (; iter != end; ++iter) {
		string ref = *iter;
		clear_reference(ref);	// Clear delimiters
		refs->push_back(ref);
	}
	return refs;
}

const string & URLPage::getURL() const
{
	return url;
}