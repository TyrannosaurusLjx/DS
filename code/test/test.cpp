# include<iostream>
# include "BST.h"


int main(){

    BinarySearchTree<int> T;
    int a ;
    a = 1;
    T.insert(a);
    T.insert(6); 
    T.insert(8);  
    bool b  = T.contains(6); 
    std::cout<<b<<std::endl;//1


    int c = T.findMin();//1
    int d = T.findMax(); // 8 
    // 1 168 18 18
    T.printTree();
    T.remove(6);
    std::cout<<c<< " "<<d<<std::endl;//1 6

    T.printTree();





    

}