//
// Created by 梁栋 on 2019-02-22.
//
#include "BinaryTree.cpp"
#include <iostream>
using namespace std;
class FindKMinNode: public BinaryTree{
public:
    FindKMinNode(vector<int> preorder, vector<int> inorder): BinaryTree(preorder,inorder){

    }
    BinaryTreeNode* findKMinNode(int k){
        if(k < 0)
            return NULL;
        BinaryTreeNode* node = this->root;
        stack<BinaryTreeNode* > stack1;
        while(node || not stack1.empty()){
            if(node){
                stack1.push(node);
                node = node->lChild;
            }else{
                node = stack1.top();
                stack1.pop();
                k--;
                if(k == 0)
                    return node;
                node = node->rChild;
            }
        }
        return NULL;
    }
};
class Solution{
public:
    static void solution(){
        vector<int> preorder = {5, 3, 2, 4, 7, 6, 8};
        vector<int> inorder = {2, 3, 4, 5, 6, 7, 8};
        FindKMinNode findKMinNode(preorder, inorder);
        BinaryTreeNode* res = findKMinNode.findKMinNode(4);
        cout<<res->val<<endl;
    }
};
