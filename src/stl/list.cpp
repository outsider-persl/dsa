#include <iostream>
#include <list>

int main() {
    std::list<int> lst = {1, 2, 3, 4, 5};
    
    // 插入元素
    lst.push_front(0);  // 在头部插入
    lst.push_back(6);   // 在尾部插入

    // 遍历输出
    for (const auto& val : lst) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 删除元素
    lst.pop_front();  // 删除头部元素
    lst.pop_back();   // 删除尾部元素

    return 0;
}
