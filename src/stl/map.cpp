#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> m;

    // 插入键值对
    m[1] = "one";
    m[2] = "two";
    m[3] = "three";

    // 遍历输出
    for (const auto& pair : m) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
