#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main()
{
	int n = 5;
	allocator<string> alloc;
	auto p = alloc.allocate(n);// p q 是迭代器
	string s;
	auto q = p;
	while (cin >> s && q != p + n)
	{
		alloc.construct(q++, s);// s是字符串 需要初始化
	}
	while (q != p)
	{
		std::cout << *--q << " ";
		alloc.destroy(q);// 必须销毁
	}
	alloc.deallocate(p, n);

	return 0;
}