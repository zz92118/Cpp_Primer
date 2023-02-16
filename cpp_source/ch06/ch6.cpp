//
// Created by cer on 17-9-19.
// chapter 06
// 函数

#include <iostream>
#include <string>

using namespace std;

int fact(int i)
{
    return i > 1 ? i * fact(i - 1) : 1;
}

void interactive_fact()
{
    string const prompt = "Enter a number within [1, 13) :\n";
    string const out_of_range = "Out of range, please try again.\n";
    for (int i; cout << prompt, cin >> i; )
    {
        if (i < 1 || i > 12)
        {
            cout << out_of_range;
            continue;
        }
        cout << fact(i) << endl;
    }
}

void reset(int &i)
{
    i = 0;
}

void string_const(string &s)
{
    size_t x = s.size();
    s[0] = 'x';
}
// bool str_subrange(const string &str1, const string &str2)
// {
//     if(str1.size()==str2.size())
//         return str1==str2;
//     string::size_type size={min(str1.size(),str2.size())};
//     string::size_type i=0;
//     while(i!=size){
//         if(str1[i]!=str2[i])
//         return ; //error! no return value!
//   }
// }


int main()
{
//    interactive_fact();
    // str_subrange();
    int i = 42;
    const int *cp = &i;
    const int &r = i;
    const int &r2 = 42;
    // int *p = cp;//类型不匹配
    // int &r3 = r;//类型不匹配
    // int &r4 = 42;//不能用字面值初始化非常量引用

    // int i =0;
    const int ci = i;
    reset(i);
    // reset(ci);// 不能把普通引用绑定到const对象
    // reset(42)// 不能把普通引用绑定到字面值
    string s("123");
    string_const(s);
    cout<<s<<endl;

    return 0;
}