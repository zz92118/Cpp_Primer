# include "screen.h"

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.display(std::cout);// 调用常量版本
    std::cout << "\n";
    myScreen.move(4, 0).set('#').display(std::cout);// 调用非常量版本
    std::cout << "\n";
    myScreen.display(std::cout);// 调用常量版本
    std::cout << "\n";

    return 0;
}