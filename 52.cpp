//
// Created by 梁栋 on 2019-02-19.
//
#include "ListNode.cpp"
#include <iostream>
#include <stack>
using namespace std;
class FindFirstCommonNode{
public:
    static ListNode* findFirstCommonNode_1(ListNode* pHead1, ListNode* pHead2){
        int length1 = ListNode::get_length(pHead1);
        int length2 = ListNode::get_length(pHead2);
        ListNode* pHeadLong;
        ListNode* pHeadShort;
        if(length1 > length2){
            pHeadLong = pHead1;
            pHeadShort = pHead2;
        }else{
            pHeadLong = pHead2;
            pHeadShort = pHead1;
        }
        int diff = abs(length1 - length2);
        while(diff--){
            pHeadLong = pHeadLong->next;
        }
        while(pHeadLong != NULL && pHeadShort != NULL && pHeadLong != pHeadShort){
            pHeadLong = pHeadLong->next;
            pHeadShort = pHeadShort->next;
        }
        return pHeadLong;
    }
    static ListNode* findFirstCommonNode(ListNode* pHead1, ListNode* pHead2){
        if(pHead1 == NULL || pHead2 == NULL){
            return NULL;
        }
        stack<ListNode*> stack1;
        stack<ListNode*> stack2;
        while(pHead1 != NULL){
            stack1.push(pHead1);
            pHead1 = pHead1->next;
        }
        while(pHead2 != NULL){
            stack2.push(pHead2);
            pHead2 = pHead2->next;
        }
        if(stack1.top() != stack2.top()){
            return NULL;
        }
        ListNode* res = stack1.top();
        while(stack1.top() == stack2.top()){
            res = stack1.top();
            stack1.pop();
            stack2.pop();
        }
        return res;
    }
};
class Solution{
public:
    static void solution(){
        ListNode* node1 = new ListNode();
        node1->value = 1;
        ListNode* node2 = new ListNode();
        node2->value = 2;
        ListNode* node3 = new ListNode();
        node3->value = 3;
        ListNode* node4 = new ListNode();
        node4->value = 4;
        ListNode* node5 = new ListNode();
        node5->value = 5;
        ListNode* node6 = new ListNode();
        node6->value = 6;
        ListNode* node7 = new ListNode();
        node7->value = 7;

        node1->next = node2;
        node2->next = node3;
        node3->next = node6;
        node6->next = node7;
        node4->next = node5;
        node5->next = node6;
        ListNode* firstCommonNode = FindFirstCommonNode::findFirstCommonNode_1(node1, node4);
        cout<<"first common node is "<<firstCommonNode->value<<endl;
    }
};
