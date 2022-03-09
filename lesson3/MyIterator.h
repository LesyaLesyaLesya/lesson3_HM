#pragma once
//сами итераторы должны реализовать три оператора: !=, ++, *.
#include <iterator>

class MyIterator : public std::iterator<std::input_iterator_tag, int>
{
public:
    MyIterator(int* p);

    MyIterator(const MyIterator& it);

    bool operator!=(MyIterator const& other) const;
    typename MyIterator::reference operator*() const;
    MyIterator& operator++();
private:
    int* p;
};
