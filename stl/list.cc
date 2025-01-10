#include <iostream>
#include <list>

int main(int argc, char const *argv[]) {
    std::list<int> l;

    l.push_front(1);
    l.push_back(2);
    l.push_front(0);

    for (auto &&i : l) {
        std::cout << i << " ";
    }

    std::cout << std::endl;
    std::cout << "front: " << l.front();
    std::cout << "tail: " << l.back();
    std::cout << l.size() << std::endl;
    
    return 0;
}
