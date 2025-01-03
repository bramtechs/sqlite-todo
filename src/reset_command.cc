#include "reset_command.hh"

namespace sqlite_todo
{

bool ResetCommand::run(const std::string& param)
{
    TodoStore& store = TodoStore::getInstance();
    store.resetItems();
    std::cout << "Reset todo items\n";

    return true;
}

}
