#include "done_command.hh"
#include "todo_store.hh"

#include <sstream>
#include <string>

namespace sqlite_todo {

bool DoneCommand::run(const std::string& param)
{
    TodoStore& store = TodoStore::getInstance();

    size_t id;
    try {
        id = std::stoull(param);
    } catch (const std::exception& ex) {
        throw CommandError("No valid id passed");
    }

    store.deleteItem(id);
    return true;
}

}
