#include "stdafx.h"
#include "StrBlobPtr.h"
#include "StrBlob.h"

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

//DEFINTIONS:
StrBlobPtr::StrBlobPtr()
{
	curr = 0;
}
StrBlobPtr::StrBlobPtr(StrBlob &a, size_t sz)
{
	wptr = a.data;
	curr = sz;
}
StrBlobPtr::StrBlobPtr(StrBlob &a) 
{ 
	wptr = a.data;
	curr = 0;
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
	auto ret = wptr.lock(); // is the vector still around?
	if (!ret) 
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret; // otherwise, return a shared_ptr to the vector
}

std::string& StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr]; // (*p) is the vector to which this object points
} 

// prefix: return a reference to the incremented object
StrBlobPtr& StrBlobPtr::incr()
{
	// if curr already points past the end of the container, can't increment it
	check(curr, "increment past end of StrBlobPtr");
	++curr; // advance the current state
	return *this;
}

void StrBlobPtr::printBlob()
{
	auto ret = wptr.lock();
	while (curr < ret->size() - 1)
	{
		cout << (*ret)[curr] << endl;
		++curr;
	}
}
