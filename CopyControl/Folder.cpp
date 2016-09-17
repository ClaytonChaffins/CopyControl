#include "stdafx.h"
#include "Folder.h"
#include "Message.h"

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

void Folder::addMsg(Message *m)
{
	messages.insert(m);
}
void Folder::remMsg(Message *m)
{
	//auto iter = find(messages.begin(), messages.end(), m); //PROBLEM!


	//messages.erase(m); //PROBLEM!!!!!!
	//delete m;

}

Folder::~Folder()
{
	//remove_from_Folders();
}