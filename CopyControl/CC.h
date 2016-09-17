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

#include "StrBlob.h"
#include "StrBlobPtr.h"

struct X {
	X() 
	{ 
		std::cout << "X()" << std::endl; 
	} 
	X(const X&) 
	{
		std::cout << "X(const X&)" <<
			std::endl;
	}
};
const vector<int> v123 = {23,5,8,9,10,11,12,13,14 };
int index1 = 0;
class Numbered
{
public: 
	Numbered()
	{
		//mysn = v123[index1]; //random num generator
		//++index1;
		mysn = 0;
	} 
	Numbered(const Numbered &orig) //makes even the copied Numered items have a unique mysn
	{
		mysn = v123[index1]; //random num generator
		++index1;
	}
	int mysn;
};
void f1(const Numbered &s) //SINCE THIS IS S AND NOT &S, THE VALUE WILL BE COPIED AND SUBSEQUENTLY BE ROUTED THROUGH THE COPY STATEMENT. IF & IS USED, IT IS NOT ROUTED THROUGH THE COPY STATEMENT
{
	cout << s.mysn << endl;
}
class HasPtr {
public:
	HasPtr(const string &s = string()) : ps(new string(s)), i(0) { }
	HasPtr(const HasPtr& tempPtr) //original HasPtr is a copy of the function passed into the ()
	{
		i = tempPtr.i;
		ps = new string(*tempPtr.ps); //memory problem?
	}
	//swap control:
	friend void swap(HasPtr&, HasPtr&);
	//the = opperator manually modifies and changes the ps string value
	HasPtr &operator=(const HasPtr &ref) // left hand operand binds to the the this pointer 
	{
		i = ref.i;
		ps = new string ("This is an assignment copy");
		return *this;
	}
	~HasPtr() //destructor
	{
		cout << "HasPtr has been destructed" << endl;
	}
	int returni()
	{
		return i;
	}
	string returnPs()
	{
		return *ps;
	}
	void changeps(string &s1)
	{
		ps = new string(s1);
	}
private:
	string *ps; 
	int i;
};
inline void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps); // CALLS THE LIBRARY SWAP FUNCTION
	swap(lhs.i, rhs.i); // swap the int members
}


class HasPtrValue {
public:
	HasPtrValue(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { }
	// each HasPtr has its own copy of the string to which ps points
	HasPtrValue(const HasPtrValue &p) : ps(new std::string(*p.ps)), i(p.i) { }
	HasPtrValue& operator=(const HasPtrValue &rhs)
	{
		auto newp = new string(*rhs.ps); // copy the underlying string
		delete ps; // free the old memory
		ps = newp; // copy data from rhs into this object
		i = rhs.i;
		return *this; // return this object
	}
	~HasPtrValue() { delete ps; }

	string returnPs()
	{
		return *ps;
	}
	int returnInt()
	{
		return i;
	}
private:
	string *ps; 
	int i;
};


class HasPtrRef {
public:
	HasPtrRef(const std::string &s = std::string()) : ps(new std::string(s)), i(0), useCount(new int(1)) { }
	// each HasPtr has its own copy of the string to which ps points

	//copy control: 
	HasPtrRef(const HasPtrRef &p) : ps(p.ps), i(p.i), useCount(p.useCount)
	{ 
		++(*useCount);
	}
	HasPtrRef& operator=(const HasPtrRef &rhs)
	{
		++(*rhs.useCount);
		--useCount;
		if (useCount == 0)
		{
			delete ps;
			delete useCount;
		}
		ps = rhs.ps;
		i = rhs.i;
		useCount = rhs.useCount;
		return *this; // return this object
	}
	~HasPtrRef() 
	{ 
		--useCount;
		if (useCount == 0)
		{
			delete ps;
			delete useCount;
		}
	}

	string returnPs()
	{
		return *ps;
	}
	int returnInt()
	{
		return i;
	}
	int returnuseCount()
	{
		return *useCount;
	}
private:
	string *ps;
	int i;
	int *useCount;
};

class Employee
{
public:
	static int incr;
	string name;
	int id;
	vector<HasPtr> v1;
	Employee() = default;
	Employee(string s) //modified constructor
	{
		name = s;
		id = incr;
		++incr;
	}
	Employee(const Employee& tempEmp) //copy control
	{
		name = tempEmp.name;
		id = tempEmp.id;
	}

	bool operator<(const Employee &rhs) //returns true if the lhs has few entries in v1
	{
		if (v1.size() < rhs.v1.size())
		{
			return true;
		}
		else return false;

	}

};
int Employee::incr = 1;


void function1() //messing with copy statements:
{

	HasPtr hP("hP 1");
	HasPtr hP2(hP); //hP2 is now a copy of hP
	string s2 = "hP WOOHOO";
	hP2.changeps(s2); //changes ps for hP2 but NOT hP 
	cout << hP.returnPs() << endl;
	cout << hP2.returnPs() << endl;
}
void function2()
{
	cout << "function2" << endl;
	HasPtr hP("hP 1"), hP2;
	hP2 = hP;
	cout << "hP2: "<< hP2.returnPs() << endl;


}
void function3()
{
	cout << "function3" << endl;
	X weep;
	X weep2(weep);
	X weep3 = weep2;
	auto weep4 =  &weep3;
	X weep5 = *weep4;

}
void function4()
{
Numbered a, b = a, c = b;
Numbered d;
	f1(a);
	f1(b);
	f1(c);
	f1(d);
}
void function5()
{
	Employee e;
	Employee e2("Bill2");
	Employee e3("Bill3");
	Employee e4("Bill4");

	e = e3;
	Employee e5(e3);
	cout << e.name << " " << e.id << endl;
	cout << e2.name << " " << e2.id << endl;
	cout << e3.name << " " << e3.id << endl;
	cout << e4.name << " " << e4.id << endl;
	cout << e5.name << " " << e5.id << endl;
}
void function6() // // First, we’ll make the class act like a value; then we’ll reimplement the class making it behave like a pointer.
{
	cout << "function6:" << endl;
	//copy EVERYTHING by value from hPV2 to hPV:
	HasPtrValue hPV("1");
	HasPtrValue hPV2("2");
	hPV = hPV2;
	cout << "first: "<< hPV.returnPs() << " " << hPV.returnInt() << endl;
	cout << "second: "<< hPV2.returnPs() << " " << hPV2.returnInt() << endl;

	HasPtrValue hPV3("3");
	HasPtrValue hPV4(hPV3);
	cout << "th2ird: " << hPV3.returnPs() << " " << hPV.returnInt() << endl;
	cout << "foruth: " << hPV4.returnPs() << " " << hPV2.returnInt() << endl;
}

void function7()
{
	cout << "function7:" << endl;
	HasPtrRef hp1("1");
	HasPtrRef hp2(hp1);
	cout << "first: " << hp1.returnPs() << " " << hp1.returnInt() << endl;
	cout << "second: " << hp2.returnPs() << " " << hp2.returnInt() << endl;
	cout << hp1.returnuseCount() << endl;

	HasPtrRef hp3("3");
	hp3 = hp2;
	cout << "third: " << hp3.returnPs() << " " << hp3.returnInt() << endl;
	cout << hp3.returnuseCount() << endl;


	//creating constuctors and copy control functions for TreeNode class...
	TreeNode tn1("1");
	TreeNode tn2();
	TreeNode tn3();

}
void function8()
{
	cout << "function8:" << endl;

	HasPtr hp1("ifowhfio3h 1");
	HasPtr hp2("svdvvdvddvdvv 2");
	HasPtr hp3("efw 3");
	swap(hp1, hp2); //CALLS THE SWAP WE DEFINED. NOT THE LIBRARY VERSION

	//sucessfully swapped: 
	cout << " hp1: "<< hp1.returnPs() << endl;
	cout << " hp2: " << hp2.returnPs() << endl;	


	Employee emp1("emp1");
	emp1.v1.push_back(hp1);
	emp1.v1.push_back(hp2);
	emp1.v1.push_back(hp3);

	Employee emp2("emp2");
	emp2.v1.push_back(hp1);

	cout << "Result of '<' opporator:" << endl; 
	cout << (emp2 < emp1) << endl;
}
void function9()
{
	Message m1("message 1");
	Message m2("message 2");
	Message m3("message 3");

	Folder f1("folder 1");
	Folder f2("folder 2");
	Folder f3("folder 3");

	m1.save(f1);
	m2.save(f1);

	cout << "printing contents of messages within each folder:" << endl;
	for (auto m : f1.messages)
	{
		cout << m->contents << endl;
	}
	cout << "test1" << endl;
}
void function10()
{
	//doesnt work: 
	/*
	cout << "function10:" << endl;
	StrBlob sb1();
	cout << (sb1 == sb1) << endl;
	*/
}