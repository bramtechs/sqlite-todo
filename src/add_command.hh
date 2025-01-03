#pragma once
#include "command.hh"

namespace sqlite_todo
{

class AddCommand : public ICommand
{
public:
    bool run(const std::string& parameter) override;
};

}
