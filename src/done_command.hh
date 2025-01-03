#pragma once
#include "command.hh"

namespace sqlite_todo
{

class DoneCommand : public ICommand
{
public:
    bool run(const std::string& param) override;
};

}
