#include "todo_store.hh"
#include "store_error.hh"

#include <iostream> // for printing to stdout
#include <iomanip> // for std::quoted

namespace sqlite_todo
{

constexpr static const char* DB_NAME = "todos.db";

TodoStore::TodoStore()
    : mDb(DB_NAME)
{
}

void TodoStore::ensureTodoTable()
{
    if (mDb.execute("CREATE TABLE todos (id int PRIMARY KEY, task text);")) { // truthy means an error happened
        mDb.perror(); // print error message
        std::cerr.flush();
    } else {
        mDb.commit();
        std::cout << "Created todo table inside " << DB_NAME << '\n';
    }
}

TodoStore& TodoStore::getInstance()
{
    if (!sStore) {
        sStore = std::unique_ptr<TodoStore>(new TodoStore());
    }
    return *sStore;
}

void TodoStore::addItem(const std::string& task)
{
    ensureTodoTable();

    SQLITE3_QUERY query = SQLITE3_QUERY("INSERT INTO todos (task) VALUES (?);");
    query.add_binding(task);

    // truthy means an error happened
    if (mDb.execute(query)) {
        mDb.perror(); // print error message
        std::cerr.flush();
        throw StoreError("Failed to add item to db table!");
    }

        mDb.commit();
        std::cout << "Added todo item " << std::quoted(task) << '\n';
    }
void TodoStore::ensureTodoTable()
{
    // truthy means an error happened
    if (mDb.execute("CREATE TABLE todos (id INTEGER PRIMARY KEY, task text);")) {
        mDb.perror(); // print error message
        std::cerr.flush();
        throw StoreError("Failed to create todos table!");
    }

    mDb.commit();
    std::cout << "Created todo table inside " << DB_NAME << '\n';
}

std::unique_ptr<TodoStore> TodoStore::sStore {};

}
