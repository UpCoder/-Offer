//
// Created by 梁栋 on 2019-03-27.
//
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class Solution {
public:
    ListNode* isCircleNode(ListNode* pHead){
        ListNode* slowNode = pHead;
        if(pHead == NULL)
            return NULL;
        ListNode* fastNode = pHead->next;
        while(fastNode != NULL && slowNode != NULL){
            if(fastNode == slowNode)
                return slowNode;
            slowNode = slowNode->next;
            fastNode = fastNode->next;
            if(fastNode == NULL)
                return NULL;
            fastNode = fastNode->next;
        }
        return NULL;
    }
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* meetNode = isCircleNode(pHead);
        if(meetNode == NULL)
            return NULL;
        int circle_number = 1;
        ListNode* start = meetNode;
        while(start->next != meetNode){
            circle_number += 1;
            start = start->next;
        }
        ListNode* first = pHead;
        ListNode* second = pHead;
        for(int i=0;i<circle_number;i++){
            first = first->next;
        }
        while(first != seoncd){
            first = first->next;
            second = second->next;
        }
        return second;
    }
};