#include "MyIntContainer.h"


MyIntContainer::MyIntContainer(std::initializer_list<int> values):
    size(values.size()),
    data(new int[size])
{
    std::copy(values.begin(), values.end(), data.get());
}

MyIntContainer::iterator MyIntContainer::begin()
{
    return iterator(data.get());
}

MyIntContainer::iterator MyIntContainer::end()
{
    return iterator(data.get() + size);
}

MyIntContainer::const_iterator MyIntContainer::begin() const
{
    return const_iterator(data.get());
}

MyIntContainer::const_iterator MyIntContainer::end() const
{
    return const_iterator(data.get() + size);
}