#include "add_command.hh"
#include "todo_store.hh"

#include <iostream>

namespace sqlite_todo
{

void AddCommand::run(const std::string& parameter)
{
    if (parameter.empty()) {
        throw CommandError("Todo item cannot be empty");
    }

    TodoStore& store = TodoStore::getInstance();
    store.addItem(parameter);
}

}
