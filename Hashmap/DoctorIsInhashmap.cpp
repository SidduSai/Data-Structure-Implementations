#include <iostream>
#include "mystringmap.h"

using namespace std;

int main()
{
	int i;
	MyStringMap<string> a;
	a.insert( string("hello"),  string("first"));
	a.insert( string("helloo"),  string("second"));
	a.insert( string("secondhello"),  string("third"));
	a.insert( string("thirdhello"),  string("fourth"));
	a.print();
	cout<<"now printing the value of hello "<<a.valueOf(string ("hello"))<<endl;
	cout<<"now printing the value of secondhello "<<a.valueOf(string ("secondhello"))<<endl;
	i = a.size();
	cout<<i<<endl;
	a.remove(string("hello"));
	a.print();
	i = a.size();
	cout<<i<<endl;
	a.clear();
	a.print();
	a.size();
}
