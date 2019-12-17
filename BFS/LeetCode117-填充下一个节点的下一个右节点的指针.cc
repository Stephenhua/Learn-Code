#include <vector>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;



class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


//解法一：采用广度优先的算法进行求解；
class Solution {
public:
    Node* connect(Node* root) {
        
      //判断当前截止条件
        if (root==nullptr)
        {
            return root ;
            /* code */
        }

        queue<Node*> temp_queue;
        temp_queue.push(root);
        while(!temp_queue.empty()){
            int size=temp_queue.size();
            
            Node *pre=nullptr;
            
            for(int i=0;i<size;i++){
                Node *cur= temp_queue.front();
                temp_queue.pop();
                
                if(pre!=nullptr){
                    pre->next=cur;
                }
                pre=cur;
                if(cur->left!=nullptr){
                    temp_queue.push(cur->left);
                }
                if(cur->right!=nullptr){
                    temp_queue.push(cur->right);
                }
            }

        }
        return root; 
        
    }
};