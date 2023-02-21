#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int ia[] = {1,2,3,4,5,6,7,8,9};
    int val = 5;
    int* result = find(begin(ia), end(ia), val);//指针也是迭代器
    auto result2 = find(ia+1,ia+7,val);//指定范围
    cout<<*result<<endl<<*result2<<endl;

}