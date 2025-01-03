#pragma once
#include "command.hh"

namespace sqlite_todo {

class HelpCommand final : public ICommand {
public:
    bool run(const std::string& param) override;
};

}
