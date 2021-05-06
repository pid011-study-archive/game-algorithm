#include <iostream>
#include <vector>

int SearchInt(std::vector<int>& sources, int target)
{
    for (int i = 0; i < sources.size(); i++)
    {
        if (sources[i] == target) return i;
    }

    return -1;
}

int main()
{
    std::vector<int> sources { 1, 6, 2, 3, 4, 10 };

    for (auto& i: sources)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    int idx = SearchInt(sources, 4);

    if (idx == -1)
        std::cout << "4가 배열에 존재하지 않음" << std::endl;
    else
        std::cout << "4는 " << idx << "번째에 위치함" << std::endl;
}
