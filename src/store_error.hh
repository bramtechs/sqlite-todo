#pragma once

namespace sqlite_todo
{

class StoreError : public std::runtime_error
{
public:
    // use constructor of base class
    using std::runtime_error::runtime_error;
};

}
