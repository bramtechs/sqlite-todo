#pragma once
#include "iterator.hh"

#include <cassert>
#include <memory>
#include <SQLITE3.hpp>
#include <stdexcept>
#include <string>
#include <vector>

namespace sqlite_todo {

// forward declaration
class TodoIterator;

/**
 * Singleton class that manages TODO items.
 */
class TodoStore {
public:
    void addItem(const std::string& task);

    void deleteItem(size_t id);

    void resetItems();

    [[nodiscard]] TodoIterator getItems();

    [[nodiscard]] static TodoStore& getInstance();

private:
    TodoStore();

    void ensureTodoTable();

    SQLITE3 mDb;
    static std::unique_ptr<TodoStore> sStore;
};

}
