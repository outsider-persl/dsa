#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* create(int data, Node* left, Node* right) {
    Node* node = new Node{
        data, left, right};
    return node;
}
void preorderTraversal(Node* node) {
    if (node != nullptr) {
        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}
void inorderTraversal(Node* node) {
    if (node != nullptr) {
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }
}

void postorderTraversal(Node* node) {
    if (node != nullptr) {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }
}
int main(int argc, char const* argv[]) {
    Node* root = create(0, nullptr, nullptr);
    Node* n1 = create(1, nullptr, nullptr);
    Node* n2 = create(2, nullptr, nullptr);
    Node* n3 = create(3, nullptr, nullptr);
    Node* n4 = create(4, nullptr, nullptr);
    Node* n5 = create(5, nullptr, nullptr);
    Node* n6 = create(6, nullptr, nullptr);
    Node* n7 = create(7, nullptr, nullptr);
    Node* n8 = create(8, nullptr, nullptr);

    // 将节点插入到树中
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->right = n5;
    n4->left = n6;
    n4->right = n7;
    n7->left = n8;

    inorderTraversal(root);
    cout << endl;
    preorderTraversal(root);
    cout << endl;
    postorderTraversal(root);
    return 0;
}
