#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<numeric>
#include <list>
#include<iterator>

using namespace std;

void e10_4()
{
    std::vector<int> v = { 1, 2, 3, 4 };
    std::cout << "ex 10.03: " << std::accumulate(v.cbegin(), v.cend(), 0) << std::endl;

    // Exercise 10.4
    std::vector<double> vd = { 1.1, 0.5, 3.3 };
    std::cout   << "ex 10.04: "
                << std::accumulate(vd.cbegin(), vd.cend(), 0)
                << std::endl;         
}

int e10__()
{
    // 10.1
    std::vector<int> v = { 1, 2, 3, 4, 5, 6, 6, 6, 2 };
    std::cout << "ex 10.01: " << std::count(v.cbegin(), v.cend(), 6) << std::endl;

    // 10.2
    std::list<std::string> l = { "aa", "aaa", "aa", "cc" };
    std::cout << "ex 10.02: " << std::count(l.cbegin(), l.cend(), "aa") << std::endl;
}

void test_back_inserter_()
{
    vector<int> vec;
    auto it = back_inserter(vec);//通过此迭代器赋值，调佣pushback插入，返回一个插入迭代器。
    *it = 42;

    vector<int> vec2;
    fill_n(back_inserter(vec2),10,0);

    for(auto i : vec2)
    {
        cout<<i<<" ";
    }
}

void test_replace_copy()
{
    list<int> ilist = {1,2,3,4,5};
    vector<int> ivec;
    replace_copy(ilist.cbegin(), ilist.cend(),back_inserter(ivec), 0, 42);
    for(auto i : ilist)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i : ivec)
    {
        cout<<i<<" ";
    }
}

int main()
{
    // e10_4();
    test_replace_copy();

    return 0;
}