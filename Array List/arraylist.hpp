#include<iostream>
#include<cmath>
using namespace std;

template <typename T>
int ArrayList<T>::size() const
{
	return(m_size);
}

template <typename T>
void ArrayList<T>::grow()
{
	T *tmp = new T[m_max*2];
	for(int k=0;k<m_size;k++)
	{
		tmp[k] = m_data[k];
	}
	m_max = m_max*2;
	delete []m_data;
	m_data = tmp;
}

template <typename T>
void ArrayList<T>::shrink()
{
	if(m_max/2 <= m_size)
	{
		T* tmp = new T[m_max/2];
		for(int k=0;k<m_size;k++)
		{
			tmp[k] = m_data[k];
		}
		m_max = m_max/2;
		delete []m_data;
		m_data = tmp;
	}
}

template <typename T>
ArrayList<T>::ArrayList(int s, const T& x)
{
	T m_data = new T[s];
	m_max = s;
	m_size = 0;
}

template <typename T>
ArrayList<T>::~ArrayList()
{
	delete []m_data;
}

template <typename T>
const T& ArrayList<T>::first() const
{
	if ( m_size != 0 )
		return m_data[0];

	return m_errobj;
}

template <typename T>
T& ArrayList<T>::operator[](int i)
{
	return m_data[i];
}

template <typename T>
const T& ArrayList<T>::operator[](int i) const
{
	return m_data[i];
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs)
{
	if(this != &rhs)
	{
		this->m_size = rhs.m_size;
		this->m_max = rhs.m_max;
		T *tmp = new T[m_max];
		for(int i=0;i<m_size;i++)
		{
			tmp[i] = rhs.m_data[i];
		} 
		m_data = tmp;
	}
	return *this;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& cpy)
{
	
	m_data = NULL;
	m_size = 0;
	m_max = 0;
	*this = cpy;
}

template <typename T>
int ArrayList<T>::find(const T& x) const
{
	for(int j=0;j<m_size;j++)
	{
		if(m_data[j] == x)
		{
			return(j);
		}
	}
}

template <typename T>
void ArrayList<T>::clear()
{
	m_max = 0;
	m_size = 0;
	m_data = NULL;
}

template <typename T>
void ArrayList<T>::insert_back(const T& x)
{
	if(m_size == 0)
	{
		T *tmp = new T[1];
		tmp[0] = x;
		m_data = tmp;
		m_size++;
		m_max = 1;
	}
	else
	{
		if(m_size == m_max)
		{
			grow();
		}
		m_data[m_size] = x;
		m_size++;
	}
	
}

template <typename T>
void ArrayList<T>::insert(const T& x, int i)
{
	if(m_max == m_size)
	{
		grow();
	}
	if(0<=i && i<=m_size)
	{
		for(int k=m_size-1;k>=i;k--)
		{
			m_data[k+1] = m_data[k];
		}
		m_data[i] = x;
		m_size++;
	}
}

template <typename T>
void ArrayList<T>::remove(int i)
{
	if(i>=0 && i<=m_size)
	{
		for(int k=i;k<m_size-1;k++)
		{
			m_data[k] = m_data[k+1];
		}
		m_size--;
	}
//	cout<<"removing complete"<<endl;
//	if(m_size<=m_max/2)
//	{
//		shrink();
//	}
}

template <typename T>
void ArrayList<T>::swap(int i, int k)
{
	T temp;
	temp = m_data[i];
	m_data[i] = m_data[k];
	m_data[k] = temp;
}

template <typename T>
void ArrayList<T>::append(const ArrayList<T>& alist)
{
	int b = 0;
	int a;
	if( alist.size() + m_size > m_max)
	{
		a = alist.m_size + this->m_size;
		while(a<m_max)
		grow();
		for(int i=m_size;i<a;i++)
		{
			m_data[i] = alist.m_data[b];
		}
	}
	else
	{
		a = alist.m_size + this->m_size;
		for(int i=m_size;i<a;i++)
		{
			m_data[i] = alist.m_data[b];
		}
	}
}
	
template <typename T>
void ArrayList<T>::reverse()
{
	T temporary;
	for (int i = 0; i < (m_size / 2); i++)
	{
	temporary = m_data[i];
	m_data[i] = m_data[(m_size - 1) - i];
	m_data[(m_size - 1) - i] = temporary;
	}
}
	
	
	
	
