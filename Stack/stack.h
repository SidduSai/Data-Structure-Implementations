#include "abstractstack.h"
#include <iostream>
using namespace std;

template <class T>
class Node
{
	public:
		T m_data;
		Node<T>* m_next;
		
		public: Node()
		{
			m_next = NULL;
		}
};

template <class T>
class stack : public AbstractStack <T>
{
	Node<T>* m_head;
	Node<T>* m_front;
	int m_size;
	public: stack()
	{
		m_size = 0;
		Node<T>* temp = new Node<T>;
		m_head = temp;
		m_front = m_head;
	}
	
public:
	
	bool isEmpty() const
	{
		if(m_size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	void push(const T& x)
	{
		if(isEmpty())
		{
			Node<T>* temp = new Node<T>;
			temp->m_data = x;
			temp->m_next = m_head;
			m_head = temp;
			m_front = temp->m_next;
			m_size++;
		}
		else
		{
			Node<T>* temp = new Node<T>;
			m_front->m_data = x;
			m_front->m_next = temp;
			m_front = temp;
			m_size++;
		}
		
	}
	
	const T& top() const throw ( Oops )
	{
		if(isEmpty())
		{
			//throw Oops( "the stack is empty" );
		}
		else
		{
		Node<T>* temp;
		temp = m_head;
		for(int i = 1; i<m_size; i++)
		{
			temp = temp->m_next;
		}
		return temp->m_data;
		}
	}
	
	void pop()
	{
		Node<T>* temp;
		if(isEmpty())
		{
			cout<<"stack is empty";
		}
		else if(m_size == 1)
		{
			delete m_head;
			m_head = m_front;
			m_size--;
		}
		else
		{
		temp = m_head;
		for(int i = 1;i<m_size-1;i++)
		{
			temp = temp->m_next;
		}
		delete temp->m_next;
		temp->m_next = m_front;
		m_size--;
		}
	}
	
	void clear()
	{
		Node<T>* temp;
		
		for(int i = 0;i < m_size; i++)
		{
			temp = m_head->m_next;
			delete m_head;
			m_head = temp;
		}
		delete temp;
	}
};
