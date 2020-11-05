#include <iostream>
#include <fstream>
#include <iterator>

int main(int argc, char *argv[])
{
    if(argc != 4)
    {
        std::cerr << "a.exe file1 file2 file3" << std::endl;
        return 1;
    }
    std::ifstream is(argv[1]);
    std::ofstream os1(argv[2]);
    std::ofstream os2(argv[3]);
    
    std::istream_iterator<int> is_iter(is), eof;
    std::ostream_iterator<int> os1_iter(os1, " "), os2_iter(os2, "\n");

    while(is_iter != eof)
    {
        if(*is_iter % 2 == 0)
        {
            *os1_iter++ = *is_iter++;
        }
        else
        {
            *os2_iter++ = *is_iter++; 
        }
    }
    return 0;
}