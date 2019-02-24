//
// Created by 梁栋 on 2019-02-24.
//
#include <iostream>
#include <vector>
#include "ListNode.cpp"
using namespace std;
class FindLastestNumber{
    // 在长度为n的数组中，每次删除第m个元素，剩下最后一个元素的值
public:
    static ListNode* findLastestNode(ListNode* head, int n, int m){
        // 首先构成一个循环链表，再开始模拟
        ListNode* pHead = head;
        // 找打结尾的节点
        while (pHead->next != NULL)
            pHead = pHead->next;
        pHead->next = head;
        ListNode* last = pHead;
        ListNode* start = head;
        for(int i=0;i<n-1;i++){
            // 剩下一个节点
            ListNode* cur = last;
            for(int j=0;j<m-1;j++){
                cur = cur->next;
            }
            // 删除cur->next节点
            // cout<<cur->next->val<<" will be deleted"<<endl;
            cur->next = cur->next->next;
            last = cur;
        }
        return last;
    }
    static ListNode* findLastestNode_V2(ListNode* head, int n, int m){
        if(m == 0){
            return head;
        }
        if(n == 1){
            return new ListNode(0);
        }
        int last = 0;
        for(int i=2;i<n;i++){
            last = (last + m) % i;
        }
        cout<<"last is "<<last<<endl;
        return new ListNode(last);
    }
};
class Solution{
public:

    static void solution(){
        int n = 10000;
        int m = 100000;
        vector<int> nums;
        for(int i=0;i<n;i++)
            nums.push_back(i);

        ListNode* head = ListNode::ListNodeFromVector(nums);
        ListNode* last = FindLastestNumber::findLastestNode(head, n, m);
        cout<<last->val<<endl;
        FindLastestNumber::findLastestNode_V2(head, n, m);
    }
};