#include<iostream>
#include<set>
#include<vector>
using namespace std;

multiset<string> c;
vector<string> v;

int main()
{   
    copy(v.begin(), v.end(), inserter(c, c.end()));
    // copy(v.begin(), v.end(), back_inserter(c));// 不合法
    copy(c.begin(), c.end(), inserter(v, v.end()));
    copy(c.begin(), c.end(), back_inserter(v));
}