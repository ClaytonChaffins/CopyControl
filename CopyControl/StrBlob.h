#pragma once
#ifndef StrBlobPtr_H
#define StrBlobPtr_H
#include "stdafx.h"
//#include"StrBlobPtr.h"

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

class StrBlobPtr; //asserting its existence in a differnet way 

class StrBlob {
public:
	typedef std::vector<std::string>::size_type size_type;
	friend class StrBlobPtr; //POTENTIAL PROBLEM!
	StrBlob::StrBlob() : data(make_shared<vector<string>>()) { }
	StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) { }
	std::shared_ptr<std::vector<std::string>> data;

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	// add and remove elements
	void push_back(const std::string &t);
	void pop_back();
	// element access
	std::string& front();
	std::string& back();
	shared_ptr<std::vector<std::string>> getData(); //returns a shared pointer to the data member
private:
	// throws msg if data[i] isn't valid
	void check(size_type i, const std::string &msg) const;
	StrBlobPtr begin();
	StrBlobPtr end();

};

#endif
