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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(k == 0)
            return NULL;
        ListNode* firstNode = new ListNode(0);
        firstNode->next = pListHead;
        for(int i=0;i<k;i++){
            if(firstNode != NULL)
                firstNode = firstNode->next;
        }
        if(firstNode == NULL)
            return NULL;
        ListNode* res = pListHead;
        while(firstNode->next != NULL){
            firstNode = firstNode->next;
            res =res->next;
        }
        return res;
    }
    static void solution(){

    }
};
