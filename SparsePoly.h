/** @file SparsePoly.h
* @class SparsePoly
* Class for an ordered sparse polynomial implementation including member functions to perform operations. Polynomial is ordered by power from highest to lowest.
*/

#ifndef SPARSE_POLY_
#define SPARSE_POLY_

#include "SparsePolyInterface.h"
#include "Node.h"
#include <vector>
#include <string>

template <class ItemType>
class SparsePoly : public SparsePolyInterface<ItemType>
{
private:

    /** Pointer to first node in the chain. */
    Node<ItemType>* headPtr;

    /** Character for polynomial variable, default is 'x'. */
    char variable;

    /** Variable to hold the current number of terms in the node chain Polynomial. */
    int termCount;

    /** Helper member function to remove one term from the linked list. This is a private member function used to remove a term from the polynomial if a 0 coefficient is entered. This function will return memory to the heap for one term.
    * @pre Assumes nonnegative integer powers.
    * @post If successful, removes one term from the polynomial linked list.
    * @param power The power of the term to remove.
    * @return This will return a boolean value to indicate if the removal was sucessful. */
    bool removeTerm(const unsigned int power);

    /** Helper member function to find the node containing the term with a given power.
    * @pre Assumes nonnegative integer powers.
    * @post Does not change the polynomial.
    * @param power The power of the target term.
    * @return Returns a pointer for the indicated term or nullptr if the term is not located. */
    Node<ItemType>* getPointerTo(const unsigned int power) const;

    /** Helper function that converts the polynomial to a vector for display purposes and is used by member functions to easily traverse the polynomial.
    * @pre None
    * @post Does not change the original polynomial.
    * @return Returns a vector of Node type objects containing the polynomial. */
    std::vector<Node<ItemType>> toVector() const;

public:

    /** Default constructor that uses 'x' as the variable. 
    * @pre None
    * @post None */
    SparsePoly();

    /** Constructor that allows a custom variable character. 
    * @pre None
    * @post None */
    SparsePoly(char var);

    /** Deep copy constructor 
    * @pre None
    * @post None */
    SparsePoly(const SparsePoly<ItemType>& other);

    /** Updates a coefficient in the term of a given power. If the new coefficient is 0, the term will be removed. If the power of the new coefficient does not exist, a term will be created and placed in the correct sorted location. If the power of the new coefficient is already present, it will replace the current coefficient with the new one.
    * @pre Only nonnegative powers are accepted.
    * @post If successful, updates a term's coefficient with a new value, removes the term from the linked list, or adds a new term to the list depending on if the term already exists and if the new coefficient is 0.
    * @param newCoefficient This is the new coefficient to update, add, or delete.
    * @param power Is the power of the target term.
    * @return Will return 0 if the update was completed successfully or -1 if a negative power was attempted. */
    int changeCoefficient(ItemType newCoefficient, unsigned int power);

    /** Clears the polynomial, removing all terms and returning memory to the heap.
    * @pre None
    * @post headPtr will be pointing to nullptr and all memory is returned to the heap. */
    void clear() final;

    /** Retrieves the degree of the polynomial.
    * @pre None
    * @post Does not change the polynomial.
    * @return Returns the degree of the polynomial or -1 if the polynomial is empty. */
    unsigned int degree() const;

    /** Returns the coefficient in the term of a given power.
    * @pre Assumes nonnegative integer powers.
    * @post Does not change the polynomial.
    * @param power The power of the target term.
    * @return Return the coefficient of the indicated term or a 0 if the term is not located in the list. */
    ItemType coefficient(unsigned int power) const;

    /** Displays the polymonial in the correct format. 
    * @pre None
    * @post Does not change the polynomial.
    * @return Returns a string of the polynomial which can be printed by the client. If the polynomial is empty, will return a string of '0'. */
    std::string displayPoly() const;

    /** Checks if polynomial contains terms. 
    * @pre None
    * @post Does not change the polynomial.
    * @return Will return a boolean value indicating if the polynomial contains any terms. */
    bool isEmpty() const;

    /** Adds another polynomial to this polynomial and returns the result. 
    * @pre Both polynomials need to be sparse, contain the same variable, have the same coefficient type, and contain only nonnegative integer powers.
    * @post Does not change the original polynomial.
    * @param anotherPoly Is the other polynomial. 
    * @return A new polynomial resulting from addition. Will return an empty polynomial if variables do not match. */
    SparsePoly<ItemType> add(const SparsePoly<ItemType>& anotherPoly) const;

    /** Multiplies another polynomial with this polynomial and returns the result. 
    * @pre Both polynomials need to be sparse, contain the same variable, have the same coefficient type, and contain only nonnegative integer powers.    
    * @post Does not change the original polynomial.
    * @param anotherPoly Is the other polynomial.
    * @return A new polynomial resulting from the multiplication. Will return an empty polynomial if variables do not match. */
    SparsePoly<ItemType> multiply(const SparsePoly<ItemType>& anotherPoly) const;

    /** Multiplies the polynomial by a scalar. 
    * @pre None
    * @post Does not change the original polynomial.
    * @param scalar The value multiplied with the polynomial. 
    * @return A new polynomial resulting from multiplying the scalar. */
    SparsePoly<ItemType> scalarMultiply(ItemType scalar) const;

    /** Evaluates the polynomial at a given value of the variable. 
    * @pre None
    * @post Does not change the original polynomial.
    * @param x The value given for the variable.
    * @return The result of evaluating the polynomial at that value. */
    ItemType evaluate(ItemType x) const;

    /** Destructor 
    * @pre None
    * @post None */
    virtual ~SparsePoly();
};

#include "SparsePoly.cpp"
#endif