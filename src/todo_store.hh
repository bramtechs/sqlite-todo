#pragma once
#include "iterator.hh"

#include <SQLITE3.hpp>
#include <memory>
#include <stdexcept>
#include <vector>
#include <string>
#include <cassert>

namespace sqlite_todo
{

// forward declaration
class TodoIterator;

/**
 * Singleton class that manages TODO items.
 */
class TodoStore
{
public:
    void addItem(const std::string& task);

    [[nodiscard]] TodoIterator getItems();

    [[nodiscard]] static TodoStore& getInstance();

private:
    TodoStore();

    void ensureTodoTable();

    SQLITE3 mDb;
    static std::unique_ptr<TodoStore> sStore;
};

}
