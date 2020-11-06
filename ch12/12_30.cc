#include "text_query.h"

void runQueries(std::ifstream &is)
{
    TextQuery tq(is);
    while(true)
    {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if(!(std::cin >> s) || s == "q")    break;
        print(std::cout, tq.query(s)) << std::endl;
    }
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        std::cerr << "a.exe file" << std::endl;
    }

    std::ifstream is(argv[1]);
    runQueries(is);
    return 0;
}