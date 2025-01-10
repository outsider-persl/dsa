#include <iostream>

class Buffer {
   private:
    int size;
    int* address;

   public:
    // 构造函数
    Buffer(int bufferSize) : size(bufferSize), address(new int[bufferSize]) {
        std::cout << " constructor\n";
        *address = bufferSize;
    }

    // 复制构造函数
    Buffer(const Buffer& other) : size(other.size), address(new int[other.size]) {
        std::cout << " copy constructor\n";
        for (int i = 0; i < size; ++i) {
            address[i] = other.address[i];
        }
    }

    // 复制赋值运算符
    Buffer& operator=(const Buffer& other) {
        std::cout << " copy assignment\n";
        if (this != &other) {
            delete[] address;
            size = other.size;
            address = new int[other.size];
            for (int i = 0; i < size; ++i) {
                address[i] = other.address[i];
            }
        }
        return *this;
    }

    // 移动构造函数
    Buffer(Buffer&& other) noexcept : size(other.size), address(other.address) {
        std::cout << " move constructor\n";
        other.size = 0;
        other.address = nullptr;
    }

    // 移动赋值运算符
    Buffer& operator=(Buffer&& other) noexcept {
        std::cout << " move assignment\n";
        if (this != &other) {
            delete[] address;
            size = other.size;
            address = other.address;
            other.size = 0;
            other.address = nullptr;
        }
        return *this;
    }

    // 析构函数
    ~Buffer() {
        std::cout << " destructor\n";
        delete[] address;
    }
};

int main() {
    Buffer b1(10);
    auto b2(b1);
    auto b3 = b1;
    b3 = b2;
    return 0;
}