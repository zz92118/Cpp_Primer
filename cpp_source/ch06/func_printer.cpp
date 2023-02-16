#include<iostream>

using namespace std;

bool lengthCompare(const string &, const string &);

bool (*pf)(const string&,const string &);

void useBigger(const string &s1, const string &s2,bool pf(const string &s1, const string &s2));
void useBigger(const string &s1, const string &s2,bool (*pf)(const string &s1, const string &s2));

// 使用typedef作为函数指针形参
// 1. 函数类型
typedef bool Func(const string &, const string &);
typedef decltype(lengthCompare) Func2;


// 2. 函数指针类型
typedef bool (*FuncP)(const string &, const string &);
typedef decltype(lengthCompare) *FuncP2;

// 重新声明usebigger
void useBigger(const string &s1, const string &s2,Func2);// 自动转化为函数的指针
void useBigger(const string &s1, const string &s2,FuncP2);


int main()
{
    string s1="hello";
    string s2="world!";
    pf = lengthCompare;
    pf = &lengthCompare;//取地址也是可行的
    // 等价的调用 
    bool b1 = pf("hello","goodbye");
    bool b1 = (*pf)("hello","goodbye");
    bool b1 = lengthCompare("hello","goodbye");
    //函数指针作为形参
    useBigger(s1,s2,lengthCompare);//lengthCompare 转化为指向函数的指针
    // 调用
    useBigger(s1,s2,pf);

}