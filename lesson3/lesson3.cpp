// Lesson2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <locale>
#include <vector>
#include <list>
#include <algorithm>
#include <string_view>

using namespace std;

template <typename T>
void printList(const T &listForPrint)
{
    for (const auto & elem : listForPrint)
    {
        cout << elem << " " ;
    }
    cout << endl;
}

double Average(const list<double> &l)
{
    double sum{ 0 };
    for_each(l.begin(), l.end(), [&](const auto& c) {sum += c; });

    return  sum / l.size();
}
void Zadanie1()
{
    /*--------------------------------------------------
    Написать функцию, добавляющую в конец списка вещественных чисел элемент,
    значение которого равно среднему арифметическому всех его элементов
    ----------------------------------------------------*/
    list<double> list1 = {1, 5.5, 3.4, 20, 8.37, 100};

    printList(list1);
    list1.push_back(Average(list1));
    printList(list1);
};


void Zadanie2()
{
    /*--------------------------------------------------
    Создать класс, представляющий матрицу. 
    Реализовать в нем метод, вычисляющий определитель матрицы.
    ----------------------------------------------------*/

    

};

string readFile(const string& fileName) {
    std::ifstream f(fileName);
    f.seekg(0, ios::end);
    size_t size = f.tellg();
    string s(size, ' ');
    f.seekg(0);
    f.read(&s[0], size); // по стандарту можно в C++11, по факту работает и на старых компиляторах
    return s;
}


void Zadanie3()
{
    /*--------------------------------------------------
    

    ----------------------------------------------------*/
    
};


int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Введите номер задания цифрой" << std::endl;
    unsigned short nomerZadania;

    std::cin >> nomerZadania;

    switch (nomerZadania)
    {
    case 1:Zadanie1(); break;

    case 2:Zadanie2(); break;

    case 3:Zadanie3(); break;

    default: break;
    }


    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
