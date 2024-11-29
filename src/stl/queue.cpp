#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;

    // 入队
    q.push(1);
    q.push(2);
    q.push(3);

    // 出队
    while (!q.empty()) {
        std::cout << q.front() << " "; // 输出队头元素
        q.pop(); // 移除队头元素
    }
    std::cout << std::endl;

    return 0;
}
