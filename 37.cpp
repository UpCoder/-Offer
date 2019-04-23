//
// Created by 梁栋 on 2019-04-09.
// 序列化和反序列化二叉树
//
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
    void printTree(){
        // 以层次序遍历整棵树，并且打印
        queue<TreeNode*> queue1;
        queue1.push(this);
        int depth = 1;
        int num = 1;
        while(not queue1.empty()){
            TreeNode* node = queue1.front();
            queue1.pop();
            if(node == NULL){
                num -= 1;
                cout<<"*,";
            }else{
                queue1.push(node->left);
                queue1.push(node->right);
                cout<<node->val<<",";
                num -= 1;
            }
            if(num == 0){
                depth += 1;
                num = 1 << (depth-1);
                cout<<endl;
            }
        }
        cout<<endl;
    }
};

class Solution {
public:
    void SerializeBase(TreeNode* root, string& res){
        if(root != NULL){
            res += ('0' + root->val);
            res += ',';
        }else{
            res += "$,";
            return;
        }
        SerializeBase(root->left, res);
        SerializeBase(root->right, res);
    }
    char* Serialize(TreeNode *root) {
        string res = "";
        SerializeBase(root, res);
        return (char*) res.substr(0, res.length()-1).c_str();
    }
    TreeNode* DeserializeBase(char*& str){
        if(*str == '$' || *str == '\0')
            return NULL;
        TreeNode* cur = new TreeNode(int(*str - '0'));
        str += 1;
        cur->left = DeserializeBase(str);
        str += 1;
        cur->right = DeserializeBase(str);
        return cur;
    }
    TreeNode* Deserialize(char *str) {
        return DeserializeBase(str);
    }
    static void solution(){
        Solution solution1;
        string str = "124$$$35$$6$$";
        TreeNode* root = solution1.Deserialize((char*) str.c_str());
        root->printTree();
    }
};

