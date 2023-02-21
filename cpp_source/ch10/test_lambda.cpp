#include<iostream>
using namespace std;

void test_1()
{
    auto f = [](int i,int j){return i+j;};//f是一个可调用的对象
    auto res = f(2,5);
    int x =10;

    auto f2 = [x](int i){return i+x; };
    auto res2 = f2(20);// 补货列表不需要传递参数
    cout<<res<<endl;
    cout<<res2<<endl;
}

int main()
{
    test_1();
}