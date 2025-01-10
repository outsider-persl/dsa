#include <iostream>

int main(int argc, char const *argv[]) {
    auto a = 1;
    auto b = 2;
    auto add = [=](int x, int y) { return a * x + b * y; };
    std::cout << add(2, 2) << std::endl;
    a++;
    b++;
    std::cout << add(2, 2) << std::endl;
    return 0;
}
