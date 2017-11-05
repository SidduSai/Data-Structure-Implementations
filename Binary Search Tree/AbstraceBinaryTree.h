/*  _____________________________
 * /                             \
 * | Abstract Binary Search Tree |
 * \_____________________________/
 *
 * @C - Galaxy Express Software
 *
 * Version 17.1.0
 * 
 * Purpose: A template abstract class that defines a Binary Search Tree
 * 
 * Preconditions: typename T *MUST* support the '<' operator
 *
 * Note: For this Homework, your Binary Search Tree implementation 
 *     should derive this class.
 */

#ifndef ABSTRACTBSTREE_H
#define ABSTRACTBSTREE_H

#include <iostream>
#include <string>

using namespace std;

/* ---------------  Class 'Oops' ---------------
Class
Thrown when an error is encountered.
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



/* ---------------  Abstract Class AbstractBSTree --------------- */
template < typename T >
class AbstractBSTree
{
public:
	  
   /*** ---- Accessor Operations ---- */
  
// Purpose: Accessor function for the number of elements in the tree
// Returns: number of elements in the tree 
  virtual int size() const = 0;

// Purpose: Checks if a tree is empty
// Returns: 'true' if the tree is empty
//     'false' otherwise  
  virtual bool isEmpty() const = 0;

// Purpose: Returns the height of the tree
// Returns: height the tree 
  virtual int height() const = 0;


// Purpose: returns the maximum element in the Tree
// Returns: a const reference to the maximum element
// Exception: if the tree is empty, THROW a 'Oops' object with an error message!!!
  virtual const T& getMax() const throw (Oops) = 0;

// Purpose: returns the minimum element in the Tree
// Returns: a const reference to the minimum element
// Exception: if the tree is empty, THROW a 'Oops' object with an error message!!!
  virtual const T& getMin() const throw (Oops) = 0;

// Purpose: finds an element in the Tree
// Parameters: x is value to be found 
// Returns: 
//     If the tree contains x then  
//         return N, the level of the node containing x
//         (the root is considered level 1)
//     If The tree does not contains x then  
//         return -N, where N is the level of the tree reached in the search
//     REPEAT: The root of the tree is considered level 1. 
  virtual int find(const T& x) const = 0;


    
  /*** ---- Mutator Operations ---- */

// Purpose: Clears the Tree
// Postconditions: an empty Tree
  virtual void clear() = 0;

// Purpose: Inserts an element into a tree
// Parameters: x is value to be added to the tree
// Postconditions: The tree now contains x
//     if the tree already contains x, ignore insertion
  virtual void insert(const T& x) = 0;

// Purpose: Removes an element from the tree
// Parameters: x, the element to remove
// Postconditions: the tree does not contains x
  virtual void remove(const T& x) = 0;
          
     
  /*** ---- Output Operations ---- */

// Purpose: Prints the Tree in Pre-Order    
  virtual void printPreOrder() const = 0;

// Purpose: Prints the Tree in Pre-Order    
  virtual void printPostOrder() const = 0; 


// Purpose: Prints the Tree In-Order with formatting
//     each level indented 4 spaces, one element per line    
  virtual void print() const = 0;
          
};
 

#endif 
