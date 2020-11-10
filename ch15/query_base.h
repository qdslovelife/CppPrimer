#ifndef _Query_Base_H
#define _Query_Base_H

class Query;

#include <iostream>
#include <string>
#include "../ch12/text_query.h"

class Query_Base
{
    friend class Query;
protected:
    virtual ~Query_Base() = default;
private:
    virtual QueryResult eval(const TextQuery &) const = 0;
    virtual std::string rep() const = 0;
};

#endif