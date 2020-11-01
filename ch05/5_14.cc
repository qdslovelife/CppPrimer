#include <iostream>
#include <string>

int main()
{
    std::string max_repeat_string, cur_repeat_string, cur_string;
    int max_count = 0, cur_count = 0;

    if(std::cin >> cur_repeat_string)
    {
        cur_count = 1;
        while(std::cin >> cur_string)
        {
            if(cur_string == cur_repeat_string)
            {
                ++cur_count;
            }
            else
            {
                if(max_count < cur_count)
                {
                    max_repeat_string = cur_repeat_string;
                    max_count = cur_count;

                    cur_repeat_string = cur_string;
                    cur_count = 1;
                }
            }
        }
    }
    if(!(max_count > 1))
    {
        std::cout << "There is no repear string." << std::endl;
    }
    else
    {
        std::cout << "The string: " << max_repeat_string << " occurs " << max_count << " times." << std::endl;
    }
    return 0;
}