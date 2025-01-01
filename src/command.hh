#pragma once
#include "todo_store.hh"

#include <string>

namespace sqlite_todo
{

class ICommand
{
public:
    virtual ~ICommand() = default;

    virtual void run() = 0;
};

}
