#pragma once
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
//#include "Sales_data.h"
#include <functional>
#include <iterator>
#include <utility>
#include <memory>

#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stdlib.h>
//Design and implement the corresponding Folder class. That class should hold a set that points to the Messages in that Folder.
class Message;
class Folder
{
	friend class Message;
public: 
	set<Message*> messages;
	string folderName;

	explicit Folder(const std::string &str = "") : folderName(str) { }
	void addMsg(Message *m);
	void remMsg(Message *m);

	~Folder();
	
private: 
	
};
