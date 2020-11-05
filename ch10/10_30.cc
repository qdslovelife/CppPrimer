#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::istream_iterator<int> is_iter(std::cin), eof;
    std::ostream_iterator<int> os_iter(std::cout, " ");
    std::vector<int> vec(is_iter, eof);
    std::sort(vec.begin(), vec.end());
    std::copy(vec.begin(), vec.end(), os_iter);
    return 0;
}