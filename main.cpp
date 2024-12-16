#include <iostream>
#include "SparsePoly.h"

using namespace std;

int main() 
{
    cout << "__________Test Document : Testing SparsePoly__________" << endl;
    cout << endl;

    cout << "=====Valid Values=====" << endl;
    cout << endl;

    // Creating poly1 polynomial of type integer
    cout << "--Testing type integer polynomial--" << endl;
    SparsePoly<int> poly1;
    poly1.changeCoefficient(5, 3); cout << "Adding new terms: 5x^3, ";
    poly1.changeCoefficient(3, 2); cout << "3x^2, ";
    poly1.changeCoefficient(-5, 1); cout << "-5x to poly1." << endl;
    cout << "poly1: " << poly1.displayPoly() << endl;
    cout << endl;

    // Creating poly2 polynomial of type integer and testing sorted
    cout << "--Testing type integer polynomial--" << endl;
    SparsePoly<int> poly2;
    poly2.changeCoefficient(2, 3); cout << "Adding new terms: 2x^3, ";
    poly2.changeCoefficient(-9, 5); cout << "-9x^5, ";
    poly2.changeCoefficient(7, 2); cout << "7x^2 to poly2." << endl;
    cout << "poly2: " << poly2.displayPoly() << endl;
    cout << endl;

    // Creating poly3 polynomial of type double
    cout << "--Testing type double polynomial--" << endl;
    SparsePoly<double> poly3;
    poly3.changeCoefficient(2.45757, 3); cout << "Adding new terms: 2.45757x^3, ";
    poly3.changeCoefficient(5.74, 5); cout << "5.74x^5, ";
    poly3.changeCoefficient(1.0, 0); cout << "1.0 to poly3." << endl;
    cout << "poly3: " << poly3.displayPoly() << endl;
    cout << endl;

    // Creating poly4 polynomial with a 'y' variable
    cout << "--Testing polynomial of variable y--" << endl;
    SparsePoly<int> poly4('y');
    poly4.changeCoefficient(5, 4); cout << "Adding new terms: 5y^4, ";
    poly4.changeCoefficient(4, 6); cout << "4y^6, ";
    poly4.changeCoefficient(8, 2); cout << "8y^2 to poly4." << endl;
    cout << "poly4: " << poly4.displayPoly() << endl;
    cout << endl;

    cout << "--Testing, changeCoefficient(), removeTerm(), clear(), and isEmpty()--" << endl;
    // Changing a coefficient
    poly4.changeCoefficient(9, 4); cout << "Changing poly4's y^4 from 5y^4 to 9y^4." << endl;
    cout << poly4.displayPoly() << endl;
    cout << endl;

    // Removing a coefficient
    poly4.changeCoefficient(0, 4); cout << "Removing y^4 from poly4." << endl;
    cout << poly4.displayPoly() << endl;
    cout << endl;

    // Checking if polynomial contains terms when there are some present
    cout << "Testing isEmpty() on poly4 when there are terms present." << endl;
    if (poly4.isEmpty())
    {
        cout << "poly4 contains 0 terms." << endl;
    }
    else
    {
        cout << "poly4 contains terms." << endl;
    }
    cout << endl;

    // Removing all terms from a polynomial
    poly4.clear(); cout << "Removing all terms from poly4." << endl;
    cout << poly4.displayPoly() << endl;
    cout << endl;

    // Checking if polynomial contains terms when there are 0 present
    cout << "Testing isEmpty() on poly4 when there are 0 terms present." << endl;
    if (poly4.isEmpty())
    {
        cout << "poly4 contains 0 terms." << endl;
    }
    else
    {
        cout << "poly4 contains terms." << endl;
    }
    cout << endl;

    // Checking the degree of a polynomial
    cout << "--Testing degree()--" << endl;
    cout << "The degree of poly3 is: " << poly3.degree() << endl;
    cout << "Polynomial degree of poly3 should be 5" << endl;
    cout << endl;

    // Checking a terms coefficient
    cout << "--Testing coefficient()--" << endl;
    cout << "The coefficient at x^3 is: " << poly2.coefficient(3) << endl;
    cout << "Coefficient should be 2 in poly2 at x^3." << endl;
    cout << endl;

    // Testing addition
    cout << "--Testing add()--" << endl;
    cout << "poly1: " << poly1.displayPoly() << endl;
    cout << "poly2: " << poly2.displayPoly() << endl;
    SparsePoly<int> poly5 = poly1.add(poly2);
    cout << poly5.displayPoly() << endl;
    cout << "Result of adding poly1 and poly2 should be the polynomial: -9x^5 + 7x^3 + 10x^2 - 5x" << endl;
    cout << endl;

    // Testing multiplication
    cout << "--Testing multiply()--" << endl;
    poly1.changeCoefficient(0, 3); // Removing x^3 for simplification
    poly1.changeCoefficient(0, 1); // Removing x for simplification
    poly2.changeCoefficient(0, 5); // Removing x^5 for simplification
    poly2.changeCoefficient(0, 3); // Removing x^3 for simplification
    poly1.changeCoefficient(-1, 0); // Adding an additional term
    poly2.changeCoefficient(2, 0); // Adding an additional term
    cout << "poly1: " << poly1.displayPoly() << endl;
    cout << "poly2: " << poly2.displayPoly() << endl;
    cout << "poly1 should be: 3x^2 - 1" << endl;
    cout << "poly2 should be: 7x^2 + 2" << endl;

    SparsePoly<int> poly6 = poly1.multiply(poly2);
    cout << "The result from multiplication is: " << poly6.displayPoly() << endl;
    cout << "Multiplying poly1 and poly2 should be: 21x^4 - x^2 - 2" << endl;
    cout << endl;

    // Testing scalar multiplication
    cout << "--Testing scalarMultiply()--" << endl;
    SparsePoly<int> poly7 = poly1.scalarMultiply(2); cout << "Multiplying poly1 by 2" << endl;
    cout << "Resulting scalar multiplication polynomial is: " << poly7.displayPoly() << endl;
    cout << "Resulting polynomial should be: 6x^2 - 2" << endl;
    cout << endl;

    // Testing evaluation at a given value of x
    cout << "--Testing evaluate()--" << endl;
    cout << "Evaluating poly1 results in: " << poly1.evaluate(2) << endl;
    cout << "Evaluation should be: 11" << endl;
    cout << endl;

    cout << "=====Boundary Values=====" << endl;
    cout << endl;

    // Checking an empty polynomial
    cout << "--Testing funtions with an empty polynomial--" << endl;

    // Testing clear() on an empty polynomial
    poly4.clear();
    cout << "Removing all terms from poly4. Should output: 0" << endl;
    cout << poly4.displayPoly() << endl;
    cout << "Clearing the empty polynomial poly 4 Should output: 0" << endl;

    // Testing coefficient on an empty polynomial
    cout << poly4.coefficient(2) << endl;
    cout << "Checking the coefficient at power 2 on an empty poly4 should output: 0" << endl;

    // Testing degree on an empty polynomial
    int degree = poly4.degree();
    if (-1 == degree)
    {
        cout << "Test passed, polynomial is empty" << endl;

    }
    else
    {
        cout << "Test failed, polynomial is emtpy" << endl;
    }

    poly1.clear(); // Clearing poly1 for additional testing

    // Testing add with an empty polynomial
    SparsePoly<int> polyEmpty = poly1.add(poly2);
    cout << polyEmpty.displayPoly() << endl;
    cout << "Trying to add with an empty polynomial should result: 7x^2 + 2" << endl;
    polyEmpty.clear(); // Clearing polyEmpty for additional testing

    // Testing multiply with an empty polynomial
    polyEmpty = poly1.multiply(poly2);
    cout << polyEmpty.displayPoly() << endl;
    cout << "Result should be: 0" << endl;
    polyEmpty.clear(); // Clearing polyEmpty for additional testing

    // Testing scalar multiplication with an empty polynomial
    polyEmpty = poly1.scalarMultiply(2);
    cout << polyEmpty.displayPoly() << endl;
    cout << "Result should be: 0" << endl;
    polyEmpty.clear(); // Clearing polyEmpty for additional testing

    // Testing evaluate with an empty polynomial
    int result = poly1.evaluate(2);
    cout << result << endl;
    cout << "Result should be: 0" << endl;
    cout << endl;

    cout << "--Testing large and small numbers--" << endl;

    // Testing for large numbers in coefficient and power
    poly4.changeCoefficient(9500000, 9500000);
    cout << poly4.displayPoly() << endl;
    cout << "Result should be: 9500000y^9500000" << endl;

    // Testing small evaluate numbers
    int result2 = poly4.evaluate(1);
    cout << result2 << endl;
    cout << "Result should be: 9500000" << endl;

    // Testing small evaluate numbers
    int result3 = poly4.evaluate(0);
    cout << result3 << endl;
    cout << "Result should be: 0" << endl;
    cout << endl;

    cout << "=====Invalid Values=====" << endl;

    cout << endl;

    cout << "--Testing negative powers--" << endl;

    poly1.changeCoefficient(2, 2); // Adding a valid value to poly1 for testing
    cout << "poly1 is currently: " << poly1.displayPoly() << endl;

    // Trying to add a negative power
    poly1.changeCoefficient(2, -5);
    cout << poly1.displayPoly() << endl; // Showing the results of that test
    cout << "Result should be: 2x^2" << endl;
    cout << endl;

    cout << "--Testing math operations with different variables--" << endl;

    poly4.clear();
    poly4.changeCoefficient(2, 3);
    poly4.changeCoefficient(3, 1);
    cout << "poly4 is currently: " << poly4.displayPoly() << endl;
    cout << "poly1 is currently: " << poly1.displayPoly() << endl;

    // Testing multiplication with 2 different variables
    SparsePoly<int>polyTest = poly4.multiply(poly1);
    cout << polyTest.displayPoly() << endl;
    cout << "Result should be: 0" << endl;

    // Testing addition with 2 different variables
    polyTest = poly4.add(poly1);
    cout << polyTest.displayPoly() << endl;
    cout << "Result should be: 0" << endl;
    cout << endl;

    cout << "--Testing multiplication and addition with different coefficient types--" << endl;
    cout << "Multiplication and addition is not allowed for polynomials of different coefficient types" << endl;
    cout << endl;

    /*cout << poly3.displayPoly() << endl;
    cout << poly2.displayPoly() << endl;
    polyTest = poly3.multiply(poly2);           Testing multiply with different polynomial types
    cout << polyTest.displayPoly() << endl;
  
    cout << poly3.displayPoly() << endl;
    cout << poly2.displayPoly() << endl;
    polyTest = poly3.add(poly2);                Testing add with different polynomial types
    cout << polyTest.displayPoly() << endl;
    */

    cout << "=====Testing complete=====" << endl;

    return 0;
}