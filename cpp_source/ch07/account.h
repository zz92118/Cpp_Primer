#include<iostream>
#include<string.h>
using namespace std;

class Account {
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double newRate) { interestRate = newRate; }
    
private:
    std::string owner;
    double amount;
    static double interestRate;
    static constexpr double todayRate = 42.42;// 累的内部只能定义constexpr
    static double initRate() { return todayRate; }
};

double Account::interestRate = initRate();// 在类的外部定义