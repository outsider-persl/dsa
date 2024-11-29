#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, std::string> umap;

    // 插入键值对
    umap[1] = "apple";
    umap[2] = "banana";
    umap[3] = "cherry";

    // 遍历输出
    for (const auto& pair : umap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
