#include "Matrix.h"


// �����������
Matrix::Matrix(int d) : size(d)
{
    // ����������� ������ 0
    if (d <= 0)
        throw std::exception("Invalid argument");

    data = new int* [d];
    // ��������
    for (int i = 0; i < d; i++)
        data[i] = new int[d];
}
Matrix::Matrix(const Matrix& matr)
{
    this->data = matr.data;
    this->size = matr.size;
}

Matrix::~Matrix()
{
    for (int i = 0; i < size; i++)
    {
        delete[] data[i];
    }
    delete[] data;
}
void Matrix::Initialize()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << "input data[" << i << "][" << j << "] = ";
            std::cin >> data[i][j];
            //std::cout << std::endl;
        }
    }
}

const int Matrix::GetSize()
{
    return size;
}

// ���������� �������� ������
void Matrix::SetAt(const int& x, const int& y, const int& val)
{
    // �� ����� �� �� �������?
    if (x < 0 || y < 0 || x > size - 1 || y > size - 1)
        throw std::exception("Invalid GetSize");

    this->data[x][y] = val;
}


// ����� �������� ������
int Matrix::GetAt(const int& x, const int& y)
{
    // �� ����� �� �� �������?
    if (x < 0 || y < 0 || x > size - 1 || y > size - 1)
        throw std::exception("Invalid GetSize");
    return this->data[x][y];
}
   // ����������, ���������� ������������� ������� � �������(���� ������)
Matrix& Matrix::Submatrix(int noCol, int noRow)
{
    if (size == 1)
        throw std::exception("size =1, submatrix is not avaliable");
    // ���������� ������ �������� �� 1 ������� � �������
    Matrix res(size - 1);
    int x, y;

    // ������� ������� �� ����������� �������
    for (int y = 0; y < noRow; y++)
    {
        // �� ����������� �������
        for (int x = 0; x < noCol; x++)
        {
            res.SetAt(x, y, this->GetAt(x, y));
        }
        // ����� ����������� �������
        for (x = noCol + 1; x < size; x++)
        {
            res.SetAt(x - 1, y, this->GetAt(x, y));
        }
    }
    // �������� ����� ����������� �������
    for (y = noRow + 1; y < size; y++)
    {
        // �� ����������� �������
        for (int x = 0; x < noCol; x++)
        {
            res.SetAt(x, y - 1, this->GetAt(x, y));
        }
        // ����� ����������� �������
        for (int x = noCol + 1; x < size; x++)
        {
            res.SetAt(x - 1, y - 1, this->GetAt(x, y));
        }
    }
    return res;
}
// �����������?
bool Matrix::IsSingular()
{
    // ����� �� ������������ 0
    return (Determinant() == 0);
}
// ������������
int Matrix::Determinant()
{
    // ������� ������� ������
    if (size == 1)
        return GetAt(0, 0);
    if (size == 2)
        return GetAt(0, 0) * GetAt(1, 1) - GetAt(1, 0) * GetAt(0, 1);
    double res = 0.0;
    int x;
    // ��������� ��������� ��������(�������) �� �������������� ���������� � ������ ������
    for (int x = 0; x < size; x++)
    {
        int sign = ((0 + x) % 2 == 0) ? 1 : -1;
        Matrix sub = Submatrix(x, 0);
        res += sign * GetAt(x, 0) * sub.Determinant();
    }
    return res;
}

std::ostream& operator<< (std::ostream& out, const Matrix& matr)
{
    for (int y = 0; y < matr.size; y++)
    {
        for (int x = 0; x < matr.size; x++)
        {
            std::cout << matr.data[y][x] << "  ";
        }
        std::cout << std::endl;
    }
    return out;
}
// ���������� �������
void Matrix::PrintMatrix()
{

    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            std::cout << data[y][x] << "  ";
        }
        std::cout << std::endl;
    }
}



