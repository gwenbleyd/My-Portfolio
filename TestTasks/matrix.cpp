#include <iostream>
#include <vector>

class Matrix{
private:
  int num_columns;
  int num_rows;
  std::vector<std::vector<int>> matrix;
  float determinant = 0;
public:
  Matrix(){
    num_columns = 0;
    num_rows = 0;
  }

  Matrix(int rows, int columns){
    Reset(rows, columns);
  }

  void Reset(int rows, int columns){
    if (rows < 0 || columns < 0) {
      throw std::out_of_range("matrix size cannot be negative");
    }
    if (rows == 0 || columns == 0) {
      num_rows = num_columns = 0;
    }
    num_rows = rows;
    num_columns = columns;
    matrix.assign(num_rows, std::vector<int>(num_columns));
  }

  int At(int row, int column) const{
    if(row < 0 || column < 0){
      throw std::out_of_range("matrix size cannot be negative");
    }
    if(row > num_rows || column > num_columns){
      throw std::out_of_range("matrix size exceeded");
    }
    return matrix.at(row).at(column);
  }

  int& At(int row, int column){
    if(row < 0 || column < 0){
      throw std::out_of_range("matrix size cannot be negative");
    }
    if(row > num_rows || column > num_columns){
      throw std::out_of_range("matrix size exceeded");
    }
    return matrix.at(row).at(column);
  }

  int getNumRows() const{
    return num_rows;
  }

  int getNumCols() const{
    return num_columns;
  }

  void display(){
    for (size_t i = 0; i < getNumRows(); i++) {
      for (size_t j = 0; j < getNumCols(); j++) {
        std::cout<<matrix.at(i).at(j)<<" ";
      }
      std::cout << std::endl;
    }
  }

  void insert(){
    for (size_t i = 0; i < getNumRows(); i++) {
      for (size_t j = 0; j < getNumCols(); j++) {
        std::cin>>matrix[i][j];
      }
      std::cout << std::endl;
    }
  }
};

Matrix operator+(const Matrix& first_matrix, const Matrix& second_matrix){
  if ((second_matrix.getNumCols() != first_matrix.getNumCols()) || (
    second_matrix.getNumRows() != first_matrix.getNumRows())){
    throw std::invalid_argument("different matrix size");
  }
  Matrix result_matrix(first_matrix.getNumRows(),
    first_matrix.getNumCols());
  for (size_t i = 0; i < first_matrix.getNumRows(); i++) {
    for (size_t j = 0; j < first_matrix.getNumCols(); j++) {
      result_matrix.At(i, j) = first_matrix.At(i, j)
        + second_matrix.At(i, j);
    }
  }
  return result_matrix;
}

Matrix operator*(const Matrix& first_matrix, const Matrix& second_matrix){
  if (first_matrix.getNumRows() != second_matrix.getNumCols()){
    throw std::invalid_argument("different matrix size");
  }
  Matrix result_matrix(first_matrix.getNumRows(),
    second_matrix.getNumCols());
  for (size_t i = 0; i < first_matrix.getNumRows(); i++) {
    for (size_t j = 0; j < second_matrix.getNumCols(); j++) {
      for(size_t k = 0; k < first_matrix.getNumCols(); k++ )
        result_matrix.At(i, j) += first_matrix.At(i, k) *
          second_matrix.At(k, j);
    }
  }
  return result_matrix;
}

Matrix operator-(const Matrix& first_matrix, const Matrix& second_matrix){
  if ((second_matrix.getNumCols() != first_matrix.getNumCols()) || (
    second_matrix.getNumRows() != first_matrix.getNumRows())){
    throw std::invalid_argument("different matrix size");
  }
  Matrix result_matrix(first_matrix.getNumRows(),
    first_matrix.getNumCols());
  for (size_t i = 0; i < first_matrix.getNumRows(); i++) {
    for (size_t j = 0; j < first_matrix.getNumCols(); j++) {
      result_matrix.At(i, j) = first_matrix.At(i, j)
        - second_matrix.At(i, j);
    }
  }
  return result_matrix;
}

bool operator ==(const Matrix& first_matrix, const Matrix& second_matrix){
  if (first_matrix.getNumRows() != second_matrix.getNumRows()) {
    return false;
  }

  if (first_matrix.getNumCols() != second_matrix.getNumCols()) {
    return false;
  }

  for (size_t i = 0; i < first_matrix.getNumRows(); i++) {
    for (size_t j = 0; j < first_matrix.getNumCols(); j++) {
      if (first_matrix.At(i, j) != second_matrix.At(i, j)) {
          return false;
      }
    }
  }
  return true;
}
