//
// Created by 梁栋 on 2019-03-31.
// 复杂链表的复制
//
#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
    static RandomListNode* buildFromVector(vector<int> nums){
        RandomListNode* pHead = new RandomListNode(nums[0]);
        RandomListNode* cur = pHead;
        vector<RandomListNode*> nodes;
        nodes.push_back(cur);
        for(int i=1;i<nums.size();i++){
            cur->next = new RandomListNode(nums[i]);
            cur = cur->next;
            nodes.push_back(cur);
        }
        nodes[0]->random = nodes[0];
        nodes[0]->random = nodes[0];
        return pHead;
    }
    void print(){
        RandomListNode* cur = this;
        while (cur != NULL){
            cout<<cur->label<<"->";
            cur = cur->next;
        }
        cout<<endl;
        cur = this;
        while (cur != NULL){
            if(cur->random != NULL){
                cout<<cur->label<<"->"<<cur->random->label<<endl;
            }
            cur = cur->next;
        }
    }
};
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead){
        if(pHead == NULL)
            return NULL;
        // 时间复杂度O(N),不需要额外的空间
        RandomListNode* cur = pHead;
        // 构建A->A'->B->B'这样的序列
        while (cur != NULL){
            RandomListNode* newNode = new RandomListNode(cur->label);
            newNode->next = cur->next;
            cur->next = newNode;
            cur = newNode->next;
        }
        // 完成侧边链表的复制
        cur = pHead;
        while(cur != NULL){
            if(cur->random != NULL){
                RandomListNode* target = cur->random->next;
                cur->next->random = target;
            }
            cur = cur->next->next;
        }
        // 生成新的list
        cur = pHead;
        RandomListNode* res = new RandomListNode(0);
        RandomListNode* res_head = res;
        while(cur){
            res->next = cur->next;
            res = res->next;
            cur->next = cur->next->next;
            cur = cur->next;

        }
        return res_head->next;
    }
    static void solution(){
        RandomListNode* pHead = RandomListNode::buildFromVector({1});
        pHead->print();
        Solution solution1;
        RandomListNode* cloneHead = solution1.Clone(pHead);
        cloneHead->print();
    }
    RandomListNode* Clone1(RandomListNode* pHead)
    {
        // 需要结束O(N)的空间复杂度，时间复杂度是O(N)
        map<RandomListNode*, RandomListNode*> map1;
        RandomListNode* res = new RandomListNode(0);
        RandomListNode* pHeadOriginal = pHead;
        RandomListNode* cur = res;
        while(pHeadOriginal!= NULL){
            cur->next = new RandomListNode(pHeadOriginal->label);
            map1[pHeadOriginal] = cur->next;
            pHeadOriginal = pHeadOriginal->next;
            cur = cur->next;
        }
        cur = res->next;
        pHeadOriginal = pHead;
        while(pHeadOriginal != NULL){
            if(pHeadOriginal->random != NULL){
                cur->random = map1[pHeadOriginal->random];
            }
            pHeadOriginal = pHeadOriginal->next;
            cur = cur->next;
        }
        return res->next;
    }
};
