#pragma once
#include "todo_store.hh"

#include <string>

namespace singleton_todo
{

class ICommand
{
public:
    virtual ~ICommand() = default;

    virtual void run() = 0;

    virtual std::string getName() const noexcept = 0;
};

class ListCommand : public ICommand
{
public:

    void run() override {

    }

    [[nodiscard]] std::string getName() const noexcept override
    {
        return "list";
    }
};

}
