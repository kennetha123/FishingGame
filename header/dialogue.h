#pragma once
#include <iostream>
#include <string>

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

    static void answer(std::string& answer_str, bool is_amount_type = false)
    {
        int option = -1;
        while (true) {
            std::cin >> answer_str;
            try {
                if (!is_amount_type)
                {
                    option = std::stoi(answer_str) - 1;
                    if (option >= 0 && option <= 2)
                    {
                        break;
                    }
                    else {
                        Dialogue::print("The answer is not in the option...");
                    }
                }
                else
                {
                    option = std::stoi(answer_str);
                    break;
                }
            }
            catch (const std::invalid_argument& e)
            {
                Dialogue::print("Please enter a valid number.");
            }
            catch (const std::out_of_range& e)
            {
                Dialogue::print("The number entered is too large.");
            }
        }


    }
};