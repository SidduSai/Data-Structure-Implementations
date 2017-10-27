#include<iostream>
#include "linkedlist.h"
//void append(int,string);
using namespace std;

int main()
{
	LinkedList<string> a;
	a.insert_back("a");
	a.insert_back("b");
	a.insert_back("c");
	a.insert_back("d");
	a.insert_back("e");
	a.insert_back("f");
	a.insert_back("g");
	a.insert_back("h");
	a.insert_back("i");
	a.insert("z",a.m_head);
	cout<< a << endl;
	a.reverse();
	cout<< a << endl;
//	LinkedList<char> c[5];
//	string s;
//	for(int i=0; i<1; i++)
//	{
//		cin>>s;
//		for(int j=0;j<s.size();j++)
//		{
//			//cout<<s[j]<<endl;
//			c[i].insert_back(s[j]);
//		}
//	}
//	string r;
//	int index;
//	string operation;
//	while(cin>>operation>>index>>r)
//	{
//		if(operation == "append")
//		{
//			append(index,r);
//		}
//	}
//
//	void append(int x, string b)
//	{
//		for(int i=0;i<b.size();i++)
//		{
//			a[x].insert_back(b[i]);
//		}
//		cout<<"#"<<x<<", "<<a[x].size()<<": "<<a[x];
//	}
}
