#pragma once
#include "command.hh"

namespace sqlite_todo {

class ListCommand final : public ICommand {
public:
    bool run(const std::string&) override;
};

}
