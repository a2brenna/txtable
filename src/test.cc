#include "txtable.h"
#include <iostream>

int main(){

    std::vector<std::string> headings = { "foolishness", "bar", "baz" };
    std::vector<std::string> row_a= { "foo", "barbie", "bazbazxsdflj" };
    std::vector<std::string> row_b= { "foo", "bar", "baz" };

    Table t(headings);

    t.add_row(row_a);
    t.add_row(row_b);

    std::cout << t;

    return 0;
}
