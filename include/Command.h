#ifndef COMMAND_H
#define COMMAND_H

#include <functional>

struct Command
{
    std::function<void()>;
};


#endif // COMMAND_H
