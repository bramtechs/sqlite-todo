#pragma once

namespace sqlite_todo
{

template <typename T>
class IIterator
{
public:
    virtual ~IIterator() = default;

    virtual bool hasNext() const = 0;

    virtual T& next() = 0;
};

}
