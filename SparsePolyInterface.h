/** @file SparsePolyInterface.h
* @class SparsePolyInterface
* Interface for classes that hold a sparse polynomial.
*/

#ifndef SPARSE_POLY_INTERFACE_
#define SPARSE_POLY_INTERFACE_

#include <string>

template<class ItemType>
class SparsePolyInterface
{

public:

    /** Updates a coefficient in the term of a given power. If the new coefficient is 0, the term will be removed. If the power of the new coefficient does not exist, a term will be created and placed in the correct sorted location. If the power of the new coefficient is already present, it will replace the current coefficient with the new one.
    * @pre Only nonnegative powers are accepted.
    * @post If successful, updates a term's coefficient with a new value, removes the term from the linked list, or adds a new term to the list depending on if the term already exists and if the new coefficient is 0.
    * @param newCoefficient This is the new coefficient to update, add, or delete.
    * @param power Is the power of the target term.
    * @return Will return 0 if the update was completed successfully or -1 if a negative power was attempted. */
    virtual int changeCoefficient(ItemType newCoefficient, unsigned int power) = 0;

    /** Clears the polynomial, removing all terms and returning memory to the heap.
    * @pre None
    * @post headPtr will be pointing to nullptr and all memory is returned to the heap. */
    virtual void clear() = 0;

    /** Retrieves the degree of the polynomial.
    * @pre None
    * @post Polynomial remains unchanged.
    * @return Returns the degree of the polynomial or -1 if the polynomial is empty. */
    virtual unsigned int degree() const = 0;

    /** Returns the coefficient in the term of a given power.
    * @pre Assumes nonnegative integer powers.
    * @post Polynomial remains unchanged.
    * @param power The power of the target term.
    * @return Return the coefficient of the indicated term or a 0 if the term is not located in the list. */
    virtual ItemType coefficient(unsigned int power) const = 0;

    /** Displays the polymonial in the correct format.
    * @pre None
    * @post Polynomial remains unchanged.
    * @return Returns a string of the polynomial which can be printed by the client. If the polynomial is empty, will return a string of '0'. */
    virtual std::string displayPoly() const = 0;

    /** Checks if polynomial contains terms.
    * @pre None
    * @post Polynomial remains unchanged.
    * @return Will return a boolean value indicating if the polynomial contains any terms. */
    virtual bool isEmpty() const = 0;

    /** Destructor */
    virtual ~SparsePolyInterface() {}
}; // end SparsePolyInterface

#endif