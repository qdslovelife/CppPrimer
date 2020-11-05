#include <iostream>
#include <string>
#include <map>

int main()
{
    std::multimap<std::string, std::string> authors = {{"JK", "HarryPotter"}};
    std::string author;
    std::cin >> author;
    auto iter = authors.find(author);
    if(iter == authors.end())
    {
        std::cout << "There is no author whose name is " << author << std::endl;
    }
    else
    {
        authors.erase(iter);
        std::cout << "Delete completed." << std::endl;
    }
    return 0;
}