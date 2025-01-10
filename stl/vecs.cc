#include <iostream>
#include <vector>

void update(std::vector<int>&& v) { v.push_back(-1); }

int main(int argc, char const* argv[]) {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = std::move(vec1);
    vec2.push_back(3);
    std::cout << "vec1 size: " << vec1.size() << std::endl;  // 输出 0
    std::cout << "vec2 size: " << vec2.size() << std::endl;  // 输出 5

    std::cout << "vec1 address: " << &vec1 << std::endl;  // 输出 0
    std::cout << "vec2 address: " << &vec2 << std::endl;  // 输出 5
    return 0;

    return 0;
}
