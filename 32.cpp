//
// Created by 梁栋 on 2019-03-28.
//
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "BinaryTree.cpp"
using namespace std;
class Solution {
public:
    vector<int> PrintFromTopToBottom(BinaryTreeNode* root) {
        vector<int> res;
        queue<BinaryTreeNode* > queue1;
        queue1.push(root);
        while(!queue1.empty()){
            BinaryTreeNode* cur = queue1.front();
            queue1.pop();
            if(cur->lChild != NULL){
                queue1.push(cur->lChild);
            }
            if(cur->rChild != NULL){
                queue1.push(cur->rChild);
            }
            res.push_back(cur->val);
        }
        return res;
    }
    void PrintZHI(BinaryTreeNode* pRoot){
        if(pRoot == NULL)
            return;
        stack<BinaryTreeNode*> stacks[2];
        stacks[0].push(pRoot);
        int cur_level = 0;
        int next_level = 1;
        while(!stacks[0].empty() || !stacks[1].empty()){
            BinaryTreeNode* cur = stacks[cur_level].top();
            stacks[cur_level].pop();
            if(cur_level == 0){
                if(cur->lChild != NULL){
                    stacks[next_level].push(cur->lChild);
                }
                if(cur->rChild != NULL){
                    stacks[next_level].push(cur->rChild);
                }
            }else{
                if(cur->rChild != NULL){
                    stacks[next_level].push(cur->rChild);
                }
                if(cur->lChild != NULL){
                    stacks[next_level].push(cur->lChild);
                }
            }
            cout<<cur->val<<" ";
            if(stacks[cur_level].empty()){
                cur_level = 1 - cur_level;
                next_level = 1 - next_level;
                cout<<""<<endl;
            }
        }
    }
    static void solution(){
        Solution solution1;
        vector<int> preOrder = {1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 12, 13, 7, 14, 15};
        vector<int> inOrder  = {8, 4, 9, 2, 10, 5, 11, 1, 12, 6, 13, 3, 14, 7, 15};
        BinaryTree binaryTree(preOrder, inOrder);
        solution1.PrintZHI(binaryTree.root);
    }
};
