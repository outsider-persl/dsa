#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // 向后追加元素
    vec.push_back(6);
    

    // 访问元素
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 随机访问
    std::cout << "Element at index 2: " << vec[2] << std::endl;

    return 0;
}
