//
// Created by 梁栋 on 2019-03-16.
//

#include "ListNode.cpp"
#include <iostream>
using namespace std;
class Solution {
public:
    ListNode* ReverseListBase(ListNode* pHead, ListNode*& res){
        if(pHead->next == NULL){
            res = pHead;
            return pHead;
        }
        ListNode* next = ReverseListBase(pHead->next, res);
        next->next = pHead;
        return pHead;
    }
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL)
            return NULL;
        ListNode* res = NULL;
        pHead = ReverseListBase(pHead, res);
        pHead->next = NULL;

        return res;
    }
    static void solution(){
        Solution solution1;
        ListNode* listNode = ListNode::ListNodeFromVector({1, 2});
        listNode = solution1.ReverseList(listNode);
        listNode->print();
    }
};