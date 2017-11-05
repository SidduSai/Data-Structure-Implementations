#include <iostream>
#include "mybstree.h"
using namespace std;

int main()
{
	int k,l,m;
	MyBSTree<int> a;
	a.insert(12);
	a.insert(4);
	a.insert(16);
	a.insert(2);
	a.insert(8);
	a.insert(27);
	a.insert(6);
	a.insert(11);
	a.insert(18);
	a.remove(18);
	a.remove(3);
	a.remove(2);
	a.remove(5);
	cout<<"the size of the tree is "<<endl;
	k = a.size();
	cout<<k<<endl;
	cout<<"the max of the tree is "<<endl;
	k = a.getMax();
	cout<<k<<endl;
	cout<<"the min of the tree is "<<endl;
	k = a.getMin();
	cout<<k<<endl;
	cout<<"the height of the tree is "<<endl;
	k = a.height();
	cout<<k;
	cout<<"the element is found in"<<endl;
	k = a.find(16);
	cout<<k;
	a.print();
//	a.clear();
//	a.printthetree();
//	a.insert(10);
//	a.insert(20);
//	a.printthetree();
	a.printPreOrder();
	cout<<endl;
	a.printPostOrder();
	MyBSTree<int> b;
	b = a;
}
