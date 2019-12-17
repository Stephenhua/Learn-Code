#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    int flag = 1; 
    Node* connect(Node* root) {
        if(!root)return nullptr;
        if(flag){  // 将根节点next置为null
            root->next = nullptr;
            flag = 0;
        } 
        if(!root->left) return root;
        root->left->next = root->right;
        if(root->next)root->right->next = root->next->left;
        else root->right->next = nullptr;
        connect(root->left);
        connect(root->right);
        return root;
    }
};