#include<iostream>
using namespace std;


int main()
{
    const char *cp = "hello world!!!";//空字符结尾的字符数组
    string s1(cp);
    string s4(cp+6,5);
    string s5(s1,6,6);
    cout<<s1<<endl;
    cout<<s4<<endl;
    cout<<s5<<endl;
    return 0;
}