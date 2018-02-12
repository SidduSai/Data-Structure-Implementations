/*  _________________________
 * /                         \
 * |   Abstract StringMap    |
 * \_________________________/
 *
 * Author: Dr. Ricardo Morales
 * 
 * Version: 17.1
 *
 * Purpose: A templated abstract class that defines a StringMap:
 *     A set of key-value pairs where the "Key" is a String and
 *     where the "Value" is of type T.
 * 
 * Note: For Homework #7, your Map implementation should derive
 *     this class AND use a hash table!
 * 
 * NOTE: Only one Value can be associated for each Key
 */

#ifndef ABSTRACTSTRINGMAP_H
#define ABSTRACTSTRINGMAP_H

#include <iostream>
#include <string>
using namespace std;


/* ---------------  Class 'Oops' ---------------
Class "thrown" when an error is encountered.
Member 'm_msg' stores an error message.
*/
class Oops
{
	string m_errormsg;
public:
	Oops(const string &msg) : m_errormsg(msg) {}
	const string& getMsg() const
	{
		return m_errormsg;
	}
};


template < typename T >
class AbstractStringMap
{
  
public:
      
   /*** ---- Accessor Operations ---- */
  
// Purpose: Accessor function for the number of elements in the Map
// Returns: number of elements in the Map 
  virtual int size() const = 0;


// Purpose: Checks if a Map is empty
// Returns: 'true' if the Map is empty
//     'false' otherwise  
  virtual bool isEmpty() const = 0;


// Purpose: Returns the value associated with a key.
// Parameters: key of the value to be found 
// Returns: 
//     If The Map contains Key then return the value associated with Key.
//     If The Map does not contains Key then THROW an OOPs object
  virtual const T& valueOf(const string& key) const throw ( Oops ) = 0;


    
  /*** ---- Mutator Operations ---- */

// Purpose: Clears the Map
// Postconditions: an empty Map
  virtual void clear() = 0;


// Purpose: Inserts an element into a Map
// Parameters: Key and  Value to be added to the Map
// Postconditions: The Map now contains the pair < Key, Value >
//     if the Map already contains a value associated with Key,
//     replace it with the parameter Val
  virtual void insert(const string& key, const T& val) = 0;

    
// Purpose: Removes an element from the Map
// Parameters: K, the Key to remove
// Postconditions: the map does not contains a pair with k as Key
  virtual void remove(const string& k) = 0;
          
     
  /*** ---- Output Operations ---- */

// Purpose: Prints the Map with pretty formatting
// NOTE: No particular order is required.
  virtual void print() const = 0;
          
          
  /*** ---- Utility Functions Operations ---- */

// Purpose: Hashes a string into an integer.
// you shall use this function for your hash-table.
private:
  virtual int hash(const string &s) const = 0;                  
          
};
 

#endif 
