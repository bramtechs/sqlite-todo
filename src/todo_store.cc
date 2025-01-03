#include "todo_store.hh"
#include "store_error.hh"
#include "todo_iterator.hh"

#include <iomanip> // for std::quoted
#include <iostream> // for printing to stdout

namespace sqlite_todo {

constexpr static const char* DB_NAME = "todos.db";

TodoStore::TodoStore()
    : mDb(DB_NAME)
{
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

void TodoStore::deleteItem(size_t id)
{
    ensureTodoTable();

    SQLITE3_QUERY query = SQLITE3_QUERY("DELETE FROM todos WHERE id = (?);");
    query.add_binding(std::to_string(id));
    if (mDb.execute(query)) {
        mDb.perror();
        std::cerr.flush();
        throw StoreError("Failed to delete item from db table");
    }
}

TodoIterator TodoStore::getItems()
{
    ensureTodoTable();

    // truthy means an error happened
    if (mDb.execute("SELECT id, task FROM todos")) {
        mDb.perror();
        std::cerr.flush();
        throw StoreError("Failed to collect items from db table!");
    }

    std::vector<Todo> items = {};
    const auto& rows = mDb.copy_result();
    for (const auto& row : *rows) {
        try {
            const int id = std::stod(row.at(0));
            items.emplace_back(id, row.at(1));
        } catch (std::exception& ex) {
            std::cerr << "Skipped broken entry: " << row.at(0) << ", " << row.at(1) << " -> " << ex.what();
        }
    }
    return TodoIterator(std::move(items));
}

void TodoStore::ensureTodoTable()
{
    // truthy means an error happened
    if (mDb.execute("CREATE TABLE todos (id INTEGER PRIMARY KEY, task text);")) {
        mDb.perror(); // print error message
        std::cerr.flush();
    } else {
        mDb.commit();
        std::cout << "Created todo table inside " << DB_NAME << '\n';
    }
}

std::unique_ptr<TodoStore> TodoStore::sStore {};

}
