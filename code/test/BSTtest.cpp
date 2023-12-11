# include "BST.h"
# include<iostream>

int main(){
    int a,b,c;
    a = 1;
    b = 9;
    c = 5;
    BinarySearchTree<int> T;
    T.insert(a);
    T.printTree(); // 1
    T.insert(9);
    T.printTree(); // 1 9
    std::cout<<T.contains(b)<<std::endl; // 1
    T.insert(c);
    T.printTree(); // 1 5 9
    std::cout<<T.isEmpty()<<std::endl; // 0
    T.makeEmpty();
    T.printTree();// empty


}