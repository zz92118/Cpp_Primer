//
// Created by cer
// chapter 3
// 字符串、向量和数组

#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::bitset;

void basic_getline(){
    string line;
    while (getline(cin, line))
        cout << line << endl;
}

void basic_string(){
    string s = "Test String.";
    cout << "Size: " << s.size() << endl
         << "Empty: " << s.empty() << endl
         << "char at index 0:" << s[0] << endl;
    for(string::size_type i=0; i<s.size(); i++){
        cout << s[i];
    }
    cout << endl;
}

void basic_vector(){
    vector<int> v;
    for (int i = 0; i != 10; i++){
        v.push_back(i);
    }
    for (vector<int>::iterator iter = v.begin();
         iter != v.end(); ++iter){
        *iter = 0;
    }
    // 不能直接输出vector
}

void basic_bieset(){
    bitset<16> bitvec1(0xffff);
    string bit_str = "1100";
    bitset<32> bitvec2(bit_str); //从右到左读取字符串，只能是string对象，不能是字面值
    bitset<16> bitvec3(bit_str, 0, 3); // 只要前三位
    cout << bitvec1 << endl
         << bitvec2 << endl
         << bitvec3 << endl
         << bitvec2.test(3) <<" " <<bitvec2.test(3) << endl
         << bitvec2.to_ulong() << endl;
}

void q_3_14(){
    vector<int> v;
    int i;
    while (cin >> i){
        v.push_back(i);
    }
}

void q_3_17(){
    vector<string> v;
    string s;
    while (cin >> s){
        v.push_back(s);
    }
    for (auto &str : v)
    {
        for (auto &c : str)
        {
            c = toupper(c);
        }
    }
    for (auto str : v){
        cout << str << endl;
    }
}


void q_3_23(){
    vector<int> v(10, 1);
    for (auto it=v.begin(); it!=v.end(); it++){
        *it *= 2;
    }
    for (auto one : v){
        cout << one <<endl;
    }
}

void q_3_31(){
    int a[10];
    for (size_t i=0; i != 10; i++){
        a[i] = i;
    }
}

void multi_array()
{
    int arr[3][4] = 
    { 
        { 0, 1, 2, 3 },
        { 4, 5, 6, 7 },
        { 8, 9, 10, 11 }
    };

    // range for
    // for (const int(&row)[4] : arr)
    //     for (int col : row) cout << col << " ";
    // cout << endl;

    // // for loop
    // for (size_t i = 0; i != 3; ++i)
    //     for (size_t j = 0; j != 4; ++j) cout << arr[i][j] << " ";
    // cout << endl;

    // using pointers.
    for (int(*row)[4] = arr; row != arr + 3; ++row)
		//(*row)
        for (int *col = *row; col != *row + 4; ++col) cout << *col << " ";
    cout << endl;

    cout<<**arr<<endl; // arr和 *arr都是地址 **arr是value

}

//c风格字符串必须\0结尾
void stringchar()
{
    string s("123");
    char a2[] = {'c','+','+'};
    char a3[] = "c++";
    cout<<sizeof(a2)<<" "<<sizeof(a3)<<endl;
    for(auto i : a2)
    {
        cout<<i<<endl;
    }
    for(auto i : a3)
    {
        cout<<i<<endl;
    }
    string a4 = a3;
    cout<<a4<<endl;

    a4 = a2 ;
    cout<<a4<<endl;


    // for(auto i : s2)
    // {
    //     cout<<i<<endl;
    // }
    // cout<<s.size()<<endl;
}

int main(){
//    basic_getline();
    // multi_array();
    stringchar();
}
//    basic_string();
//    basic_bieset();
//    q_3_14();
//    q_3_17();
//     q_3_23();
// }