#include "tree.h"
#include <iostream>

int main(){

    int a,b,c,d;
    a = 1;
    b = 2;
    c = 3;
    d = 4;
    //// BinaryTree
    // std::cout<<"测试二叉树"<<std::endl;
    // BinaryTree<int> BT;
    // BT.printTree();
    // std::cout<<BT.isEmpty()<<std::endl;
    
    std::cout<<"测试二叉搜索树"<<std::endl;
    BinarySearchTree<int>BST;
    BST.printTree();
    std::cout<<"bool = "<<BST.isEmpty()<<std::endl;
    BST.insert(a);  
    BST.printTree();
    BST.insert(2);
    std::cout<<"bool = "<<BST.isEmpty()<<std::endl;
    BST.printTree();
    BST.makeEmpty();
    std::cout<<std::endl;
    BST.printTree();

}