#include "matrix.h"
#include <iostream>

template <typename Object> void printMatrix(matrix<Object> &matrix);

int main() {
  matrix<int> m;
  matrix<int> m1(3, 4);
  m1.resize(5, 6);
  m1[0][0] = 1;

  matrix<std::string> m2({{"apple", "banana"}, {"batman", "343"}});

  printMatrix(m1);
  printMatrix(m2);
}

template <typename Object> void printMatrix(matrix<Object> &matrix) {
  std::cout << "Contents of vector: " << endl;
  for (int i = 0; i < matrix.numrows(); i++) {
    for (int j = 0; j < matrix.numcols(); j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << endl;
  }
}
