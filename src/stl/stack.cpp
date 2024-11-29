#include <iostream>
#include <stack>

int main() {
    std::stack<int> stk;

    // 入栈
    stk.push(1);
    stk.push(2);
    stk.push(3);

    // 出栈
    while (!stk.empty()) {
        std::cout << stk.top() << " "; // 输出栈顶元素
        stk.pop(); // 移除栈顶元素
    }
    std::cout << std::endl;

    return 0;
}
