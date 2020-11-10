#include "query.h"

int main()
{
    std::ifstream is("./storyDataFile");
    TextQuery text(is);
    Query query = Query("fiery") & Query("bird") | Query("wind");
    std::cout << query.eval(text) << std::endl;
    return 0;
}