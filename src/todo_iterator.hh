#pragma once
#include "iterator.hh"

#include <string>
#include <vector>

namespace sqlite_todo
{

/**
 * Iterator for a collection of TodoItems (strings)
 * In a real codebase, one should just use C++ std::vector's built-in iterators.
 */
class TodoIterator : public IIterator<std::string>
{
public:
    TodoIterator(std::vector<std::string>&& items)
        : mItems(items){
    }

    bool hasNext() const override {
        return mIndex < mItems.size();
    }

    [[nodiscard]] std::string& next() override {
        assert(hasNext() && "No items left!");
        return mItems[mIndex];
    }

private:
    std::vector<std::string> mItems;
    std::size_t mIndex {};
};

}
