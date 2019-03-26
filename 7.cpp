//
// Created by 梁栋 on 2019-03-22.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution{
public:
    TreeNode* reConstructBinaryTreeBase(vector<int> pre, vector<int> vin, int s_pre, int e_pre, int s_in, int e_in){
        TreeNode* root = new TreeNode(pre[s_pre]);
        if(s_pre > e_pre || s_in > e_in)
            return NULL;
        if(s_pre == e_pre)
            return root;
        int target = pre[s_pre];
        int vin_index = s_in;
        for(int i=s_in;i<=e_in;i++){
            if(vin[i] == target){
                vin_index = i;
            }
        }
        int len = vin_index - s_in;
        int new_s_pre = s_pre + 1;
        int new_e_pre = new_s_pre + (len-1);
        int new_s_in = s_in;
        int new_e_in = vin_index - 1;
        cout<<new_s_pre<<","<<new_e_pre<<";"<<new_s_in<<","<<new_e_in<<endl;
        root->left = reConstructBinaryTreeBase(pre, vin, new_s_pre, new_e_pre, new_s_in, new_e_in);
        new_s_pre = new_e_pre + 1;
        new_e_pre = e_pre;
        new_s_in = vin_index + 1;
        new_e_in = e_in;
        cout<<new_s_pre<<","<<new_e_pre<<";"<<new_s_in<<","<<new_e_in<<endl;
        root->right = reConstructBinaryTreeBase(pre, vin, new_s_pre, new_e_pre, new_s_in, new_e_in);
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return reConstructBinaryTreeBase(pre, vin, 0, int(pre.size()-1), 0, int(vin.size()-1));
    }
    static void solution(){
        vector<int> pre = {1,2,4,7,3,5,6,8};
        vector<int> in = {4,7,2,1,5,3,8,6};
        Solution solution1;
        TreeNode* root = solution1.reConstructBinaryTree(pre, in);
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()){
            TreeNode* cur = nodes.front();
            nodes.pop();
            if(cur->left != NULL)
                nodes.push(cur->left);
            if(cur->right != NULL)
                nodes.push(cur->right);
            cout<<cur->val<<endl;
        }

    }
};
