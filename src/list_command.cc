#include "list_command.hh"
#include "todo.hh"
#include "todo_iterator.hh"
#include "todo_store.hh"

namespace sqlite_todo {

void ListCommand::run(const std::string&)
{
    TodoStore& store = TodoStore::getInstance();

    auto items = store.getItems();
    while (items.hasNext()) {
        std::cout << items.next() << "\n";
    }
}

}
