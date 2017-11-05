#include <iostream>
#include "AbstraceBinaryTree.h"
#include <algorithm>
using namespace std;

template <class T>
class TreeNode
{
	public:
	
	T m_data;
	TreeNode<T>* m_left;
	TreeNode<T>* m_right;
	
	TreeNode()
	{
		m_left = NULL;
		m_right = NULL;
	}
};

template <class T>
class MyBSTree : public AbstractBSTree <T>
{
		int m_size;
		TreeNode<T>* m_root;		
			
		void prettyPrint (const TreeNode<T>* t, int pad) const;
		
		void recursive_insert(TreeNode<T>*& t, const T& x);
		
		void recursive_remove(TreeNode<T>*& t,const T& x);
		
		int recursive_height(TreeNode<T>* t) const;
		
		int recursive_find(TreeNode<T>* t,const T& x) const;
		
		void recursive_clear(TreeNode<T>*& t);
		
		void recursive_preorder(TreeNode<T>* t) const;
		
		void recursive_postorder(TreeNode<T>* t) const;
		
		TreeNode<T>* clone(TreeNode<T>* t);
		
//		const MyBSTree<T>&  operator= (const MyBSTree<T>& rhs)
				
	public :	
		
		MyBSTree()
		{
			m_size = 0;
			m_root = NULL;
		}
	
		int size() const;

		void printthetree() const
		{
			prettyPrint(m_root,2);
		}
	
		void insert(const T& x)
		{
			recursive_insert(m_root, x);
		}
		
		bool isEmpty() const;
		
		int height() const
		{
			//int m_height = 0;
			//int maxheight = recursive_height(m_root,m_height);
			//return maxheight;
			return recursive_height(m_root);
		}
		
		
		const T& getMax() const throw (Oops)
		{
			if(m_root == NULL)
			{
				throw Oops("the tree is empty");
			}
			else
			getTheMax(m_root);
		}
		
		const T& getTheMax(TreeNode<T>* t) const;
		
		const T& getMin() const throw (Oops)
		{
			if(m_root == NULL)
			{
				cout<<"The tree is empty "<<endl;
			}
			else
			getTheMin(m_root);
		}
		
		const T& getTheMin(TreeNode<T>* t) const;
		
		int find(const T& x) const
		{
			recursive_find(m_root,x);
		}
		
		void clear()
		{
			recursive_clear(m_root);
		}
		
		void remove(const T& x)
		{
			recursive_remove(m_root,x);
		}
		
		void printPreOrder() const
		{
			recursive_preorder(m_root);
		}
		
		void printPostOrder() const
		{
			recursive_postorder(m_root);
		}
		
		void print() const
		{
			printthetree();
		}
		
		const MyBSTree<T>&  operator= (const MyBSTree<T>& rhs)
		{
			cout<<"inside the operator ="<<endl;
			this->m_root = this->clone(rhs.m_root);
		}
		
};

#include "mybstree.hpp"
