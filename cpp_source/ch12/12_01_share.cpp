#include<iostream>
#include<string>
using namespace std;

void fun1()
{
    shared_ptr<string> p1;
    string s1;
    p1 = make_shared<string>("111");//用于构造给定类型的对象
    if(p1 && p1->empty())
    {
        *p1 = "hi";
    }

    auto p6 = make_shared<vector<string>>();

    //拷贝和赋值
    auto p = make_shared<int>(42);
    auto q(p);//拷贝 该对象有两个引用者

    auto r = make_shared<int>(42);
    r = q;//赋值 r的引用计数递减 q的引用计数递增
}

int main()
{

}