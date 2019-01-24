#ifndef TREENODE
#define TREENODE

#include <LeetCodeConfig.h>
#include <stack>
template <typename T>
struct TreeNode {
    T val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T t):
        val(t), left(nullptr), right(nullptr)
    {

    }
};

typedef TreeNode<int> TreeNodeInt;

template <typename T>
TreeNode<T>* createTree(TreeNode<T>* node, T t)
{
    if (node == nullptr) {
        printf("createTree null\n");
        node = new TreeNode<T>(t);
        node->val = t;
        return node;
    }

    if (node->val > t) {
        printf("createTree left = %d, insert = %d \n", node->val, t);
        node->left = createTree(node->left, t);
    }
    else if (node->val < t) {
        printf("createTree right = %d, insert = %d \n", node->val, t);
        node->right = createTree(node->right, t);
    }
    return node;
}
//4 1 3 2 5


void PreorderTraversal(TreeNodeInt* root) {
    std::cout<<"Preorder Traversal"<<std::endl;
    std::stack<TreeNode<int>*> stack;
    if (root == nullptr) {
        return;
    }
    TreeNode<int>* node = nullptr;
    stack.push(root);
    while (!stack.empty()) {
        node = stack.top();
        stack.pop();
        std::cout<<node->val<<" , ";
        if (node->right) {
            stack.push(node->right);
        }

        if (node->left) {
            stack.push(node->left);
        }
    }
    std::cout<<std::endl;
}

void PostTraversal(TreeNodeInt* root)
{
    std::cout<<"Post Traversal"<<std::endl;
    std::stack<TreeNode<int>*> stack;
    std::vector<int> vec;
    if (root == nullptr) {
        return;
    }
    TreeNode<int>* node = nullptr;
    stack.push(root);

    while (!stack.empty()) {
        node = stack.top();
        stack.pop();

        vec.insert(vec.begin(), node->val);
        if (node->left) {
            stack.push(node->left);
        }
        if (node->right) {
            stack.push(node->right);
        }
    }

    for (int v : vec) {
        std::cout<<v<<" , ";
    }
    std::cout<<std::endl;
}

void SequenceTraversal(TreeNodeInt* root)
{
    std::cout<<"Sequence Traversal"<<std::endl;
    std::queue<TreeNodeInt*> q;
    if (root == nullptr) return;
    TreeNodeInt* node = nullptr;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            node = q.front();
            q.pop();
            std::cout<<node->val<<" , ";
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }
        std::cout<<std::endl;
        std::cout<<"----------"<<std::endl;
    }
}

#endif // TREENODE

