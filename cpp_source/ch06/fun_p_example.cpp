#include<iostream>
#include<vector>
using namespace std;

int func(int a,int b);

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }

typedef decltype(func) *func1;
vector<decltype(func)* > v; // v中的元素是指向func的指针
vector<func1> vec;
// { add, subtract, multiply, divide }; // v中的元素是指向func的指针


int main()
{
    v.push_back(add);
    v.push_back(subtract);
    v.push_back(multiply);
    v.push_back(divide);

    vec.push_back(add);
    vec.push_back(subtract);
    vec.push_back(multiply);
    vec.push_back(divide);

    for (auto f : v) // f是函数指针
          std::cout << f(2, 2) << std::endl;

    cout<<"using typedef"<<endl;

    for (auto f : vec) 
          std::cout << f(2, 2) << std::endl;
}




