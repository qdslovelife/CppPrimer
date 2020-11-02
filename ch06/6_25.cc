#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        std::cerr << "Call form: 6_25.exe para1 para2." << std::endl;
        return 1;
    }
    std::string s = argv[1] + std::string(" ") + argv[2];
    std::cout << s << std::endl;
    return 0;
}