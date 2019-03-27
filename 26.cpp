//
// Created by 梁栋 on 2019-03-27.
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
class Solution{
public:
    bool isSubTree(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot2 == NULL)
            return true;
        if(pRoot1 == NULL)
            return false;
        if(pRoot1->val != pRoot2->val){
            return false;
        }
        return isSubTree(pRoot1->left, pRoot2->left) && isSubTree(pRoot1->right, pRoot2->right);
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == NULL || pRoot2 == NULL)
            return false;
        bool result = false;
        if(pRoot1->val == pRoot2->val){
            result = isSubTree(pRoot1, pRoot2);
        }
        if(!result){
            result = HasSubtree(pRoot1->left, pRoot2);
        }
        if(!result){
            result = HasSubtree(pRoot1->right, pRoot2);
        }
        return result;

    }
    static void solution(){

    }
};
