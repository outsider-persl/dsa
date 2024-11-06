#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n, vector<int>& memo) {
    if (n <= 1) {
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    return memo[n];
}

int main() {
    int n;
    cout << "请输入 n：";
    cin >> n;
    vector<int> memo(n + 1, -1);
    cout << "Fibonacci(" << n << ") = " << fibonacci(n, memo) << endl;

    // 0 1 1 2 3 5 8 13 21 34 55 89
    return 0;
}
