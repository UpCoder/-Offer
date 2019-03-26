//
// Created by 梁栋 on 2019-03-22.
// 二叉树的下一个节点
//
#include <iostream>
#include <vector>
using namespace std;
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        TreeLinkNode* pNext = NULL;
        if(pNode->right != NULL){
            pNext = pNode->right;
            while(pNext->left != NULL){
                pNext = pNext->left;
            }
        }else{
            TreeLinkNode* pParent = pNode->next;
            if(pParent != NULL){
                TreeLinkNode* pCurrent = pNode;
                while(pParent != NULL && pParent->right == pCurrent){
                    pCurrent = pParent;
                    pParent = pCurrent->next;
                }
                pNext = pParent;
            }
        }
        return pNext;
    }
    static void solution(){

    }
};