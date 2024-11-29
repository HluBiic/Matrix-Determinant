# Matrix-Determinant
  - **Subject**: *Algorithms II*
  - **Type**: *Homework 01*
  - **Year**: *2. year - winter semester (2024)*
  - **Language**: *C++*
---
***Task***
Your task is to implement the calculation of the determinant of a square matrix. Implement the square matrix as a class Matrix. In the class, implement the following public methods:
  - Appropriate constructors,
  - Getter and setter for individual elements of the matrix,
  - A method to return the order of the matrix,
  - A method to calculate the determinant,
  - A helper method to print the matrix to the standard output.

Implement methods as const where possible i.e., with the const attribute in the method declaration. The method of calculating the determinant depends on the size of the matrix. For matrices of size 1, 2, and 3, you can use formulas (refer to [1, page 215]), and for larger matrices, use the method based on transforming the matrix into an upper triangular matrix using Gaussian elimination. However, this transformation into an upper triangular matrix should not alter the data in the original matrix; you must create a local copy of the data and transform that instead. Of course, you can also implement additional private helper methods if needed. Demonstrate the functionality of your solution with examples.
