//
// Created by 梁栋 on 2019-03-30.
// 二叉树中和为某一值的路径
//
#include <iostream>
#include <vector>
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
    void FindPathBase(TreeNode* root, int expectNumber, int curSum, vector<int > curList, vector<vector<int> >& res){
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL){
            if(curSum + root->val == expectNumber){
                curList.push_back(root->val);
                res.push_back(curList);
            }
            return;
        }
        if(root->left != NULL){
            curList.push_back(root->val);
            FindPathBase(root->left, expectNumber, curSum + root->val, curList, res);
            curList.pop_back();

        }
        if(root->right != NULL){
            curList.push_back(root->val);
            FindPathBase(root->right, expectNumber, curSum + root->val, curList, res);
            curList.pop_back();
        }
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int > > res;
        FindPathBase(root, expectNumber, 0, {}, res);
        return res;
    }
    static void solution(){

    }
};