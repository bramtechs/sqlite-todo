#pragma once
#include "todo_store.hh"

#include <stdexcept>
#include <string>

namespace sqlite_todo {

class CommandError : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class ICommand {
public:
    virtual ~ICommand() = default;

    virtual void run(const std::string& param) = 0;
};

}
