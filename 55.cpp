//
// Created by 梁栋 on 2019-02-22.
//
#include "BinaryTree.cpp"
#include <iostream>
using namespace std;
class Solution{
public:
    static void solution(){
        vector<int> preorder = {1, 2, 4, 5, 7, 3};
        vector<int> inorder = {4, 2, 7, 5, 1, 3};
        BinaryTree binaryTree(preorder, inorder);
        cout<<"Depth is "<<binaryTree.getDepth()<<endl;
        binaryTree.printTree();
        cout<<"\nIs Balanced Binary Tree?"<<binaryTree.isBalanced()<<endl;
    }
};