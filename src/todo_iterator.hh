#pragma once
#include "iterator.hh"
#include "todo.hh"

#include <string>
#include <vector>

namespace sqlite_todo
{

/**
 * Iterator for a collection of Todo.
 * In a real codebase, one should just use C++ std::vector's built-in iterators.
 */
class TodoIterator : public IIterator<Todo>
{
public:
    TodoIterator(std::vector<Todo>&& items)
        : mItems(items){
    }

    [[nodiscard]] bool hasNext() const override {
        return mIndex < mItems.size();
    }

    [[nodiscard]] Todo& next() override {
        assert(hasNext() && "No items left!");
        return mItems[mIndex];
    }

private:
    std::vector<Todo> mItems;
    std::size_t mIndex {};
};

}
