#pragma once
#include <iostream>

class Dialogue
{
public:
    template<typename first_args, typename... args>
    static void print(const first_args& first_arg, const args&... arg)
    {
        std::cout << first_arg;
        if constexpr (sizeof...(arg) > 0)
        {
            print(arg...);
        }
        else {
            std::cout << std::endl;
        }
    }

    static void answer(std::string& answer_str)
    {

    }
};