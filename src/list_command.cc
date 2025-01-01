#include "list_command.hh"
#include "todo.hh"
#include "todo_store.hh"
#include "todo_iterator.hh"

namespace sqlite_todo
{

void ListCommand::run()
{
    TodoStore& store = TodoStore::getInstance();

    auto items = store.getItems();
    while (items.hasNext()) {
        std::cout << items.next() << "\n";
    }
}

}
