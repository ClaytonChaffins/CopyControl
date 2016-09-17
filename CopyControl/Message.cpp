#include "stdafx.h"
#include "Message.h"
#include "Folder.h"

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

void Message::save(Folder &f)
{
	folders.insert(&f); // add the given Folder to our list of Folders
	f.addMsg(this); // add this Message to f's set of Messages
}
void Message::remove(Folder &f)
{
	folders.erase(&f); // take the given Folder out of our list of Folders
	f.remMsg(this); // remove this Message to f's set of Messages
}
// add this Message to Folders that point to m
void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders) // for each Folder that holds m
		f->addMsg(this); // add a pointer to this Message to that Folder
}
Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
	add_to_Folders(m); // add this Message to the Folders that point to m
}
// remove this Message from the corresponding Folders
void Message::remove_from_Folders()
{
	for (auto f : folders) // for each pointer in folders
		f->remMsg(this); // remove this Message from that Folder
}
Message::~Message()
{
	remove_from_Folders();
}
Message& Message::operator=(const Message &rhs)
{
	// handle self-assignment by removing pointers before inserting them
	remove_from_Folders(); // update existing Folders
	contents = rhs.contents; // copy message contents from rhs
	folders = rhs.folders; // copy Folder pointers from rhs
	add_to_Folders(rhs); // add this Message to those Folders
	return *this;
}
void swap(Message &lhs, Message &rhs)
{
	using std::swap; // not strictly needed in this case, but good habit
					 // remove pointers to each Message from their (original) respective Folders
	for (auto f : lhs.folders) f->remMsg(&lhs); 
	for (auto f : rhs.folders) f->remMsg(&rhs);
	// swap the contents and Folder pointer sets
	swap(lhs.folders, rhs.folders); // uses swap(set&, set&)
	swap(lhs.contents, rhs.contents); // swap(string&, string&)
									  // add pointers to each Message to their (new) respective Folders
	for (auto f : lhs.folders) f->addMsg(&lhs); for (auto f : rhs.folders) f->addMsg(&rhs);
}