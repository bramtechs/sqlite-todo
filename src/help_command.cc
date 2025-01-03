#include "help_command.hh"

#include <iostream>

namespace sqlite_todo {

bool HelpCommand::run(const std::string& param)
{
    std::cout << "add <task title> - Adds a todo task." << '\n';
    std::cout << "complete <id> - Marks a task as completed by removing it:" << '\n';
    std::cout << "list - Lists all the tasks that haven't been done:" << '\n';
    std::cout << "clear - Removes the tasks database" << '\n';
    std::cout << "help - Shows this help screen" << '\n';

    return true;
}

}
