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
    static ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL)
            return NULL;
        ListNode* cur = pHead;
        ListNode* new_head = pHead;
        ListNode* previousNode = NULL;
        while(cur->next != NULL){
            if(cur->val == cur->next->val){
                ListNode* last = cur->next;
                while(last != NULL && last->val == cur->val){
                    last = last->next;
                }
                if(previousNode == NULL){
                    if(last == NULL)
                        return NULL;
                    cur = last;
                    new_head = cur;
                }else{
                    previousNode->next = last;
                    if(last == NULL)
                        return new_head;
                    cur = last;
                }
            }else{
                previousNode = cur;
                cur = cur->next;
            }
        }

        return new_head;
    }
    static void deleteNode(ListNode** pListNode, ListNode* pToBeDeleted){
        // 总体来说思路是找到next，使用next的元素替换当前的节点
        if(*pListNode == NULL)
            return;
        if((*pListNode)->next == NULL){
            (*pListNode) = NULL;
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
        ListNode* head = ListNode::ListNodeFromVector({0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5});
//        ListNode* pToBeDeleted = head;
//        ListNode** pHead = &head;
//        DeleteNode::deleteNode(pHead, pToBeDeleted);
//        head->print();
        ListNode* res  = DeleteNode::deleteDuplication(head);
        if(res == NULL){
            cout<<"res is NULL"<<endl;
        }else{
            res->print();
        }
    }
};