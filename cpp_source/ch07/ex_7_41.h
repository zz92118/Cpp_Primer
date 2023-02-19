#ifndef CP5_ex7_41_h
#define CP5_ex7_41_h

#include <string>
#include <iostream>

class Sales_data {
    // 友元函数
    friend std::istream &read(std::istream &is, Sales_data &item);// 返回引用 常用用法
    friend std::ostream &print(std::ostream &os, const Sales_data &item);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

public:// 提供的接口
    //前两个参数可以提供 最后一个参数 revenue通过计算得到 revenue(n*p)
    Sales_data(const std::string &s, unsigned n, double p):bookNo(s), units_sold(n), revenue(n*p)
    { std::cout << "Sales_data(const std::string&, unsigned, double)" << std::endl; }//
    
    Sales_data() : Sales_data("", 0, 0.0f)
    { std::cout << "Sales_data()" << std::endl; }
    
    Sales_data(const std::string &s) : Sales_data(s, 0, 0.0f)
    { std::cout << "Sales_data(const std::string&)" << std::endl; }
    
    Sales_data(std::istream &is);

    std::string isbn() const { return bookNo; }// 声明+定义
    Sales_data& combine(const Sales_data&);// 声明
    
private://并不是接口的一部分
    inline double avg_price() const;       // 内联版本的avgprice函数 

private:
    std::string bookNo;//ISBN编号
    unsigned units_sold = 0;//销量
    double revenue = 0.0;//总收入
};

//this 来把对象当做整体进行访问 *this把this对象作为实参传递给read函数
Sales_data::Sales_data(std::istream &is)
{
    read(is, *this);//解引用 this得到该对象，形参列表式对象引用
}


Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

inline
double Sales_data::avg_price() const
{
    return units_sold ? revenue/units_sold : 0;
}

// declarations for nonmember parts of the Sales_data interface.
// 非成员接口函数
// nonmember functions
std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;// 必须是非const的引用
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue; // 不会修改 所以是const引用ß
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

#endif
