
# Polynomial

## Overview
`SparsePoly` is a C++ program designed to manage and manipulate sparse polynomials efficiently. Sparse polynomials store only non-zero terms, making them ideal for operations involving large polynomials with few non-zero coefficients.

This implementation includes functionality for creating, managing, and querying sparse polynomials using a linked list-based structure. The project also introduces an interface, `SparsePolyInterface`, to define common operations for classes handling sparse polynomials.

## Features
- **Term Management**:
  - Add, update, or delete terms based on their coefficients and exponents.
  - Automatically remove terms with a zero coefficient.
- **Query Operations**:
  - Retrieve the degree of the polynomial (highest exponent).
  - Access coefficients for specific terms.
- **Polynomial Manipulation**:
  - Convert the polynomial into a vector for easy display.
  - Clear all terms to reset the polynomial.
- **Efficient Storage**: Only stores non-zero terms to save memory.

## Setup and Compilation

### Visual Studio
1. Open the project in Visual Studio.
2. Exclude unnecessary `.cpp` files from the build (if needed).
3. Build and run the program.

### Command Line
1. Navigate to the project directory:
   ```bash
   cd path/to/project
   ```
2. Compile using `g++`:
   ```bash
   g++ -o Polynomial main.cpp SparsePoly.cpp PolynomialBase.cpp Node.cpp -std=c++17
   ```
3. Run the program:
   ```bash
   ./Polynomial
   ```

## Usage
1. **Create a Sparse Polynomial**:
   - Instantiate the `SparsePoly` class and initialize terms as needed.
2. **Modify Terms**:
   - Use `changeCoefficient()` to add or update terms.
   - Automatically removes terms with zero coefficients.
3. **Query Polynomial**:
   - Retrieve the polynomial's degree with `degree()`.
   - Access specific coefficients using `coefficient()`.
4. **Display Polynomial**:
   - Convert the polynomial into a vector using `toVector()` and print it.

## Example
For a polynomial:
```
5x^3 + 2x^2 - 7
```
The program will:
- Store terms efficiently using a linked list.
- Allow querying the coefficient of `x^2`, which returns `2`.
- Enable operations to modify or clear terms.

## Future Enhancements
- Extend support for mathematical operations (e.g., addition, multiplication, evaluation).
- Provide more flexible input/output options (e.g., file-based operations).
- Explore optimizations for very large polynomials.

## License
This project is open-source and available under the MIT license.
