#include <iostream>
#include <queue>

int main() {
    // 默认是最大堆
    std::priority_queue<int> pq;

    // 入队
    pq.push(3);
    pq.push(1);
    pq.push(2);

    // 输出优先级队列（按照优先级从高到低输出）
    while (!pq.empty()) {
        std::cout << pq.top() << " "; // 输出堆顶元素
        pq.pop(); // 移除堆顶元素
    }
    std::cout << std::endl;

    return 0;
}
