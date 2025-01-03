#include "todo_store.hh"

#include "add_command.hh"
#include "command.hh"
#include "help_command.hh"
#include "list_command.hh"

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <memory>
#include <ranges>
#include <stdexcept>
#include <unordered_map>

namespace sqlite_todo {

class QuitCommand : public ICommand {
public:
    bool run(const std::string& param) override
    {
        std::cout << "Bye!\n";
        return false;
    }
};

class CliTodoProgram {
public:
    CliTodoProgram()
    {
        registerCommands();
    }

    bool takeInput()
    {
        std::cout << "Enter a command. Type 'help' to list all commands.\n";

        std::string input;
        std::getline(std::cin, input);

        std::string name;
        std::string param;

        try {
            const auto words = splitInputByChar(input, ' ');
            if (words.empty()) {
                throw CommandError("No command given!");
            }

            if (words.size() > 1) {
                name = words[0];
                param = input.substr(name.size() + 1);
            } else {
                name = words[0];
                param = "";
            }

            auto& command = mCommands.at(name);
            clearConsole();
            if (!command->run(param)) {
                return false;
            }

        } catch (const CommandError& error) {
            std::cerr << error.what() << '\n';
        } catch (const std::out_of_range&) {
            std::cerr << std::quoted(input) << " command does not exist.\n";
        } catch (const std::exception& ex) {
            std::cerr << "Unexpected error:" << ex.what() << '\n';
        }

        return true;
    }

    bool shouldRun() const noexcept
    {
        return mShouldRun;
    }

private:
    std::vector<std::string> splitInputByChar(std::string input, char ch) const
    {
        auto range = std::views::split(input, ch);
        std::vector<std::string> result;
        for (auto&& subrange : range) {
            result.emplace_back(subrange.begin(), subrange.end());
        }
        return result;
    }

    void clearConsole()
    {
#if defined _WIN32
        system("cls");
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined(__APPLE__)
        system("clear");
#else
        // We don't know how to clear on your platform...
#endif
    }

    void registerCommands()
    {
        mCommands.emplace("list", std::make_unique<ListCommand>());
        mCommands.emplace("add", std::make_unique<AddCommand>());
        mCommands.emplace("help", std::make_unique<HelpCommand>());
        mCommands.emplace("quit", std::make_unique<QuitCommand>());
    }

    bool mShouldRun { true };
    std::unordered_map<std::string, std::unique_ptr<ICommand>> mCommands {};
};

}

int main(int argc, char** argv)
{
    auto program = sqlite_todo::CliTodoProgram();
    while (program.shouldRun()) {
        if (!program.takeInput()) {
            break;
        }
    }
    return EXIT_SUCCESS;
}
