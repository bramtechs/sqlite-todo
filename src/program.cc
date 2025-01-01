#include "todo_store.hh"

#include "command.hh"
#include "list_command.hh"

#include <iomanip>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <unordered_map>

namespace sqlite_todo {

class CliTodoProgram {
public:
    CliTodoProgram()
    {
        registerCommands();
    }

    void takeInput()
    {
        std::cout << "Enter a command. Type 'help' to list all commands.\n";

        std::string input;
        std::cin >> input;

        try {
            auto& command = mCommands.at(input);
            command->run();
        } catch (std::out_of_range&) {
            std::cerr << std::quoted(input) << " command does not exist.\n";
        }
    }

    bool shouldRun() const noexcept
    {
        return mShouldRun;
    }

private:
    void registerCommands()
    {
        mCommands.emplace("list", std::make_unique<ListCommand>());
    }

    bool mShouldRun { true };
    std::unordered_map<std::string, std::unique_ptr<ICommand>> mCommands {};
};

}

int main(int argc, char** argv)
{
    auto program = sqlite_todo::CliTodoProgram();
    while (program.shouldRun()) {
        program.takeInput();
    }
    return 0;
}
