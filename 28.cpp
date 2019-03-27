//
// Created by 梁栋 on 2019-03-27.
// 对称的二叉树
//
#include <vector>
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
    bool isSymmetricalBase(TreeNode* pRoot1, TreeNode pRoot2){
        if(pRoot1 == NULL && pRoot2 == NULL)
            return true;
        if(pRoot1 == NULL || pRoot2 == NULL)
            return false;
        if(pRoot1->val != pRoot2->val)
            return false;
        return isSymmetricalBase(pRoot1->left, pRoot2->right)
        && isSymmetricalBase(pRoot1->right, pRoot2->left);
    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == NULL)
            return true;
        return isSymmetricalBase(pRoot, pRoot);

    }

};

