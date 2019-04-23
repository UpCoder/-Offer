//
// Created by 梁栋 on 2019-03-31.
// 将一颗搜索二叉树转变成排序双向链表
//
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
class Solution {
public:
    void ConvertBase(TreeNode* root, TreeNode** lastNode){
        if(root == NULL)
            return NULL;
        if(root->left){
            ConvertBase(root->left, lastNode);
        }
        root->left = *lastNode;
        if(*lastNode){
            (*lastNode)->right = root;
        }
        (*lastNode) = root;
        if(root->right){
            ConvertBase(root->right, lastNode);
        }
    }
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL)
            return NULL;
        TreeNode* lastNode = NULL;
        ConvertBase(pRootOfTree, &lastNode);
        TreeNode* res = pRootOfTree;
        while (res && res->left){
            res = res->left;
        }
        return res;
    }
};

