#include <iostream>
using namespace std;

template <typename T>
LinkedList<T>::LinkedList()
{
	m_size = 0;
	m_head = new Node<T>;
	m_head->m_next = NULL;
	m_back = m_head;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	Node<T>* temp;
	while(m_head != NULL)
	{
		temp = m_head->m_next;
		delete m_head;
		m_head = temp;
	}
}

template <typename T>
const LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
	Node<T>* temp = rhs.m_head;
	this->clear();
	this->m_size = rhs.m_size;
	if(this->m_size > 0)
	{
		for(int i=0;i<rhs.m_size;i++)
		{
			this->insert_back(temp->m_data);
			temp = temp->m_next;
		}
		this->m_back = temp->m_next;
	}
}

template <typename T>
void LinkedList<T>::reverse()
{
	Node<T>* prev;
	Node<T>* current;
	Node<T>* nextnode;
	prev = new Node<T>;
	prev->m_next = NULL;
	current = m_head;
	while(current->m_next != NULL)
	{
		nextnode = current->m_next;
		current->m_next = prev;
		prev = current;
		current = nextnode;
	}
	m_head = prev;
}

template <typename T>
int LinkedList<T>::size() const
{
	return m_size;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	if(m_size == 0)
	{
		return true;
	}
	else 
	return false;
}

template <typename T>
Node<T>* LinkedList<T>::getFirstPtr()
{
	if(isEmpty())
	{
		return NULL;
	}
	else
	{
		return m_head;
	}
}

template <typename T>
const Node<T>* LinkedList<T>::getFirstPtr() const
{
	if(m_size == 0)
	{
		return NULL;
	}
	else
	{
		return m_head;
	}
}

template <typename T>
Node<T>* LinkedList<T>::getLastPtr()
{
	if(isEmpty)
	{
		return NULL;
	}
	else
	return m_back;
}

template <typename T>
Node<T>* LinkedList<T>::getAtPtr(int i)
{
	Node<T>* temp;
	temp = m_head;
	for(int j=0;j<i;j++)
	{
		temp = temp->m_next;
	}
	return temp;
}

template <typename T>
void LinkedList<T>::clear()
{
	{
	Node<T>* temp;
	while(m_head != NULL)
	{
		temp = m_head->m_next;
		delete m_head;
		m_head = temp;
	}
	m_size = 0;
	m_head = new Node<T>;
	m_head->m_next = NULL;
	m_back = m_head;
}

}

template <typename T>
void LinkedList<T>::insert_front(const T& x)
{
	Node<T>* temp = new Node<T>;
	temp->m_data = x;
	temp->m_next = m_head;
	m_head = temp;
	m_size++;
}

template <typename T>
void LinkedList<T>::insert_back(const T& x)
{
	if(m_size == 0)
	{
		insert_front(x);
	}
	else
	{
	Node<T>* temp = new Node<T>;
	temp->m_next = NULL;
	m_back->m_data = x;
	m_back->m_next = temp;
	m_back = temp;
	m_size++;
	}
}

template <typename T>
void LinkedList<T>::insert(const T& x, Node<T>* pos)
{
	Node<T>* temp = new Node<T>;
	temp->m_data = pos->m_data;
	temp->m_next = pos->m_next;
	pos->m_data = x;
	pos->m_next = temp;
	m_size++;
}

template <typename T>
void LinkedList<T>::remove_front()
{
	Node<T>* temp = new Node<T>;
	temp = m_head->m_next;
	delete m_head;
	m_head = temp;
	m_size--;
}

template <typename T>
void LinkedList<T>::remove_back()
{
	Node<T>* temp = m_head;
	for(int i=0;i<m_size-2;i++)
	{
		temp = temp->m_next;
	}
	delete temp->m_next;
	temp->m_next = m_back;
	m_size--;
}

template <typename T>
void LinkedList<T>::remove(Node<T>* pos)
{
	if(m_size == 1)
	{
		remove_front();		
		m_size--;
	}
	else if(pos->m_next->m_next == NULL)
	{
		remove_back();	
		m_size--;
	}
	else{
	Node<T>* temp = new Node<T>;
	temp->m_next = pos->m_next->m_next;
	pos->m_data = pos->m_next->m_data;
	delete pos->m_next;
	pos->m_next = temp;
	m_size--;
	}
}

template <typename T>
ostream& operator<<(std::ostream& out, const LinkedList<T>& list)
{
	const Node<T>* temp;
	temp = list.getFirstPtr();
	while(temp->m_next != NULL)
	{
		cout<<temp->m_data;
		temp = temp->m_next;
	}
	cout << ",";
}
