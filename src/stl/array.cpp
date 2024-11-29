#include <iostream>
#include <array>

int main() {
    std::array<int, 5> arr = {1, 2, 3, 4, 5};

    // 访问元素
    for (const auto& val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
