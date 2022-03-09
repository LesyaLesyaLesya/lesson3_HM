
#include <iostream>
#include <exception>


class Matrix
{

private:
    // Размер
    int size;
    // Двумерный массив через указатели
    int** data;

public:

    // Конструктор
    Matrix(int d);
    Matrix(const Matrix& matr);
    ~Matrix();
    void Initialize();
    const int GetSize();
   
    // Установить значение ячейки
    void SetAt(const int& x, const int& y, const int& val);

    // Взять значение ячейки
    int GetAt(const int& x, const int& y);

    // Подматрица, полученная вычеркиванием строчки и столбца(надо дальше)
    Matrix& Submatrix(int noCol, int noRow);
    
    // Вырожеднная?
    bool IsSingular();
    
    // Определитель
    int Determinant();
    
    // Напечатать матрицу
   
    friend std::ostream& operator<< (std::ostream& out, const Matrix& matr);
    void PrintMatrix();
};



