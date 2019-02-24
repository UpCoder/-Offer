//
// Created by 梁栋 on 2019-02-19.
//
#include <vector>
#include <iostream>
using namespace std;
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    static ListNode* ListNodeFromVector(vector<int> xs){
        ListNode* res = new ListNode(0);
        ListNode* head = res;
        for(int i=0;i<xs.size();i++){
            head->next = new ListNode(xs[i]);
            head = head->next;
        }
        return res->next;
    }
    void print(){
        ListNode* head = this;
        while(head != NULL){
            cout<<head->val<<"->";
            head = head->next;
        }
        cout<<endl;
    }
    static int get_length(ListNode* head){
        int length = 0;
        while(head != NULL){
            head = head->next;
            length += 1;
        }
        return length;
    }
};