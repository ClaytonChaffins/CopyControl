#pragma once
// CopyControl.cpp : Defines the entry point for the console application.
//

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
//NEED TO DEFINE FOLDER CLASS!
class Folder;
class Message 
{
	friend class Folder;
public:
	string contents; // actual message text
	set<Folder*> folders; // Folders that have this Message

	void add_to_Folders(const Message&);
	// remove this Message from every Folder in folders
	void remove_from_Folders();

	// folders is implicitly initialized to the empty set
	explicit Message(const std::string &str = "") : contents(str) { }
	// copy control to manage pointers to this Message
	Message(const Message&); // copy constructor
	Message& operator=(const Message&); // copy assignment
	~Message(); // destructor
				// add/remove this Message from the specified Folder's set of messages
	void save(Folder&); 
	void remove(Folder&);
private:
							   // utility functions used by copy constructor, assignment, and destructor
							   // add this Message to the Folders that point to the parameter

};


