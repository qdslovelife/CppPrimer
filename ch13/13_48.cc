#include <vector>
#include "my_string.h"

String f(String s)  { return s; }

int main()
{
    std::vector<String> vec;
    vec.push_back("ni");
    vec.push_back("hao");
    vec.push_back("zhong");
    vec.push_back("guo");
    String ret = f(vec[0]);
    return 0;
}