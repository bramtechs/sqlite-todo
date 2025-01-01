#pragma once
#include "iterator.hh"

#include <SQLITE3.hpp>
#include <memory>
#include <vector>
#include <string>
#include <cassert>

namespace sqlite_todo
{

class TodoItems;

/**
 * Singleton class that manages TODO items.
 */
class TodoStore
{
public:
    void addItem(const std::string& task);

    [[nodiscard]] TodoItems getItems();
    
    [[nodiscard]] static TodoStore& getInstance();

private:
    TodoStore();

    void ensureTodoTable();

    SQLITE3 mDb;
    static std::unique_ptr<TodoStore> sStore;
};

}
