/*
 * Complete Matrix Class
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
using namespace std;

template <typename Object> class matrix {
public:
  // Parameterized Constructor: builds an empty rows x cols grid
  matrix(int rows, int cols) : array(rows) {
    for (auto &thisRow : array)
      thisRow.resize(cols);
  }

  // Zero-argument constructor to allow for matrix declaration without
  // initialization (empty matrix)
  matrix() = default;

  // Parameterized Constructor: pass-by-value-then-move handle rvalue and lvalue
  matrix(vector<vector<Object>> v) : array{std::move(v)} {}

  // Operator overloading: const/non-const pair enables m[i][j] read+write while
  // respecting const-correctness
  const vector<Object> &operator[](int row) const { return array[row]; }
  vector<Object> &operator[](int row) { return array[row]; }

  // Accessors to get the number of rows and cols
  int numrows() const { return array.size(); }
  // assumes rectangular matrix; row 0 stands in for all rows
  int numcols() const { return numrows() ? array[0].size() : 0; }

  // resize mutator to change size of vector (rows) and size of vectors per
  // vector (columns)
  void resize(int rows, int cols) {
    array.resize(rows);
    for (auto &thisRow : array)
      thisRow.resize(cols);
  }

  // Print values of matrix

private:
  // sole storage; kept private so operator[] is the only sanctioned access
  // point
  vector<vector<Object>> array;
};
#endif
