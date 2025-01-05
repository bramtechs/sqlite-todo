#include "list_command.hh"
#include "todo.hh"
#include "todo_iterator.hh"
#include "todo_store.hh"

namespace sqlite_todo {

bool ListCommand::run(const std::string&)
{
    TodoStore& store = TodoStore::getInstance();

    auto items = store.getItems();
    if (!items.hasNext()) {
        std::cout << "There are no TODO items yet, add them with the 'add' command!\n";
    }
    while (items.hasNext()) {
        std::cout << items.next() << "\n";
    }

    return true;
}

}
