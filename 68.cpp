//
// Created by 梁栋 on 2019-02-24.
//
#include "BinaryTree.cpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class FindParent{
// 找到树里面任意两个节点的最低公公祖先
private:
    static BinaryTreeNode* findCommonParentSearchBinary(BinaryTreeNode* node1, BinaryTreeNode* node2, BinaryTree* binaryTree){
        BinaryTreeNode* res = binaryTree->root;
        int min_value = min(node1->val, node2->val);
        int max_value = max(node1->val, node2->val);
        while (true){
            if(res->val > min_value && res->val < max_value)
                return res;
            if(res->val > min_value && res->val > max_value)
                res = res->lChild;
            if(res->val < min_value && res->val < max_value)
                res = res->rChild;
        }
    }
    static BinaryTreeNode* findCommonParent_V2(BinaryTreeNode* node1, BinaryTreeNode* node2, BinaryTree* binaryTree){
        stack<BinaryTreeNode*> path1 = binaryTree->findPath(node1);
        cout<<"The number of node in the path1 is "<<path1.size()<<endl;
        stack<BinaryTreeNode*> path2 = binaryTree->findPath(node2);
        cout<<"The number of node in the path2 is "<<path2.size()<<endl;
        BinaryTreeNode* res;
        while(!path1.empty() && !path2.empty()){
            if(path1.top() == path2.top()){
                res = path1.top();
                path1.pop();
                path2.pop();
            }else{
                break;
            }
        }
        return res;
    }
    static BinaryTreeNode* findCommonParent_V1(BinaryTreeNode* node1, BinaryTreeNode* node2, BinaryTree* binaryTree){
        BinaryTreeNode* res;
        queue<BinaryTreeNode*> queue2;
        queue2.push(binaryTree->root);
        while (!queue2.empty()){
            BinaryTreeNode* cur = queue2.front();
            queue2.pop();
            if(cur == NULL)
                continue;
            queue<BinaryTreeNode*> queue1;
            bool find_node1 = false;
            bool find_node2 = false;
            queue1.push(cur);
            while(!queue1.empty()){
                BinaryTreeNode* node = queue1.front();
                queue1.pop();
                if(node == node1)
                    find_node1 = true;
                if(node == node2)
                    find_node2 = true;
                if(node->lChild)
                    queue1.push(node->lChild);
                if(node->rChild)
                    queue1.push(node->rChild);
            }
            if(find_node1 && find_node2){
                res = cur;
                queue2.push(cur->lChild);
                queue2.push(cur->rChild);
            }
        }
        return res;
    }
public:
    static void findParent(BinaryTreeNode* node1, BinaryTreeNode* node2, BinaryTree* binaryTree, bool isSearch){
        if(isSearch){
            BinaryTreeNode* res = findCommonParentSearchBinary(node1, node2, binaryTree);
            cout<<"Node value: "<<res->val<<endl;
        }else{
            BinaryTreeNode* res = findCommonParent_V2(node1, node2, binaryTree);
            cout<<"Node value: "<<res->val<<endl;
        }
    }
};
class Solution{
public:
    static void solution(){
        vector<int> inorder = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> preorder = {8, 4, 2, 1, 3, 6, 5, 7, 9};
        BinaryTree* binaryTree = new BinaryTree(preorder, inorder);
        binaryTree->printTree();
        cout<<"ok"<<endl;
        BinaryTreeNode* node1 = binaryTree->findNode(6);
        cout<<node1->val<<endl;
        BinaryTreeNode* node6 = binaryTree->findNode(1);
        cout<<node6->val<<endl;
        if(node6->lChild != NULL){
            cout<<"left: "<< node6->lChild->val<<endl;
        }else{
            cout<<"left: NULL"<<endl;
        }
        if(node6->rChild != NULL){
            cout<<"right: "<< node6->rChild->val<<endl;
        }else{
            cout<<"right: NULL"<<endl;
        }
        cout<<"Is Search BinaryTree?"<<binaryTree->isSearch()<<endl;
        FindParent::findParent(node1, node6, binaryTree, false);

    }
};
