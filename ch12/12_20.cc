#include "strblob.h"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        std::cerr << "a.exe file" << std::endl;
        return 1;
    }
    std::string word;
    StrBlob blob;
    StrBlobPtr blob_ptr(blob);
    std::ifstream is(argv[1]);
    while(std::getline(is, word))
    {
        blob.push_back(word);
    }
    try
    {
        while(true)
        {
            std::cout << blob_ptr.deref() << std::endl;
            blob_ptr.incr();
        }
    }
    catch(const std::out_of_range& e)
    {
        std::cout << e.what();
        return 0;
    }
    return 0;
}