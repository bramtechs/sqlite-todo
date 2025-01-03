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

    /**
     * Run the inherited command.
     *
     * \param param The text specified after the command.
     * \return True if the program should continue, false otherwise.
     */
    virtual bool run(const std::string& param) = 0;
};

}
