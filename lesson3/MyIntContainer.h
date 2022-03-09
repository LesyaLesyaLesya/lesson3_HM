#pragma once
#include <initializer_list>
#include <memory>
#include "MyIterator.h"

    class MyIntContainer
{
public:
    typedef MyIterator iterator;
    typedef MyIterator const const_iterator;

    MyIntContainer(std::initializer_list<int> values);

    iterator begin();
    iterator end();

    const_iterator begin() const;
    const_iterator end() const;
private:
    const size_t size;
    std::unique_ptr<int[]> data;
};