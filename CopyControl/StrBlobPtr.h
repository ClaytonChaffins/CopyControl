#pragma once
#ifndef StrBlob_H
#define StrBlob_H
//#include "StrBlob.h"
#include "stdafx.h"

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
//PTR CLASS NOW:

class StrBlob;
// StrBlobPtr throws an exception on attempts to access a nonexistent element
class StrBlobPtr {
public:
	friend class StrBlob;
	StrBlobPtr();
	StrBlobPtr(StrBlob &a, size_t sz);
	StrBlobPtr(StrBlob &a);
	std::string& deref() const;
	StrBlobPtr& incr(); // prefix version
	void printBlob();
private:
	// check returns a shared_ptr to the vector if the check succeeds
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
	// store a weak_ptr, which means the underlying vector might be destroyed
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr; // current position within the array
};


#endif