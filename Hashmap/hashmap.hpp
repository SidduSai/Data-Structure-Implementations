#include<iostream>
using namespace std;

template <typename T>
int MyStringMap<T>::hash(const string& s) const
{
	unsigned int h=0;
	for (int i=0;i<s.length();i++)
	h = h*i + s[i];
	return h % m_max;
}

template <typename T>
void MyStringMap<T>::insert(const T& key, const T& val)
{
//	cout<<"inside the insert function"<<key<<val<<endl;
	int i = hash(key);
	pair<string> tmp;
	tmp.key = key;
	tmp.value = val;
	if(m_data[i].isEmpty())
	{
		m_data[i].insert_front(tmp);
	}
	else
	{
		m_data[i].insert_back(tmp);
	}
	m_size++;
}

template <typename T>
int MyStringMap<T>::size() const
{
	return m_size;
}

template <typename T>
bool MyStringMap<T>::isEmpty() const
{
	if(m_size != 0)
	return false;
	else
	return true;
}

template <typename T>
const T& MyStringMap<T>::valueOf(const T& key) const throw ( Oops )
{
	int i = hash(key);
	if(m_data[i].isEmpty())
	throw Oops(" There is no element in the table");
	else
	{
		Node< pair<T> >* temp = m_data[i].getFirstPtr();
		for(int j = 0;j<m_data[i].m_size; j++)
		{
			if(temp->m_data.key == key)
			return temp->m_data.value;
			else
			temp = temp->m_next;
		}
		throw Oops(" There is no element in the table");
	}
}

template <typename T>
void MyStringMap<T>::print() const
{
	for(int i = 0;i<m_max;i++)
	{
		if(m_data[i].m_head->m_next == NULL)
		continue;
		else
		{
			Node< pair<T> >* temp = m_data[i].getFirstPtr();
			for(int j=0;j<m_data[i].m_size;j++)
			{
				cout<<temp->m_data.value<<endl;
				temp = temp->m_next;
			}
		}
	}
}

template <typename T>
void MyStringMap<T>::remove(const T& k)
{
	int i = hash(k);
	if(m_data[i].isEmpty())
	cout<<"there is nothing to remove"<<endl;
	else
	{
		Node< pair<T> >* temp = m_data[i].getFirstPtr();
		for(int j = 0;j<m_data[i].m_size;j++)
		{
			if(temp->m_data.key == k)
			{
				m_data[i].remove(temp);
				m_size--;
//				cout<<"the data element that we are removing with the key as"<< k<<"is "<<temp->m_data.value<<endl;
			}
			else
			temp = temp->m_next;
		}
	}
}

template <typename T>
void MyStringMap<T>::clear()
{
	for(int i=0;i < m_max;i++)
	{
		if(m_data[i].isEmpty())
		continue;
		else
		m_data[i].clear();
	}
}
