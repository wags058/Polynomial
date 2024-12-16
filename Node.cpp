/** @file Node.cpp
* Creates a node to hold a polynomial term.
* @author Stephen Wagner
* @date 10/13/2024
* CSCI 591 Section 1 
*/

#include "Node.h"

template<class ItemType>
Node<ItemType>::Node() : next(nullptr) 
{} // end constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& someCoefficient, unsigned int somePower)
    : coefficient(someCoefficient), power(somePower), next(nullptr) 
{} // end constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& someCoefficient, unsigned int somePower, Node<ItemType>* nextNodePtr)
    : coefficient(someCoefficient), power(somePower), next(nextNodePtr) 
{} // end constructor

template<class ItemType>
void Node<ItemType>::setCoefficient(const ItemType& someCoefficient) 
{
    coefficient = someCoefficient;
} // end setCoefficient

template<class ItemType>
void Node<ItemType>::setPower(unsigned int somePower) 
{
    power = somePower;
} // end setPower

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr) 
{
    next = nextNodePtr;
} // end setNext

template<class ItemType>
ItemType Node<ItemType>::getCoefficient() const 
{
    return coefficient;
} // end getCoefficient

template<class ItemType>
unsigned int Node<ItemType>::getPower() const 
{
    return power;
} // end getPower

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const 
{
    return next;
} // end getNext