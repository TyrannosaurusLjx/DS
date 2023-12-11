# include "BT.h"

# include <iostream>

int main(){

    BinaryTree<int> T;
    int a,b,c,d;
    a = 1;
    b = 2;
    c = 3;
    d = 4;
    bool s = T.isEmpty();
    std::cout<<"bool:"<< s <<std::endl;
    T.printTree();


}