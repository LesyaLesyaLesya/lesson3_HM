#include "MyIterator.h"


MyIterator::MyIterator(int* p) :
    p(p)
{

}

MyIterator::MyIterator(const MyIterator& it):
    p(it.p)
{

}


bool MyIterator::operator!=(MyIterator const& other) const
{
    return p != other.p;
}


typename MyIterator::reference MyIterator::operator*() const
{
    return *p;
}


MyIterator& MyIterator::operator++()
{
    ++p;
    return *this;
}