#include <iostream>
#include <cstdlib>
#include <sstream>
#include "stack.h"
using namespace std;

int main()
{
	int d,k=1;
	string equ;
	getline(cin,equ);
	stack<int> a;
	stack<string> b;
	stack<string> c;
	while(equ != ".")
	{
		string s;
		istringstream iss(equ);
		while(iss >> s)
		{
			d = atoi( s.c_str());
			if(d == 0)
			{
				if(s == "+" || s == "-" || s == "/"|| s == "*")
				{
					c.push(s);
				}
				else
					if(s == "{" || s == "[" || s == "(")
					{
					b.push(s);
					}
					else if((s == "}" && b.top() != "{") || (s == "]" && b.top() != "[") || (s == ")" && b.top() != "(") )
						{
						cout<<"INVALID from bracket comparision"<<endl;
						break;
						}
					else
						{
							int y = a.top();
							a.pop();
							int x = a.top();
							a.pop();
							string w = c.top();
							int z;
							if(w == "+")
							z = x + y;
							else if(w == "-")
							z = x - y;
							else if(w == "*")
							z = x * y;
							else if(w == "/")
							z = x / y;
							
							a.push(z);
							c.pop();
							b.pop();
						}	
			}
			else
			{
				a.push(d);
			}
			k++;	
		}
		cout<<"the final sum is "<<a.top();
		getline(cin,equ);		
	}
	if(a.isEmpty() && b.isEmpty() && c.isEmpty())
	cout<<"everything is empty";
	else
	cout<<"INVALID";
}
