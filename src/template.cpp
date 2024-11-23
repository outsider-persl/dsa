// clang++ c++ modules
#include <iostream>
#include <vector>

template <typename T>
void getTypeName(const T& varibale);

template <typename T>
void printVector(const std::vector<T>& vec) {
    getTypeName(vec);
    for (const T& elem : vec) {
        getTypeName(elem);
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
void getTypeName(const T& varibale) {
    // f: float, i: int, d: double, c: char, etc
    std::cout << typeid(varibale).name() << std::endl;
}

int main(int argc, char const* argv[]) {
    std::vector vecs = {1, 2, 3};
    printVector(vecs);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
