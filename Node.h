/** @file Node.h
* @class Node
* Class to structure a node to hold a polynomial term.
*/

#ifndef NODE_
#define NODE_

#include <cstddef>

template<class ItemType>
class Node 
{
private:
	/** Coefficient of the term */
	ItemType coefficient;
	/** Power of the variable in the term */
	unsigned int power;
	/** Pointer to the next node */
	Node<ItemType>* next;

public:
	/** Default constructor 
	* @pre None
	* @post Initializes the node. */
	Node();

	/** Parameterized constructor
	* @pre Assumes nonnegative integer power.
	* @post Initializes the node.
	* @param someCoefficient Given coefficient to initialize.
	* @param somePower Given power to initialize. */
	Node(const ItemType& someCoefficient, unsigned int somePower);

	/** Parameterized constructor with next node pointer. 
	* @pre Assumes nonnegative integer power.
	* @post Initializes the node.
	* @param someCoefficient Given coefficient to initialize.
	* @param somePower Given power to initialize. 
	* @param nextNodePtr Pointer to next node in the linked list. */
	Node(const ItemType& someCoefficient, unsigned int somePower, Node<ItemType>* nextNodePtr);

	/** Sets the coefficient of the node.
	* @pre None
	* @post Coefficient is added to the term in current node.
	* @param someCoefficient Is the coefficient to be set. */
	void setCoefficient(const ItemType& someCoefficient);

	/** Sets the power of the node.
	* @pre Power must be nonnegative.
	* @post Power is added to the term in current node.
	* @param somePower The power to be set. */
	void setPower(unsigned int somePower);

	/** Sets the next node pointer.
	* @pre None
	* @post Next node pointer is added to the term in current node.
	* @param nextNodePtr Is the pointer value to be set. */
	void setNext(Node<ItemType>* nextNodePtr);

	/** Gets the coefficient within the node. 
	* @pre None
	* @post Does not change the coefficient.
	* @return The coefficient value. */
	ItemType getCoefficient() const;

	/** Gets the power within the node. 
	* @pre Assume nonnegative integer power.
	* @post Does not change the power.
	* @return The power value. */
	unsigned int getPower() const;

	/** Gets the pointers to the next node. 
	* @pre None
	* @post Does not change the pointer.
	* @return Returns a pointer for the next node. */
	Node<ItemType>* getNext() const;

};
#include "Node.cpp"
#endif