//
// Created by 梁栋 on 2019-03-16.
//

#include "ListNode.cpp"
#include <iostream>
using namespace std;
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* res = new ListNode(0);
        ListNode* saved_res = res;
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
        }else{
            if(pHead2 != NULL){
                res->next = pHead2;
            }
        }
        return saved_res->next;
    }
    static void solution(){
//        ListNode* listNode = ListNode::ListNodeFromVector({1, 2, 4,6, 7,9});
//        ListNode* listNode1 = ListNode::ListNodeFromVector({3, 4, 5, 8, 9, 10});
//        Solution solution1;
//        ListNode* res = solution1.Merge(listNode, listNode1);
//        res->print();
        int data[21];
        data[0] = 0;
        data[1] = 1;
        data[2] = 1;
        data[3] = 2;
        for(int i=3;i<21;i++){
            data[i] = data[i-1] + data[i-3];
            cout<<data[i]<<endl;
        }
        cout<<data[20]<<endl;

    }
};