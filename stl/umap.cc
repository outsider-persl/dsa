#include <iostream>
#include <string>
#include <unordered_map>

typedef std::string string;

int main(int argc, char const *argv[]) {
    std::unordered_map<string, int> umap;
    umap.insert({"d", 1});
    auto it = umap.end();
    std::cout << it->first << std::endl;
    return 0;
}
