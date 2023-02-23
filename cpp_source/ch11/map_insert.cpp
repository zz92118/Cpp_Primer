#include <iostream>
#include <map>
#include <string>

using namespace std;

int test()
{
    map<int,int> m;
    m.insert({1,1});
    m.insert({1,2});
    m.insert({1,1});
    m.insert({2,1});
    for(auto i = m.begin(); i!=m.end(); i++)
    {
        cout<<i->first<<" "<<i->second<<endl;
    }
}

int main()
{
	map<string, size_t> counts;
	for (string word; cin >> word;)
	{
		auto result = counts.insert({ word, 1 });
		if (!result.second)
			++result.first->second;//insert 返回<string,size>map迭代器，解引用得到second成员，最后++自增操作
	}
	for (auto const& count : counts)
		cout << count.first << " " << count.second << ((count.second > 1) ? " times\n" : " time\n");

	return 0;
}