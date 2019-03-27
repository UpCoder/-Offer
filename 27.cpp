//
// Created by 梁栋 on 2019-03-27.
// 二叉树的镜像
//
#include <iostream>
#include <cstring>
#include <string>
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
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL){
            return;
        }
        TreeNode* lChild = pRoot->left;
        TreeNode* rChild = pRoot->right;
        pRoot->left = rChild;
        pRoot->right = lChild;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};

