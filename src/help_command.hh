#pragma once
#include "command.hh"

namespace sqlite_todo
{

class HelpCommand final : public ICommand
{
public:
    void run() override;
};

}