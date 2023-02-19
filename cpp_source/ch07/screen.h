#ifndef CH07_screen
#define CH07_screen

#include <string>
#include <iostream>
#include <vector>

// 声明
class Screen;
class Window_mgr;



class Screen {
friend class Window_mgr;// 友元类，windowmgr可以访问screen的private成员
// friend void Window_mgr::clear(ScreenIndex); //也可以对成员函数定义友元

public:
    using pos = std::string::size_type;// 定义类中出现的别名

    Screen() = default; // 1
    Screen(pos ht, pos wd):height(ht), width(wd), contents(ht*wd, ' '){ } // 2 初始化列表
    Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht*wd, c){ } // 3 contents是ht*wd个c构成的字符串

    // 重载成员函数
    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r*width+c]; }
    // 内联函数声明和定义
    inline Screen& move(pos r, pos c);
    inline Screen& set(char c);
    inline Screen& set(pos r, pos c, char ch);

    const Screen& display(std::ostream &os) const { do_display(os); return *this; } //const的引用 为了连续调用但不改变返回的对象的值
    Screen& display(std::ostream &os) { do_display(os); return *this; }

    //可变数据成员
    void some_member() const{
        ++access_ctr;
    }

private:
    void do_display(std::ostream &os) const { os << contents; }//this指针可以隐式的从指向非常量的指针转化为指向常量的指针

    // 调用的对象是否是const来决定调用常量还是非常量版本 

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;//contents是ht*wd个c构成的字符串

    mutable size_t access_ctr;// 可变数据成员 任何成员函数（即使是const）函数也可以改变。
};

inline Screen& Screen::move(pos r, pos c)
{
    cursor = r*width + c;
    return *this;
}

inline Screen& Screen::set(char c)
{
    contents[cursor] = c;//设置当前光标所在位置的新value 引用
    return *this;// 将this作为左值 返回 （返回一个引用）
}

inline Screen& Screen::set(pos r, pos c, char ch)
{
    contents[r*width+c] = ch;
    return *this;
}

// inline void Window_mgr::clear(ScreenIndex i)
// {
// 	Screen& s = screens[i];
// 	s.contents = std::string(s.height*s.width,' ');
// }

class Window_mgr
{
public:
    //窗口中每个屏幕的编号
	using ScreenIndex = std::vector<Screen>::size_type;
    //将编号指定的screen设置为空白
	inline void clear(ScreenIndex);
    // 返回类型
    ScreenIndex addScreen(const Screen&);

private:
	std::vector<Screen> screens{Screen(24,80,' ')};//默认初始化的screens 使用花括号的方法构建类内初始值。
};

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen& s)//返回类型需要指定类的作用域
{
    screens.push_back(s);
    return screens.size()-1;
}


inline void Window_mgr::clear(ScreenIndex i)
{
	Screen& s = screens[i];
	s.contents = std::string(s.height*s.width,' ');//友元类提供了私有成员的访问接口
}




#endif
