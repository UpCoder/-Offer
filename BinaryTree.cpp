//
// Created by 梁栋 on 2019-02-22.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
class BinaryTreeNode{
public:
    int val;
    BinaryTreeNode* lChild;
    BinaryTreeNode* rChild;
    BinaryTreeNode(int x){
        this->val = x;
        this->lChild = NULL;
        this->rChild = NULL;
    }
};
class BinaryTree{
private:
    struct Position{
        int start;
        int end;
        Position(int a,int b){
            this->start = a;
            this->end = b;
        }
    };
    BinaryTreeNode* buildBinaryTree(const vector<int>& preorder, Position pre, const vector<int>& inorder, Position in){
        if(preorder.size() != inorder.size() || (pre.end - pre.start) != (in.end - in.start)){
            cout<<"Error, the size of inorder and preorder are not eauql"<<endl;
            return NULL;
        }
        if(pre.end <= pre.start)
            return NULL;
        BinaryTreeNode* root = new BinaryTreeNode(preorder[pre.start]);
        int split_index = -1;
        for(int i=in.start;i<in.end;i++){
            if(inorder[i] == preorder[pre.start]){
                split_index = i;
                break;
            }
        }
        if(-1 == split_index){
            cout<<"Error, the root(subroot) do not exists in Inorder"<<endl;
            return NULL;
        }
        int number_node_l = split_index - in.start;
        Position pre_l(pre.start + 1, pre.start + number_node_l + 1);
        Position pre_r(pre.start + number_node_l + 1, pre.end);

        Position in_l(in.start, split_index);
        Position in_r(split_index+ 1, in.end);
        cout<<"Cur: "<<pre.start<<"->"<<pre.end<<", "<<in.start<<"->"<<in.end<<"   "<<number_node_l<<endl;
        cout<<"Left: "<<pre_l.start<<"->"<<pre_l.end<<", "<<in_l.start<<"->"<<in_l.end<<"   "<<number_node_l<<endl;
        root->lChild = buildBinaryTree(preorder, pre_l, inorder, in_l);
        root->rChild = buildBinaryTree(preorder, pre_r, inorder, in_r);
        return root;
    }

    int getDepthCore(BinaryTreeNode* node){
        if(node == NULL)
            return 0;
        if(node->lChild == NULL && node->rChild == NULL)
            return 1;
        return max(getDepthCore(node->lChild), getDepthCore(node->rChild)) + 1;
    }

    int getIsBalancedCore(BinaryTreeNode* node, bool& res){
        if(node == NULL)
            return 0;
        if(node->lChild == NULL && node->rChild == NULL)
            return 1;
        if(res == false)
            return 0;
        int depth_l = getIsBalancedCore(node->lChild, res);
        int depth_r = getIsBalancedCore(node->rChild, res);
        if(abs(depth_l - depth_r) > 1)
            res = false;
        return max(depth_l, depth_r) + 1;
    }

    bool getNodePath(BinaryTreeNode* target, BinaryTreeNode* root, stack<BinaryTreeNode*>& res){
        if(root == target){
            res.push(root);
            return true;
        }
        if(root == NULL)
            return false;
        bool l_res = getNodePath(target, root->lChild, res);
        bool r_res = getNodePath(target, root->rChild, res);
        if(l_res || r_res)
            res.push(root);
        return l_res || r_res;
    }
public:
    BinaryTreeNode* root = NULL;
    BinaryTree(vector<int> preorder, vector<int> inorder){
        // 根据前序和中序构建二叉树
        if(preorder.size() != inorder.size()){
            this->root = NULL;
        }else{
            Position pre(0, preorder.size()), in(0, preorder.size());
            this->root = buildBinaryTree(preorder, pre, inorder, in);
        }
    }
    BinaryTree(BinaryTreeNode* x){
        this->root = x;
    }
    void printTree(){
        // 以层次序遍历整棵树，并且打印
        queue<BinaryTreeNode*> queue1;
        queue1.push(this->root);
        int depth = 1;
        int num = 1;
        while(not queue1.empty()){
            BinaryTreeNode* node = queue1.front();
            queue1.pop();
            if(node == NULL){
                num -= 1;
                cout<<"*,";
            }else{
                queue1.push(node->lChild);
                queue1.push(node->rChild);
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
    vector<int> getInorder(){
        vector<int> res;
        stack<BinaryTreeNode* > stack1;
        BinaryTreeNode* node = this->root;
        while(node || not stack1.empty()){
            if(node){
                stack1.push(node);
                node = node->lChild;
            }else{
                node = stack1.top();
                stack1.pop();
                res.push_back(node->val);
                node = node->rChild;
            }
        }
        return res;
    }
    int getDepth(){
        // 获取二叉树的深度
        return getDepthCore(this->root);
    }
    bool isBalanced(){
        // 判断一颗二叉树是不是平衡二叉树
        // 平衡二叉树的左右子树高度不超过1
        bool res = true;
        getIsBalancedCore(this->root, res);
        return res;
    }
    BinaryTreeNode* findNode(int v){
        if(root == NULL)
            return NULL;
        if(root->val == v)
            return root;
        BinaryTree left(this->root->lChild);
        BinaryTree right(this->root->rChild);
        BinaryTreeNode* res = left.findNode(v);
        if(res != NULL)
            return res;
        res = right.findNode(v);
        return res;
    }
    bool isSearch(){
        // 判断这棵树是不是搜索二叉树
        if(this->root == NULL)
            return true;
        if(this->root->lChild != NULL && this->root->val < this->root->lChild->val){
            return false;
        }
        if(this->root->rChild != NULL && this->root->val > this->root->rChild->val){
            return false;
        }
        BinaryTree* left = new BinaryTree(this->root->lChild);
        BinaryTree* right = new BinaryTree(this->root->rChild);
        return left->isSearch() && right->isSearch();
    }
    stack<BinaryTreeNode*> findPath(BinaryTreeNode* target){
        stack<BinaryTreeNode*> res;
        this->getNodePath(target, this->root, res);
        return res;
    }
};
//class Solution{
//public:
//    static void solution(){
//        vector<int> preorder = {5, 3, 2, 4, 7, 6, 8};
//        vector<int> inorder = {2, 3, 4, 5, 6, 7, 8};
//        BinaryTree tree(preorder, inorder);
//        tree.printTree();
//        vector<int> inorder_res = tree.getInorder();
//        for(int i=0;i<inorder_res.size();i++){
//            cout<<inorder_res[i]<<",";
//        }
//        cout<<endl;
//    }
//};