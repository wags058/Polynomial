/** @file SparsePoly.cpp 
*SparsePoly creates a linked list to hold a sparse polynomial and perform operations. The polynomial is ordered by power from highest to lowest.
* @author Stephen Wagner
* @date 10/13/2024
* CSCI 591 Section 1 
*/

#include "SparsePoly.h"
#include "Node.h"
#include <cstddef>
#include <vector>
#include <cmath>

// Default constructor
template <class ItemType>
SparsePoly<ItemType>::SparsePoly() : headPtr(nullptr), termCount(0), variable('x')
{ }  // End default constructor

// Constructor allowing custom variable character
template <class ItemType>
SparsePoly<ItemType>::SparsePoly(char var) : headPtr(nullptr), termCount(0), variable(var)
{ }  // End variable constructor

// Copy constructor
template <class ItemType>
SparsePoly<ItemType>::SparsePoly(const SparsePoly<ItemType>& other)
{
    termCount = other.termCount;
    variable = other.variable;
    Node<ItemType>* origChainPtr = other.headPtr; // Points to nodes in original chain

    if (origChainPtr == nullptr)
        headPtr = nullptr;  // Original polynomial is empty
    else
    {
        // Copy first node
        headPtr = new Node<ItemType>(origChainPtr->getCoefficient(), origChainPtr->getPower());

        // Copy remaining nodes
        Node<ItemType>* endChainPtr = headPtr; // Points to last node in new chain
        origChainPtr = origChainPtr->getNext(); // Advance original chain pointer

        while (origChainPtr != nullptr)
        {
            // Get next items from original chain
            ItemType nextCoefficient = origChainPtr->getCoefficient();
            unsigned int nextPower = origChainPtr->getPower();

            // Create a new node containing the next coefficient and power
            Node<ItemType>* newNode = new Node<ItemType>(nextCoefficient, nextPower);

            // Link new node to end of new chain
            endChainPtr->setNext(newNode);

            // Advance pointer to new last node
            endChainPtr = endChainPtr->getNext();

            // Advance original chain pointer
            origChainPtr = origChainPtr->getNext();
        } // End while

        endChainPtr->setNext(nullptr);  // Flag end of chain
    } // End if
}  // End copy constructor

// Returns the degree of the polynomial
template <class ItemType>
unsigned int SparsePoly<ItemType>::degree() const 
{
    if (headPtr == nullptr) 
    {
        return -1; // Polymonial is empty
    } // End if
    return headPtr->getPower(); // Since the terms are sorted, return the first node power
} // End degree

// Returns the coefficient of an indicated term
template <class ItemType>
ItemType SparsePoly<ItemType>::coefficient(unsigned int power) const 
{
    Node<ItemType>* nodePtr = getPointerTo(power); // Use getPointerTo to find the correct pointer
    if (nodePtr != nullptr) 
    {
        ItemType coefficient = nodePtr->getCoefficient();
        nodePtr = nullptr;
        return coefficient;
    } // End if
    return 0; // If the term is not found
} // End coefficient

// Changes a coefficient if term is already present, adds a new coefficient in the term if not present, removes a term if new coefficient is 0.
template <class ItemType>
int SparsePoly<ItemType>::changeCoefficient(ItemType newCoefficient, unsigned int power) 
{
    if (power < 0) // Checking if power is nonnegative
    {
        return -1;
    } // End if
    // Remove the term if the new coefficient is zero
    if (newCoefficient == 0) 
    {
        removeTerm(power); // Calls removeTerm if new coefficient is 0
        return 0;
    } // End if

    Node<ItemType>* prevPtr = nullptr;
    Node<ItemType>* currentPtr = headPtr;

    // Traverse to find the correct insertion point
    while (currentPtr != nullptr && currentPtr->getPower() > power) 
    {
        prevPtr = currentPtr;
        currentPtr = currentPtr->getNext();
    } // End while

    // If a term with the same power is found, update its coefficient
    if (currentPtr != nullptr && currentPtr->getPower() == power) 
    {
        currentPtr->setCoefficient(newCoefficient);
    }
    else 
    {
        // Create a new node for the new term
        Node<ItemType>* newNode = new Node<ItemType>(newCoefficient, power);
        newNode->setNext(nullptr);

        // Insert in the correct sorted position
        if (prevPtr == nullptr) 
        { 
            // Insertion at the head
            newNode->setNext(headPtr);
            headPtr = newNode;
        }
        else 
        {
            newNode->setNext(currentPtr);
            prevPtr->setNext(newNode);
        } // End if
        termCount++;
        newNode = nullptr;
    } // End if
    prevPtr = nullptr;
    currentPtr = nullptr;
    return 0;
}  // End changeCoefficient

// Creates a vector used to display polynomial in displayPoly
template <class ItemType>
std::vector<Node<ItemType>> SparsePoly<ItemType>::toVector() const
{
    // Create a vector of Node type objects to hold the polynomial terms
    std::vector<Node<ItemType>> polyContents;
    Node<ItemType>* currentPtr = headPtr;
    int counter = 0;
    while ((currentPtr != nullptr) && (counter < termCount))
    {
        // Copy coefficient and power from each node into vector
        polyContents.push_back(Node<ItemType>(currentPtr->getCoefficient(), currentPtr->getPower()));
        currentPtr = currentPtr->getNext();
        counter++;
    } // End while
    currentPtr = nullptr;
    return polyContents;
}  // End toVector

// Clears the linked list and returns memory to the heap
template <class ItemType>
void SparsePoly<ItemType>::clear()
{
    Node<ItemType>* currentPtr = headPtr;
    while (currentPtr != nullptr && !isEmpty())
    {
        Node<ItemType>* nodeToDelete = currentPtr;
        currentPtr = currentPtr->getNext();

        // Return node to the system
        delete nodeToDelete;
        nodeToDelete = nullptr;
    } // End while
    headPtr = nullptr;
    currentPtr = nullptr;
    termCount = 0;
} //End clear

// Helper function to check if the list contains any terms
template<class ItemType>
bool SparsePoly<ItemType>::isEmpty() const
{
    return termCount == 0;
}  // End isEmpty

// Helper function to remove a term from polynomial
template <class ItemType>
bool SparsePoly<ItemType>::removeTerm(const unsigned int power) 
{
    Node<ItemType>* targetPtr = getPointerTo(power); // Locate pointer to target term

    // Check if the polynomial is not empty and the target node exists
    bool canRemoveItem = !isEmpty() && (targetPtr != nullptr);

    if (canRemoveItem) 
    {
        // Removal if the target is the head
        if (targetPtr == headPtr) 
        {
            // Check if there is a second term
            Node<ItemType>* nextNodePtr = headPtr->getNext();
            if (nextNodePtr != nullptr) 
            {
                // Copy second node's data into first node
                headPtr->setCoefficient(nextNodePtr->getCoefficient());
                headPtr->setPower(nextNodePtr->getPower());
                headPtr->setNext(nextNodePtr->getNext());

                // Clean up memory by deleting second node and setting temporary pointer to nullptr
                nextNodePtr->setNext(nullptr);
                delete nextNodePtr;
                nextNodePtr = nullptr;
            }
            else 
            {
                // If the target term is the only term
                delete headPtr;
                headPtr = nullptr;
                nextNodePtr = nullptr;
            } // End if
        }
        else  // Removal if the target is not the head
        {
            // Locate the term before the target to bypass
            Node<ItemType>* prevPtr = headPtr;
            while (prevPtr->getNext() != targetPtr) 
            {
                prevPtr = prevPtr->getNext();
            } // End while
            prevPtr->setNext(targetPtr->getNext());

            // Clean up memory
            targetPtr->setNext(nullptr);
            delete targetPtr;
            targetPtr = nullptr;
        } // End if

        termCount--; // Decrease the term count
    } // End if
    targetPtr = nullptr;
    return canRemoveItem;
} // End removeTerm

// Helper function to assist in locating a specific node
template <class ItemType>
Node<ItemType>* SparsePoly<ItemType>::getPointerTo(const unsigned int power) const
{
    bool found = false;
    Node<ItemType>* currentPtr = headPtr;

    while (!found && (currentPtr != nullptr))
    {
        found = (power == currentPtr->getPower());
        if (!found)
        {
            currentPtr = currentPtr->getNext();
        } // End if
    } // End while
    if (!found)
    {
        currentPtr = nullptr;
    } // End if

    return currentPtr;
} // End getPointerTo

// Destructor
template <class ItemType>
SparsePoly<ItemType>::~SparsePoly()
{
    clear();
}  // End destructor
   
// Displays polynomial in correct format
template <class ItemType>
std::string SparsePoly<ItemType>::displayPoly() const
{
    // Copy polynomial to a vector using the member function toVector()
    std::vector<Node<ItemType>> contents = toVector();

    if (contents.empty())
    {
        return std::string("0");
    } // End if

    // Construct a string by iterating over the vector
    std::string polyString;
    for (size_t i = 0; i < contents.size(); ++i)
    {
        ItemType coefficient = contents[i].getCoefficient();
        unsigned int power = contents[i].getPower();

        // Concatenate coefficient
        if (i > 0)
        {
            polyString += " + ";
        }
        if (static_cast<ItemType>(1.0) != coefficient || power == 0)
        {
            polyString += "(" + std::to_string(coefficient) + ")";
        }
        else if (static_cast<ItemType>(-1.0) == coefficient)
        {
            polyString += "(-1)";
        } // End if
        // Concatenate variable and power
        if (power > 0)
        {
            polyString += variable;
            if (power > 1)
            {
                polyString += "^" + std::to_string(power);
            } // End if
        } // End if
    } // End for
    return polyString;
} // End displayPoly

// Evaluates the polynomial at a given value of x
template <class ItemType>
ItemType SparsePoly<ItemType>::evaluate(ItemType x) const
{
    ItemType result = 0;
    Node<ItemType>* currentPtr = headPtr;

    while (currentPtr != nullptr)
    {
        // Retreive the coefficient and power from each node
        ItemType coefficient = currentPtr->getCoefficient();
        unsigned int power = currentPtr->getPower();

        // Computes the value of each term and adds it to result
        result += (coefficient * std::pow(x, static_cast<ItemType>(power)));

        currentPtr = currentPtr->getNext();
    } // End while
    currentPtr = nullptr;
    return result;
} // End evaluate

// Adds two polynomials together and returns a new polynomial object
template <class ItemType>
SparsePoly<ItemType> SparsePoly<ItemType>::add(const SparsePoly<ItemType>& anotherPoly) const
{
    SparsePoly<ItemType> result;

    // Check if variables are the same
    if (variable != anotherPoly.variable)
    {
        // Returns an empty polynomial if their variables to not match
        return result;
    } // End if
    // Pointer to the current polynomial
    Node<ItemType>* thisPtr = headPtr;
    // Pointer for the other polynomial
    Node<ItemType>* otherPtr = anotherPoly.headPtr;

    // Traverse both polynomials
    while (thisPtr != nullptr && otherPtr != nullptr)
    {
        if (thisPtr->getPower() == otherPtr->getPower())
        {
            // Can add the coefficients
            ItemType newCoefficient = thisPtr->getCoefficient() + otherPtr->getCoefficient();
            if (newCoefficient != 0)
            {
                result.changeCoefficient(newCoefficient, thisPtr->getPower());
            } // End if
            thisPtr = thisPtr->getNext();
            otherPtr = otherPtr->getNext();
        }
        else if (thisPtr->getPower() > otherPtr->getPower())
        {
            // If current polynomial has greater power
            result.changeCoefficient(thisPtr->getCoefficient(), thisPtr->getPower());
            thisPtr = thisPtr->getNext();
        }
        else
        {
            // If other polynomial has greater power
            result.changeCoefficient(otherPtr->getCoefficient(), otherPtr->getPower());
            otherPtr = otherPtr->getNext();
        } // End if
    } // End while
    // If there are any unused terms in current polynomial
    while (thisPtr != nullptr)
    {
        result.changeCoefficient(thisPtr->getCoefficient(), thisPtr->getPower());
        thisPtr = thisPtr->getNext();
    } // End while
    // If there are any unused terms in other polynomial
    while (otherPtr != nullptr)
    {
        result.changeCoefficient(otherPtr->getCoefficient(), otherPtr->getPower());
        otherPtr = otherPtr->getNext();
    } // End while
    thisPtr = nullptr;
    otherPtr = nullptr;
    return result;
} // End add

// Multiplies two polynomials together and returns a new polynomial object
template <class ItemType>
SparsePoly<ItemType> SparsePoly<ItemType>::multiply(const SparsePoly<ItemType>& anotherPoly) const
{
    SparsePoly<ItemType> result;

    // Check if variables are the same
    if (variable != anotherPoly.variable)
    {
        // Returns an empty polynomial if their variables to not match
        return result;
    }
    // Pointer to the current polynomial
    Node<ItemType>* thisPtr = headPtr;
    // Pointer for the other polynomial
    Node<ItemType>* otherPtr = anotherPoly.headPtr;

    if (thisPtr == nullptr || otherPtr == nullptr)
    {
        return result;
    }
    // Traverse each term of current polynomial
    while (thisPtr != nullptr)
    {
        // Multiply each term in current polynomial with each term in other polynomial
        otherPtr = anotherPoly.headPtr; // Reset otherPoly to the first node
        while (otherPtr != nullptr)
        {
            // Multiply each coefficient and add each power
            ItemType newCoefficient = thisPtr->getCoefficient() * otherPtr->getCoefficient();
            unsigned int newPower = thisPtr->getPower() + otherPtr->getPower();

            // Check if coefficient already exists in the result polynomial, if so add the coefficients, if not add a new term
            ItemType existCoefficient = result.coefficient(newPower);
            if (existCoefficient != 0)
            {
                result.changeCoefficient(existCoefficient + newCoefficient, newPower);
            }
            else
            {
                result.changeCoefficient(newCoefficient, newPower);
            }
            otherPtr = otherPtr->getNext();
        } // End while
        thisPtr = thisPtr->getNext();
    } // End while
    thisPtr = nullptr;
    otherPtr = nullptr;
    return result;
} // End multiply

// Multiplies the polynomial by a scalar and returns a new polynomial object
template <class ItemType>
SparsePoly<ItemType> SparsePoly<ItemType>::scalarMultiply(ItemType scalar) const
{
    SparsePoly<ItemType> result;

    // Pointer to the current polynomial
    Node<ItemType>* thisPtr = headPtr;

    // Traverse each term of current polynomial
    while (thisPtr != nullptr)
    {
        // Multiply the coefficient by the scalar
        ItemType newCoefficient = thisPtr->getCoefficient() * scalar;

        unsigned int newPower = thisPtr->getPower();

        // Add the new term to result polynomial
        result.changeCoefficient(newCoefficient, newPower);

        thisPtr = thisPtr->getNext();
    } // End while

    thisPtr = nullptr;
    return result;
} // End scalarMultiply