
#include "AbstracrtStringMap.h"
#include "linkedlist.h"

template <class T>
class MyStringMap : public AbstractStringMap<T>
{
	int hash(const string& s) const;
	
	template <typename U>
	class pair {
		public:
		string key;
		U value;
	};
	
	public : 

	LinkedList< pair<T> >* m_data;
	int m_size;
	int m_max;
	
	MyStringMap()
	{
		m_size = 0;
		m_max = 1000;
		m_data = new LinkedList< pair<T> >[m_max];
//		m_data = new T*[m_max];
	}
	
    int size() const;

	bool isEmpty() const;
	
	const T& valueOf(const T& key) const throw ( Oops );
	
	void clear();
	
	void insert(const T& key, const T& val);
	
	void remove(const T& k);
	
	void print() const;
	
};

#include "hashmap.hpp"
