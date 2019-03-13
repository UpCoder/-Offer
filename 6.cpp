//
// Created by 梁栋 on 2019-03-12.
//
#include <iostream>
#include "ListNode.cpp"
using namespace std;
class PrintListNodeFromTail2Head{
public:
    static void printListNodeFromTail2Head(ListNode* head){
        if(head == NULL)
            return;
        printListNodeFromTail2Head(head->next);
        cout<<head->val<<"<-";
    }
};
class Solution{
public:
    static void solution(){
        ListNode* listNode = ListNode::ListNodeFromVector({1, 2, 5, 6, 3, 2});
        PrintListNodeFromTail2Head::printListNodeFromTail2Head(listNode);
    }
};