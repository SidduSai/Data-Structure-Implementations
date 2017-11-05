#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
int MyBSTree<T>::size() const
{
	return m_size;
}

template <typename T>
const T& MyBSTree<T>::getTheMax(TreeNode<T>* t) const
{
	if(t->m_right == NULL)
	{
		return t->m_data;
	}
	else
	return getTheMax(t->m_right);
}
	
template <typename T>		
const T& MyBSTree<T>::getTheMin(TreeNode<T>* t) const
{
	if(t->m_left == NULL)
	{
		return t->m_data;
	}
	else
	return getTheMin(t->m_left);
}

template <typename T>
void MyBSTree<T>::recursive_insert(TreeNode<T>*& t, const T& x)
		{
			if(t == NULL)
			{
				t = new TreeNode<T>;
				t->m_data = x;
				m_size++;
			}
			else
			{
				if(x < t->m_data)
				{
					recursive_insert(t->m_left,x);
				}
				else if(x > t->m_data)
				{
					recursive_insert(t->m_right,x);
				}
				else
				{
					return;
				}
			}
		}
		
template <typename T>		
void MyBSTree<T>::recursive_remove(TreeNode<T>*& t,const T& x)
		{
			if(t == NULL)
			{
				return;
			}
			if(x<t->m_data)
			{
				recursive_remove(t->m_left,x);
			}
			else if(x<t->m_data)
			{
				recursive_remove(t->m_right,x);
			}
			else
			{
				m_size++;
				if(t->m_left == NULL && t->m_right == NULL )
				{
					delete t;
					t = NULL;
				}
				else if(t->m_left == NULL || t->m_right == NULL )
				{
					TreeNode<T>* child = t->m_left;
					if(child == NULL)
					{
						child = t->m_right;
					}
					delete t;
					t = child;
				}
				else
				{
					t->m_data = getTheMax(t->m_left);
					recursive_remove(t->m_left,t->m_data);
				}
			}
		}
		
		template <typename T>
		void MyBSTree<T>::prettyPrint (const TreeNode<T>* t, int pad) const
		{
 			string s(pad, ' ');
 			if (t == NULL)
     		cout << endl;
 			else
			{
   				prettyPrint(t->m_right, pad+4);
   				cout << s << t->m_data << endl;
   				prettyPrint(t->m_left, pad+4);
 			}  
		}
		
template <typename T>
bool MyBSTree<T>::isEmpty() const
		{
			if(m_root != NULL)
			return false;
			else
			return true;
		}
		
template <typename T>		
int MyBSTree<T>::recursive_height(TreeNode<T>* t) const
{
//	cout<<"inside the recursive height"<<endl;
	if(t == NULL)
	{
		return 0;
	}
	else
	{
		int righth, lefth;
		righth = recursive_height(t->m_right);
		lefth = recursive_height(t->m_left);
		return 1 + max(righth,lefth);
	}
}

template <typename T>
int MyBSTree<T>::recursive_find(TreeNode<T>* t, const T& x) const
{
	if(t == NULL)
	return -1;
	else if(t->m_data == x)
	return 1;
	else if(t->m_data > x)
	{
		int a;
		a = recursive_find(t->m_left,x);
		if(a < 0)
		return a-1;
		else
		return 1+a;
	}
	else if(t->m_data < x)
	{
		int b;
		b = recursive_find(t->m_right,x);
		if(b<0)
		return b-1;
		else
		return 1+b;
	}
}

template <typename T>
void MyBSTree<T>::recursive_clear(TreeNode<T>*& t)
{
	if(t == NULL)
	{
		return;
	}
	else
	{
		recursive_clear(t->m_left);
		recursive_clear(t->m_right);
		delete t;
		t = NULL;
	}
}

template <typename T>
void MyBSTree<T>::recursive_preorder(TreeNode<T>* t) const
{
	if(t == NULL)
	{
		return;
	}
	else
	{
		cout<<t->m_data<<endl;
		recursive_preorder(t->m_left);
		recursive_preorder(t->m_right);
	}
}

template <typename T>
void MyBSTree<T>::recursive_postorder(TreeNode<T>* t) const
{
	if(t == NULL)
	{
		return;
	}
	else
	{
		recursive_postorder(t->m_left);
		recursive_postorder(t->m_right);
		cout<<t->m_data<<endl;
	}
}

template <typename T>
TreeNode<T>* MyBSTree<T>::clone(TreeNode<T>* t)
{
	if(t == NULL) return NULL;
	else
	{
		TreeNode<T>* temp = new TreeNode<T>;
		temp->m_data = t->m_data;
		temp->m_left = clone(t->m_left);
		temp->m_right = clone(t->m_right);
		return temp;
	}
}
