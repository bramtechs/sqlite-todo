/*
 * Copyright (c) 2025. Doomhowl Interactive - All Rights Reserved
 * Redistribution and use in source and binary forms, with or without modification are not permitted
 * without the prior written permission of Doomhowl Interactive.
 *
 * File created on: 01-01-2025
 */

#pragma once
#include <ostream>

namespace sqlite_todo
{

struct Todo
{
    int id;
    std::string task;
};

// support printing
inline std::ostream& operator<<(std::ostream& out, const Todo& todo)
{
    out << todo.id << " - " << todo.task;
    return out;
}

};
