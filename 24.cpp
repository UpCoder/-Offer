//
// Created by 梁栋 on 2019-03-27.
//
#include <iostream>
#include <cstring>
#include <string>
#include "ListNode.cpp"
using namespace std;
class Solution{
public:
    ListNode* ReverseListBase(ListNode* pHead, ListNode* & res){
        if(pHead->next == NULL){
            res = pHead;
            return pHead;
        }
        ListNode* last = ReverseListBase(pHead->next, res);
        last->next = pHead;
        return pHead;
    }
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL || pHead->next == NULL)
            return pHead;
        ListNode* res;
        ListNode* new_head = ReverseListBase(pHead, res);
        new_head->next = NULL;
        return res;
    }
    static void solution(){
        Solution solution1;
        ListNode* listNode = ListNode::ListNodeFromVector({0, 1, 2, 3, 4, 5});
        ListNode* reversed = solution1.ReverseList(listNode);
        reversed->print();
    }
};
