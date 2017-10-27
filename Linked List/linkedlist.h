/* @file: linkedlist.h
 * Definition of templated class LinkedList
 * Implementation of List A.D.T.
 * @C - Galaxy Express Software
 * 
 * Version 17.1.1
 */

/* __________________
  /                  \
  | LinkedList Class |
  \__________________/
   
    Purpose: Implements a List ADT using a dynamically allocated 
        linked list to store the elements of the list.

    Error Handling: Whenever a function is given invalid parameter values 
        the function should return and the list should remain unchanged. 
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

// --------------- Class Node ---------------
template <class T>
class Node
{
public:
  T m_data;            // Data to be stored
  Node<T>* m_next;     // Pointer to the next element in the list


  // Purpose: Default constructor
  // Postconditions: next pointer set to NULL
  // ---INLINE---
  Node() : m_next(NULL) {}

  // Purpose: Auxiliaty constructor, construct from parameters
  // Postconditions: data and next pointer set to parameters
  // ---INLINE---
  Node(const T& x, Node<T>* p) 
             : m_data(x), m_next(p) {}

};


// --------------- Class LinkedList ---------------
template <class T>
class LinkedList
{
 public:
  Node<T>* m_head;     // Pointer to the head of the list
  Node<T>* m_back;     // Pointer to the back of the list
  int m_size;          // The number of elements in the list
  
public:
  
  // Purpose: Default constructor
  // Postconditions: this list represents the empty list
  LinkedList();

  
  // -------------
  // --------- Big 3 Member Functions ---
  // -------------

  // Purpose: Destructor
  ~LinkedList();

  // Purpose: performs a deep copy of the data from rhs into this linked list
  // Parameters: rhs is linked list to be copied
  // Returns: *this
  // Postconditions: this list contains same data values (in the same order)
  //     as are in rhs; any memory previously used by this list has been
  //     deallocated.
  const LinkedList<T>&  operator= (const LinkedList<T>& rhs);

 void reverse();

  // Purpose: copy constructor
  // Parameters: rhs is the LinkedList that is to be copied
  // Postconditions: this list contains same data values (in same order) 
  //      as in rhs.
  LinkedList(const LinkedList<T>& rhs);
  
  

  // -------------
  // --------- Basic Accessor Operations ---
  // -------------

  // Purpose: accessor function to the size the list
  // Returns: current size of the list
  int size() const;
    
  // Purpose: determines whether the list is empty
  // Returns: 'true' if list is empty; 'false' otherwise
  bool isEmpty() const;

  // Purpose: Get a pointer to the first element node
  // Returns: pointer to the first node in the list; 
  //     returns NULL if the list is empty
  Node<T>* getFirstPtr();

  // Purpose: Get a pointer to constant to the first element node               
  // Returns: pointer to constant to the first node in the list;                
  //     returns NULL if the list is empty                                      
  const Node<T>* getFirstPtr() const;

  // Purpose: accessor function for last element node
  // Returns: pointer to the last element's node in the list; 
  //     returns NULL if list is empty
  Node<T>* getLastPtr();

  // Purpose: accessor function for a node in the list
  // Returns: pointer to the node at the i'th position in the list; 
  //     returns NULL if no such element exists.
  Node<T>* getAtPtr(int i);



  // -------------
  // --------- Basic Mutator Operations ---
  // -------------
  
  // Purpose: effectively "empties" the list, 
  //          Turn the list into an empty list.
  // Postconditions: ALL dynamically allocated memory for elements is deallocated
  void clear();

  // Purpose: insert element x in the front of the list 
  // Parameters: x is data value to inserted
  // Postconditions: x is the first element of the list
  void insert_front(const T& x);

  // Purpose: insert element x in the back of the list 
  // Parameters: x is data value to inserted
  // Postconditions: x is the last element of the list
  void insert_back(const T& x);

  // Purpose: puts the data value x at the position pointed by pos
  // Parameters: x is data value to inserted
  //     pos pointer to the position to insert x at.
  // Preconditions: pos is a pointer to a node in this list.
  // Postconditions: x is inserted at the position pointed by pos
  void insert(const T& x, Node<T>* pos);

  
  // Purpose: remove the element in the front of the list 
  // Postconditions: the first element of the list is removed
  void remove_front();

  // Purpose: removes the element at the back of the list 
  // Postconditions: the last element of the list is removed
  void remove_back();

  // Purpose: remove the element in the position pointed by pos
  // Parameters: pos pointer to the position to remove.
  // Preconditions: pos is a pointer to a node in this list.
  // Postconditions: element pointed by pos is removed from the list
  void remove(Node<T>* pos);
  


  // --------
  // ---- Complex Operations ---
  // --------

  // Purpose: determines whether this list is identical to rhs list in
  // terms of data values and their order in the list
  // Parameters: rhs is list to be compared to this list
  // Returns: true if lists are identical; otherwise, false
  bool operator== (const LinkedList<T>& rhs) const;
            
}; // of class LinkedList



// ---------------  Utility Function for Printing
// Purpose: prints a LinkedList
template <typename T>                 
std::ostream& operator<< (std::ostream& out, const LinkedList<T>& list);

#include "LinkedList.hpp"

#endif
