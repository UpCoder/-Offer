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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
        ListNode* res = new ListNode(0);
        ListNode* res_head = res;
        while(pHead1 != NULL && pHead2 != NULL){
            if(pHead1->val < pHead2->val){
                res->next = pHead1;
                res = res->next;
                pHead1 = pHead1->next;
            }else{
                res->next = pHead2;
                res = res->next;
                pHead2 = pHead2->next;
            }
        }
        if(pHead1 != NULL){
            res->next = pHead1;
        }
        if(pHead2 != NULL){
            res->next = pHead2;
        }
        return res_head->next;
    }
    static void solution(){
        ListNode* listNode1 = ListNode::ListNodeFromVector({0, 1, 3, 6, 9});
        ListNode* listNode2 = ListNode::ListNodeFromVector({2, 3 ,5, 7, 10});
        Solution solution1;
        ListNode* res = solution1.Merge(listNode1, listNode2);
        res->print();
    }
};
