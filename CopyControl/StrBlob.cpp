#include "stdafx.h"
#include "StrBlob.h"
#include"StrBlobPtr.h"

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
#include <vector>
using std::vector;
using std::find;
#include <algorithm>
#include <numeric>
#include <string.h> //for old style char strings
#include <initializer_list>
#include <deque>
#include <list>
#include <forward_list>
#include <string>
#include <stack>
#include <functional>
#include <iterator>
#include <utility>
#include <memory>

#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

//beginning of defintions: 
//typedef std::vector<std::string>::size_type size_type;
void StrBlob::check(size_type i, const string &msg) const
{
	if (i >= data->size()) 
		throw out_of_range(msg);
}
string& StrBlob::front()
{
	// if the vector is empty, check will throw
	check(0, "front on empty StrBlob");
	return data->front();
}
string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}
void StrBlob::push_back(const std::string & t)
{
	data->push_back(t);
}
void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}
StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}
shared_ptr<std::vector<std::string>> StrBlob::getData()
{
	return (data);
}


