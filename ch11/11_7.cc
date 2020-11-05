#include <map>
#include <string>
#include <vector>

int main()
{
    std::map<std::string, std::vector<std::string>> family = {{"Trump", {"Ivanka"}}};
    family["Trump"].push_back("Tiffany");
    family["Biden"] = std::vector<std::string>();
    return 0;
}