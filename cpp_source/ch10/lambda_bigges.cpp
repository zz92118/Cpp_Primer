#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// 在vector中寻找第一个大于等于给定长度的元素。找到后根据位置计算有多少元素的长度大于等于给定值。
// from ex 10.9
template<typename Sequence>
inline std::ostream& println(Sequence const& seq)
{
    for(auto const& elem : seq) std::cout << elem << " ";
    std::cout << std::endl;

    return std::cout;
}


void elimdups(std::vector<std::string> &vs)
{
    std::sort(vs.begin(), vs.end());
    auto new_end = std::unique(vs.begin(), vs.end());
    vs.erase(new_end, vs.end());
}

void biggies(std::vector<std::string> &vs, std::size_t sz)
{
    using std::string;

    elimdups(vs);

    println(vs);

    // sort by size, but maintain alphabetical order for same size.
    std::stable_sort(vs.begin(), vs.end(), [](string const& lhs, string const& rhs){
        return lhs.size() < rhs.size();
    });
    println(vs);

    // get an iterator to the first one whose size() is >= sz
    auto wc = std::find_if(vs.begin(), vs.end(), [sz](string const& s){
            return s.size() >= sz;
    });
    println(vs);
        
    // print the biggies 调用此对象
    std::for_each(wc, vs.end(), [](const string &s){
        std::cout << s << " ";
    }); 
}

int main()
{
    // ex10.16
    std::vector<std::string> v
    {
        "1234","1234","1234","hi~", "alan", "alan", "cp"
    };
    std::cout << "ex10.16: "<<std::endl;
    biggies(v, 3);// 先进行排序
    std::cout << std::endl;

    return 0;
}