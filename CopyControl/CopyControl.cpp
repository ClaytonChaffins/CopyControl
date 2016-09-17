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

#include "StrBlob.h"
#include "StrBlobPtr.h"
//#include "TextQ.h"
#include "Employee.h"
#include "TreeNode.h"
#include "Message.h"
#include "Folder.h"
#include "CC.h"

/*
#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "TextQ.h
*/

/*
= means copy. Using () means direct initilization
Assignment operators ordinarily should return a reference to their left-hand operand.

A deleted function is one that is declared but may not be used in any other way
Classes that want to prevent copying should define their copy constructor and copy-assignment operators using = delete rather than making those members private.

It is crucially important for assignment operators to work correctly, even
when an object is assigned to itself. A good way to do so is to copy the
right-hand operand before destroying the left-hand operand.

The easiest way to make a class act like a pointer is to use shared_ptrs to manage the resources in the class

define swap as a friend so you can acess private data members

defining swap can be an important optimization for classes that allocate resources.
"copy and swap" swaps the lefthand operand with a copy of the right-hand operand:
Assignment operators that use copy and swap are automatically exception safe and correctly handle self-assignment

*/

int main()
{
	cout << "Exercises Section 13.1.1: " << endl;
	function1();

	cout << "13.1.2. The Copy-Assignment Operator:" << endl;
	function2();

	cout << "Exercises Section 13.1.3:" << endl;
	function3();

	cout << "Exercises Section 13.1.4" << endl;
	function4();

	cout << "Exercises Section 13.1.6:" << endl;


	cout << "Exercises Section 13.1.6:" << endl;
	function5();

	cout << "Exercises Section 13.2.1:" << endl;
	function6(); // First, we’ll make the class act like a value; then we’ll reimplement the class making it behave like a pointer.

	function7(); //defining 2 different versions of HasPtr

	cout << "Exercises Section 13.3" << endl;
	function8(); //testing swapping 

	cout << "Exercises Section 13.4:" << endl;
	function9();

	function10();
	//FINISHED THIS SECTION AT 13.4


    return 0;
}

