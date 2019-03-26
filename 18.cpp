//
// Created by 梁栋 on 2019-03-26.
//
#include "ListNode.cpp"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class DeleteNode{
public:
    static void deleteNode(ListNode** pListNode, ListNode* pToBeDeleted){
        // 总体来说思路是找到next，使用next的元素替换当前的节点
        if(*pListNode == NULL)
            return;
        if((*pListNode)->next == NULL){
            *pListNode = NULL;
            delete pToBeDeleted;
            return;
        }
        ListNode* head = *pListNode;
        if(pToBeDeleted->next == NULL){
            // 待删除的是最后一个元素，则必须从投到尾查找删除
            while(head->next != pToBeDeleted){
                head = head->next;
            }
            head->next = NULL;
            delete pToBeDeleted;
        }else{
            // 不是最后一个元素
            ListNode* next = pToBeDeleted->next;
            pToBeDeleted->val = next->val;
            pToBeDeleted->next = next->next;
            delete(next);
        }
    }
};
class Solution{
public:
    static void solution(){
        ListNode* head = ListNode::ListNodeFromVector({0, 1, 2, 3, 4});
        ListNode* pToBeDeleted = head;
        ListNode** pHead = &head;
        DeleteNode::deleteNode(pHead, pToBeDeleted);
        head->print();
    }
};