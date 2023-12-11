# include "AT.h"
# include<iostream>


int main(){
    int a,b,c,d;
    a = 1;
    b = 2;
    c = 3;
    d = 4;

    AvlTree<int> T;
    T.insert(a);
    T.printTree(); // 1
    T.insert(9);
    T.printTree(); // 1 9
    std::cout<<T.contains(b)<<std::endl; // 1
    T.insert(c);
    T.printTree(); // 1 5 9
    int m = T.findMin();
    std::cout<<T.isEmpty()<<"m"<<m<<std::endl; // 0
    T.makeEmpty();
    T.printTree();// empty

}