#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

int main(int argc, char const *argv[]) {
    TreeNode root{1, nullptr, nullptr};
    cout << root.val << endl;
    return 0;
}
