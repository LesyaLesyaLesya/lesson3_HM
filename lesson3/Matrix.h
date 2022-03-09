
#include <iostream>
#include <exception>


class Matrix
{

private:
    // ������
    int size;
    // ��������� ������ ����� ���������
    int** data;

public:

    // �����������
    Matrix(int d);
    Matrix(const Matrix& matr);
    ~Matrix();
    void Initialize();
    const int GetSize();
   
    // ���������� �������� ������
    void SetAt(const int& x, const int& y, const int& val);

    // ����� �������� ������
    int GetAt(const int& x, const int& y);

    // ����������, ���������� ������������� ������� � �������(���� ������)
    Matrix& Submatrix(int noCol, int noRow);
    
    // �����������?
    bool IsSingular();
    
    // ������������
    int Determinant();
    
    // ���������� �������
   
    friend std::ostream& operator<< (std::ostream& out, const Matrix& matr);
    void PrintMatrix();
};



