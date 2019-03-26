//
// Created by 梁栋 on 2019-03-16.
//

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
#include <iostream>
#include "ListNode.cpp"
class Solution {
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
        ListNode* listNode = ListNode::ListNodeFromVector({1, 2, 3, 4, 5});
        Solution solution1;
        ListNode* res = solution1.FindKthToTail(listNode, 1);
        if(res != NULL){
            cout<<res->val<<endl;
        }else{
            cout<<"NULL"<<endl;
        }
    }
};