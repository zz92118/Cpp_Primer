#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using std::string;
using namespace std::placeholders;

bool isLesserThanOrEqualTo6(const string &s, string::size_type sz)
{
    return s.size() <= sz;
}

int main()
{
    std::vector<string> authors{ "Mooophy", "pezy", "Queequeg90", "shbling", "evan617" };
    std::cout << count_if(authors.cbegin(), authors.cend(), bind(isLesserThanOrEqualTo6, _1, 6));
}